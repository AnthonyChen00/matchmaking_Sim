#include "sim.h"
#include <iostream>

/* Simulator consisting of 3 cities (1,2,3) and 3 edges.
                  1
              a->/ \ <- b
                2--3
                  ^ c
*/

/* adjacent matrix repesentation
    1 2 3
  1|0|a|b
  2|a|0|c
  3|b|c|0
*/

void Sim::initialize_Simulator_A(){

  //Initialize listOfCities
  City a;
  City b;
  City c;
  listOfCities.push_back(a);
  listOfCities.push_back(b);
  listOfCities.push_back(c);

  //Initialize listOfUsers

}

void Sim::add_city(City newCity){
  listOfCities.push_back(newCity);
}


int main(){
  std::cout << "hello :)" << std::endl; // [d] main function to make sure everything is compiling
}
