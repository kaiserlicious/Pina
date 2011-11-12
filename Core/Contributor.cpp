
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

#include "Contributor.h"
#include "../Templates/Ordering.h"

#include "Author.h"
#include "Author_email.h"
#include "Author_website.h"
#include "Authoring_tool.h"
#include "Comments.h"
#include "Copyright.h"
#include "Source_data.h"

#define THIS Contributor
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* children */
  buildChildren(Types());

  /* attributes */
  //no attributes

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "contributor";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
