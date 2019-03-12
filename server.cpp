#include "server.h"

Server::Server(){

}
Server::Server(std::vector<City> cities){
  //constructor for a server object
  for(unsigned int i=0;i<cities.size();i++){
    printf("cities[%d] has cityno of %d", i, cities[i].getCityNo());
    cityList.push_back(cities[i]);
  }
  for(unsigned int i=0;i<cities.size();i++){
    std::vector<int> tempVector(cities.size(),0);
    adjMatrix.push_back(tempVector);
  }
}
Server::~Server(){

}

void Server::group(){

}

void Server::printCity(){
  for(unsigned int i=0; i<cityList.size();i++){
    printf("cityList[%d] has cityno of %d", i, cityList[i].getCityNo());
    cityList[i].printAdjMatrix();
    printf("\n");
  }
}
void Server::printUsers(){
  for(int i=0;i<userList.size();i++){
    printf("User %d is in city %d", userList[i].getID(),userList[i].getCity());
  }
}
void Server::init_city_adjMatrix(){
  //creating a adjMatrix
  for(unsigned int i=0; i<cityList.size();i++){
    cityList[i].setAdjMatrix(adjMatrix);
  }
}
void Server::removeUser(User targetUser){
  for (unsigned int i = 0; i < userList.size(); i++){
    if (targetUser.getID() == userList[i].getID()){

      userList.erase(userList.begin() + i);
    }
    else{
      userList[i].removeUser(targetUser);
    }
    cityList.at(targetUser.getCity()).removeUser(targetUser);
  }
}

int Server::getDistance(int pingingUserCity, int targetUserCity){
  return adjMatrix[pingingUserCity][targetUserCity];
}
void Server::addUser(User targetUser){
  // for(unsigned int i=0; i< userList.size();i++){
  //   commandUserPing(userList[i],targetUser);
  // }
  printf("SIZE OF USERLIST IS %d", userList.size());
  userList.push_back(targetUser);
  for(unsigned int i=0; i< userList.size();i++){
    commandUserPing(targetUser,userList[i]);
  }

}
void Server::updateMatrix(int distance, City cityOne, City cityTwo){
  int cityOneId = cityOne.getCityNo();
  int cityTwoId = cityTwo.getCityNo();
  adjMatrix[cityOneId][cityTwoId] = distance;
  adjMatrix[cityTwoId][cityOneId] = distance;
}

void Server::updateUserWanted(int userID, std::vector<User> usersWanted){
  for(int i=0; i<userList.size();i++){
    if(userList[i].getID() == userID){
      userList[i].setWantedHosts(usersWanted);
    }
  }
}

void Server::commandUserPing(User pingingUser){
  pingingUser.pingAll(userList);
}
void Server::commandUserPing(User pingingUser, User pingedUser){
  pingingUser.ping(pingedUser);
}
