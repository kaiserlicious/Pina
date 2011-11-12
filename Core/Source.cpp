
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

#include "Source.h"
#include "../Templates/Ordering.h"

#define THIS Source
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */
  createAttribute(attrib_id,"id");
  createAttribute(attrib_name,"name");

  /** children**/
  buildChildren(Types());

  /** other **/
  Bool_array* bool_array =0;
  Float_array* float_array =0;
  IDREF_array* idref_array =0;
  Int_array* int_array =0;
  Name_array* name_array =0;
  SIDREF_array* sidref_array =0;
  Token_array* token_array =0;

  if(queryElement(bool_array)){type = BOOL_ARRAY;}
  if(queryElement(float_array)){type = FLOAT_ARRAY;}
  if(queryElement(idref_array)){type = IDREF_ARRAY;}
  if(queryElement(int_array)){type = INT_ARRAY;}
  if(queryElement(name_array)){type = NAME_ARRAY;}
  if(queryElement(sidref_array)){type = SIDREF_ARRAY;}
  if(queryElement(token_array)){type = TOKEN_ARRAY;}

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "source";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
