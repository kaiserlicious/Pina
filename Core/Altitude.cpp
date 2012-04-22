
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

#include "Altitude.h"
#include "../Templates/Ordering.h"
#include "../Utils/Utils.h"

#define THIS Altitude
namespace PINA_NAMESPACE{

THIS::THIS(XmlElement* h):Element(h){

  /* attributes */
  createAttribute(attrib_mode,"mode",Enum::RELATIVE_TO_GROUND);

  /* children */

  /* data */
  if(handle){
    Utils::fromString(altitude,handle->getText());
  }
}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); }

const std::string THIS::Name = "altitude";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  XmlElement* element = XmlParser::environment->newElement(getName());
  element->setText(Utils::toString(altitude));
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    element->setAttribute(iter->first,iter->second->toString());
    iter++;
  }
  return element;
}

}/*PINA_NAMESPACE*/
#undef THIS
