#include "sim.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define NUMBEROFUSERS 5000
#define NUMBEROFSIMS 50

/* Simulator consisting of 3 cities (1,2,3) and 3 edges.
                  a
              3->/ \ <- 5
                b--c
            6> /  ^4
              d

30 users initialized with:
bandwidth = 10
spread out evenly among cities, added to cities in order of (a,b,c,d)

 adjacent matrix repesentation
    a b c d
  a|0|3|5|0
  b|3|0|4|6
  c|5|4|0|0
  d|0|6|0|0
*/

Sim::Sim(){
}

Sim::~Sim(){

}
void Sim::initialize_Simulator(){
  //Initialize listOfCities
  City a;
  a.setCityNo(0);
  a.setPercent(50);
  add_city(a);
  City b;
  b.setCityNo(1);
  b.setPercent(20);
  add_city(b);
  City c;
  c.setCityNo(2);
  c.setPercent(20);
  add_city(c);
  City d;
  d.setCityNo(3);
  d.setPercent(10);
  add_city(d);

  // std::cout << "PART A" << std::endl;
  //creating cities
  std::vector<City> tempCityList;
  tempCityList.push_back(a);
  tempCityList.push_back(b);
  tempCityList.push_back(c);
  tempCityList.push_back(d);

  server.init_cities(tempCityList);


  server.updateMatrix(3,a,b);
  server.updateMatrix(5,a,c);
  server.updateMatrix(4,b,c);
  server.updateMatrix(6,b,d);
  server.updateMatrix(9,a,d);
  server.updateMatrix(10,c,d);

  server.init_city_adjMatrix();
}
void Sim::create_users(){
  outputFile.open("groups_of_users.txt");
  auto t1 = std::chrono::high_resolution_clock::now();

  for(unsigned int i=0; i<NUMBEROFUSERS; i++){
    std::vector<int> newGroup;
    int chooser;
    //chooser = std::rand()%4; // 4 for the amount of cities.
    chooser = i % 4;
    if(chooser == 0){
      User addedUser(i%NUMBEROFUSERS,std::rand()%3+1,&server,0);
      newGroup = server.addUser(addedUser,mode);
      if(newGroup.size() > 0){
      for (auto i = newGroup.begin(); i != newGroup.end(); i++){
          outputFile << *i << " ";
        }
        outputFile << std::endl;
      }
      listOfUsers.push_back(addedUser);
    }
    else if(chooser == 1){
      User addedUser(i%NUMBEROFUSERS,std::rand()%3+1,&server,1);
      newGroup = server.addUser(addedUser,mode);
      if(newGroup.size() > 0){
        for (auto i = newGroup.begin(); i != newGroup.end(); i++){
            outputFile << *i << " ";
        }
        outputFile << std::endl;
      }
      listOfUsers.push_back(addedUser);
  }
    else if(chooser == 2){
      User addedUser(i%NUMBEROFUSERS,std::rand()%3+1,&server,2);
      newGroup = server.addUser(addedUser,mode);
      if(newGroup.size() > 0){
        for (auto i = newGroup.begin(); i != newGroup.end(); i++){
            outputFile << *i << " ";
        }
      outputFile << std::endl;
      }
      listOfUsers.push_back(addedUser);
    }
    else if(chooser == 3){
      User addedUser(i%NUMBEROFUSERS,std::rand()%3+1,&server,3);
      newGroup = server.addUser(addedUser,mode);
      if(newGroup.size() > 0){
        for (auto i = newGroup.begin(); i != newGroup.end(); i++){
            outputFile << *i << " ";
        }
        outputFile << std::endl;
      }
      listOfUsers.push_back(addedUser);
    }
  }
  outputFile.close();
  auto t2 = std::chrono::high_resolution_clock::now();
  // std::cout << "Simulator took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << "ms to matchmake\n";
  // std::cout << "PART E\n";
}

void Sim::add_city(City newCity){
  listOfCities.push_back(newCity);
}
void Sim::add_user(User newUser){
  listOfUsers.push_back(newUser);
}

void Sim::print_cities(){
  for(unsigned int i=0; i<server.getCityList().size();i++){
    printf("City %d:", server.getCityList().at(i).getCityNo());
    server.getCityList().at(i).printUsers();
    // print_Uservector(server.getCityList().at(i).getUsers());
    std::cout << std::endl;
  }
}

void Sim::print_users(){
  printf("User List:\n");
  for (unsigned int i = 0; i < listOfUsers.size();i++){
    printf("%d\n",listOfUsers[i].getID());
  }
}

void Sim::print_Uservector(std::vector<User> printing){
  for(unsigned int i=0; i<printing.size();i++){
    printf("UserID %d with these desired hosts:", printing[i].getID());
    std::cout << std::endl;
  }
}

void Sim::print_adjMatrix(){
  for (unsigned int i = 0; i < adjMatrix.size(); ++i){
    for (unsigned int j = 0; j < adjMatrix[0].size(); ++j){
      std::cout << adjMatrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}


double Sim::averagePing(){
  std::string line;
  int count = 0;
  double sum = 0;
  double temp = 0;
  inputFile.open("groups_of_users.txt");
  outputFile.open("pingValues.csv");
  if (inputFile.is_open()){
    while(getline(inputFile, line)){
      temp = calculate_ping(line);
      count++;
      sum+= temp;
      outputFile << std::to_string(temp) + ","<< std::endl;
    }
    inputFile.close();
  }
  return sum/count;
}

double Sim::calculate_ping(std::string input){
  int temp= 0;
  std::vector<int> users;
  double sum = 0;
  for (unsigned int i = 0; i < input.size();i++){
    if(input[i] == ' '){
      users.push_back(temp);
      temp = 0;
    }
    else{
      temp = temp * 10 + (input[i] - '0');
    }
  }
  for (unsigned int i = 1; i < users.size();i++){
    sum += listOfUsers[users[0]].ping(listOfUsers[users[i]]);
  }
  return sum/4;
}

int main(){
  std::ofstream outputFile;
  outputFile.open("Average_ping_normal.crv");
  double sum = 0.0;
  for (int i = 0; i < NUMBEROFSIMS; i++){
    std::srand((unsigned)time(0)+i);
    Sim simulators;
    simulators.setMode(1);
    simulators.initialize_Simulator();
    simulators.create_users();
    double ping = simulators.averagePing();
    outputFile << ping << "," << std::endl;
    sum += ping;
  }
  std::cout<<"Normal method average ping is: " << sum/NUMBEROFSIMS << std::endl;
  outputFile.close();
  sum = 0.0;

  outputFile.open("Average_ping_random.crv");
  for(int i = 0; i < NUMBEROFSIMS; i++){
    std::srand((unsigned)time(0)+i);
    Sim simulators;
    simulators.setMode(2);
    simulators.initialize_Simulator();
    simulators.create_users();
    double ping = simulators.averagePing();
    outputFile << ping << "," << std::endl;
    sum += ping;
  }
  std::cout<<"Random method average ping is: " << sum/NUMBEROFSIMS << std::endl;
  outputFile.close();
  sum = 0.0;

  outputFile.open("Average_ping_geo.crv");
  for (int i = 0; i < NUMBEROFSIMS; i++){
    std::srand((unsigned)time(0)+i);
    Sim simulators;
    simulators.setMode(0);
    simulators.initialize_Simulator();
    simulators.create_users();
    double ping = simulators.averagePing();
    outputFile << ping << "," << std::endl;
    sum += ping;
  }
  std::cout<<"Geolocation method average ping is: " << sum/NUMBEROFSIMS << std::endl;
  outputFile.close();
}
