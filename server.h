#ifndef SERVER_H
#define SERVER_H

#include "user.h"
#include <vector>

class Server{
  public:
    Server();
    ~Server();
    void group();
    void removeUser(User targetUser);
    void addUser(User targetUser);
  private:
    std::vector< std::vector<int> > adjMatrix;
    std::vector< std::vector<User> > users;
    std::vector< std::vector<int> > userDistances;
};

#endif
