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
  for(unsigned int i=0;i<userList.size();i++){
    printf("User %d is in city %d\n", userList[i].getID(),userList[i].getCity());
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
      cityList.at(targetUser.getCity()).removeUser(targetUser);
    }
    else{
      userList[i].removeUser(targetUser);
    }

  }
}

int Server::getDistance(int pingingUserCity, int targetUserCity){
  return adjMatrix[pingingUserCity][targetUserCity];
}
std::vector<int> Server::addUser(User targetUser){
  userList.push_back(targetUser);
  cityList[targetUser.getCity()].addUser(targetUser);
  std::vector<int> zero;
  int loc = userList.size()- 1;
  for(unsigned int i=0; i< userList.size();i++){
    commandUserPing(userList[i],userList[loc]);
  }

  for(unsigned int i=0; i< userList.size();i++){
    commandUserPing(userList[loc],userList[i]);
  }
  if(userList.size() > 5)
    return (matchmake());
  // if(userList.size() > 10)
  //   return matchmakeRandom();
  else{
    return zero;
  }
}
std::vector<int> Server::matchmakeRandom(){
  std::srand((unsigned)time(0));
  std::vector<int> final_group;
  for(int i=0; i<5;i++){
    int randomUser = rand()%userList.size();
    final_group.push_back(userList[randomUser].getID());
    removeUser(userList[randomUser]);
  }
  return final_group;
}
std::vector<int> Server::matchmake(){
  std::vector< std::pair<int, std::vector<int> > >count;
  std::vector<int> final_group;
  int target =0;
  int found = 0;
  //printf("In matchmaking \n");
  for(unsigned int i=0; i<userList.size(); i++){
    for(unsigned int j=0; j<userList[i].getWantedHosts().size(); j++){
      found = 0;
      for(unsigned int k=0; k<count.size(); k++){
        if(count.at(k).first == userList[i].getWantedHosts().at(j)){
          found = 1;
          count.at(k).second.push_back(userList[i].getID());
          if(count.at(k).second.size() >= 4){
            target = k;
            break;
          }
          break;
        }
      }
      if(found == 0){
        std::vector<int> tempVector;
        tempVector.push_back(userList[i].getID());
        count.push_back(std::pair<int, std::vector<int>>(userList[i].getWantedHosts().at(j),tempVector));
      }
      if(target!= 0){
        break;
      }
    }
    if(target!=0){
      break;
    }
  }
  if(target!=0){
    //printf("Found target \n");
    final_group.push_back(count.at(target).first);
    for(unsigned int i=0; i<count.at(target).second.size();i++){
      //printf("%d",count.at(target).second.at(i));
      final_group.push_back(count.at(target).second.at(i));
      for(unsigned int j=0;j<userList.size();j++){
        if(userList[j].getID() == count.at(target).second.at(i)){
          removeUser(userList[j]);
          break;
        }
      }
    }
    for(unsigned int j=0;j<userList.size();j++){
      if(userList[j].getID() == count.at(target).first){
          removeUser(userList[j]);
      }
    }
  }
  return (final_group);
}



void Server::updateMatrix(int distance, City cityOne, City cityTwo){
  int cityOneId = cityOne.getCityNo();
  int cityTwoId = cityTwo.getCityNo();
  adjMatrix[cityOneId][cityTwoId] = distance;
  adjMatrix[cityTwoId][cityOneId] = distance;
}

void Server::updateUserWanted(int userID, std::vector<int> usersWanted){
  for(unsigned int i=0; i<userList.size();i++){
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
