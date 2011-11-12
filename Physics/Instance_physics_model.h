
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

#ifndef COLLADA_INSTANCE_PHYSICS_MODEL_H
#define COLLADA_INSTANCE_PHYSICS_MODEL_H

#include "../Element.h"


#define THIS Instance_physics_model

namespace PINA_NAMESPACE{

class Extra;




class Instance_force_field;
class Instance_rigid_body;
class Instance_rigid_constraint;


/**
@brief Embeds a physics model inside another physics model or instantiates a physics model within a physics scene.
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
      Instance_force_field,
      Instance_rigid_body,
      Instance_rigid_constraint
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_sid;
  Attribute<std::string> attrib_name;
  Attribute<std::string> attrib_url;
  Attribute<std::string> attrib_parent;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_INSTANCE_PHYSICS_MODEL_H*/
