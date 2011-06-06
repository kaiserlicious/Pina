
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

#ifndef COLLADA_POLYLIST_H
#define COLLADA_POLYLIST_H

#include "../Abilities/ElementHasInput_shared.h"
#include "Vcount.h"
#include "P.h"
#include "Extra.h"
#include "Vertices.h"

#define THIS Polylist
namespace PINA_NAMESPACE{

/**
@brief Describes a list of polygons
*/
class THIS: public ElementHasInput_shared{

  public:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));
  std::string getName();
 ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Input_shared,
  Vcount,
  P,
  Extra
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_name;
  Attribute<unsigned int> attrib_count;
  Attribute<std::string> attrib_material;

  /** methods **/
  Input_shared* getInput_shared(Enum::Semantic semantic){
    std::list<Input_shared*> inputs;
    queryElements(inputs);
    std::list<Input_shared*>::iterator iter;
    for(iter = inputs.begin(); iter != inputs.end(); iter++){
      if((*iter)->attrib_semantic.exists()){
        if(*(*iter)->attrib_semantic.getData()==semantic){
          return *iter;
        }
      }
    }
    return 0;
  }

  template<typename T>
  bool getData(Enum::Semantic semantic, std::list< std::list<T> >& out){
    postToLog(new LogEntry<Enum::Debug>(getName(),"getData called"));
    Input_shared* in = getInput_shared(semantic);
    if(!in){
      postToLog(new LogEntry<Enum::Error>(getName(),"No input"));
      return false;
    }
    unsigned int offset =0;
    in->attrib_offset.queryData(offset);
    unsigned int num_inputs = getNumberOfInputs();

    P* p =0;
    if(!queryElement(p)){
      postToLog(new LogEntry<Enum::Error>(getName(),"No p!"));
      return false;
    }
    std::list<unsigned int> indices;
    indices =  p->getIndices(offset,num_inputs);

    std::list<unsigned int> currentIndices;
    std::list<unsigned int>::iterator indicesIter = indices.begin();
    std::list<T> polygon;
    Vcount* vcount =0;
    if(!queryElement(vcount)){return false;}
    std::list<unsigned int> vcountList = vcount->vertices;
    std::list<unsigned int>::iterator vcountIter;
    for(vcountIter = vcountList.begin();vcountIter != vcountList.end();vcountIter++){
      for(unsigned int i=0;i<*vcountIter;i++){
        currentIndices.push_back(*indicesIter);
        indicesIter++;
      }
      if(!in->getValues(currentIndices,polygon)){
        postToLog(new LogEntry<Enum::Error>(getName(),"getValues failed!"));
        return false;
      }
      out.push_back(polygon);
      currentIndices.clear();
      polygon.clear();
    }
    postToLog(new LogEntry<Enum::Info>(getName(),"getData successfull"));
    return true;
  };

  template<typename T>
  bool getVertices(Enum::Semantic semantic, std::list< std::list<T> >& out){
    postToLog(new LogEntry<Enum::Debug>(getName(),"getVertices called"));
    Input_shared* in = getInput_shared(Enum::VERTEX);
    if(!in){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find input"));
      return false;
    }
    unsigned int offset =0;
    in->attrib_offset.queryData(offset);
    unsigned int num_inputs = getNumberOfInputs();
    Input_unshared* vertices_input = getVertexInput(semantic);
    if(!vertices_input){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find vertex input"));
      return false;
    }
    P* p =0;
    if(!queryElement(p)){
      postToLog(new LogEntry<Enum::Error>(getName(),"no p"));
      return false;
    }
    std::list<unsigned int> indices;
    indices =  p->getIndices(offset,num_inputs);

    std::list<unsigned int> currentIndices;
    std::list<unsigned int>::iterator indicesIter = indices.begin();
    std::list<T> polygon;
    Vcount* vcount =0;
    if(!queryElement(vcount)){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find vcount"));
      return false;
    }
    std::list<unsigned int> vcountList = vcount->vertices;
    std::list<unsigned int>::iterator vcountIter;
    for(vcountIter = vcountList.begin();vcountIter != vcountList.end();vcountIter++){
      for(unsigned int i=0;i<*vcountIter;i++){
        currentIndices.push_back(*indicesIter);
        indicesIter++;
      }
      if(!vertices_input->getValues(currentIndices,polygon)){return false;}
      out.push_back(polygon);
      currentIndices.clear();
      polygon.clear();
    }
    postToLog(new LogEntry<Enum::Info>(getName(),"getVertices successfull"));
    return true;
  }

  Input_unshared* getVertexInput(Enum::Semantic semantic){
    Input_shared* in = this->getInput_shared(Enum::VERTEX);
    if(!in){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find input_shared"));
      return 0;
    }
    Vertices* vertices=0;
    std::string url;
    in->attrib_source.queryData(url);
    this->getDocument()->getByURL(vertices,url);
    if(!vertices){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find vertices"));
      return 0;
    }
    Input_unshared* vert_input = vertices->getInput_unshared(semantic);
    if(!vert_input){
      postToLog(new LogEntry<Enum::Error>(getName(),"cant find vertex input"));
      return 0;
    }
    return vert_input;
  }

  unsigned int getNumberOfInputs(){
    std::list<Input_shared*> inputs;
    queryElements(inputs);
    return inputs.size();
  }

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
