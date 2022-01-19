// A weighted vertex class

#ifndef _MY_WEIGHTED_VERTEX_CLASS_
#define _MY_WEIGHTED_VERTEX_CLASS_

#include<iostream>
#include<set>
using namespace std;


class WeightedVertex
{
   
private: 

 unsigned key;
 unsigned weight;

 
public: 
 
 WeightedVertex(){}

 WeightedVertex(unsigned newKey, unsigned newWeight);
 
 WeightedVertex(const WeightedVertex& wV);
    
 unsigned getWeight() const;
 
 unsigned getkeyWeight(unsigned key);
 
 unsigned getKey() const;
 
 void  setWeight(unsigned Weight);
 
 void  setKey(unsigned Key);
 
 friend bool operator < ( const WeightedVertex& lhs , const WeightedVertex& rhs );
 
 friend bool operator > ( const WeightedVertex& lhs , const WeightedVertex& rhs );
       
 };



#endif