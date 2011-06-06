
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

#ifndef COLLADA_PCURVES_H
#define COLLADA_PCURVES_H

#include "../Element.h"

#if PINA_BREP
#define THIS Pcurves

namespace PINA_NAMESPACE{

class Input_unshared;
class Vcount;
class P;
class Extra;

#if PINA_SUBNAMESPACES
//namespace PINA_BREP_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/


/**
@brief Specifies how an edge is represented in a face’s parametric space.
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
      Input_unshared,
      Vcount,
      P,
      Extra
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;
  Attribute<unsigned int> attrib_count;

  /* data */

private:

};

#if PINA_SUBNAMESPACES
//}/*PINA_BREP_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_BREP*/
#endif /*COLLADA_PCURVES_H*/