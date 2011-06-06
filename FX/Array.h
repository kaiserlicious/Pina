
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

#ifndef COLLADA_ARRAY_H
#define COLLADA_ARRAY_H

#include "../Element.h"
#include "../Types/SimpleTypes.h"
#include "../Templates/TypelistConstructor64to128.h"


#define THIS Array

namespace PINA_NAMESPACE{




class Sampler1D;
class Sampler2D;
class Sampler3D;
class SamplerCUBE;
class SamplerDEPTH;
class Sampler_image;
class SamplerRECT;
class Sampler_states;
class Usertype;

/**
@brief
*/
class THIS: public Element{
  public:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));
  std::string getName();
  ~THIS();
  /*TiXmlElement* toTiXmlElement();*/
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons64to128<
  PINA_UNIQUE_SIMPLE_TYPES,
  Array
  >::List Types;

  /* attributes */
  Attribute<unsigned int> attrib_length;
  Attribute<bool> attrib_resizable;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_ARRAY_H*/
