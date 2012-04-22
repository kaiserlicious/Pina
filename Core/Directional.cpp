
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

#include "Directional.h"
#include "../Templates/Ordering.h"

#define THIS Directional
namespace PINA_NAMESPACE{

THIS::THIS(XmlElement* h):Element(h){

  /* attributes */

  /* children */
  /*NOTE The light’s default direction vector in local coordinates is [0,0,-1], pointing down the negative z axis. The actual direction of the light is defined by the transform of the node where the light is instantiated.*/
  buildChildren(Types());

}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "directional";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
