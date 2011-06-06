
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

#ifndef COLLADA_RIGID_CONSTRAINT_H
#define COLLADA_RIGID_CONSTRAINT_H

#include "../Element.h"


#define THIS Rigid_constraint

namespace PINA_NAMESPACE{

class Technique_common;
class Technique;
class Extra;





class Ref_attachment;
class Attachment;
class Enabled;
class Interpenetrate;
class Limits;
class Swing_cone_and_twist;
class Min;
class Max;
class Linear;
class Spring;
class Stiffness;
class Damping;
class Angular;

/**
@brief Connects components, such as Rigid_body, into complex physics models with moveable parts.
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
      Ref_attachment,
      Attachment,
      Technique_common,
      Technique,
      Extra
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_sid;
  Attribute<std::string> attrib_name;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_RIGID_CONSTRAINT_H*/
