#include "server.h"

Server::Server(std::vector<City> cities){
  for(unsigned int i=0;i<cities.size();i++){
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

void Server::init_city_adjMatrix(){
  for(unsigned int i=0; i<cityList.size();i++){
    cityList[i].setAdjMatrix(adjMatrix);
  }
}
void Server::removeUser(User targetUser){
  //search within the userList for the targetUser ID index of the list

  for (unsigned int i = 0; i < userList.size(); i++){
    if (targetUser.getID() == userList[i].getID()){

      //remove the user from the list
      userList.erase(userList.begin() + i);
    }
    else{
      userList[i].removeUser(targetUser);
    }
  }
}


void Server::addUser(User targetUser){
  commandUserPing(targetUser);
  userList.push_back(targetUser);
  for(unsigned int i=0; i< userList.size();i++){
    commandUserPing(userList[i],targetUser);
  }
}
void Server::updateMatrix(int distance, City cityOne, City cityTwo){
  int cityOneId = cityOne.getCityNo();
  int cityTwoId = cityTwo.getCityNo();
  adjMatrix[cityOneId][cityTwoId] = distance;
  adjMatrix[cityTwoId][cityOneId] = distance;
}

void Server::updateUserWanted(int userID, std::vector<User> usersWanted){

}

void Server::commandUserPing(User pingingUser){
  pingingUser.pingAll(userList);
}
void Server::commandUserPing(User pingingUser, User pingedUser){
  pingingUser.ping(pingedUser);
}
