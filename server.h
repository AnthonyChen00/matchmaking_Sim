#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "user.h"
#include <vector>

class City;
class User;

#define DESIRED_PING 5
//Server maintains a userlist and tell users to ping other users to update the list
class Server{
  public:
    Server();
    Server(std::vector<City> cities);
    ~Server();
    void init_city_adjMatrix();
    void group();

    void addCity(City* new_city){cityList.push_back(*(new_city));}
    std::vector<City> getCityList(){return cityList;}
    std::vector<User> getUserList(){return userList;}
    void printCity();
    void printUsers();
    void addUser(User targetUser);
    void removeUser(User targetUser);
    int getDistance(int pingingUserCity, int targetUserCity);
    void updateMatrix(int distance, City cityOne, City cityTwo); //updating the adjacent matrix
    void updateUserWanted(int userID, std::vector<User> usersWanted);

    void commandUserPing(User pingingUser);
    void commandUserPing(User pingingUser, User pingedUser);
  private:
    std::vector< std::vector<int> > adjMatrix;
    std::vector< std::vector<User> > userGroups;
    std::vector< City > cityList;
    std::vector< User > userList;
};

#endif
