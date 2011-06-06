
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

#include "Wrap_s.h"
#include "../Templates/Ordering.h"


#define THIS Wrap_s
namespace PINA_NAMESPACE{




THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */

  /* children */
  buildChildren(Types());

  /* data */
  TiXmlElement* element = handle.ToElement();
  if(element){
    std::string str = element->GetText();
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

std::string THIS::getName(){
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "wrap_s";

THIS::~THIS(){
}

TiXmlElement* THIS::toTiXmlElement(){
  TiXmlElement* element = new TiXmlElement(getName());
  std::string str;
  switch(data){
    case Enum::WRAP:{str = "WRAP";}
    case Enum::MIRROR:{str = "MIRROR";}
    case Enum::CLAMP:{str = "CLAMP";}
    case Enum::BORDER:{str = "BORDER";}
    case Enum::MIRROR_ONCE:{str = "MIRROR_ONCE";}
  }
  TiXmlText* text = new TiXmlText(str);
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

