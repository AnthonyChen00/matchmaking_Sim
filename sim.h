#ifndef SIM_H
#define SIM_H
#include "user.h"
#include "city.h"
#include "server.h"
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

class User;
class Server;
class City;

class Sim{
  public:
    Sim();
    ~Sim();
    void initialize_Simulator();
    void add_city(City newCity);
    void add_user(User newUser);
    void print_cities();
    void print_users();
    void print_Uservector(std::vector<User> printing);
    void print_adjMatrix();
    void create_users();
    double averagePing();
    double calculate_ping(std::string input);
    void setMode(int newMode){mode = newMode;}
    void processTime();

  private:
    Server server;
    std::vector<City> listOfCities;
    std::vector<User> listOfUsers;
    std::vector< std::vector<int> > adjMatrix;
    std::ofstream outputFile;
    std::ifstream inputFile;
    int mode; //0 - geolocation, 1 - ping matchmaking, 2 - random matchmaking

  };

#endif
