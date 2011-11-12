
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

THIS::THIS(Document* d, XmlElement* h):Element(d,h){
  XmlElement* element = handle;
  if( element ){
    /* determine the name of the unkown element */
    name = element->getName();
    /* attributes */
    std::string attribName, attribValue;
    while(element->nextAttribute(attribName,attribValue)){
      postToLog(new LogEntry<Enum::Debug>(getName(),"Creating unknown attribute with name " + attribName + " with value " + attribValue));
      /* must add attribute directly (not via addattribute) to avoid checking if element has such an attribute (...element has no attrbiute with name...) */
      attributes.insert(std::make_pair(attribName,new Attribute<std::string>(attribName,attribValue)));
    }
    /* children */
    buildChildren(Types());
    /*data*/
    data = element->getText();
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

XmlElement* THIS::toXmlElement(){
  XmlElement* element = XmlParser::environment->newElement(getName());
  element->setText(data);
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
