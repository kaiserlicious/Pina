
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

#include "Color_target.h"
#include "../Templates/Ordering.h"

#include "../Core/Param_reference.h"
#include "Instance_image.h"


#define THIS Color_target
namespace PINA_NAMESPACE{




THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */
  createAttribute(attrib_index,"index",0u);
  createAttribute(attrib_slice,"slice",0u);
  createAttribute(attrib_mip,"mip",0u);
  createAttribute(attrib_face,"face",Enum::POSITIVE_X);

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

const std::string THIS::Name = "color_target";

THIS::~THIS(){
}




}/*PINA_NAMESPACE*/
#undef THIS

