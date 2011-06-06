
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

#include "Technique_common.h"
#include "../Templates/Ordering.h"

#include "../Kinematics/Axis_info.h"
#include "../Kinematics/Effector_info.h"
#include "../Kinematics/Frame_origin.h"
#include "../Kinematics/Frame_tip.h"
#include "../Kinematics/Frame_tcp.h"
#include "../Kinematics/Frame_object.h"
#include "../Kinematics/Joint.h"
#include "../Kinematics/Instance_joint.h"
#include "../Kinematics/Link.h"

#include "../Physics/Angular_velocity.h"
#include "../Physics/Velocity.h"
#include "../Physics/Dynamic.h"
#include "../Physics/Mass.h"
#include "../Physics/Mass_frame.h"
#include "../Physics/Inertia.h"
#include "../Physics/Physics_material.h"
#include "../Physics/Instance_physics_material.h"
#include "../Physics/Shape.h"
#include "../Physics/Dynamic_friction.h"
#include "../Physics/Static_friction.h"
#include "../Physics/Restitution.h"
#include "../Physics/Enabled.h"
#include "../Physics/Interpenetrate.h"
#include "../Physics/Limits.h"
#include "../Physics/Swing_cone_and_twist.h"
#include "../Physics/Min.h"
#include "../Physics/Max.h"
#include "../Physics/Linear.h"
#include "../Physics/Spring.h"
#include "../Physics/Stiffness.h"
#include "../Physics/Damping.h"
#include "../Physics/Angular.h"

#include "Newparam.h"
#include "Formula.h"
#include "Instance_formula.h"

#define THIS Technique_common
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */

  /* children */
  buildChildren(Types());

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "technique_common";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
