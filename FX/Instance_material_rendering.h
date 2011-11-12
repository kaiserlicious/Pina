
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

#ifndef COLLADA_INSTANCE_MATERIAL_RENDERING_H
#define COLLADA_INSTANCE_MATERIAL_RENDERING_H

#include "../Element.h"


#define THIS Instance_material_rendering

namespace PINA_NAMESPACE{

class Extra;





class Technique_override;
class Bind_fx;

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
  Extra,
  Technique_override,
  Bind_fx
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_url;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_INSTANCE_MATERIAL_RENDERING_H*/
