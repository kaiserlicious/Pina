
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

#include "Modifier.h"
#include "../Templates/Ordering.h"


#define THIS Modifier
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
    if(str == "CONST"){
      data = Enum::CONST;
    }
    if(str == "UNIFORM"){
      data = Enum::UNIFORM;
    }
    if(str == "VARYING"){
      data = Enum::VARYING;
    }
    if(str == "STATIC"){
      data = Enum::STATIC;
    }
    if(str == "VOLATILE"){
      data = Enum::VOLATILE;
    }
    if(str == "EXTERN"){
      data = Enum::EXTERN;
    }
    if(str == "SHARED"){
      data = Enum::SHARED;
    }
  }

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){
  children.sort(Ordering<Types>());
}

const std::string THIS::Name = "modifier";

THIS::~THIS(){
}

TiXmlElement* THIS::toTiXmlElement(){
  TiXmlElement* element = new TiXmlElement(getName());
  std::string str;
  switch(data){
    case Enum::CONST:{str = "CONST";}
    case Enum::UNIFORM:{str = "UNIFORM";}
    case Enum::VARYING:{str = "VARYING";}
    case Enum::STATIC:{str = "STATIC";}
    case Enum::VOLATILE:{str = "VOLATILE";}
    case Enum::EXTERN:{str = "EXTERN";}
    case Enum::SHARED:{str = "SHARED";}
    default:{}
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

