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

#ifndef PINA_XML_H
#define PINA_XML_H

#include <string>
#include <set>
#include "../Utils/Utils.h"
#include "../TinyXml/tinyxml.h"

namespace PINA_NAMESPACE{

  class XmlElement{
    public:
    virtual XmlElement* getFirstChild() =0;
    virtual XmlElement* getFirstChild(std::string) =0;
    virtual XmlElement* nextSibling() =0;
    virtual XmlElement* previousSibling() =0;
    virtual bool getAttributeText(const std::string& name, std::string& out) =0;
    virtual std::string getText() =0;
    virtual std::string getName() =0;
    template<typename T>
    bool queryAttribute(const std::string& name,T& out){
      std::string text;
      if(getAttributeText(name,text)){
        Utils::fromString(out,text);
        return true;
      }
      return false;
    }
    virtual ~XmlElement(){}
  };

  class XmlDocument{
    public:
    virtual bool load(std::string file) =0;
    virtual bool save(std::string file) =0;
    virtual XmlElement* getRootElement() =0;
    virtual ~XmlDocument(){};
  };

  namespace TinyXml{

    /*Tiny xml element*/
    class Element : public XmlElement{
    public:
      Element(TiXmlElement* e):tixElement(e),prev(0),next(0){
        TiXmlNode* child =0;
        TiXmlElement* element =0;
        for( child = tixElement->FirstChild(); child; child = child->NextSibling() ){
          element = child->ToElement();
          if(element){
            children.push_back(new Element(element));
          }
        }
        if(children.size() > 1){
          for(std::size_t i =1; i<children.size(); i++){
            children[i]->prev = children[i-1];
            children[i-1]->next = this;
          }
        }
      }

      XmlElement* getFirstChild(){
        if(children.empty()){
          return 0;
        }
        return children[0];
      }

      XmlElement* getFirstChild(std::string name){
        for(std::vector<Element*>::iterator iter = children.begin(); iter < children.end(); iter++){
          if((*iter)->getName() == name){
            return *iter;
          }
        }
        return 0;
      }

      XmlElement* nextSibling(){
        return next;
      }

      XmlElement* previousSibling(){
        return prev;
      }

      bool getAttributeText(const std::string& name, std::string& out){
        const std::string* attrib = tixElement->Attribute(name);
        if(attrib){
          out = *attrib;
          return true;
        }
        return false;
      }

      std::string getText(){
        return tixElement->GetText();
      }

      std::string getName(){
        return tixElement->ValueStr();
      }

    private:
      TiXmlElement* tixElement;
      Element* prev;
      Element* next;
      std::vector<Element*> children;
    };

    /*Tiny xml document*/
    class Document : public XmlDocument{
    public:
      Document(){
        rootElement =0;
      }
      ~Document(){
        delete rootElement;
      }

      bool load(std::string file){
        bool ok = document.LoadFile(file);
        if(ok){
          rootElement = new Element(document.RootElement());
        }
        return ok;
      }

      bool save(std::string file){
        return document.SaveFile(file);
      }

      XmlElement* getRootElement(){
        return rootElement;
      }

    private:
      TiXmlDocument document;
      Element* rootElement;

    };
  }//TinyXml namespace


} //PINA_NAMESPACE

#endif // PINA_XML_H
