#include "server.h"

Server::Server(){

}
Server::Server(std::vector<City> cities){
  //constructor for a server object
  for(unsigned int i=0;i<cities.size();i++){
    std::vector<int> tempVector(cities.size(),0);
    adjMatrix.push_back(tempVector);
  }
}
Server::~Server(){

}

void Server::group(){

}

void Server::init_cities(std::vector<City> cities){
  for(unsigned int i=0;i<cities.size();i++){
    std::vector<int> tempVector(cities.size(),0);
    cityList.push_back(cities[i]);
    adjMatrix.push_back(tempVector);
  }
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
  userList.push_back(targetUser);
  int loc = userList.size()- 1;
  for(unsigned int i=0; i< userList.size();i++){
    commandUserPing(userList[i],userList[loc]);
  }

  for(unsigned int i=0; i< userList.size();i++){
    commandUserPing(userList[loc],userList[i]);
  }
  if(userList.size() > 5)
    matchmake();
}
void Server::matchmake(){
  std::vector< std::pair<int,int> >count;
  int target =0;
  int found = 0;
  for(int i=0; i<userList.size(); i++){
    for(int j=0; j<userList[i].getWantedHosts().size(); j++){
      found = 0;
      for(int k=0; k<count.size(); k++){
        if(count.at(k).first == userList[i].getWantedHosts().at(j).getID()){
          found = 1;
          count.at(k).second = count.at(k).second + 1;
          if(count.at(k).second >= 4){
            target = count.at(k).first;
            printf("USER %d HAS BROKEN FORMATION", count.at(k).first);
            break;
          }
          break;
        }
      }
      if(found == 0){
        count.push_back(std::pair<int,int>(userList[i].getWantedHosts().at(j).getID(),1));
      }
      if(target!= 0){
        break;
      }
    }
    if(target!=0){
      break;
    }
  }

  // Add data about the pinging distance in each group.
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
