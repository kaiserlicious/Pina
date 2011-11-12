
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

#ifndef COLLADA_TECHNIQUE_COMMON_H
#define COLLADA_TECHNIQUE_COMMON_H

#include "../Element.h"
#include "../Templates/TypelistConstructor32to64.h"
/* Light */
#include "Ambient.h"
#include "Directional.h"
#include "Point.h"
#include "Spot.h"
/* Source */
#include "Accessor.h"
/* Optics */
#include "Orthographic.h"
#include "Perspective.h"

/*TODO extend for FX, Physics, Kineamtics*/

#define THIS Technique_common
namespace PINA_NAMESPACE{

//kinematics:
class Axis_info;
class Effector_info;
class Frame_origin;
class Frame_tip;
class Frame_tcp;
class Frame_object;
class Newparam;
class Joint;
class Instance_joint;
class Link;
class Formula;
class Instance_formula;

//physics
class Angular_velocity;
class Velocity;
class Dynamic;
class Mass;
class Mass_frame;
class Inertia;
class Physics_material;
class Instance_physics_material;
class Shape;
class Dynamic_friction;
class Static_friction;
class Restitution;
class Enabled;
class Interpenetrate;
class Limits;
class Swing_cone_and_twist;
class Min;
class Max;
class Linear;
class Spring;
class Stiffness;
class Damping;
class Angular;


/**
@brief Describes a technique to use an element
*/
class THIS: public Element{
  public:
  THIS(Document* d, XmlElement* h = 0);
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons32to64<
  /* Light */
  Ambient,
  Directional,
  Point,
  Spot,
  /* Source */
  Accessor,
  /* Optics */
  Orthographic,
  Perspective,

  /*Kinematics (Kinematics)*/
  Axis_info,
  Frame_origin,
  Frame_tip,
  Frame_tcp,
  Frame_object,
  /*Kinematics_model (Kinematics)*/
  Newparam,
  Joint,
  Instance_joint,
  Link,
  Formula,
  Instance_formula,
  /*Motion (Kinematics)*/
  Axis_info,
  Effector_info,
  /*Instance_RigidBody (Physics)*/
  Angular_velocity,
  Velocity,
  Dynamic,
  Mass,
  Mass_frame,
  Inertia,
  Physics_material,
  Instance_physics_material,
  Shape,
  /*Physics_material (Physics)*/
  Dynamic_friction,
  Static_friction,
  Restitution,
  /*Rigid_constraint (Physics)*/
  Enabled,
  Interpenetrate,
  Limits,
  Swing_cone_and_twist,
  Min,
  Max,
  Linear,
  Spring,
  Stiffness,
  Damping,
  Angular
  >::List Types;

  /* attributes */

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
