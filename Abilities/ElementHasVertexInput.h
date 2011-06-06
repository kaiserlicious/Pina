
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

#ifndef ELEMENT_WITH_VERTEX_INPUT_H
#define ELEMENT_WITH_VERTEX_INPUT_H

#include "ElementHasInput_shared.h"
#include "../Core/Input_unshared.h"
#include "../Core/Vertices.h"
#include "../Config.h"

#define THIS ElementHasVertexInput
namespace PINA_NAMESPACE{

class THIS: public ElementHasInput_shared{

  protected:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0)):ElementHasInput_shared(d,h){
  }

  public:
  
  //TODO dont ignore set attribute of inputs
  
  
  Input_shared* getInput_sharedNew(Enum::Semantic semantic){
    Enum::Semantic s = Enum::POSITION;
    std::vector<Input_shared*> inputs;
    queryElements(inputs);
    for (unsigned int i=0; i<inputs.size(); i++) {
      if(inputs[i]->queryAttributeValue("semantic",s)){
        if (s == semantic) {
          return inputs[i];
        }
      }
    }
    return 0;
  }
  
  Input_unshared* getInput_unsharedNew(Enum::Semantic semantic){
    Input_shared* input_shared = getInput_sharedNew(Enum::VERTEX);
    if (input_shared){
      Vertices* vertices =0;
      std::string url;
      input_shared->queryAttributeValue("source",url);
      getDocument()->getByURL(vertices,url);
      if (vertices) {
        Enum::Semantic s = Enum::POSITION;
        std::vector<Input_unshared*> inputs;
        vertices->queryElements(inputs);
        for (unsigned int i=0; i<inputs.size(); i++) {
          if (inputs[i]->queryAttributeValue("semantic",s)){
            if (s == semantic) {
              return inputs[i];
            }
          }
        }
      }
    }
    return 0;
  }

  
  template<template <typename,typename> class CONTAINER, typename TYPE, typename ALLOC >
  bool getDataNew(Enum::Semantic semantic, CONTAINER<TYPE,ALLOC>& out){
    // try to find a seperate input for the semantic
    Input_shared* input_shared = getInput_sharedNew(semantic);
    if (input_shared) {
      unsigned int offset=0;
      input_shared->queryAttributeValue("offset",offset);
      unsigned int num_inputs = getNumberOfInputs();
      
      P* p=0;
      queryElement(p);
      if (p) {
        std::vector<unsigned int> indices;
        p->getIndicesNew(indices,offset,num_inputs);
        if (input_shared->getValuesNew(indices,out)) {
          return true;
        }
      }
    }
    //the is no serperate input, try to find the sematic at the vertex element
    input_shared = getInput_sharedNew(Enum::VERTEX);
    if (input_shared){
      Input_unshared* input_unshared = getInput_unsharedNew(semantic);
      if (input_unshared) {
        unsigned int offset=0;
        input_shared->queryAttributeValue("offset",offset);
        unsigned num_inputs = getNumberOfInputs();
        
        P* p=0;
        queryElement(p);
        if (p) {
          std::vector<unsigned int> indices;
          p->getIndicesNew(indices,offset,num_inputs);
          if (input_unshared->getValuesNew(indices,out)) {
            return true;
          }
        }
      }
    }
    return false;
  }
  
  Input_unshared* getVertexInput(Enum::Semantic semantic){
    Input_shared* in = this->getInput_shared(Enum::VERTEX);
    if(!in){return 0;}
    Vertices* vertices;
    std::string url;
    in->attrib_source.queryData(url);
    this->getDocument()->getByURL(vertices,url);
    if(!vertices){return 0;}
    Input_unshared* vert_input = vertices->getInput_unshared(semantic);
    if(!vert_input){return 0;}
    return vert_input;
  }

  
  template<template < typename,typename> class CO, template <typename,typename> class CI,
  typename TYPE, typename AI, typename AO>
  bool getDataNew2(Enum::Semantic semantic, CO<CI<TYPE,AI>,AO>& out){
    // try to find a seperate input for the semantic
    Input_shared* input_shared = getInput_sharedNew(semantic);
		if (input_shared) {
      unsigned int offset=0;
      input_shared->queryAttributeValue("offset",offset);
      unsigned int num_inputs = getNumberOfInputs();
      
      std::vector<unsigned int> indices;
      std::vector<P*> p;
      CI<TYPE,AI> temp;
      queryElements(p);
      for (unsigned int i =0; i<p.size(); i++) {
        p[i]->getIndicesNew(indices,offset,num_inputs);
        input_shared->getValuesNew(indices,temp);
        out.push_back(temp);
        return true;
      }
    }
    //there is no serperate input, try to find the sematic at the vertex element
    input_shared = getInput_sharedNew(Enum::VERTEX);
		if (input_shared){
      Input_unshared* input_unshared = getInput_unsharedNew(semantic);
      if (input_unshared) {
        unsigned int offset=0;
        input_shared->queryAttributeValue("offset",offset);
        unsigned num_inputs = getNumberOfInputs();
        
        std::vector<P*> p;
        CI<TYPE,AI> temp;
        queryElements(p);
        std::vector<unsigned int> indices;
        for (unsigned int i=0; i<p.size(); i++) {
          p[i]->getIndicesNew(indices,offset,num_inputs);
          input_unshared->getValuesNew(indices,temp);
        }
        return true;
      }
    }
    return false;
  }
  

  template<typename T>
  bool getVertices(Enum::Semantic semantic, std::list<std::list<T> >& out){
    postToLog(new LogEntry<Enum::Debug>(getName(),"getVertices called"));
    Input_shared* in = this->getInput_shared(Enum::VERTEX);
    if(!in){return false;}
    unsigned int offset=0;
    in->attrib_offset.queryData(offset);
    unsigned int num_inputs = this->getNumberOfInputs();
    Input_unshared* vertices_input = getVertexInput(semantic);
    if(!vertices_input){return false;}

    std::list<P*> p;
    this->queryElements(p);
    if(p.empty()){
      postToLog(new LogEntry<Enum::Debug>(getName(),"no p"));
      return false;
    }
    std::list<P*>::iterator p_iter;
    std::list<unsigned int> indices;
    std::list<T> temp_list;
    for(p_iter = p.begin(); p_iter != p.end(); p_iter++){
      indices =  (*p_iter)->getIndices(offset,num_inputs);
      if(!vertices_input->getValues(indices,temp_list)){
        postToLog(new LogEntry<Enum::Error>(getName(),"getValues failed"));
        return false;
      }
      out.push_back(temp_list);
    }
    return true;
  }

  template<typename T>
  bool getVertices(Enum::Semantic semantic, std::list<T>& out){
    postToLog(new LogEntry<Enum::Debug>(getName(),"getVertices called"));
    Input_shared* in = this->getInput_shared(Enum::VERTEX);
    if(!in){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find input_shared"));
      return false;
    }
    unsigned int offset=0;
    in->attrib_offset.queryData(offset);
    unsigned int num_inputs = this->getNumberOfInputs();
    Input_unshared* vertices_input = getVertexInput(semantic); //*
    if(!vertices_input){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find vertices input"));
      return false;
    }

    P* p =0;
    this->queryElement(p);
    if(!p){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find p"));
      return false;
    }
    std::list<unsigned int> indices;
    indices =  p->getIndices(offset,num_inputs);

    if(!vertices_input->getValues(indices,out)){
      postToLog(new LogEntry<Enum::Error>(getName(),"getValues failed!"));
      return false;
    }
    return true;
  }

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
