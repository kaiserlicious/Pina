
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

#ifndef COLLADA_COLLADA_H
#define COLLADA_COLLADA_H

#include "../Element.h"
#include "../Templates/TypelistConstructor16to32.h"

#define THIS Collada

namespace PINA_NAMESPACE{

  class Asset;
  class Library_animation_clips;
  class Library_animations;
  class Library_articulated_systems; //(in Kinematics)
  class Library_cameras;
  class Library_controllers;
  
  class Library_effects; //(in FX)

  class Library_force_fields; //(in Physics)
  class Library_formulas;
  class Library_geometries;
  
  class Library_images; //(in FX)

  class Library_joints; //(in Kinematics)
  class Library_kinematics_models; //(in Kinematics)
  class Library_kinematics_scenes; //(in Kinematics)
  class Library_lights;
  
  class Library_materials; //(in FX)

  class Library_nodes;
  class Library_physics_materials; //(in Physics)
  class Library_physics_models; //(in Physics)
  class Library_physics_scenes; //(in Physics)
  class Library_visual_scenes;
  class Scene;
  class Extra;

/**
@brief The root element of a  document
*/
class THIS: public Element{
  public:
  THIS(Document* d, XmlElement* h = 0);
  //THIS(XmlHandle* h);
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  typedef TL::Cons16to32<
  Asset,
  Library_animation_clips,
  Library_animations,
  Library_articulated_systems, //(in Kinematics)
  Library_cameras,
  Library_controllers,
  
  Library_effects, //(in FX)

  Library_force_fields,//(in Physics)
  Library_formulas,
  Library_geometries,
  
  Library_images, //(in FX)

  Library_joints, //(in Kinematics)
  Library_kinematics_models, //(in Kinematics)
  Library_kinematics_scenes, //(in Kinematics)
  Library_lights,
  
  Library_materials, //(in FX)

  Library_nodes,
  Library_physics_materials, //(in Physics)
  Library_physics_models, //(in Physics)
  Library_physics_scenes, //(in Physics)
  Library_visual_scenes,
  Scene,
  Extra
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_version;
  Attribute<std::string> attrib_xmlns;
  Attribute<std::string> attrib_base; 

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
