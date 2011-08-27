
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

#include "Config.h"
#include "Document.h"
#include "Element.h"
#include "Core/Collada.h"

#define THIS Document

namespace PINA_NAMESPACE{

THIS::THIS():collada(0){
  collada = new Collada(this);
}

THIS::~THIS(){
  std::vector<Element*>::iterator iter;
  for(iter = elements.begin(); iter != elements.end(); iter++){
    delete *iter;
    *iter =0;
  }
  while(!log.empty()){
    delete log.front();
    log.pop();
  }
  elements.clear();
}

bool THIS::save(std::string filename){
  postLogEntry(new LogEntry<Enum::Info>("Document","Saving to file: "+filename));
  if(!collada){
    postLogEntry(new LogEntry<Enum::Error>("Document","No COLLADA element"));
    return false;
  }
  TiXmlDocument doc;
  TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
  doc.LinkEndChild(decl);
  doc.LinkEndChild(collada->write());
  if(doc.SaveFile(filename.c_str())){
    postLogEntry(new LogEntry<Enum::Info>("Document","TiXmlDocument successfully writen to disk"));
  }
  else{
    postLogEntry(new LogEntry<Enum::Error>("Document","Failed to write TiXmlDocument to disk"));
  }
  return true;
}

bool THIS::load(std::string filename){
  TiXmlDocument doc;
  bool load_okay = doc.LoadFile(filename);
  if(! load_okay){
    postLogEntry(new LogEntry<Enum::Error>("Document","cant find file " + filename + " , aborting!"));
    return false;
  }
  TiXmlHandle root_handle(0);
  bool root_okay = doc.RootElement();
  if (root_okay){
    postLogEntry(new LogEntry<Enum::Info>("Document","root OK"));
    root_handle = doc.RootElement();
  }
  else{
    postLogEntry(new LogEntry<Enum::Error>("Document","cant find root, aborting!"));
    return false;
  }
  bool collada_okay = root_handle.ToElement()->ValueStr() == "COLLADA";
  if(load_okay && root_okay && collada_okay){
    postLogEntry(new LogEntry<Enum::Info>("Document","found Colllada"));
    collada = new Collada(this,root_handle);
  }
  else{
    postLogEntry(new LogEntry<Enum::Error>("Document","cant find Element!"));
    return false;
  }
  return true;
}

Element* THIS::getByURL(std::string url){
  if(url[0] == '#'){url.erase(url.begin());}
  return searchId(collada,url);
}

Element* THIS::searchId(Element* element,std::string url){
  Attribute<std::string>* id =0;
  element->queryAttribute("id",id);
  if(id){
    if(id->exists()){
      if(id->toString() == url){
        return element;
      }
    }
  }
  std::list<std::pair<TypeInfo,Element*> >::iterator iter = element->children.begin();
  while(iter != element->children.end()){
    Element* result;
    result = searchId(iter->second,url);
    if(result){
      return result;
    }
    iter++;
  }
  return 0;
}

bool THIS::popLogEntry(){
  if(log.empty()){
    return false;
  }
  else{
    log.pop();
    return true;
  }
}

}/*PINA_NAMESPACE*/
#undef THIS
