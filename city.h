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

    int getCityNo(){return cityNo;}
    void setCityNO(int newCityNo){cityNo = newCityNo;} // update/assign the current City ID

    int setAdjMatrix();
    int getDistance(City targetCity); // return the distance between this city and targetCity
    void updateDistance(int distance, City targetCity); // update the distance between this city and targetCity
    void addCity(int distance[]); 


  private:
    std::vector<User> Users;
    std::vector< std::vector<int> > adjMatrix;
    int cityNo;
};

#endif
