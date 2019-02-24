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

<<<<<<< HEAD
void User::pingAll(std::vector<User> users){
  for(int i=0; i<users.size(); i++){
    std::pair<int,int> tempPair;
    tempPair.first = users[i].getID();
    tempPair.second = ping(users[i]);
    distanceTo.push_back(tempPair);
  }
  send();
}
int User::ping(User target){ // [c] frickin forward declarations, I am getting confused by the pointers and stuff
  if(target.getID() == userID){
    return 0;
  }
=======
void User::removeUser(User targetUser){
  //removing an user would removes from distanceTo vector
}

void User::addUser(User targetUser){
  int distance = ping(targetUser);
  distanceTo.push_back(distance);
}

int User::ping(User target){
>>>>>>> 21b25e7d6405a6859a4cb8ed7ff63dc3843352fe
  int distance = currentCity->getDistance(*(target.getCity()));
  return distance/bandwidth;
}

void User::send(){
//  server->updateUserDistances(userID, distanceTo);
}
