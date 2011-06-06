
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

#ifndef COLLADA_INPUT_H
#define COLLADA_INPUT_H

#include "../Element.h"
#include "../Types/Enum.h"
#include "../Core/Source.h"
#include "../Config.h"

#define THIS IsInput
namespace PINA_NAMESPACE{

class THIS{
  protected:
  THIS(Element* s);

  public:

  /** functions **/
  template<template <typename,typename> class CONTAINER_I, typename TYPE_I, typename ALLOC_I,
           template <typename,typename> class CONTAINER_O, typename TYPE_O, typename ALLOC_O>
  bool getValuesNew(CONTAINER_I<TYPE_I,ALLOC_I> indices, CONTAINER_O<TYPE_O,ALLOC_O>& out){
    std::string url;
    if (self->queryAttributeValue("source",url)) {
      Source* source =0;
      self->getDocument()->getByURL(source,url);
      if (source) {
        return source->getValuesNew(indices,out);
      }
    }
    return false;
  }
  
  template<template <typename,typename> class CONTAINER_I, typename TYPE_I, typename ALLOC_I,
  template <typename,typename> class CONTAINER_O, typename TYPE_O, typename ALLOC_O>
  bool getValues(CONTAINER_I<TYPE_I,ALLOC_I> indices, CONTAINER_O<TYPE_O,ALLOC_O>& out){
    return getValuesNew(indices,out);
  }   

  template<typename T>
  bool getValue(unsigned int index, std::list<T>& out){
    self->getDocument()->postLogEntry(new LogEntry<Enum::Debug>(self->getName(),"get Value called"));
    Attribute<std::string>* source_url=0;
    std::string url;
    if(!source_url->queryData(url)){
      self->getDocument()->postLogEntry(new LogEntry<Enum::Error>(self->getName(),"Attribute has no url"));
      return false;
    }
    Source* source =0;
    self->getDocument()->getByURL(source,url);
    if(!source){
      self->getDocument()->postLogEntry(new LogEntry<Enum::Error>(self->getName(),"Cant find source at "+ url));
      return false;
    }
    return source->getValue(index,out);
  };

  template<typename T>
  bool getValues(std::list<T>& out){
    self->getDocument()->postLogEntry(new LogEntry<Enum::Debug>(self->getName(),"get Value called"));
    Attribute<std::string>* source_url=0;
    if(!self->queryAttribute("source",source_url)){
      self->getDocument()->postLogEntry(new LogEntry<Enum::Error>(self->getName(),"Cant find source Attribute"));
      return false;
    }
    std::string url;
    if(!source_url->queryData(url)){
      self->getDocument()->postLogEntry(new LogEntry<Enum::Error>(self->getName(),"Attribute has no url"));
      return false;
    };
    Source* source=0;
    self->getDocument()->getByURL(source,url);
    if(!source){
      self->getDocument()->postLogEntry(new LogEntry<Enum::Error>(self->getName(),"Cant find source at "+ url));
      return false;
    }
    return source->getValues(out);
  };

  private:
  Element* self;

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
