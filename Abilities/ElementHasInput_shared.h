
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

#ifndef ELEMENT_WITH_INPUT_SHARED_H
#define ELEMENT_WITH_INPUT_SHARED_H

#include "../Element.h"
#include "../Core/Input_shared.h"
#include "../Core/P.h"
#include "../Config.h"

#define THIS ElementHasInput_shared
namespace PINA_NAMESPACE{

class THIS: public Element{

  protected:
  THIS(Document* d, XmlElement* h = 0):Element(d,h){
  }

  public:

  template<typename T>
  bool getData(Enum::Semantic semantic, std::list<std::list<T> >& out){
    postToLog(new LogEntry<Enum::Debug>(getName(),"getData called (multi lists)"));
    Input_shared* in = getInput_shared(semantic);
    if(!in){
      postToLog(new LogEntry<Enum::Error>(getName(),"No input found"));
      return false;
    }
    unsigned int offset;
    in->attrib_offset.queryData(offset);
    unsigned int num_inputs = getNumberOfInputs();

    std::list<P*> p;
    queryElements(p);
    if(p.empty()){
      postToLog(new LogEntry<Enum::Error>(getName(),"No p found"));
      return false;
    }
    std::list<P*>::iterator p_iter;
    std::list<unsigned int> indices;
    std::list<T> temp_list;
    for(p_iter = p.begin(); p_iter != p.end(); p_iter++){
      indices =  (*p_iter)->getIndices(offset,num_inputs);
      if(!in->getValues(indices,temp_list)){
        postToLog(new LogEntry<Enum::Error>(getName(),"getValues failed"));
        return false;
      }
      out.push_back(temp_list);
    }
    return true;
  };

  template<typename T>
   	bool getData(Enum::Semantic semantic, std::list<T>& out){
    postToLog(new LogEntry<Enum::Debug>(getName(),"getData called (single list)"));
    Input_shared* in = getInput_shared(semantic);
    if(!in){
      postToLog(new LogEntry<Enum::Error>(getName(),"no input found"));
      return false;
    }
    unsigned int offset =0;
    in->attrib_offset.queryData(offset);
    unsigned int num_inputs = getNumberOfInputs();

    P* p =0;
    queryElement(p);
    if(!p){
      postToLog(new LogEntry<Enum::Error>(getName(),"no p found"));
      return false;
    }
    std::list<unsigned int> indices;
    indices =  p->getIndices(offset,num_inputs);

    if(!in->getValues(indices,out)){
      postToLog(new LogEntry<Enum::Error>(getName(),"getValues failed"));
      return false;
    }
    postToLog(new LogEntry<Enum::Info>(getName(),"get Vertices successfull"));
    return true;
  };

  unsigned int getNumberOfInputs(){
    std::list<Input_shared*> inputs;
    queryElements(inputs);
    return inputs.size();
  }

  Input_shared* getInput_shared(Enum::Semantic semantic){
    std::stringstream logStream;
    logStream << "getInput_shared called with semantic: " << semantic;
    postToLog(new LogEntry<Enum::Debug>(getName(),logStream.str()));
    std::list<Input_shared*> inputs;
    queryElements(inputs);
    logStream.str(std::string());
    logStream << "Found " << inputs.size() << " shared Inputs";
    postToLog(new LogEntry<Enum::Debug>(getName(),logStream.str()));

    std::list<Input_shared*>::iterator iter;
    for(iter = inputs.begin(); iter != inputs.end(); iter++){
      if((*iter)->attrib_semantic.exists()){
        if(*((*iter)->attrib_semantic.getData())==semantic){
          postToLog(new LogEntry<Enum::Debug>(getName(),"Found the input"));
          return (*iter);
        }
      }
    }
    postToLog(new LogEntry<Enum::Error>(getName(),"Cant find input"));
    return 0;
  }

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
