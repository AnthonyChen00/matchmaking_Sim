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
    void setWantedHosts(std::vector<int> userWanted);
    std::vector<int> getWantedHosts(){return wantedHosts;}
    // Member Functions

    // Add a user into the wantedHost vector of a user
    void addWantedHosts(User wantedHost);
    // Removing a user from the wantedHosts vector
    void removeUser(User targetUser);
    // Pinging another user
    double ping(User target);
    // Pinging all other users within the userList of server
    void pingAll(std::vector<User> users);
    // Send updated wantedHost vector to the server
    void send();

  private:
    int userID;
    int bandwidth;
    int cityID;
    std::vector<int> wantedHosts;
    Server* server;
};

#endif
