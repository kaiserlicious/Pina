
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

#ifndef COLLADA_PHYSICS_MATERIAL_H
#define COLLADA_PHYSICS_MATERIAL_H

#include "../Element.h"

#if PINA_PHYSICS
#define THIS Physics_material

namespace PINA_NAMESPACE{

class Asset;
class Technique_common;
class Technique;
class Extra;

#if PINA_SUBNAMESPACES
//namespace PINA_PHYSICS_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/


/**
@brief Defines the physical properties of an object.
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
      Asset,
      Technique_common,
      Technique,
      Extra
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;

  /* data */

private:

};

#if PINA_SUBNAMESPACES
//}/*PINA_PHYSICS_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_FX*/
#endif /*COLLADA_PHYSICS_MATERIAL_H*/
