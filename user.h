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
    Server* getServer(){return server;}
    City* getCity(){return currentCity;}
    void removeUser(User targetUser); //[e] might need to change the data structure/format of the user list of other users
    void addUser(User targetUser);    //[e] dont know how to deal with indexing users from the list  and how to handle user's being deleted
    int ping(User target);
    void send();
  private:
    int userID;
    int bandwidth;
    City* currentCity;
    std::vector<int> distanceTo; //need a method of knowing which user is to where - how will we distingush who this one guy is connected to?
    Server* server;
};

#endif
