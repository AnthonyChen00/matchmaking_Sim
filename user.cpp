#include "user.h"


User::User(int userID, int bandwidth, Server* server, int city){
  cityID = city;
  this->server = server;
  this->userID = userID;
  this->bandwidth = bandwidth;
}

User::~User(){
  server = NULL;
  cityID = 0;
  while(!wantedHosts.empty()){
    wantedHosts.pop_back();
  }
}

// Both pingALL and ping should update addwantedHosts if needed to.
void User::pingAll(std::vector<User> users){
  // int desired_ping = 100 //to bypass error, need to implenment
  for(unsigned int i=0; i<users.size(); i++){
    ping(users[i]);
  }
}

double User::ping(User target){
  if(target.getID() == userID){
    return 0;
  }
  int distance = server->getDistance(getCity(),target.getCity());
  // printf("The distance: %d and the bandwidth: %d and the DESIRED_PING is %d \n", distance,bandwidth,DESIRED_PING);
  if(distance*1.0/bandwidth < DESIRED_PING){
    // printf("added \n");
    addWantedHosts(target);
    return (distance*1.0/bandwidth);
  }
}

void User::removeUser(User targetUser){
  for (unsigned int i = 0; i < wantedHosts.size(); i++){
    if (wantedHosts[i] == targetUser.getID()){
      wantedHosts.erase(wantedHosts.begin() + i);
      break;
    }
  }
}

void User::addWantedHosts(User wantedHost){
  wantedHosts.push_back(wantedHost.getID());
  send();
}

void User::setWantedHosts(std::vector<int> userWanted){
  wantedHosts =  userWanted;
}
// Use whenever wantedHosts is changed, so when hosts are added and when hosts are removed
void User::send(){
  server->updateUserWanted(userID, wantedHosts);
}
