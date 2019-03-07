#pragma once
#ifndef USER_H
#define USER_H

#include "server.h"
#include "city.h"
#include <stdlib.h>
#include <vector>
#include <utility>
#include <iostream>

class City;
class Server;

class User{
  public:
    User(int userID, int bandwidth, Server* server, int cityID);
    ~User();

    //Setters and Getters
    int getID(){return userID;}
    void setID(int new_ID){userID = new_ID;}
    void setCity(int newCityId){cityID = newCityId;}
    void setServer(Server* newServer){server = newServer;}
    int getBandwidth(){return bandwidth;}
    void setBandWidth(int new_bandwidth){bandwidth = new_bandwidth;}
    Server* getServer(){return server;}
    int getCity(){return cityID;}

    std::vector<User> getWantedHosts(){return wantedHosts;}
    void addWantedHosts(User wantedHost);

    // Member Functions
    void removeUser(User targetUser);
    int ping(User target);
    void pingAll(std::vector<User> users);
    void send();

  private:
    int userID;
    int bandwidth;
    int cityID;
    std::vector<User> wantedHosts;
    Server* server;
};

#endif
