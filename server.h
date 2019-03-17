#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "user.h"
#include <map>
#include <vector>

class City;
class User;
// The acceptable ping limit for a matchmaking group
#define DESIRED_PING 10
//Server maintains a userlist and tell users to ping other users to update the list
class Server{
  public:
    Server();
    Server(std::vector<City> cities);
    ~Server();
    void init_city_adjMatrix();
    void group();

    // Add city to server database
    void addCity(City* new_city){cityList.push_back(*(new_city));}
    // Return city database
    std::vector<City> getCityList(){return cityList;}
    // Return user database
    std::vector<User> getUserList(){return userList;}
    // Initialize server with a group of cities
    void init_cities(std::vector<City> cities);
    // Printing city/user list for testing purposes
    void printCity();
    void printUsers();
    // Adding a user into the server/matchmaking queue
    std::vector<int> addUser(User targetUser, int mode);
    // Removing a user from the matchmaking queue
    void removeUser(User targetUser);
    // Getting distance between cities
    int getDistance(int pingingUserCity, int targetUserCity);
    // Updating adjacency matrix
    void updateMatrix(int distance, City cityOne, City cityTwo); //updating the adjacent matrix
    // Update wantedUsers for every user
    void updateUserWanted(int userID, std::vector<int> usersWanted);
    // Ping-Decision matchmaking
    std::vector<int> matchmake();
    // Random matchmaking
    std::vector<int> matchmakeRandom();
    // Geolocation matchmaking
    std::vector<int> geolocation();
    // Helper for geolocation matchmaking
    std::vector<int> geolocationHelper(std::pair<int,std::vector<int>> count, std::vector<int> temp);
    // Telling a user to ping all other users
    void commandUserPing(User pingingUser);
    // Telling a user to ping one specific other user
    void commandUserPing(User pingingUser, User pingedUser);
    // Set matchmaking algorithm
    void setMode(int mode);
  private:
    std::vector< std::vector<int> > adjMatrix;
    std::vector< City > cityList;
    std::vector< User > userList;
    std::vector< std::pair< int,int> > waitingHosts;

};

#endif
