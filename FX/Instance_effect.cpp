
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

#include "Instance_effect.h"
#include "../Templates/Ordering.h"

#include "Technique_hint.h"
#include "../Core/Setparam.h"
#include "../Core/Extra.h"

#if PINA_FX
#define THIS Instance_effect
namespace PINA_NAMESPACE{
#if PINA_SUBNAMESPACES
//namespace PINA_FX_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */
  createAttribute(attrib_sid,"sid");
  createAttribute(attrib_name,"name");
  createAttribute(attrib_url,"url");

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

const std::string THIS::Name = "instance_effect";

THIS::~THIS(){
}

#if PINA_SUBNAMESPACES
//}/*PINA_FX_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_FX*/