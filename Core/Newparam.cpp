
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

#include "Newparam.h"
#include "../Templates/Ordering.h"

#include "../FX/Annotate.h"
#include "../FX/Semantic.h"
#include "../FX/Modifier.h"
#include "../FX/Sampler1D.h"
#include "../FX/Sampler2D.h"
#include "../FX/Sampler3D.h"
#include "../FX/SamplerCUBE.h"
#include "../FX/SamplerDEPTH.h"
#include "../FX/SamplerRECT.h"
#include "../FX/Sampler_image.h"
#include "../FX/Sampler_states.h"
#include "../FX/Array.h"
#include "../FX/Usertype.h"
#include "../Kinematics/SIDREF.h"


#define THIS Newparam
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */
  createAttribute(attrib_sid,"sid");

  /* children */
  buildChildren(Types());
  //NOTE TODO check spec, needs to be extended for kinematics,FX,physics
//   parameter_type = constructSimpleType(h,d);

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "newparam";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS