
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

#ifndef COLLADA_ARTICULATED_SYSTEM_H
#define COLLADA_ARTICULATED_SYSTEM_H

#include "../Element.h"


#define THIS Articulated_system

namespace PINA_NAMESPACE{

class Asset;
class Extra;





class Kinematics;
class Motion;

/**
@brief Provides a library in which to place <kinematics_model> elements.
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
      Asset,
      Kinematics,
      Motion,
      Extra
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;


  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_ARTICULATED_SYSTEM_H*/
