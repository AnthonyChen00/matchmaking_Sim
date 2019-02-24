#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "user.h"
#include <vector>

class City;
class User;

//Server maintains a userlist and tell users to ping other users to update the list
class Server{
  public:
    Server();
    ~Server();
    void group();
    void removeUser(User targetUser);
    void addUser(User targetUser);
    void updateMatrix(int distance, City cityOne, City cityTwo); //updating the adjacent matrix
    void updateUserDistances(int userID, std::vector<int> distanceTo);
    void commandUserPing(User pingingUser);
    void commandUserPing(User pingingUser, User pingedUser);
  private:
    std::vector< std::vector<int> > adjMatrix;
<<<<<<< HEAD
    std::vector< std::vector<User> > userGroups;
=======
>>>>>>> 21b25e7d6405a6859a4cb8ed7ff63dc3843352fe
    std::vector< City > cityList;
    std::vector< User > userList;
};

#endif
