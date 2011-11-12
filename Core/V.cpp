
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

#include "V.h"
#include "../Templates/Ordering.h"

#define THIS V
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, XmlElement* h):Element(d,h){

  /* attributes */

  /* children */

  /* data */
  XmlElement* element = handle;
  if(element){
      Utils::fromString(indices,element->getText());
  }

}

std::list<unsigned int> THIS::getIndices(unsigned int offset, unsigned int num_inputs){
  std::list<unsigned int> out;
  for(unsigned int i=0; i< indices.size(); i= i+num_inputs){
    out.push_back(indices[i+offset]);
  }
  return out;
}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "v";

THIS::~THIS(){
}

XmlElement* THIS::toXmlElement(){
  std::stringstream stream;
  std::vector<unsigned int>::iterator uint_iter;
  for(uint_iter = indices.begin(); uint_iter != indices.end(); uint_iter++){
    stream << *uint_iter << ' ';
  }
  XmlElement* element = XmlParser::environment->newElement(getName());
  element->setText(stream.str());
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
