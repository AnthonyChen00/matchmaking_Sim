#include "sim.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define NUMBEROFUSERS 50000
#define NUMBEROFSIMS 1

/* Simulator consisting of 4 cities (1,2,3,4) and 4 edges.
                  a
            10 ->/ \ <- 25
                b--c
          30 > /  ^15
              d

5000 users initialized with:
bandwidth = 10

 adjacent matrix repesentation
    a b c d
  a|0|10|25|12
  b|10|0|15|30
  c|25|15|0|15
  d|12|30|15|0
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

  std::vector<City> tempCityList;
  tempCityList.push_back(a);
  tempCityList.push_back(b);
  tempCityList.push_back(c);
  tempCityList.push_back(d);

  server.init_cities(tempCityList);


  server.updateMatrix(10,a,b);
  server.updateMatrix(25,a,c);
  server.updateMatrix(15,b,c);
  server.updateMatrix(30,b,d);
  server.updateMatrix(12,a,d);
  server.updateMatrix(15,c,d);

  server.init_city_adjMatrix();
}
void Sim::create_users(){
  outputFile.open("groups_of_users.txt");
  auto t1 = std::chrono::high_resolution_clock::now();

  for(unsigned int i=0; i<NUMBEROFUSERS; i++){
    std::vector<int> newGroup;
    int chooser;
    chooser = std::rand()%100;
    if(chooser >= 50){
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
    else if(chooser >= 30 && chooser < 50){
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
    else if(chooser >= 10 && chooser < 30){
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
    else if(chooser < 10){
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
  outputFile.open("Average_time.csv");
  auto t2 = std::chrono::high_resolution_clock::now();
<<<<<<< HEAD
  outputFile << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() <<",";
  outputFile.close();
  // std::cout << "PART E\n";
=======
>>>>>>> 582adba165ba1be529b7403ec3ebf366658a5d57
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
  outputFile.close();
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

void Sim::processTime(){
  inputFile.open("Average_time.csv");
  std::string line;
  getline(inputFile,line);
  switch (mode) {
    case 0:
      outputFile.open("Average_time_normal.csv",std::ios::app);
      break;

    case 1:
      outputFile.open("Average_time_random.csv",std::ios::app);
      break;

    case 2:
      outputFile.open("Average_time_geo.csv",std::ios::app);
      break;
  }
  outputFile<<line<<std::endl;
  outputFile.close();
  inputFile.close();
}



int main(){
  std::ofstream outputFile1;
  double sum = 0.0;
  outputFile1.open("Average_ping_normal.csv");
  for (int i = 0; i < NUMBEROFSIMS; i++){
    std::srand((unsigned)time(0)+i);
    Sim simulators;
    simulators.setMode(1);
    simulators.initialize_Simulator();
    simulators.create_users();
    double ping = simulators.averagePing();
    outputFile1 << ping << "," << std::endl;
    sum += ping;
    simulators.processTime();
  }
  std::cout<<"Normal method average ping is: " << sum/NUMBEROFSIMS << std::endl;
  outputFile1.close();
  sum = 0.0;

  // outputFile1.open("Average_ping_random.csv");
  // for(int i = 0; i < NUMBEROFSIMS; i++){
  //   std::srand((unsigned)time(0)+i);
  //   Sim simulators;
  //   simulators.setMode(2);
  //   simulators.initialize_Simulator();
  //   simulators.create_users();
  //   double ping = simulators.averagePing();
  //   outputFile1 << ping << "," << std::endl;
  //   sum += ping;
  //   simulators.processTime();
  // }
  // std::cout<<"Random method average ping is: " << sum/NUMBEROFSIMS << std::endl;
  // outputFile1.close();
  // sum = 0.0;
  //
  // outputFile1.open("Average_ping_geo.csv");
  // for (int i = 0; i < NUMBEROFSIMS; i++){
  //   std::srand((unsigned)time(0)+i);
  //   Sim simulators;
  //   simulators.setMode(0);
  //   simulators.initialize_Simulator();
  //   simulators.create_users();
  //   double ping = simulators.averagePing();
  //   outputFile1 << ping << "," << std::endl;
  //   sum += ping;
  //   simulators.processTime();
  // }
  // std::cout<<"Geolocation method average ping is: " << sum/NUMBEROFSIMS << std::endl;
  // outputFile1.close();
}
