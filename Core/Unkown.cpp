
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

#include "Unkown.h"
#include "../Templates/Ordering.h"

#define THIS Unkown
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){
  TiXmlElement* element = handle.Element();
  if( element ){
    /* determine the name of the unkown element */
    name = element->ValueTStr();
    /* attributes */
    TiXmlAttribute* attribute = element->FirstAttribute();
    while(attribute){
      postToLog(new LogEntry<Enum::Debug>(getName(),"Creating unknown attribute with name "
      + attribute->NameTStr() + " with value " + attribute->ValueStr()));
      /* must add attribute directly (not via addattribute) to avoid checking if element has such an attribute (...element has no attrbiute with name...) */
      std::string a_name = attribute->NameTStr();
      std::pair<std::string,AbstractAttribute*> a_pair(a_name,new Attribute<std::string>(a_name,attribute->ValueStr()));
      attributes.insert(a_pair);
      attribute = attribute->Next();
    }
    /* children */
    buildChildren(Types());
    /*data*/
    data = element->GetText();
  }

}

std::string THIS::getName(){
  return name;
}

void THIS::order(){
 children.sort(Ordering<Types>());
}

/*Unkown elements cant have a fixed name*/
//const std::string THIS::Name = "";

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

}/*PINA_NAMESPACE*/
#undef THIS
