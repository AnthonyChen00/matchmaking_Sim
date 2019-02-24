#include "city.h"

City::City(){
  cityNo = 0;
}

City::~City(){

}

int City::setAdjMatrix(std::vector< std::vector<int> > desiredMatrix){
  for(int i=0; i<desiredMatrix.size(); i++){
    adjMatrix.push_back(desiredMatrix[i]);
  }
  return 0;
}
void City::updateDistance(int distance, City targetCity){
  //remove the value of the city and then put it back
  int targetCityId = targetCity.getCityNo();
  adjMatrix[targetCityId][cityNo] = distance;
  adjMatrix[cityNo][targetCityId] = distance;
}

int City::getDistance(City targetCity){
  //return the distance of city - related to user.h ping function
  return(adjMatrix[cityNo][targetCity.getCityNo()]);
}

// void City::addCity(int distance[]){
//   //add a new city of adjmatrix
// }

void City::removeUser(User targetUser){
  
}
