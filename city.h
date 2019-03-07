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

    int getCityNo(){return cityNo;}
    void setCityNo(int newCityNo){cityNo = newCityNo;} // update/assign the current City ID

    std::vector<User> getUsers(){return Users;}
    int setAdjMatrix(std::vector< std::vector<int> > desiredMatrix);
    int getDistance(int cityID); // return the distance between this city and targetCity
    void updateDistance(int distance, City targetCity); // update the distance between this city and targetCity

    void addCity(int distance[]);
    void removeUser(User targetUser);
    void addUser(User targetUser);

    void printAdjMatrix();

  private:
    std::vector<User> Users;
    std::vector< std::vector<int> > adjMatrix; // [a]: should be shared among all the cities, should the simulator update/maintain the matrix completely?
    int cityNo;
};

#endif
