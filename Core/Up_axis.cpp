
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

#include "Up_axis.h"
#include "../Templates/Ordering.h"

#define THIS Up_axis
namespace PINA_NAMESPACE{

THIS::THIS(XmlElement* h):Element(h){

  /* attributes */

  /* children */
  if(handle){
    std::string s = handle->getText();
    axis = Y_UP;
    if(s == "X_UP"){ axis = X_UP; }
    if(s == "Z_UP"){ axis = Z_UP; }
  }

}

std::string THIS::getName() const {
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "up_axis";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  XmlElement* element = XmlParser::environment->newElement(getName());
  std::string text=0;
  switch(axis){
    case(X_UP):{
      text = "X_UP";
      break;
    }
    case(Y_UP):{
      text = "Y_UP";
      break;
    }
    case(Z_UP):{
      text = "Z_UP";
      break;
    }
  }
  element->setText(text);
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
