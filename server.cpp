#include "server.h"

Server::Server(){

}
Server::~Server(){

}

void Server::group(){

}

void Server::removeUser(User targetUser){
  for(int i=0; i<userList.size(); ++i){
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

void Server::updateUserDistances(int userID, std::vector<int> distanceTo){

}

void Server::commandUserPing(User pingingUser){
  pingingUser.pingAll(userList);
}
void Server::commandUserPing(User pingingUser, User pingedUser){
  pingingUser.ping(pingedUser);
}
