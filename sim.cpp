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
  a.setCityNO(0);
  add_city(a);
  City b;
  b.setCityNO(1);
  add_city(b);
  City c;
  c.setCityNO(2);
  add_city(c);
  City d;
  d.setCityNO(3);
  add_city(d);

  std::cout << "PART A" << std::endl;

  std::vector<City> tempCityList;
  tempCityList.push_back(a);
  tempCityList.push_back(b);
  tempCityList.push_back(c);
  tempCityList.push_back(d);
  // Initializing Server
  Server server(tempCityList);

  std::cout << "PART B" << std::endl;
  server.updateMatrix(3,a,b);
  server.updateMatrix(5,a,c);
  server.updateMatrix(4,b,c);
  server.updateMatrix(6,b,d);
  std::cout << "PART C" << std::endl;
  server.init_city_adjMatrix();

  std::cout << "PART D" << std::endl;
  //Add listOfUsers
  for(int i=0; i<NUMBEROFUSERS; i++){
    int chooser;
    chooser = i%4; // 4 for the amount of cities.
    std::cout << "PART E " << i << std::endl;
    if(chooser == 0){
      User addedUser(i%NUMBEROFUSERS,10,server,a);
      std::cout << i << std::endl;
      server.addUser(addedUser);
    }
    else if(chooser == 1){
      User addedUser(i%NUMBEROFUSERS,10,server,b);
      std::cout << i << std::endl;
      server.addUser(addedUser);
    }
    else if(chooser == 2){
      User addedUser(i%NUMBEROFUSERS,10,server,c);
      std::cout << i << std::endl;
      server.addUser(addedUser);
    }
    else if(chooser == 3){
      User addedUser(i%NUMBEROFUSERS,10,server,d);
      std::cout << i << std::endl;
      server.addUser(addedUser);
    }
  }
}

void Sim::add_city(City newCity){
  listOfCities.push_back(newCity);
}
void Sim::add_user(User newUser){
  listOfUsers.push_back(newUser);
}

void Sim::print_cities(){
  for(int i=0; i<listOfCities.size();i++){
    std::printf("City %d with these users: ", listOfCities[i].getCityNo());
    print_Uservector(listOfCities[i].getUsers());
    std::cout << std::endl;
  }
}

void Sim::print_users(){

}
void Sim::print_Uservector(std::vector<User> printing){
  for(int i=0; i<printing.size();i++){
    std::printf("UserID %d with these desired hosts:", printing[i].getID());
    for(int j=0; j<printing[i].getWantedHosts().size();j++){
      std::printf("%d ", printing[i].getWantedHosts().at(j).getID());
    }
    std::cout << std::endl;
  }
}
void Sim::print_adjMatrix(){
  for (int i = 0; i < adjMatrix.size(); ++i){
    for (int j = 0; j < adjMatrix[0].size(); ++j){
      std::cout << adjMatrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
int main(){
  Sim simulator_a;
  simulator_a.initialize_Simulator_A();
  simulator_a.print_cities();
}
