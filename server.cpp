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

void Server::init_city_adjMatrix(){

}
void Server::removeUser(User targetUser){
  //search within the userList for the targetUser ID index of the list
  for (int i = 0; i < userList.size(); i++){
    if (targetUser.getID == userlist[i].getID){
      //remove the user from the list
      userlist.erase(i);
      break;
    }
  }
  for (int i = 0; i < userList.size(); i++){

  }
  City targetUserCity = targetUser.getCity;
  targetUserCity.removeUser(targetUser);


  }
  //remove the targetUser's distance from everyone else's distance
  //remove from group?
}

void Server::addUser(User targetUser){
  commandUserPing(targetUser);
  userList.push_back(targetUser);
  for(int i=0; i< userList.size();i++){
    commandUserPing(userList[i],targetUser);
  }
}
void Server::updateMatrix(int distance, City cityOne, City cityTwo){
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
