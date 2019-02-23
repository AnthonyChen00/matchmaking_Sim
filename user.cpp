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

}

void User::addUser(User targetUser){

}

int User::ping(User target){ // [c] frickin forward declarations, I am getting confused by the pointers and stuff
  return 0;
  // attempt 2
  // City temp = target.getCity();
  // int distance = temp.getDistance(this->getCity());
  // return distance;
  // // return target.getBandwidth() + target.getCity()->getDistance(target.getCity()); //original attempt
}

void User::send(){

}
