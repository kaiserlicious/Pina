
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

#ifndef COLLADA_RIGID_BODY_H
#define COLLADA_RIGID_BODY_H

#include "../Element.h"


#define THIS Rigid_body

namespace PINA_NAMESPACE{

class Technique_common;
class Technique;
class Extra;
class Translate;
class Rotate;





class Dynamic;
class Mass;
class Mass_frame;
class Mass_frame;
class Inertia;
class Physics_material;
class Instance_physics_material;
class Shape;


/**
@brief Describes simulated bodies that do not deform.
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
      Technique_common,
      Technique,
      Extra,
      Dynamic,
      Mass,
      Mass_frame,
      Translate,
      Rotate,
      Mass_frame,
      Inertia,
      Physics_material,
      Instance_physics_material,
      Shape
      >::List Types;

  /* attributes */
  Attribute<std::string> attrib_sid;
  Attribute<std::string> attrib_name;
  Attribute<std::string> attrib_id;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_RIGID_BODY_H*/
