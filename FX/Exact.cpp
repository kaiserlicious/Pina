
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

#include "Exact.h"
#include "../Templates/Ordering.h"

#if PINA_FX
#define THIS Exact
namespace PINA_NAMESPACE{
#if PINA_SUBNAMESPACES
//namespace PINA_FX_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */

  /* children */
  buildChildren(Types());

  /* data */
  TiXmlElement* element = handle.ToElement();
  if(element){
    data = element->GetText();
  }

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "exact";

THIS::~THIS(){
}

TiXmlElement* THIS::toTiXmlElement(){
  TiXmlElement* element = new TiXmlElement(getName());
  TiXmlText* text = new TiXmlText(data);
  element->LinkEndChild(text);
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    element->SetAttribute(iter->first,iter->second->toString());
    iter++;
  }
  return element;
}

#if PINA_SUBNAMESPACES
//}/*PINA_FX_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_FX*/
