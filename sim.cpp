#include "sim.h"
#include <iostream>

/* Simulator consisting of 3 cities (1,2,3) and 3 edges.
                  a
              3->/ \ <- 5
                b--c
                  ^ 4
*/

/* adjacent matrix repesentation
    a b c
  a|0|3|5
  b|3|0|4
  c|5|4|0
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

  // Initializing Server
  Server server;
  
  //Initialize listOfUsers

}

void Sim::add_city(City newCity){
  listOfCities.push_back(newCity);
}


int main(){
  std::cout << "hello :)" << std::endl; // [d] main function to make sure everything is compiling
}
