
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

#include "Create_cube.h"
#include "../Templates/Ordering.h"

#include "Size.h"
#include "Mips.h"
#include "Array.h"
#include "Format.h"
#include "Init_from_create.h"

#if PINA_FX
#define THIS Create_cube
namespace PINA_NAMESPACE{
#if PINA_SUBNAMESPACES
//namespace PINA_FX_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */

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

const std::string THIS::Name = "create_cube";

THIS::~THIS(){
}

#if PINA_SUBNAMESPACES
//}/*PINA_FX_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_FX*/