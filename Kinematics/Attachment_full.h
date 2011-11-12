
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

#ifndef COLLADA_ATTACHMENT_FULL_H
#define COLLADA_ATTACHMENT_FULL_H

#include "../Element.h"


#define THIS Attachment_full

namespace PINA_NAMESPACE{

class Rotate;
class Translate;




class Link;




/**
@brief The kinematics scene is the instantiated model for a concrete scene. It defines the links that are used and the current configuration of the scene, especially default or current joint values.
*/
class THIS: public Element{
  public:
  THIS(Document* d, XmlElement* h = 0);
  std::string getName();
  ~THIS();
  /*XmlElement* toXmlElement();*/
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
      Rotate,
      Translate,
      Link
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_joint;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_ATTACHMENT_FULL_H*/
