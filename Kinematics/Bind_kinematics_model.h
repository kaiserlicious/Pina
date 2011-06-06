
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

#ifndef COLLADA_BIND_KINEMATICS_MODEL_H
#define COLLADA_BIND_KINEMATICS_MODEL_H

#include "../Element.h"

#if PINA_KINEMATICS
#define THIS Bind_kinematics_model

namespace PINA_NAMESPACE{

class Param_reference;

#if PINA_SUBNAMESPACES
//namespace PINA_KINEMATICS_NAMESPACE{

class SIDREF;

#endif /*PINA_SUBNAMESPACES*/


/**
@brief Creates a symbolic connection between two previously defined parameters.
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
      Param_reference,
      SIDREF
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_node;

  /* data */

private:

};

#if PINA_SUBNAMESPACES
//}/*PINA_KINEMATICS_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_KINEMATICS*/
#endif /*COLLADA_BIND_KINEMATICS_MODEL_H*/
