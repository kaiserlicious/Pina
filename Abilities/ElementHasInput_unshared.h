
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

#ifndef ELEMENT_WITH_INPUT_UNSHARED_H
#define ELEMENT_WITH_INPUT_UNSHARED_H

#include "../Core/Input_unshared.h"
#include "../Config.h"

#define THIS ElementWithInput_unshared
namespace PINA_NAMESPACE{

class THIS:public Element{

  protected:
  THIS(Document* d, XmlElement* h = 0):Element(d,h){
  }

  public:
  template<typename T>
  bool getData(typename Enum::Semantic semantic, std::list<unsigned int> indices, std::list<T>& out){
    Input_unshared* in = getInput_unshared(semantic);
    if(!in){return false;}
    if(!getValues(in,indices,out)){return false;}
    return true;
  }

  template<typename T>
  bool getData(typename Enum::Semantic semantic, std::list<T>& out){
    Input_unshared* in = getInput_unshared(semantic);
    if(!in){return false;}
    if(!getValues(in,out)){return false;}
    return true;
  }

  Input_unshared* getInput_unshared(Enum::Semantic semantic){
    std::list<Input_unshared*> inputs;
    queryElements(inputs);
    std::list<Input_unshared*>::iterator iter;
    for(iter = inputs.begin(); iter != inputs.end(); iter++){
      if((*iter)->attrib_semantic.exists()){
        if(*(*iter)->attrib_semantic.getData()==semantic){
          return *iter;
        }
      }
    }
    return 0;
  }

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
