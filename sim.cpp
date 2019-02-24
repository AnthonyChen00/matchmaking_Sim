#include "sim.h"
#include <iostream>

/* Simulator consisting of 3 cities (1,2,3) and 3 edges.
                  a
              3->/ \ <- 5
                b--c
            6> /  ^4
              d
*/

/* adjacent matrix repesentation
    a b c d
  a|0|3|5|0
  b|3|0|4|6
  c|5|4|0|0
  d|0|6|0|0
*/

void Sim::initialize_Simulator_A(){
  //Initialize listOfCities
  City a;
  a.setCityNO(1);
  add_city(a);
  City b;
  b.setCityNO(2);
  add_city(b);
  City c;
  c.setCityNO(3);
  add_city(c);
  City d;
  d.setCityNO(4);
  add_city(d);

  std::vector<City> tempCityList;
  tempCityList.push_back(a);
  tempCityList.push_back(b);
  tempCityList.push_back(c);
  tempCityList.push_back(d);
  // Initializing Server
  Server server(tempCityList);

  server.updateMatrix(3,a,b);
  server.updateMatrix(5,a,c);
  server.updateMatrix(4,b,c);
  server.updateMatrix(6,b,d);
  server.init_city_adjMatrix();
  //Add listOfUsers
  for(int i=0; i<30; i++){
    int chooser;
    chooser = i%4; // 4 for the amount of cities.
    if(chooser == 0){
      //User addedUser()
    }
    else if(chooser == 1){

    }
    else if(chooser == 2){

    }
    else if(chooser == 3){

    }
  }
}

void Sim::add_city(City newCity){
  listOfCities.push_back(newCity);
}


int main(){
  std::cout << "hello :)" << std::endl; // [d] main function to make sure everything is compiling
}
