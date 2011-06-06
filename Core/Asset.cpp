
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

#include "Asset.h"

#include "Created.h"
#include "Extra.h"
#include "Contributor.h"
#include "Coverage.h"
#include "Keywords.h"
#include "Modified.h"
#include "Revision.h"
#include "Subject.h"
#include "Title.h"
#include "Unit.h"
#include "Up_axis.h"
#include "../Templates/Ordering.h"

#define THIS Asset
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* children */
  buildChildren(Types());

  /* attributes */

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); }

const std::string THIS::Name = "asset";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
