
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

#ifndef COLLADA_AXIS_INFO_H
#define COLLADA_AXIS_INFO_H

#include "../Element.h"

#if PINA_KINEMATICS
#define THIS Axis_info

namespace PINA_NAMESPACE{

class Newparam;
class Setparam;
class Active;
class Locked;
class Index;
class Limits;
class Formula;
class Instance_formula;
class Bind_kinematics;
class Speed;
class Acceleration;
class Deceleration;
class Jerk;

#if PINA_SUBNAMESPACES
//namespace PINA_KINEMATICS_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/


/**
@brief Represents a rigid kinematical object without mass whose motion is constrained by one or more joints.
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
      Newparam,
      Active,
      Locked,
      Index,
      Limits,
      Formula,
      Instance_formula,
      Bind_kinematics,
      Setparam,
      Speed,
      Acceleration,
      Deceleration,
      Jerk
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_sid;
  Attribute<std::string> attrib_name;
  Attribute<std::string> attrib_axis;

  /* data */


private:

};

#if PINA_SUBNAMESPACES
//}/*PINA_KINEMATICS_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_KINEMATICS*/
#endif /*COLLADA_AXIS_INFO_H*/
