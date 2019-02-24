#include "server.h"

Server::Server(std::vector<City> cities){
  for(int i=0;i<cities.size();i++){
    cityList.push_back(cities[i]);
  }
  for(int i=0;i<cities.size();i++){
    std::vector<int> tempVector(cities.size(),0);
    adjMatrix.push_back(tempVector);
  }
}
Server::~Server(){

}

void Server::group(){

}

void Server::removeUser(User targetUser){
  // search through the entire userList for targetUser. After deleting user,
  //update all past user's ID
  bool removed = false;
  for(int i=0; i<userList.size(); ++i){
    userList[i].removedUser(targetUser);
    if (removed){
      userList[i].setID(i);
    }
    if(targetUser.getID() == userList[i].getID()){
      userList.erase(userList.begin() + i);
    }
  }
  // Have to update other users Lists.
}

void Server::addUser(User targetUser){
  commandUserPing(targetUser);
  userList.push_back(targetUser);
  for(int i=0; i< userList.size();i++){
    commandUserPing(userList[i],targetUser);
  }
}

void Server::updateMatrix(int value, int row, int col){
  adjMatrix[row][col] = value;
}

void updateMatrix(int distance, City cityOne, City cityTwo){
  int cityOneId = cityOne.getCityNo();
  int cityTwoId = cityTwo.getCityNo();
  adjMatrix[cityOneId][cityTwoId] = distance;
  adjMatrix[cityTwoId][cityOneId] = distance;
}

void Server::commandUserPing(User pingingUser){
  pingingUser.pingAll(userList);
}
void Server::commandUserPing(User pingingUser, User pingedUser){
  pingingUser.ping(pingedUser);
}
