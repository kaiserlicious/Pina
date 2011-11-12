
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

#ifndef COLLADA_SOURCE_H
#define COLLADA_SOURCE_H

#include "../Document.h"
#include "../Element.h"
#include "Asset.h"
#include "Bool_array.h"
#include "Float_array.h"
#include "IDREF_array.h"
#include "Int_array.h"
#include "Name_array.h"
#include "SIDREF_array.h"
#include "Token_array.h"
#include "Technique_common.h"
#include "Technique.h"

#define THIS Source
namespace PINA_NAMESPACE{

/**
@brief Describes a data source.
*/
class THIS: public Element{
  public:
  THIS(Document* d, XmlElement* h = 0);
  std::string getName();
 ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Asset,
  Bool_array,
  Float_array,
  IDREF_array,
  Int_array,
  Name_array,
  SIDREF_array,
  Token_array,
  Technique_common,
  Technique
  >::List Types;

  enum Type{
    BOOL_ARRAY,
    FLOAT_ARRAY, 
    IDREF_ARRAY,
    INT_ARRAY,
    NAME_ARRAY,
    SIDREF_ARRAY,
    TOKEN_ARRAY,
  };

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;

  /** other **/
  Type type;

  /* functions */

  /* get a single vlaue*/
  template<typename T>
  bool getValue(unsigned int index,std::list<T>& out){
    out.clear();
    Accessor* acc =0;
    if(!queryElement("technique_common",acc)){return false;}

    unsigned int param_size = acc->getParamSize();
    std::vector<bool> pattern = acc->getPattern();
    unsigned int start_index = acc->getOffset()+ (pattern.size()*index);

    std::vector<T> vec;
    if(! getArray(acc->getSource(),vec)){
      postToLog(new LogEntry<Enum::Error>(Name,"Cant find Source"));
      return false;
    }

    for(unsigned int i =0; i<param_size; i++){
      if(pattern[i]){
        out.push_back(vec[start_index+i]);
      }
    }

    return true;
  }

  /* get a list of values*/
  template<template <typename,typename> class CONTAINER_I, typename TYPE_I,typename ALLOC_I,
  				 template <typename,typename> class CONTAINER_O, typename TYPE_O,typename ALLOC_O>
  bool getValuesNew(CONTAINER_I<TYPE_I,ALLOC_I> indices, CONTAINER_O<TYPE_O,ALLOC_O>& out){
    out.clear();
    Accessor* accessor =0;
    queryElement("technique_common",accessor);
    if (accessor) {
      unsigned int parameterSize = accessor->getParamSize();
      std::vector<bool> pattern = accessor->getPattern();
      unsigned int offset = accessor->getOffset();
      unsigned int startIndex =0;
      typename std::vector<TYPE_O> values;
      std::string url;
      accessor->queryAttributeValue("source",url);
      if (getArray(url,values)) {
        typename CONTAINER_I<TYPE_I,ALLOC_I>::iterator index_iter;
        for(index_iter = indices.begin();index_iter != indices.end(); index_iter++){
          for(unsigned int i =0; i<parameterSize; i++){
            startIndex = ((*index_iter)*parameterSize)+offset;
            if(pattern[i]){
              out.push_back(values[startIndex+i]);
            }
          }
        }
        return true;
      }
    }
    return false;
  }
  
  template<typename T>
  bool getValues(std::list<unsigned int> indices, std::list<T>& out){
    out.clear();
    Accessor* acc =0;
    if(!queryElement("technique_common",acc)){
      postToLog(new LogEntry<Enum::Error>(Name,"Cant find accessor"));
      return false;
    }

    unsigned int param_size = acc->getParamSize();
    std::vector<bool> pattern = acc->getPattern();
    unsigned int start_index =0;
    unsigned int offset = acc->getOffset();

    std::vector<T> vec;
    if(! getArray(acc->getSource(),vec)){
      postToLog(new LogEntry<Enum::Error>(Name,"getArray failed"));
      return false;
    }

    std::list<unsigned int>::iterator index_iter;
    for(index_iter = indices.begin();index_iter != indices.end(); index_iter++){
      for(unsigned int i =0; i<param_size; i++){
        start_index = ((*index_iter)*param_size)+offset;
        if(pattern[i]){
          out.push_back(vec[start_index+i]);
        }
      }
    }
    return true;
  }

  /* get all vlaues*/
  template<typename T>
  bool getValues(std::list<T>& out){
    out.clear();
    Accessor* acc =0;
    if(!queryElement("technique_common.accessor",acc)){
      postToLog(new LogEntry<Enum::Error>(Name,"Cant find accessor"));
      return false;
    }

    unsigned int param_size = acc->getParamSize();
    std::vector<bool> pattern = acc->getPattern();
    unsigned int start_index = acc->getOffset();

    std::vector<T> vec;
    if(! getArray(acc->getSource(),vec)){
      postToLog(new LogEntry<Enum::Error>(Name,"getArray failed"));
      return false;
    }

    unsigned int limit = vec.size()-param_size;
    for(unsigned int pos = start_index; pos<=limit; pos+=param_size){
      for(unsigned int i =0; i<param_size; i++){
        if(pattern[i]){
          out.push_back(vec[pos+i]);
        }
      }
    }
    return true;
  }

  private:

  bool getArray(std::string str, std::vector<float>& out){
    Float_array* array;
    getDocument()->getByURL(array,str);
    if(!array){return false;}
    out = array->values;
    return true;
  }

  bool getArray(std::string str, std::vector<int>& out){
    Int_array* array;
    getDocument()->getByURL(array,str);
    if(!array){return false;}
    out = array->values;
    return true;
  }

  bool getArray(std::string str, std::vector<bool>& out){
    Bool_array* array;
    document->getByURL(array,str);
    if(!array){return false;}
    out = array->values;
    return true;
  }

  bool getArray(std::string str, std::vector<std::string>& out){
    switch(type){
      case IDREF_ARRAY:{
        IDREF_array* array;
        document->getByURL(array,str);
        if(!array){return false;}
        out = array->values;
        break;
      }
      case NAME_ARRAY:{
        Name_array* array;
        document->getByURL(array,str);
        if(!array){return false;}
        out = array->values;
        break;
      }
      case SIDREF_ARRAY:{
        SIDREF_array* array;
        document->getByURL(array,str);
        if(!array){return false;}
        out = array->values;
        break;
      }
      case TOKEN_ARRAY:{
        Token_array* array;
        document->getByURL(array,str);
        if(!array){return false;}
        out = array->values;
        break;
      }
      default:{
        return false;
        break;
      }
    }
    return true;
  }

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
