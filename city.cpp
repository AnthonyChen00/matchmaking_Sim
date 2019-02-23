#include "city.h"

City::City(){
  cityNo = 0;
}

City::~City(){

}

void City::updateDistance(int distance, City targetCity){
  //remove the value of the city and then put it back
  int targetCityId = targetCity.getCityNo();
  this->adjMatrix[targetCityId][this->cityNo] = distance;
  this->adjMatrix[this->cityNo][targetCityId] = distance;
}

int City::getDistance(City targetCity){
  //return the distance of city - related to user.h ping function
  return(adjMatrix[this->cityNo][targetCity.getCityNo()]);
}

void City::addCity(int distance[]){
  //add a new city of adjmatrix
}
