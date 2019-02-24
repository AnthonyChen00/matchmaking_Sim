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
      userList.erase(i);
    }
  }
}

void Server::addUser(User targetUser){

}

void Server::updateMatrix(int value, int row, int col){

}

void Server::updateUserDistances(int userID, std::vector<int> distanceTo){

}
