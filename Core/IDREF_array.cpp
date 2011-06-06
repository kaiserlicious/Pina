
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

#include "IDREF_array.h"
#include "../Templates/Ordering.h"

#define THIS IDREF_array
namespace PINA_NAMESPACE{

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */
  createAttribute(attrib_count,"count");
  createAttribute(attrib_id,"id");
  createAttribute(attrib_name,"name");

  /* children */
  TiXmlElement* element = handle.ToElement();
  if(element){
    Utils::fromString(values,element->GetText());
  }

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){ children.sort(Ordering<Types>()); } const std::string THIS::Name = "IDREF_array";

THIS::~THIS(){
}

TiXmlElement* THIS::toTiXmlElement(){
  std::stringstream stream;
  std::vector<std::string>::iterator id_iter;
  for(id_iter = values.begin(); id_iter != values.end(); id_iter++){
    stream << (std::string)(*id_iter);
  }
  TiXmlElement* element = new TiXmlElement(getName());
  TiXmlText* text = new TiXmlText(stream.str());
  element->LinkEndChild(text);
  std::map<std::string,AbstractAttribute*>::iterator iter;
  iter = attributes.begin();
  while(iter != attributes.end()){
    element->SetAttribute(iter->first,iter->second->toString());
    iter++;
  }
  return element;
}

}/*PINA_NAMESPACE*/
#undef THIS