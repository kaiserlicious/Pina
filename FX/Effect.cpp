
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

#include "Effect.h"
#include "../Templates/Ordering.h"

#include "../Core/Asset.h"
#include "Annotate.h"
#include "../Core/Newparam.h"
#include "../Core/Extra.h"
#include "Profile_BRIDGE.h"
#include "Profile_CG.h"
#include "Profile_GLES.h"
#include "Profile_GLES2.h"
#include "Profile_GLSL.h"
#include "Profile_COMMON.h"


#define THIS Effect
namespace PINA_NAMESPACE{




THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */
  createAttribute(attrib_id,"id");
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

const std::string THIS::Name = "effect";

THIS::~THIS(){
}




}/*PINA_NAMESPACE*/
#undef THIS

