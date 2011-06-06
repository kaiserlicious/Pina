
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

#include "Target_value.h"
#include "../Templates/Ordering.h"

#if PINA_PHYSICS
#define THIS Target_value
namespace PINA_NAMESPACE{
#if PINA_SUBNAMESPACES
//namespace PINA_PHYSICS_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */

  /* children */
  buildChildren(Types());

  /* data */
  TiXmlElement* element = h.ToElement();
  if(element){
    Utils::fromString(data,element->GetText());
  }

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "target_value";

THIS::~THIS(){
}

#if PINA_SUBNAMESPACES
//}/*PINA_PHYSICS_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_PHYSICS*/


