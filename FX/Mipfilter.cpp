
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

#include "Mipfilter.h"
#include "../Templates/Ordering.h"


#define THIS Mipfilter
namespace PINA_NAMESPACE{




THIS::THIS(XmlElement* h):Element(h){

  /* attributes */

  /* children */
  buildChildren(Types());

  /* data */
  XmlElement* element = handle;
  if(element){
    std::string str = element->getText();
    /*remove spaces*/
    while(str.find(" ") != std::string::npos)
    {
      str.replace(str.find(" "), 1, "");
    }
    /*default*/
    data = Enum::LINEAR;
    if(str == "NONE"){
      data = Enum::NONE;
    }
    if(str == "NEAREST"){
      data = Enum::NEAREST;
    }
  }

}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "mipfilter";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  XmlElement* element = XmlParser::environment->newElement(getName());
  std::string str;
  switch(data){
    case Enum::NONE:{str = "NONE";}
    case Enum::NEAREST:{str = "NEAREST";}
    case Enum::LINEAR:{str = "LINEAR";}
    default:{}
  }
  element->setText(str);
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

