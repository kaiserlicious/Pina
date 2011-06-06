
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

#ifndef COLLADA_PRIMITIVE_ELEMENTS_H
#define COLLADA_PRIMITIVE_ELEMENTS_H

#include "../Element.h"

#if PINA_PHYSICS
#define THIS Primitive_elements

namespace PINA_NAMESPACE{

class Lines;
class Linestrips;
class Polygons;
class Polylist;
class Triangles;
class Trifans;
class Tristrips;

#if PINA_SUBNAMESPACES
//namespace PINA_PHYSICS_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/


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
  typedef TL::Cons<
      Lines,
      Linestrips,
      Polygons,
      Polylist,
      Triangles,
      Trifans,
      Tristrips
      >::List Types;

  /* attributes */

  /* data */

private:

};

#if PINA_SUBNAMESPACES
//}/*PINA_PHYSICS_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_FX*/
#endif /*COLLADA_PRIMITIVE_ELEMENTS_H*/