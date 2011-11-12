
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

#ifndef COLLADA_TECHNIQUE_FX_H
#define COLLADA_TECHNIQUE_FX_H

#include "../Element.h"


#define THIS Technique_fx

namespace PINA_NAMESPACE{

class Extra;
class Asset;





class Annotate;
class Blinn;
class Constant;
class Lambert;
class Phong;
class Pass;

/**
@brief
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
  Asset,
  Annotate,
  Blinn,
  Constant,
  Lambert,
  Phong,
  Pass,
  Extra
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_sid;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_TECHNIQUE_FX_H*/
