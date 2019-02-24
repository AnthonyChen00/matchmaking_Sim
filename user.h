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
    User(int userID, int bandwidth, Server server, City city);
    ~User();

    //Setters and Getters
    int getID(){return userID;}
    void setID(int new_ID){userID = new_ID;}
    void setCity(City* newCity){currentCity = newCity;}
    void setServer(Server* newServer){server = newServer;}
    int getBandwidth(){return bandwidth;}
    void setBandWidth(int new_bandwidth){bandwidth = new_bandwidth;}
    Server* getServer(){return server;}
    City* getCity(){return currentCity;}
    void addWantedHosts(User wantedHost);
    // Member Functions
    int ping(User target);
    void pingAll(std::vector<User> users);
    void send();

  private:
    int userID;
    int bandwidth;
    City* currentCity;
    std::vector< std::pair<int,int> > distanceTo; //need a method of knowing which user is to where - how will we distingush who this one guy is connected to?
    std::vector<User> wantedHosts;
    Server* server;
};

#endif
