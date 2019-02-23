#pragma once
#ifndef USER_H
#define USER_H

#include "server.h"
#include "city.h"
#include <stdlib.h>
#include <vector>

class City;
class Server;

class User{
  public:
    User();
    ~User();
    void setCity(City* newCity){currentCity = newCity;}
    void setServer(Server* newServer){server = newServer;}
    int getBandwidth(){return bandwidth;}
    City* getCity(){return currentCity;}
    void removeUser(User targetUser);
    void addUser(User targetUser);
    int ping(User target);
    void send();
  private:
    int userID;
    int bandwidth;
    City* currentCity;
    std::vector<int> distanceTo; //need a method of knowing which user is to where
    Server* server;
};

#endif
