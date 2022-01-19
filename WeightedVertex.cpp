#include "WeightedVertex.h"
using namespace std;
// CLASS IMPLEMENTATION

WeightedVertex::WeightedVertex(unsigned newKey, unsigned newWeight){
    key = newKey;
    weight = newWeight;
    
 }
 
WeightedVertex::WeightedVertex(const WeightedVertex& wV){
    key = wV.getKey();
    weight = wV.getWeight();
 } 
 
unsigned WeightedVertex::getKey() const {
    return key;
 }
    
unsigned WeightedVertex::getWeight() const {
    return weight;
 }
 
void  WeightedVertex::setWeight(unsigned Weight){
    weight = Weight;
 }

void  WeightedVertex::setKey(unsigned Key){
    key = Key;
 }

unsigned WeightedVertex::getkeyWeight(unsigned Key){
   return weight;
}

 
bool operator < (const WeightedVertex& lhs , const WeightedVertex& rhs ){
         return lhs.getKey() < rhs.getKey(); 
             
}
   
bool operator > ( const WeightedVertex& lhs ,  const WeightedVertex& rhs ){
        return lhs.getKey() > rhs.getKey(); 
             
}


 
 


