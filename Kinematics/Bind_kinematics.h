
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

#ifndef COLLADA_BIND_KINEMATICS_H
#define COLLADA_BIND_KINEMATICS_H

#include "../Element.h"


#define THIS Bind_kinematics

namespace PINA_NAMESPACE{

class Param_reference;
class Float;
class Int;
class Bool;
class SIDREF;






/**
@brief The kinematics scene is the instantiated model for a concrete scene. It defines the links that are used and the current configuration of the scene, especially default or current joint values.
*/
class THIS: public Element{
  public:
  THIS(XmlElement* h = 0);
  std::string getName() const;
  ~THIS();
  /*XmlElement* toXmlElement();*/
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
      Param_reference,
      Float,
      Int,
      Bool,
      SIDREF
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_symbol;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_BIND_KINEMATICS_H*/
