
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

#ifndef COLLADA_INSTANCE_CAMERA_H
#define COLLADA_INSTANCE_CAMERA_H

#include "../Abilities/IsInstance.h"
#include "Extra.h"
#include "Camera.h"

#define THIS Instance_camera
namespace PINA_NAMESPACE{

class Camera;

/**
@brief Instanciates a camera element
*/
class THIS: public Element, public IsInstance<Camera>{
  public:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Extra
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_sid;
  Attribute<std::string> attrib_name;
  Attribute<std::string> attrib_url;

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif