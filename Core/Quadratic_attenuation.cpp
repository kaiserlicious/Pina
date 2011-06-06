
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

#include "Quadratic_attenuation.h"
#include "../Templates/Ordering.h"

#define THIS Quadratic_attenuation
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */
  createAttribute(attrib_sid,"sid");

  /* children */

  /* data */
  TiXmlElement* element = handle.ToElement();
  if(element){
    Utils::fromString(value,element->GetText());
  }
}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "quadratic_attenuation";

THIS::~THIS(){
}

TiXmlElement* THIS::toTiXmlElement(){
  TiXmlElement* element = new TiXmlElement(getName());
  TiXmlText* text = new TiXmlText(Utils::toString(value));
  element->LinkEndChild(text);
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    element->SetAttribute(iter->first,iter->second->toString());
    iter++;
  }
  return element;
}

}/*PINA_NAMESPACE*/
#undef THIS