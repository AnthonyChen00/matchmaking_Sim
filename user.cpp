#include "user.h"


User::User(int userID, int bandwidth, Server* server, int city){
  cityID = city;
  this->server = server;
  this->userID = userID;
  this->bandwidth = bandwidth;
}

User::~User(){
  server = NULL;
  currentCity = 0;
  while(!wantedHosts.empty()){
    wantedHosts.pop_back();
  }
}

// Both pingALL and ping should update addwantedHosts if needed to.
void User::pingAll(std::vector<User> users){
  // int desired_ping = 100 //to bypass error, need to implenment
  for(unsigned int i=0; i<users.size(); i++){
    // if (ping(users[i]) < desired_ping){
    //   addWantedHosts(users[i]);
    // }
  }
  send();
}
int User::ping(User target){
  if(target.getID() == userID){
    return 0;
  }
  int distance = server->getDistance(getCity(),target.getCity());
  return distance/bandwidth;
}

void User::removeUser(User targetUser){
  for (unsigned int i = 0; i < wantedHosts.size(); i++){
    if (wantedHosts[i].getID() == targetUser.getID()){
      wantedHosts.erase(wantedHosts.begin() + i);
    }
  }
}

void User::addWantedHosts(User wantedHost){
  wantedHosts.push_back(wantedHost);
  send();
}

// Use whenever wantedHosts is changed, so when hosts are added and when hosts are removed
void User::send(){
  server->updateUserWanted(userID, wantedHosts);
}
