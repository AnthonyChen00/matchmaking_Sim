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
<<<<<<< HEAD
      userList.erase(userList.begin() + i);
=======
      userList.erase(i);
      removed = true;
>>>>>>> 21b25e7d6405a6859a4cb8ed7ff63dc3843352fe
    }
  }
  // Have to update other users Lists.
}

void Server::addUser(User targetUser){
<<<<<<< HEAD
  commandUserPing(targetUser);
  userList.push_back(targetUser);
  for(int i=0; i< userList.size();i++){
    commandUserPing(userList[i],targetUser);
  }
}

void Server::updateMatrix(int value, int row, int col){
  adjMatrix[row][col] = value;
=======
  targetUser.setID = userList.size();
  userList.push_back(targetUser);
  //needs to ping every other user
  //every other user needs to update their distanceTo vector to add new user
  for (int i = 0; i < userList.size(); i++){
      targetUser.addUser(userList[i]);
      userList[i].addUser(targetUser);
  }
>>>>>>> 21b25e7d6405a6859a4cb8ed7ff63dc3843352fe
}

void updateMatrix(int distance, City cityOne, City cityTwo){
  int cityOneId = cityOne.getCityNo;
  int cityTwoId = cityTwo.getCityNo;
  adjMatrix[cityOneId][cityTwoId] = distance;
  adjMatrix[cityTwoId][cityOneId] = distance;
}

void Server::commandUserPing(User pingingUser){
  pingingUser.pingAll(userList);
}
void Server::commandUserPing(User pingingUser, User pingedUser){
  pingingUser.ping(pingedUser);
}
