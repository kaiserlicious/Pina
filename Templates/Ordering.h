
/*copyright 2010 Simon Graeser*/

/*
This file is part of Pina.

Pina is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Pina is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Pina.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PINA_ORDERING_H
#define PINA_ORDERING_H

#include "../Config.h"
#include "../Element.h"
#include "../TypeInfo/TypeInfo.h"

namespace PINA_NAMESPACE{


template<typename T>
struct FindInList;

template<typename Head, typename Tail>
struct FindInList<Typelist<Head,Tail> >{
  static bool find(Element* element){
    if(TypeInfo(typeid(*element)) == TypeInfo(typeid(Head))){
      return true;
    }
    else{
      return FindInList<Tail>::find(element);
    }
  }
};

template<>
struct FindInList<NullType>{
  static bool find(Element* element){
    return false;
  }
};

/*standard ordering functor, order is derived from the typelist*/
template<typename T>
struct Ordering;

template<typename Head,typename Tail>
struct Ordering<Typelist<Head,Tail> >{
  static bool order(Element* a, Element* b){
    if(not FindInList<Typelist<Head,Tail> >::find(a)){
      return false;
    }
    if(not FindInList<Typelist<Head,Tail> >::find(b)){
      return true;
    }
    if(TypeInfo(typeid(*a)) == TypeInfo(typeid(Head))){
      return true;
    }
    if(TypeInfo(typeid(*b)) == TypeInfo(typeid(Head))){
      return false;
    }
    return Ordering<Tail>::order(a,b);
  }
  bool operator () (std::pair<TypeInfo,Element*> a,std::pair<TypeInfo,Element*> b){
    return Ordering<Typelist<Head,Tail> >::order(a.second,b.second);
  }
};

template<>
struct Ordering<NullType>{
  template<typename A, typename B>
  static bool order(A*,B*){
    return false;
  }
  bool operator () (std::pair<TypeInfo,Element*>,std::pair<TypeInfo,Element*>){
    return false;
  }
};



/*functor class to allow the custom ordering, order is derived from a priority list*/
/*Note: multiple elements can have the same priority (they will keep their current sequence when sorted)*/
class PriorityOrdering{
  public:
  PriorityOrdering(std::map<TypeInfo,unsigned int>& l):lookup(l){
  }
  bool operator () (std::pair<TypeInfo,Element*> e1, std::pair<TypeInfo,Element*> e2){
    std::map<TypeInfo,unsigned int>::iterator e1_iter;
    std::map<TypeInfo,unsigned int>::iterator e2_iter;

    e1_iter = lookup.find(e1.first);
    if( not(e1_iter != lookup.end()) ){
      return false;
    }
    e2_iter = lookup.find(e2.first);
    if( not(e2_iter != lookup.end()) ){
      return true;
    }

    return e1_iter->second < e2_iter->second;
  }
  private:
  std::map<TypeInfo,unsigned int>& lookup;
};


}; /*PINA_NAMESPACE*/

#endif
