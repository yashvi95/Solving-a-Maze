#ifndef _NUM_MAZE_H_
#define _NUM_MAZE_H_

#include "WeightedVertex.h"
#include "Graph.h"
#include<iostream>
#include<set>
#include<map>
#include <stack>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

class numMaze
{

public:    
/**   Reads in the number of rows N, the number of columns M, and
      the NxM vertex weights. This function also connects the
      vertices appropriately to build the represented number maze.
      Parameters:  a graph of WeightedVertex objects */
void readMaze(Graph<WeightedVertex>& G){
     
     //N= Rows, M= Columns, v= weightedvertices
      unsigned N, M, v;
     
     //read in N and M from user input
      cin >> N >> M;
  
 
if(N>=1 || N<=999 || M>=1 || M<=999){ //1<=N and M >= 999 size of graph 

  //Going through the Graph matrix, to create WeightedVertex Object and Adding to Graph 
  for(unsigned i = 1; i<=N*M; i++){
          cin>>v;
          WeightedVertex newV(i, v);
          G.addVertex(newV);    
   }
   
   //Connecting the WeightedVertex to each other and adding Edges to Graph
   for(unsigned i = 1; i<=N*M; i++){
      if(i%M != 0)
      {
         G.add( G.getWeightedVertex(i), G.getWeightedVertex(i+1),1);
         G.add( G.getWeightedVertex(i+1), G.getWeightedVertex(i),1);
       }
       
       if(i>=(M+1) && i<=(N*M)){
          
        G.add( G.getWeightedVertex(i), G.getWeightedVertex(i-M),1);
        G.add( G.getWeightedVertex(i-M), G.getWeightedVertex(i),1);
        
       }
       
     }
}
                         
}

/** - Applies a modification to Dijkstra's SSSP algorithm to 
      work with weighted vertices instead of weighted edges.
      Parameters:  a graph of WeightedVertex objects and
      the source WeightedVertex object
      Returns: a pair consisting of
    - a map containing shortest distances by (weighted) vertex
    - a map containing pi/parent information to store the path */
pair<map<WeightedVertex, int>,map<WeightedVertex,WeightedVertex> > 
getSSSP(Graph<WeightedVertex> G, WeightedVertex source){
     
     typedef pair<int, WeightedVertex> distVertpair;
     
     priority_queue< distVertpair, vector <distVertpair> , greater<distVertpair> > priQueue; 
     
     int INF = numeric_limits<int>::max();
     
     map<WeightedVertex,WeightedVertex> parent;
     map<WeightedVertex, int> distance;
     
     set<WeightedVertex> vertices = G.getVertices(); 
     
     for(auto i = vertices.begin(); i!=vertices.end(); i++){
        distance.emplace(make_pair(*i, INF)); 
        parent.emplace(make_pair(*i,*i));
     }
 
     
     priQueue.push(make_pair(0, source));
     auto sourceKey = distance.find(source);
     sourceKey->second = source.getWeight(); 
     
    while (!priQueue.empty()){
       
       WeightedVertex u = priQueue.top().second;
       
       priQueue.pop();
       
       set<WeightedVertex> adjVert;
       adjVert = G.getAdjacent(u);
       
      for(auto i = adjVert.begin(); i!=adjVert.end(); i++){
          
          auto uKey = distance.find(u);
          int uWeight = uKey->second;
          
          WeightedVertex v = *i;
          auto vKey = distance.find(*i);
          int vWeight = vKey->second;
         
          if(vWeight > (uWeight + v.getWeight())){
             
             vKey->second = (uKey->second + v.getWeight());
             auto vParent = parent.find(v);
             vParent->second = u;
             priQueue.push(make_pair(vKey->second, v));
          }
       }
     }
     
   
     pair< map<WeightedVertex, int>, map<WeightedVertex, WeightedVertex> > sssP;
     sssP = make_pair(distance, parent);
     
     return sssP;
     
            
}

/** - Shows the path information from a source vertex to a destination vertex.
      Assumes vertices are WeightedVertex objects.
      Parameters:  a map from a WeightedVertex object to another WeightedVertex object
      representing the pi/parent information;
      the source WeightedVertex object; and 
      the destination WeightedVertex object */
void showPath(map<WeightedVertex,WeightedVertex> parents,WeightedVertex source, 
                                                              WeightedVertex destination){
      stack<int> path;
      
      path.push(destination.getWeight());
      auto end = parents.find(destination);
      path.push(end->second.getWeight());
   while(end->second.getKey() != source.getKey()){
      end = parents.find(end->second);
      path.push(end->second.getWeight());
      }
     
      
   while(!path.empty()){
      cout << path.top() << " ";
      path.pop();
   }
}

};

#endif