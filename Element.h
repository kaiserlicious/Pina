
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

#ifndef COLLADA_ELEMENT_H
#define COLLADA_ELEMENT_H

#include "Config.h"
#include <vector>
#include <string>
#include <map>
#include <list>

#include "Tinyxml/tinyxml.h"
#include "Types/Attribute.h"
#include "TypeInfo/TypeInfo.h"
#include "Utils/Utils.h"
#include "Templates/Typelists.h"
#include "Templates/TypelistConstructor.h"
#include "Templates/CompileTimeCheck.h"
#include "Templates/Type2Type.h"
#include "Log/Log.h"

#define STATIC_CHECKED_FUNCTIONS

namespace PINA_NAMESPACE{
  class Document;
}

#define THIS Element
namespace PINA_NAMESPACE{

/*NOTE all string comparisons are case sensitive, this is correct because xml is case sensitve*/

/**
@brief The base class of all Elements.
*/
class THIS{

friend class Document;

public:

  virtual THIS* get(std::string name);

  /**
  @brief The constructor
  @param d The Document the Element will belong to
  @param h Handle for an xml Element. If a handle is specified the element will try to read its attributes, data and child elements from the handle. If no handle is given an element with default values will be constructed.

  A Element will be deleted when the Document it belongs to is deleted. Do not delete Elements by hand, as they could be used by other elements. To remove unwanted child elements use the removeElement function.
  */
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));

  /**
  @brief Remove a child element
  @param element Pointer to the element that should be removed
  @return Returns true if the emlement has been sucessfully deleted, false otherwise (i.e. the element doesent exist)

  The element is acctually not deleted and could still be used by other Elemtents. It will be deleted when the Document ist belongs to is deleted. Do not delete it by hand.
  */
  bool removeElement(const THIS* element);

  /**
  @brief Add a child element 
  @param element Pointer to the element that is added, must belong to the same Document
  @return Returns true if the element is successfully added, false otherwise.

  To be successfully added the child must belong to the same Document it parent belongs to.
  */
  bool add(THIS* element);

  /**
  @brief Returns all child elements in the order they appear.
  @param container a std container like std::vector or std::list
  */
  template< template<typename,typename> class Container, typename Alloc >
  void getChildren(Container<THIS*,Alloc>& container){
    std::list<std::pair<TypeInfo,THIS*> >::iterator iter;
    for(iter = children.begin();iter != children.end(); iter++){
      container.push_back(iter->second);
    }
  }

  /** 
  @brief Retrieve a single element
  @param element A Pointer of the element type you want to retrieve
  @return Returns true if the element is found, false otherwise

  Use this function to retrieve a child element of a certain type. If there are multiple children of that type the first element will be returned.
  */
  template<typename T>
  bool queryElement(T*& element ){
    TypeInfo tinfo = typeid(T);
    std::list<std::pair<TypeInfo,THIS*> >::iterator iter;
    for(iter = children.begin();iter != children.end(); iter++){
      if(iter->first == tinfo){
        element = dynamic_cast<T*>(iter->second);
        if(element){
          return true;
        }
        else{
          return false;
        }
      }
    }
    element =0;
    return false;
  }

  /**
  @brief retrieve a single element from a lower level
  @param names a list of strings representing the names of the elements on the path down the hierarchy.
  @param element A Pointer of the element type you want to retrieve
  @return Returns true if the element is found, false otherwise

  Query child elements over more than one hierarchy level. The function will try to find a child with a name matching the first name in the names list. If a child is found that child will try to find a child with the second name in names, and so on. When names is empty the current element will search for a child that has the type of the input element.
  */
  template<typename T>
  bool queryElement(std::list<std::string> names,T& element){
    if(names.empty()){
      return queryElement(element);
    }
    std::string name = names.front();
    std::list<std::pair<TypeInfo,THIS*> >::iterator iter;
    for(iter = children.begin();iter != children.end(); iter++){
      if(iter->second->getName() == name){
        names.pop_front();
        return iter->second->queryElement(names,element);
      }
    }
    element =0;
    return false;
  }

  /**
  @brief retrieve a single element from a lower level (convenience function)
  @param names a string representing the names of the elements on the path down the hierarchy. The names are seperated by "."
  @param element A Pointer of the element type you want to retrieve
  @return Returns true if the element is found, false otherwise
  @see queryElement(std::list<std::string> names,T& element)
  */
  template<typename T>
  bool queryElement(std::string names,T& element ){
    std::string substring;
    std::list<std::string> stringList;
    std::string::size_type index;
    while((index = names.find_first_of(".")) != std::string::npos)
    {
      substring = names.substr(0 , index);
      if (substring.size() != 0)
      {
      	stringList.push_back(substring);
      }
      names.erase(0,index+1);
    }
    if (names.size() > 0)
    {
      stringList.push_back(names);
    }
    
    return queryElement(stringList,element);
  }

  /**
  @brief retrieve all elements of one type
  @param container A std container like vector or list of the type you want to retrieve
  @return Returns true if at least one element of the sepcified type was found and false if no matching element was found
  */
  template< template<typename,typename> class Container,typename T, typename Alloc >
  bool queryElements(Container<T*,Alloc>& container ){
    TypeInfo tinfo = typeid(T);
    container.clear();
    bool success = false;
    std::list<std::pair<TypeInfo,Element*> >::iterator iter;
    for(iter = children.begin();iter != children.end(); iter++){
      if(iter->first == tinfo){
        T* element = dynamic_cast<T*>(iter->second);
        if(element){
          container.push_back(element);
          success = true;
        }
      }
    }
    return success;
  }

  /**
  @brief retrieve all elements
  @param container A std container like vector or list of Element
  @return Returns true if a least one child element exists
  */
  template< template<typename,typename> class Container, typename Alloc >  
  bool queryElements(Container<THIS*,Alloc>& container ){
    container.clear();
    std::list<std::pair<TypeInfo,Element*> >::iterator iter;
    for(iter = children.begin();iter != children.end(); iter++){
          container.push_back(iter->second);
    }
    return ! container.empty();
  }
  

  /**
  @brief add an attribute
  @param attribute The attribute to add
  @return Retruns true if the attribute was added successfully
  */
  template<typename T>
  bool addAttribute(const Attribute<T>& attribute){
    std::map<std::string,AbstractAttribute*>::iterator iter;
    iter = attributes.find(attribute.getName());
    if(iter != attributes.end()){
      Attribute<T>* attrib = dynamic_cast<Attribute<T>*>(iter->second);
      if(attrib){
        *attrib = attribute;
        return true;
      }
      else{
        postToLog(new LogEntry<Enum::Error>(getName(),"Attribute has wrong type"));
      }
    }
    else{
      postToLog(new LogEntry<Enum::Error>(getName(),"Element has no attribute with name "+attribute.getName()));
    }
    return false;
  }

  /**
  @brief retrieve an attribute
  @param name The name of the attribute
  @param attrib Pointer to an attribute of the searched type
  @return Returns true if the attribute is found. The attrib parameter will point to the attribute.
  */
  template<typename T>
  bool queryAttribute(std::string name,Attribute<T>*& attrib){
    std::map<std::string,AbstractAttribute*>::iterator iter;
    iter = attributes.find(name);
    if(iter != attributes.end()){
      if(iter->second->exists()){
        Attribute<T>* t = dynamic_cast<Attribute<T>*>(iter->second);
        if(t){
          attrib = t;
        }
      }
      return true;
    }
    return false;
  }

  /** 
  @brief retrieve an attribute value directly
  @param name the name of the attribute
  @param value The output value
  @return Returns true if the matching attribute and value are found. The output is stored in the value parameter. 
  */
  template<typename T>
  bool queryAttributeValue(std::string name,T& value){
    std::map<std::string,AbstractAttribute*>::iterator iter;
    iter = attributes.find(name);
    if(iter != attributes.end()){
      if(iter->second->exists()){
        Attribute<T>* attrib = dynamic_cast<Attribute<T>*>(iter->second);
        if(attrib){
          return attrib->queryData(value);
        }
      }
    }
    return false;
  }

  /**
  @brief Get the name of the element
  @return A string containing the name of the element
  */
  virtual std::string getName()=0;

  /**
  @brief Convert the element to a xml-element
  @return Pointer to the created xml-element
  @note Only the element it self will be converted, but not its children. To build the elment and its children use write()
  */
  virtual TiXmlElement* toTiXmlElement();

  /**
  @brief Write the element and its children to xml-element
  @return Pointer to the created xml-element

  This function will build the complete xml tree, containing the element and all its children
  */
  TiXmlElement* write();

  /**
  @brief The destructor
  */
  virtual ~THIS(){};

  /**
  @brief Get the TypeInfo of the element
  @return Returns a TypeInfo object containing information about the type of the element
  */
  TypeInfo getType();

  /**
  @brief Get the Document the element belongs to
  @return Pointer to the Document the element belongs to.
  */
  Document* getDocument() const;

