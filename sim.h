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

    // Create simulator and cities
    void initialize_Simulator();
    // Add cities into simulator
    void add_city(City newCity);
    // Add user into simulator
    void add_user(User newUser);
    // Print current cities
    void print_cities();
    // Print current users
    void print_users();
    // Print users' wantedHosts
    void print_Uservector(std::vector<User> printing);
    // Print adjacent matrix
    void print_adjMatrix();
    // create NUMBEROFUSERS users
    void create_users();
    // calculate average ping
    double averagePing();
    // calculate average ping file parse
    double calculate_ping(std::string input);
    // set mode for which matchmaking
    void setMode(int newMode){mode = newMode;}
    // calculate average time
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
