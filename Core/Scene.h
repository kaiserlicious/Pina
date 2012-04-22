
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

#ifndef COLLADA_SCENE_H
#define COLLADA_SCENE_H

#include "../Element.h"
#include "Extra.h"
#include "Instance_visual_scene.h"

#define THIS Scene
namespace PINA_NAMESPACE{

/**
@brief Describes a scene with all its data
*/
class THIS: public Element{
  public:
  THIS(XmlElement* h = 0);
  std::string getName() const;
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  //Instance_physics_scene,
  Instance_visual_scene,
  //Instance_kinematics_scene,
  Extra
  >::List Types;

/* attributes */

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
