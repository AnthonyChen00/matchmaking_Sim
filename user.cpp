#include "user.h"


User::User(){
  bandwidth = rand() % 5;
  currentCity = NULL;
  server = NULL;
}

User::~User(){
  server = NULL;
  currentCity = NULL;
  while(!distanceTo.empty()){
    distanceTo.pop_back();
  }
}

void User::removeUser(User targetUser){
  //removing an user would removes from distanceTo vector
}

void User::addUser(User targetUser){
  int distance = ping(targetUser);
  distanceTo.push_back(distance);
}

int User::ping(User target){
  int distance = currentCity->getDistance(*(target.getCity()));
  return distance/bandwidth;
}

void User::send(){
  server->updateUserDistances(userID, distanceTo);
}
