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
    void add_city(City newCity);
  private:
    Server server;
    std::vector<City> listOfCities;
    std::vector<User> listOfUsers;
    std::vector< std::vector<int> > adjMatrix; // [a]: used for the construction of cities, need to figure out how to set matrix of vectors as argument for function, may need to use pointers or something 

  };

#endif
