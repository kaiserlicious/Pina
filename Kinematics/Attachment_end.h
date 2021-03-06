
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

#ifndef COLLADA_ATTACHMENT_END_H
#define COLLADA_ATTACHMENT_END_H

#include "../Element.h"


#define THIS Attachment_end

namespace PINA_NAMESPACE{

class Translate;
class Rotate;






/**
@brief An articulated system controls the behavior of a kinematics model. COLLADA kinematics distinguishes between two articulated systems: one system controls the strict kinematics aspects of a kinematics chain, and another controls the dynamic aspects (the motion).
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
      Translate,
      Rotate
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_joint;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_ATTACHMENT_END_H*/
