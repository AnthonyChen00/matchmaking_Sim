#pragma once
#ifndef CITY_H
#define CITY_H

#include "user.h"
#include <vector>

class User;
class Server;

class City{
  public:
    City();
    ~City();

    // Setters and Getters
    int getCityNo(){return cityNo;}
    void setPercent(int newPercent){percent = newPercent;};
    int getPercent(){return percent;}
    void setCityNo(int newCityNo){cityNo = newCityNo;} // update/assign the current City ID
    std::vector<User> getUsers(){return Users;}
    int setAdjMatrix(std::vector< std::vector<int> > desiredMatrix);
    int getDistance(int cityID); // return the distance between this city and targetCity
    void updateDistance(int distance, City targetCity); // update the distance between this city and targetCity

    // Member functions
    // Adding another city and updating adjMatrix for the distance to that city
    void addCity(int distance[]);
    // Removing a user from list of Users
    void removeUser(User targetUser);
    // Adding a user to the city
    void addUser(User targetUser);
    // Printing for testing purposes
    void printUsers();
    void printAdjMatrix();

  private:
    std::vector<User> Users;
    std::vector< std::vector<int> > adjMatrix; // [a]: should be shared among all the cities, should the simulator update/maintain the matrix completely?
    int cityNo;
    int percent;
};

#endif
