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

int User::ping(User target){
  return target.bandwidth;
}

void User::send(){
  
}
