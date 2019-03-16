#include "city.h"

City::City(){
  cityNo = 0;
  percent = 0;
}

City::~City(){

}

int City::setAdjMatrix(std::vector< std::vector<int> > desiredMatrix){
  for(unsigned int i=0; i<desiredMatrix.size(); i++){
    adjMatrix.push_back(desiredMatrix[i]);
  }
  return 0;
}
void City::printAdjMatrix(){
  std::cout << " in printAdjMatrix" << std::endl;
  for(unsigned int i=0;i<adjMatrix.size();i++){
    for(unsigned int j=0; j<adjMatrix.size();j++){
      std::cout << adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
void City::updateDistance(int distance, City targetCity){
  //remove the value of the city and then put it back
  int targetCityId = targetCity.getCityNo();
  adjMatrix[targetCityId][cityNo] = distance;
  adjMatrix[cityNo][targetCityId] = distance;
}

int City::getDistance(int cityID){
  //return the distance of city - related to user.h ping function
  return(adjMatrix[cityNo][cityID]);
}


void City::addUser(User targetUser){
  Users.push_back(targetUser);
}

void City::removeUser(User targetUser){
  for (unsigned int i = 0; i < Users.size(); i++){
    if (targetUser.getID() == Users[i].getID()){
      Users.erase(Users.begin()+i);
      break;
    }
    else{
      Users[i].removeUser(targetUser);
    }
  }
}

void City::printUsers(){
  for (unsigned int i = 0; i < Users.size();i++){
    printf("%d ",Users[i].getID());
  }
}
