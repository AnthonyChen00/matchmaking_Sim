#include "sim.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define NUMBEROFUSERS 30
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
void Sim::initialize_Simulator_A(){
  //Initialize listOfCities
  City a;
  a.setCityNo(0);
  add_city(a);
  City b;
  b.setCityNo(1);
  add_city(b);
  City c;
  c.setCityNo(2);
  add_city(c);
  City d;
  d.setCityNo(3);
  add_city(d);

  std::cout << "PART A" << std::endl;
  //creating cities
  std::vector<City> tempCityList;
  tempCityList.push_back(a);
  tempCityList.push_back(b);
  tempCityList.push_back(c);
  tempCityList.push_back(d);
  // Initializing Server
  // Server server(tempCityList);
  server.init_cities(tempCityList);

  std::cout << "PART B" << std::endl;
  //creating the distance matrix of all cities
  server.updateMatrix(3,a,b);
  server.updateMatrix(5,a,c);
  server.updateMatrix(4,b,c);
  server.updateMatrix(6,b,d);
  server.updateMatrix(9,a,d);
  server.updateMatrix(10,c,d);
  std::cout << "PART C" << std::endl;
  //updating the distance matrix of all the cities
  server.init_city_adjMatrix();

  printf("cities in server: %d\n",server.getCityList().size());

  std::cout << "PART D" << std::endl;
  //create users and adding them to list of users
  for(unsigned int i=0; i<NUMBEROFUSERS; i++){
    int chooser;
    chooser = i%4; // 4 for the amount of cities.
    if(chooser == 0){
      User addedUser(i%NUMBEROFUSERS,1,&server,0);
      server.addUser(addedUser);
      // listOfUsers.push_back(addedUser);
    }
    else if(chooser == 1){
      User addedUser(i%NUMBEROFUSERS,1,&server,1);
      server.addUser(addedUser);
      // listOfUsers.push_back(addedUser);
  }
    else if(chooser == 2){
      User addedUser(i%NUMBEROFUSERS,1,&server,2);
      server.addUser(addedUser);
      // listOfUsers.push_back(addedUser);
    }
    else if(chooser == 3){
      User addedUser(i%NUMBEROFUSERS,1,&server,3);
      server.addUser(addedUser);
      // listOfUsers.push_back(addedUser);
    }
  }
  std::cout << "PART E\n";
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
    // for(unsigned int j=0; j<printing[i].getWantedHosts().size();j++){
    //   std::printf("%d ", printing[i].getWantedHosts().at(j).getID());
    // }
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

void Sim::simulate_loss(){
  printf("Simulating removing user from all objects...\n");
  printf("Removing user %d, from city %d\n",server.getUserList().at(1).getID(), server.getUserList().at(1).getCity());
  server.removeUser(server.getUserList().at(1));
}

int main(){
  Sim simulator_a;
  simulator_a.initialize_Simulator_A();
  printf("Before\n");
  simulator_a.print_cities();
  printf("After\n");
  //simulator_a.simulate_loss();
  simulator_a.print_cities();
}
