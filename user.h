#pragma once
#ifndef USER_H
#define USER_H

#include "server.h"
#include "city.h"
#include <vector>

class City;
class Server;

class User{
  public:
    User();
    ~User();
    void setCity(City* newCity){currentCity = newCity;}
    City* getCity(){return currentCity;}
    void removeUser(User targetUser);
    void addUser(User targetUser);
    int ping(User target);
    void send();
  private:
    int bandwidth;
    City* currentCity;
    std::vector<int> distanceTo;
    Server* server;
};

#endif
