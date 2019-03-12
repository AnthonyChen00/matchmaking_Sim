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
    void add_user(User newUser);
    void print_cities();
    void print_users();
    void print_Uservector(std::vector<User> printing);
    void print_adjMatrix();
    void simulate_loss();

  private:
    Server server;
    std::vector<City> listOfCities;
    std::vector<User> listOfUsers;
    std::vector< std::vector<int> > adjMatrix;

  };

#endif
