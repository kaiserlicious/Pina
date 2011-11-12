
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

#include "Effector_info.h"
#include "../Templates/Ordering.h"

#include "Bind_kinematics.h"
#include "../Core/Newparam.h"
#include "../Core/Setparam.h"
#include "Speed.h"
#include "Acceleration.h"
#include "Deceleration.h"
#include "Jerk.h"


#define THIS Effector_info
namespace PINA_NAMESPACE{




THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */
  createAttribute(attrib_sid,"sid");
  createAttribute(attrib_name,"name");

  /* children */
  buildChildren(Types());

  /* data */

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "effector_info";

THIS::~THIS(){
}




}/*PINA_NAMESPACE*/
#undef THIS


