
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

#include "Collada.h"
#include "../Templates/Ordering.h"

  #include "Asset.h"
  #include "Library_animation_clips.h"
  #include "Library_animations.h"
//   #include "Library_articulated_systems.h" //(in Kinematics)
  #include "Library_cameras.h"
  #include "Library_controllers.h"
  #if PINA_FX
  #include "../FX/Library_effects.h" //(in FX)
  #endif
//   #include "Library_force_fields.h" //(in Physics)
  #include "Library_formulas.h"
  #include "Library_geometries.h"
  #if PINA_FX
  #include "../FX/Library_images.h" //(in FX)
  #endif
//   #include "Library_joints.h" //(in Kinematics)
//   #include "Library_kinematics_models.h" //(in Kinematics)
//   #include "Library_kinematics_scenes.h" //(in Kinematics)
  #include "Library_lights.h"
  #if PINA_FX
  #include "../FX/Library_materials.h" //(in FX)
  #endif
  #include "Library_nodes.h"
//   #include "Library_physics_materials.h" //(in Physics)
//   #include "Library_physics_models.h" //(in Physics)
//   #include "Library_physics_scenes.h" //(in Physics)
#include "Library_visual_scenes.h"
#include "Scene.h"
#include "Extra.h"

#define THIS Collada
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */
  createAttribute(attrib_xmlns,"xmlns");
  createAttribute(attrib_version,"version");
  createAttribute(attrib_base,"base");

  /** child elements**/
  buildChildren(Types());

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); }

const std::string THIS::Name = "COLLADA";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
