// Graph template class - allows for different vertex types

#ifndef _MY_GRAPH_CLASS_
#define _MY_GRAPH_CLASS_
#include "WeightedVertex.h"
#include <string>
#include<set>
#include<map>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
class Graph 
{
private:
   string graphName;
   set<T>vertices; 
   multimap<T, T> edges; 
   
public:
  
   /**Graph Name, Constructor*/
Graph(string name){
      
      name = graphName;
}
   
   /**Adds vertices from WeightedVertex*/
void addVertex(T weightedVertex){
     
     vertices.emplace(weightedVertex);  
          
}
  
   /**adds an edge between vertices source and destination with weight edgeWeight (which defaults to 1)*/
void add(T source, T destination, int edgeWeight = 1){
     
     edges.emplace(source, destination);
     
}
  
   /**returns the number of vertices in the graph*/
unsigned getNumVertices(){
   
   return vertices.size();
}
   
   /**returns the number of edges in the graph*/
unsigned getNumEdges(){
  
   return edges.size();
}
   
  /**removes the edge between vertices source and destination, if it exists */
void remove(T source, T destination){
  
   for(auto i = edges.begin(); i!=edges.end(); i++){
      if(((*i).first.getKey() == source.getKey()) && ((*i).second.getKey() == destination.getKey())){
         edges.erase(i);
      }
   }
   
}
  
   /**returns the weight of the edge between vertices source and destination, 
   if it exists; otherwise, it just returns 0*/
int getEdgeWeight (T source, T destination){
   
   for(auto i = edges.begin(); i!=edges.end(); i++){
      if(((*i).first.getWeight() == source.getWeight()) && ((*i).second.getWeight() == destination.getWeight())){
         return ((*i).first.getWeight() + (*i).second.getWeight());
      }
    }
       return 0;     
}
  
  /**returns a set containing the vertices in the graph*/
set<T> getVertices(){ 
     
     return vertices;
  }
     
  /**returns a set containing the vertices in the graph that are adjacent to a given vertex*/
set<T> getAdjacent(T v){
   
   set<T> adjacentVertices;
   for(auto i = edges.begin(); i!=edges.end(); i++){
      if((*i).first.getKey() == v.getKey()){
         //WeightedVertex adjwV((*i).second.getKey(), (*i).second.getWeight());
         adjacentVertices.emplace((*i).second);
      }
   }
   return adjacentVertices;
}
         
         
         


/**Returns WeightedVertex object of the key vertex entered*/
T getWeightedVertex(unsigned key){

  for(auto i = vertices.begin(); i!=vertices.end(); i++){
    if((*i).getKey() == key){
       return *i;
    }
  }  
}


/**Checks if Graph is Empty*/
bool isEmpty(Graph<T> G){
   if(vertices.size() == 0 && edges.size() == 0){
      return true;
   }
   else
   return false;
}




/**Prints the Vertices and Edges*/
void print(Graph<T> G){
   
   cout << " Number Maze has "<< G.getNumVertices() <<" vertices and "<< G.getNumEdges() <<" edges:"<<endl;
   cout << "  V={";
   for(auto it = G.vertices.begin(); it!=G.vertices.end(); it++)
   { 
      if(it == G.vertices.begin()){
         cout << (*it).getWeight();
      }
      if (it != G.vertices.begin()) 
      {
      cout<< ","<<  (*it).getWeight();
      }
   }
    cout << "}" <<endl;
    
 typedef pair<unsigned, unsigned> pairs;
 set<pairs> g;  
   
 for (auto it = G.edges.begin(); it!= G.edges.end(); ++it)
   {
      g.insert(make_pair((*it).first.getWeight(), (*it).second.getWeight()));
   }

   unsigned t,j;
   for (auto const &x : g)
   {
      t = x.first;
      j = x.second;
      
      break;
   }

  cout << "  E={";
   for (auto const &x : g)
   {
      if(x.first == t && x.second == j)
      {
         cout <<"("<< x.first << "," << x.second<< ")";
         
      }
   else
      {
     cout <<",("<< x.first << "," << x.second<< ")";
     }
    }
  
   cout<< "}";     
}



};

#endif