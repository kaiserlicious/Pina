
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

#include "SamplerCUBE.h"
#include "../Templates/Ordering.h"

#include "Instance_image.h"
#include "Texcoord.h"
#include "Wrap_s.h"
#include "Wrap_t.h"
#include "Wrap_p.h"
#include "Minfilter.h"
#include "Magfilter.h"
#include "Mipfilter.h"
#include "Border_color.h"
#include "Mip_max_level.h"
#include "Mip_min_level.h"
#include "Mip_bias.h"
#include "Max_anisotropy.h"
#include "../Core/Extra.h"


#define THIS SamplerCUBE
namespace PINA_NAMESPACE{




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

const std::string THIS::Name = "samplercube";

THIS::~THIS(){
}




}/*PINA_NAMESPACE*/
#undef THIS

