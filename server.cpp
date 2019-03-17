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
std::vector<int> Server::addUser(User targetUser, int mode){
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
  if(userList.size() > 5){
    switch(mode){
      case 0:
        return geolocation();

      case 1:
        return matchmake();

      case 2:
        if (userList.size() > 10){
          return matchmakeRandom();
        }
        else{
          return zero;
        }
    }
  }
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

std::vector<int> Server::geolocation(){
  std::vector< std::pair<int, std::vector<int> > >count;
  std::vector<int> final_group;
  std::vector<int> target;
  int found = 0;
  for(unsigned int i=0; i<userList.size(); i++){
    for(unsigned int j=0; j<userList[i].getWantedHosts().size(); j++){
      found = 0;
      for(unsigned int k=0; k<count.size(); k++){
        if(count.at(k).first == userList[i].getWantedHosts().at(j)){
          found = 1;
          count.at(k).second.push_back(userList[i].getID());
          if(count.at(k).second.size() >= 4){
            target.push_back(k);
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
    }
  }
  if(target.size()!=0){
    std::vector< std::vector<int> > temp(target.size());
    int desiredHost = -1;
    int targetCity;
    for (unsigned int i = 0 ; i < target.size();i++){
      for(unsigned int m =0; m<userList.size();m++){
        if(userList[m].getID() == count.at(target[i]).first){
          targetCity = userList[m].getCity();
        }
      }
      for (unsigned int j = 0; j < cityList[targetCity].getUsers().size();j++){
        for (unsigned int k = 0; k < count.at(target[i]).second.size();k++){
          if (count.at(target[i]).second.at(k) == cityList[targetCity].getUsers().at(j).getID()){
            temp[i].push_back(k);
          }
          if (temp[i].size() > 3){
            desiredHost = i;
            break;
          }
        }
        if (temp[i].size() > 3){
          break;
        }
      }
      if (temp[i].size() > 3){
        break;
      }
    }
    if (desiredHost == -1){
      int foundHost = 0;
      int percentage = 0;
      for (unsigned int i=0 ; i < target.size();i++){
        foundHost = 0;
        for(unsigned int m=0; m<userList.size();m++){
          if(userList[m].getID() == count.at(target[i]).first){
            targetCity = userList[m].getCity();
          }
        }
        for(unsigned int n=0; n<cityList.size();n++){
          if(targetCity == cityList[n].getCityNo()){
            percentage = cityList[n].getPercent() / 10;
          }
        }
        for(unsigned int j=0; j<waitingHosts.size();j++){
          if(waitingHosts[j].first == count.at(target[i]).first){
            foundHost = 1;
            waitingHosts[j].second = waitingHosts[j].second + 1;
            if(waitingHosts[j].second > percentage){
              waitingHosts.erase(waitingHosts.begin()+j);
              return geolocationHelper(count.at(target[i]),temp[i]);
            }
          }
        }
        if(foundHost == 0){
          waitingHosts.push_back(std::pair<int,int>(count.at(target[i]).first,0));
        }
      }
    }
    else{
      final_group.push_back(count.at(target.at(desiredHost)).first);
      for(unsigned int i=0; i<temp[desiredHost].size();i++){
        final_group.push_back(count.at(target.at(desiredHost)).second.at(temp[desiredHost].at(i)));
        for(unsigned int j=0; j<userList.size();j++){
          if(userList[j].getID() == count.at(target.at(desiredHost)).second.at(temp[desiredHost].at(i))){
            removeUser(userList[j]);
            break;
          }
        }
      }
      for(unsigned int j=0; j<userList.size();j++){
        if(userList[j].getID() == count.at(target.at(desiredHost)).first){
          removeUser(userList[j]);
          break;
        }
      }
    }
  }
  return (final_group);
}
std::vector<int> Server::geolocationHelper(std::pair<int,std::vector<int>> count, std::vector<int> temp){
  std::vector<int> final_group;
  final_group.push_back(count.first);
  int counter = temp.size();
  for(unsigned int j=0; j<temp.size(); j++){
    final_group.push_back(count.second.at(temp[j]));
    for(unsigned int k=0;k<userList.size();k++){
      if(userList[k].getID() == count.second.at(temp[j])){
        removeUser(userList[k]);
        break;
      }
    }
  }
  int iterator = 0;

  for(unsigned int j=0; j<temp.size();j++){
    count.second.erase(count.second.begin()+temp[j]-iterator);
    iterator++;
  }
  std::srand((unsigned)time(0));
  for(unsigned int i=counter; i<5;i++){
    int random = std::rand()%count.second.size();
    final_group.push_back(count.second.at(random));
    for(unsigned int j=0; j<userList.size();j++){
      if(userList[j].getID() == count.second.at(random)){
        removeUser(userList[j]);
        break;
      }
    }
  }
  for(unsigned int i=0; i<userList.size();i++){
    if(userList[i].getID() == count.first){
      removeUser(userList[i]);
      break;
    }
  }
  return final_group;
}

std::vector<int> Server::matchmake(){
  std::vector< std::pair<int, std::vector<int> > >count;
  std::vector<int> final_group;
  int target =0;
  int found = 0;
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
    final_group.push_back(count.at(target).first);
    for(unsigned int i=0; i<count.at(target).second.size();i++){
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
