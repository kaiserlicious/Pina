
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

#include "Nurbs_surface.h"
#include "../Templates/Ordering.h"

#include "../Core/Source.h"
#include "../Core/Control_vertices.h"
#include "../Core/Extra.h"


#define THIS Nurbs_surface
namespace PINA_NAMESPACE{




THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */
  createAttribute(attrib_degree_u,"degree_u");
  createAttribute(attrib_closed_u,"closed_u");
  createAttribute(attrib_degree_v,"degree_v");
  createAttribute(attrib_closed_v,"closed_v");

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

const std::string THIS::Name = "nurbs_surface";

THIS::~THIS(){
}




}/*PINA_NAMESPACE*/
#undef THIS