protected:

  /**
  @brief Create an attribute
  */
  template<typename T>
  void createAttribute(Attribute<T>& attrib, std::string name){
    attrib = Attribute<T>(name,handle);
    attributes[name] = &attrib;
    postToLog(new LogEntry<Enum::Debug>(getName(),std::string("created Attribute ")+ name + " with value: " + attrib.toString()));
  }

  /** 
  @brief Create an attribute with default value
  */
  template<typename T>
  void createAttribute(Attribute<T>& attrib, std::string name,T d){
    attrib = Attribute<T>(name,d,handle);
    attributes[name] = &attrib;
    postToLog(new LogEntry<Enum::Debug>(getName(),"created Attribute " + name + " with value: " + attrib.toString()));
  }

  /**
  @brief Order the children
  */
  virtual void order() =0;

  /**
  */
  template<typename Head, typename Tail>
  THIS* createElement(Type2Type<Typelist<Head,Tail> >,std::string name, TiXmlHandle h){
    if(Head::Name == name){
      postToLog(new LogEntry<Enum::Debug>(getName(),"Going to create " + Head::Name ));
      return new Head(document,h);
    }
    else{
      return createElement(Type2Type<Tail>(),name,h);
    }
  }

  /**
  */
  THIS* createElement(Type2Type<NullType>,std::string name, TiXmlHandle h){
    #if PINA_ALLOW_UNDEFINED
      postToLog(new LogEntry<Enum::Debug>(getName(),"Going to create unknown element with name: " + name ));
      return buildUnkown(document,h);
    #endif
    return 0;
  }

  static THIS* buildUnkown(Document* doc, TiXmlHandle h);

  /**
  @brief Build the children of the element
  */
  template<typename T>
  void buildChildren(T){
    if(handle.ToNode()){
      TiXmlNode* node =0;
      TiXmlElement* element =0;
      while( (node = handle.ToNode()->IterateChildren(node)) ){
        element = node->ToElement();
        if(element){
          std::string name = element->ValueStr();
          TiXmlHandle newHandle = TiXmlHandle(element);
          add(createElement(Type2Type<T>(),name,newHandle));
        }
      }
    }
  }


  /**
  @brief Post a debug message to the log
  */
  void postToLog(LogEntry<Enum::Debug>* logEntry);

  /**
  @brief Post a info message to the log
  */
  void postToLog(LogEntry<Enum::Info>* logEntry);

  /**
  @brief Post a error message to the log
  */
  void postToLog(LogEntry<Enum::Error>* logEntry);

  /**
  @brief Post a severe message to the log
  */
  void postToLog(LogEntry<Enum::Severe>* logEntry);

  /**
  @brief Post a fatal message to the log
  */
  void postToLog(LogEntry<Enum::Fatal>* logEntry);

  /* data */
  TiXmlHandle handle; /// Handle to the xml element
  Document* document; /// The document the element belongs to
  std::map<std::string,AbstractAttribute*> attributes; /// The attributes of the element
  std::list<std::pair<TypeInfo,THIS*> > children; /// The children of the element

}; /* End of class */


}/*PINA_NAMESPACE*/
#undef THIS
#endif
