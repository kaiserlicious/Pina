
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

#ifndef COLLADA_P_H
#define COLLADA_P_H

#include <vector>
#include "../Element.h"

#define THIS P
namespace PINA_NAMESPACE{

/**
@brief Describes a geometric primitive
*/
class THIS: public Element{
  public:
  THIS(Document* d, XmlElement* h = 0);
  std::string getName();
  ~THIS();
  XmlElement* toXmlElement();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef NullType Types;

  /* attributes */

  /* data */
  std::vector<unsigned int> indices;

  /* functions */
  std::list<unsigned int> getIndices(unsigned int offset, unsigned int num_inputs);
  
  template<template <typename,typename> class CONTAINER,typename TYPE, typename ALLOC>
  void getIndicesNew(CONTAINER<TYPE,ALLOC>& Container,unsigned int offset, unsigned int num_inputs){
    Container.clear();
    for(unsigned int i=offset; i< indices.size(); i= i+num_inputs){
      Container.push_back(indices[i]);
    }
  }
  

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
