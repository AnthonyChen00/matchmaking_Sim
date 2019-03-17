#include <vector>
#include <iostream>
#include <utility>
#include "sim.cpp"
#include "city.cpp"
#include "server.cpp"
#include "user.cpp"



int main(){
  City a;
  City b;
  a.setCityNO(1);
  b.setCityNO(0);
  std::vector< std::vector<int> > adjMatrix;
  std::vector<int> tempArray;
  tempArray.push_back(2);
  tempArray.push_back(3);
  adjMatrix.push_back(tempArray);
  tempArray[0] = 5;
  tempArray[1] = 4;
  adjMatrix.push_back(tempArray);
  // std::cout << adjMatrix[0][1] << std::endl;
  a.setAdjMatrix(adjMatrix);
  b.setAdjMatrix(adjMatrix);

  std::cout << a.getDistance(b) << std::endl;

  Server serverA;
  User A(0,12,serverA,a);
  User B(1,10,serverA,b);
  std::cout << A.getCity()->getDistance(b) << std::endl;
  // std::cout << << std::endl;
  // std::cout << A.ping(B) << std::endl;
}
