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
    void setCityNO(int newCityNo){cityNo = newCityNo;} // update/assign the current City ID

    int setAdjMatrix();
    int getDistance(City targetCity); // return the distance between this city and targetCity
    void updateDistance(int distance, City targetCity); // update the distance between this city and targetCity
<<<<<<< HEAD
    void addCity(int distance[]); // [b] dont think this is currently neccessary
    void removeUser(User targetUser);
    void addUser(User targetUser);
=======
    void addCity(int distance[]); 

>>>>>>> 21b25e7d6405a6859a4cb8ed7ff63dc3843352fe

  private:
    std::vector<User> Users;
    std::vector< std::vector<int> > adjMatrix;
    int cityNo;
};

#endif
