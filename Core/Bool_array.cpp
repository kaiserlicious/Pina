
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

#include "Bool_array.h"
#include "../Templates/Ordering.h"

#define THIS Bool_array
namespace PINA_NAMESPACE{

THIS::THIS(XmlElement* h):Element(h){

  /* attributes */
  createAttribute(attrib_count,"count");
  createAttribute(attrib_id,"id");
  createAttribute(attrib_name,"name");

  /* data */
  XmlElement* element = handle;
  if(element){
    std::vector<std::string> strings;
    Utils::fromString(strings,element->getText());
    std::vector<std::string>::iterator iter;
    for(iter = strings.begin(); iter != strings.end(); iter++){
      values.push_back((*iter) == "true" ? true : false);
    }
    
  }

}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); }

const std::string THIS::Name = "bool_array";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  std::stringstream stream;
  std::vector<bool>::iterator bool_iter;
  for(bool_iter = values.begin(); bool_iter != values.end(); bool_iter++){
    if(*bool_iter){
      stream << "true";
    }
    else{
      stream << "false";
    }
  }
  XmlElement* element = XmlParser::environment->newElement(getName());
  element->setText(stream.str());
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
