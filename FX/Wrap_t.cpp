
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

#include "Wrap_t.h"
#include "../Templates/Ordering.h"


#define THIS Wrap_t
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
    data = Enum::WRAP;
    if(str == "MIRROR"){
      data = Enum::MIRROR;
    }
    if(str == "CLAMP"){
      data = Enum::CLAMP;
    }
    if(str == "BORDER"){
      data = Enum::BORDER;
    }
    if(str == "MIRROR_ONCE"){
      data = Enum::MIRROR_ONCE;
    }
  }

}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "wrap_t";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  XmlElement* element = XmlParser::environment->newElement(getName());
  std::string str;
  switch(data){
    case Enum::WRAP:{str = "WRAP";}
    case Enum::MIRROR:{str = "MIRROR";}
    case Enum::CLAMP:{str = "CLAMP";}
    case Enum::BORDER:{str = "BORDER";}
    case Enum::MIRROR_ONCE:{str = "MIRROR_ONCE";}
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

