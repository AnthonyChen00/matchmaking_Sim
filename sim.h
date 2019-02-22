#ifndef SIM_H
#define SIM_H
#include "user.h"
#include "city.h"
#include "server.h"
#include <vector>

class User;
class Server;
class City;

class Sim{
  public:
    Sim();
    ~Sim();
    void initialize_Simulator_A();
  private:
    Server server;
    std::vector<City> listOfCities;
    std::vector<User> listOfUsers;
};

#endif
