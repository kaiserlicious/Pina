
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
#include "Document.h"
#include "Core/Unkown.h"

#define THIS Element
namespace PINA_NAMESPACE{


class InvalidElement : public THIS{
  public:
  InvalidElement():THIS(0,0){}
  std::string getName(){return std::string(); }
  void order(){}
  THIS* get(std::string){
    return this;
  }
  static InvalidElement instance;
};

InvalidElement InvalidElement::instance = InvalidElement();


THIS* THIS::get(std::string name){
  std::list<std::pair<TypeInfo,Element*> >::iterator iter;
  for(iter = children.begin();iter != children.end(); iter++){
    if(iter->second->getName() == name){
        return iter->second;
      }
    }
    return &InvalidElement::instance;
}


THIS::THIS(Document* d, XmlElement* h):handle(h),document(d){
  //if(!d){
  //  postToLog(new LogEntry<Enum::Fatal>("Element","Detected nullpointer as Document"));
  //}
    if(d){
        document->elements.push_back(this);
    }
}

Document* THIS::getDocument() const{
  return document;
}

THIS* THIS::buildUnkown(Document* doc, XmlElement* h){
  return new Unkown(doc,h);
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
    if(element->document == document){
      children.push_back(std::pair<TypeInfo,THIS*>(typeid(*element),element));
      return true;
    }
  }
  return false;
}

XmlElement* THIS::toXmlElement(){
  XmlElement* element = document->createXmlElement(getName());
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    postToLog(new LogEntry<Enum::Info>(getName(),"looking for Attribute: " + iter->first));
    if(iter->second->exists()){
      element->setAttribute(iter->first,iter->second->toString());
    }
    iter++;
  }
  return element;
}

XmlElement* THIS::write(){
  postToLog(new LogEntry<Enum::Debug>(getName(),"writing: " + getName()));
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

void THIS::postToLog(LogEntry<Enum::Debug>* logEntry){
  #if PINA_ENABLE_DEBUG_LOG
   document->postLogEntry(logEntry);
  #endif
}

void THIS::postToLog(LogEntry<Enum::Info>* logEntry){
  #if PINA_ENABLE_INFO_LOG
   document->postLogEntry(logEntry);
  #endif
}

void THIS::postToLog(LogEntry<Enum::Error>* logEntry){
  #if PINA_ENABLE_ERROR_LOG
   document->postLogEntry(logEntry);
  #endif
}

void THIS::postToLog(LogEntry<Enum::Severe>* logEntry){
  #if PINA_ENABLE_SEVERE_LOG
   document->postLogEntry(logEntry);
  #endif
}

void THIS::postToLog(LogEntry<Enum::Fatal>* logEntry){
  #if PINA_ENABLE_FATAL_LOG
   document->postLogEntry(logEntry);
  #endif
}

}/*PINA_NAMESPACE*/
#undef THIS
