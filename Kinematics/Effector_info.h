
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

#ifndef COLLADA_EFFECTOR_INFO_H
#define COLLADA_EFFECTOR_INFO_H

#include "../Element.h"


#define THIS Effector_info

namespace PINA_NAMESPACE{

class Newparam;
class Setparam;




class Bind_kinematics;
class Speed;
class Acceleration;
class Deceleration;
class Jerk;




/**
@brief Connects two links.
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
      Bind_kinematics,
      Newparam,
      Setparam,
      Speed,
      Acceleration,
      Deceleration,
      Jerk
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_sid;
  Attribute<std::string> attrib_name;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_EFFECTOR_INFO_H*/
