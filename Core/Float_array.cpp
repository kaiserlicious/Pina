
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

#include "Float_array.h"
#include "../Templates/Ordering.h"

#define THIS Float_array
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */
  createAttribute(attrib_count,"count");
  createAttribute(attrib_id,"id");
  createAttribute(attrib_name,"name");
  createAttribute(attrib_digits,"digits");
  createAttribute(attrib_magnitude,"magnitude");

  /* children */

  /* data */
  XmlElement* element = handle;
  if(element){
      Utils::fromString(values,element->getText());
  }

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "float_array";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  std::stringstream stream;
  std::vector<float>::iterator float_iter;
  for(float_iter = values.begin(); float_iter != values.end(); float_iter++){
    stream << *float_iter << ' ';
  }
  XmlElement* element = XmlParser::environment->newElement(getName());
  element->setText(stream.str());
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    if(iter->second->exists()){
      element->setAttribute(iter->first,iter->second->toString());
    }
    iter++;
  }
  return element;
}

}/*PINA_NAMESPACE*/
#undef THIS
