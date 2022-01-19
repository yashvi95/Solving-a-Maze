// Solution to UVA Problem 929: Number Maze

#include <iostream>

using namespace std;

#include <set>
#include <map>
#include <algorithm>
#include "Graph.h"
#include "WeightedVertex.h"
#include "numMaze.h"

int main() 
{ 
    
   Graph< WeightedVertex > G("Number Maze");
   
   numMaze NumMaze;
   NumMaze.readMaze(G);
   //G.print(G);
   
  
   set<WeightedVertex> V = G.getVertices();
   pair<map<WeightedVertex,int>,map<WeightedVertex,WeightedVertex>>
   result=NumMaze.getSSSP(G , *(V.begin()));

   //auto it = V.begin();
   
   //Show the distances from the source
   //cout << "Distances from " << (*it).getWeight() << ": ";
   //for( auto v : V )
  // cout << result.first[v] << " ";
   //cout << endl;

    // Show the path
   //cout << "Solution: ";
  // NumMaze.showPath(result.second , *(V.begin()) , *(V.rbegin()));
  // cout << endl;

   cout << result.first[*(V.rbegin())] <<endl;
   

   return 0; 
}