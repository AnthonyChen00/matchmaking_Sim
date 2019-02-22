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
    void removeUser(User targetUser);
    void addUser(User targetUser);
    void updateMatrix(int value, int row, int col);
    int getCity(){return cityNo;}
    void setCity(int newCityNo){cityNo = newCityNo;}
  private:
    std::vector<User> Users;
    std::vector< std::vector<int> > adjMatrix;
    //needs to store the distance to other cities, maybe have an array? each index represents a city and the value is the distance? 
    int cityNo;
};

#endif
