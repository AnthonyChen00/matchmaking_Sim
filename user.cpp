#include "user.h"


User::User(int userID, int bandwidth, Server server, City city){
  currentCity = &city;
  this->server = &server;
  this->userID = userID;
  this->bandwidth = bandwidth;
}

User::~User(){
  server = NULL;
  currentCity = NULL;
  while(!distanceTo.empty()){
    distanceTo.pop_back();
  }
}

void User::pingAll(std::vector<User> users){
  for(int i=0; i<users.size(); i++){
    std::pair<int,int> tempPair;
    tempPair.first = users[i].getID();
    tempPair.second = ping(users[i]);
    distanceTo.push_back(tempPair);
  }
  send();
}
int User::ping(User target){
  if(target.getID() == userID){
    return 0;
  }
  int distance = currentCity->getDistance(*(target.getCity()));
  return distance/bandwidth;
}

void User::send(){
//  server->updateUserDistances(userID, distanceTo);
}
