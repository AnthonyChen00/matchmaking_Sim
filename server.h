#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "user.h"
#include <vector>

class City;
class User;

class Server{
  public:
    Server();
    ~Server();
    void group();
    void removeUser(User targetUser);
    void addUser(User targetUser);
    void updateMatrix(int value, int row, int col);
    void updateUserDistances(int userID, std::vector<int> distanceTo);
    void commandUserPing(User pingingUser);
    void commandUserPing(User pingingUser, User pingedUser);
  private:
    std::vector< std::vector<int> > adjMatrix;
    std::vector< std::vector<User> > userGroups;
    std::vector< City > cityList;
    std::vector< User > userList;
};

#endif
