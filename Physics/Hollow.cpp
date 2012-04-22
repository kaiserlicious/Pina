
/*copyright 2011 Simon Graeser*/

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

#include "Hollow.h"
#include "../Templates/Ordering.h"


#define THIS Hollow
namespace PINA_NAMESPACE{




THIS::THIS(XmlElement* h):Element(h){

  /* attributes */
  createAttribute(attrib_sid,"sid");

  /* children */
  buildChildren(Types());

  /* data */
  XmlElement* element = handle;
  if(element){
    Utils::fromString(data,element->getText());
  }

}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "hollow";

THIS::~THIS(){
}




}/*PINA_NAMESPACE*/
#undef THIS



