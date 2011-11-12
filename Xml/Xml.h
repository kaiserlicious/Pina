/*copyright 2011 Simon Graeser*/

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
    virtual void toFirstChild() =0;
    virtual XmlElement* nextChild() =0;
    virtual void appendChild(XmlElement* child) =0;
    virtual void setAttribute(std::string name, std::string value) =0;
    virtual bool getAttribute(const std::string& name, std::string& out) =0;
    virtual bool nextAttribute(std::string& name, std::string& value) =0;
    virtual std::string getText() =0;
    virtual void setText(std::string text) =0;
    virtual std::string getName() =0;
    template<typename T>
    bool queryAttribute(const std::string& name,T& out){
      std::string text;
      if(getAttribute(name,text)){
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
    virtual ~XmlDocument(){}
  };

  class XmlParser{
  public:
    virtual XmlElement* newElement(std::string name) =0;
    virtual XmlDocument* newDocument() =0;
    static XmlParser* environment;
  };


  namespace TinyXml{

    //Tiny xml element
    class Element : public XmlElement{
    public:
      Element(TiXmlElement* e):tixElement(e),child(0){
      }

      Element(std::string name) : tixElement(new TiXmlElement(name)),child(0){
      }

      ~Element(){
          std::vector<Element*>::iterator iter;
          for(iter = children.begin(); iter != children.end(); iter++){
              delete *iter;
          }
      }

      XmlElement* nextChild(){
        child = child ? child->NextSiblingElement() : tixElement->FirstChildElement();
        if(!child){
          return 0;
        }
        Element* xmlElement = new Element(child);
        children.push_back(xmlElement);
        return xmlElement;
      }

      void setText(std::string text){
        TiXmlText* tixText = new TiXmlText(text);
        tixElement->LinkEndChild(tixText);
      }

      void appendChild(XmlElement* other){
        Element* element = dynamic_cast<Element*>(other);
        if(element){
          children.push_back(element);
          tixElement->LinkEndChild(element->tixElement);
        }
      }

      void setAttribute(std::string name, std::string value){
        tixElement->SetAttribute(name,value);
      }

      bool nextAttribute(std::string& name, std::string& value){
        attribute = attribute ? attribute->Next() : tixElement->FirstAttribute();
        if(attribute){
          name = attribute->Name();
          value = attribute->Value();
          return true;
        }
        return false;
      }

      void toFirstChild(){

      }

      bool getAttribute(const std::string& name, std::string& out){
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
      std::vector<Element*> children;
      TiXmlElement* tixElement;
      TiXmlElement* child;
      TiXmlAttribute* attribute;

    };

    // Tiny xml document
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

    class Parser : public XmlParser{
    public:
        XmlElement* newElement(std::string name){
            return new Element(name);
        }
        XmlDocument* newDocument(){
            return new Document();
        }
    };

  }//TinyXml namespace


} //PINA_NAMESPACE

#endif // PINA_XML_H
