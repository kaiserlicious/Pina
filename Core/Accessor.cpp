
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

#include "Accessor.h"
#include "../Templates/Ordering.h"

#include "Param_data_flow.h"


#define THIS Accessor
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */
  createAttribute(attrib_source,"source");
  createAttribute(attrib_stride,"stride",1u);
  createAttribute(attrib_count,"count");
  createAttribute(attrib_offset,"offset",0u);

  /* children */
  buildChildren(Types());

}

std::vector<bool> THIS::getPattern(){
  std::vector<bool> out;
  unsigned int stride = 1;
  if(attrib_stride.exists()){
    attrib_stride.queryData(stride);
  }
  std::list<Param_data_flow*> param;
  queryElements(param);
  std::list<Param_data_flow*>::iterator iter;
  for(iter = param.begin(); iter != param.end(); iter++){
    if( (*iter)->attrib_name.exists() ){
      out.push_back(true);
    }
    else{
      out.push_back(false);
    }
  }
  for(unsigned int i = out.size(); i < stride ; i++){
    out.push_back(false);
  }
  return out;
}

unsigned int THIS::getParamSize(){
  std::list<Param_data_flow*> params;
  queryElements(params);
  return params.size();
}

unsigned int THIS::getOffset(){
  if(attrib_offset.exists()){
    return *attrib_offset.getData();
  }
  return 0;
}

std::string THIS::getSource(){
  std::string source;
  attrib_source.queryData(source);
  return source;
}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); }

const std::string THIS::Name = "accessor";

THIS::~THIS(){}

}/*PINA_NAMESPACE*/
#undef THIS
