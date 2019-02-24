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

    //Setters and Getters
    void getID(){return userID;}
    void setID(int new_ID){userID = new_ID;} //assigned by the server
    void setCity(City* newCity){currentCity = newCity;}
    void setServer(Server* newServer){server = newServer;}
    int getBandwidth(){return bandwidth;}
    void setBandWidth(int new_bandwidth){bandwidth = new_bandwidth;}
    Server* getServer(){return server;}
    City* getCity(){return currentCity;}

    // Member Functions
    void removeUser(User targetUser);
    void addUser(User targetUser);    
    void send();

  private:
    int userID;
    int bandwidth;
    City* currentCity;
    std::vector<int> distanceTo;
    Server* server;
};

#endif
