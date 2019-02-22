#ifndef CITY_H
#define CITY_H

#include "user.h"
#include <vector>

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
    int cityNo;
};

#endif
