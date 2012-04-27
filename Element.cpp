
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

#include "Config.h"
#include "Element.h"
//#include "Document.h"
#include "Core/Unkown.h"
#include "Xml/Xml.h"

#define THIS Element
namespace PINA_NAMESPACE{


THIS::THIS(XmlElement* h):handle(h){
}


THIS* THIS::buildUnkown(XmlElement* h){
  return new Unkown(h);
}

bool THIS::removeElement(const THIS* element){
  std::list<std::pair<TypeInfo,THIS*> >::iterator iter;
  bool success = false;
  for(iter = children.begin();iter != children.end(); iter++){
    if(iter->second == element){
      children.erase(iter);
      success = true;
    }
  }
  return success;
}

bool THIS::add(THIS* element){
    if(element){
      children.push_back(std::pair<TypeInfo,THIS*>(typeid(*element),element));
      return true;
    }
    return false;
}

XmlElement* THIS::toXmlElement(){
  XmlElement* element = XmlParser::environment->newElement(getName());
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    debug("looking for Attribute: " + iter->first);
    if(iter->second->exists()){
      element->setAttribute(iter->first,iter->second->toString());
    }
    iter++;
  }
  return element;
}

XmlElement* THIS::write(){
  debug("writing: " + getName());
  order();
  XmlElement* self = toXmlElement();
  std::list<std::pair<TypeInfo,THIS*> >::iterator iter;
  iter = children.begin();
  while(iter != children.end()){
    self->appendChild(iter->second->write());
    iter++;
  }
  return self;
}

TypeInfo THIS::getType(){
  return typeid(*this);
}

void THIS::debug( const std::string& message) const{
    std::cout << getName() << ": " << message << std::endl;
}
void THIS::warning( const std::string& message) const{
    std::cout << getName() << ": " << message << std::endl;
}
void THIS::error(const std::string& message) const{
    std::cout << getName() << ": " << message << std::endl;
}
void THIS::fatal( const std::string& message) const{
    std::cout << getName() << ": " << message << std::endl;
}

}/*PINA_NAMESPACE*/
#undef THIS
