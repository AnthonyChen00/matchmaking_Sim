#include "server.h"

Server::Server(){

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
      userList.erase(i);
      removed = true;
    }
  }
}

void Server::addUser(User targetUser){
  targetUser.setID = userList.size();
  userList.push_back(targetUser);
  //needs to ping every other user
  //every other user needs to update their distanceTo vector to add new user
  for (int i = 0; i < userList.size(); i++){
      targetUser.addUser(userList[i]);
      userList[i].addUser(targetUser);
  }
}

void updateMatrix(int distance, City cityOne, City cityTwo){
  int cityOneId = cityOne.getCityNo;
  int cityTwoId = cityTwo.getCityNo;
  adjMatrix[cityOneId][cityTwoId] = distance;
  adjMatrix[cityTwoId][cityOneId] = distance;
}
