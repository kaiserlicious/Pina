
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

#ifndef COLLADA_ATTRIBUTE_H
#define COLLADA_ATTRIBUTE_H

#include <string>
#include "../Tinyxml/tinyxml.h"
#include "../Types/Enum.h"
#include "../Config.h"
#include "../Math/Math.h"
#include "../Utils/Utils.h"

#define THIS AbstractAttribute
namespace PINA_NAMESPACE{

class THIS{
  public:
  THIS(std::string n):name(n){
  }
  virtual std::string toString()const=0;
  virtual bool exists()const=0;

  std::string getName()const{
    return name;
  }

  protected:
  std::string name;
};
#undef THIS

#define THIS AttributeBase

template<typename T>
class THIS: public AbstractAttribute{
  public:
  THIS(std::string n):AbstractAttribute(n),data(0){
  }

  ~THIS(){
    delete data;
  }

  template<typename QUERY>
  bool queryData(QUERY& query)const{
    if(data){
      query = *data;
      return true;
    }
    return false;
  }

  T* getData()const{
    return data;
  }

  bool exists()const{
    return data;
  }

  protected:
  T* data;

};
#undef THIS

#define THIS Attribute

/** default instanciation **/
template<typename T>
class THIS:public AttributeBase<T>{
  public:
  THIS():AttributeBase<T>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<T>(name){
    initData(h,name);
  }

  THIS(std::string name, T default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<T>(name){
    if(!initData(h,name)){
      AttributeBase<T>::data = new T(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    T result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryValueAttribute(name,&result) == TIXML_SUCCESS){
      AttributeBase<T>::data = new T(result);
      return true;
    }
    else{ return false; }
  }

  Attribute<T>& operator =(const Attribute<T>& attrib){
    delete AttributeBase<T>::data;
    if(attrib.exists()){ AttributeBase<T>::data = new T(*attrib.data); }
    else{ AttributeBase<T>::data =0; }
    AttributeBase<T>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    std::stringstream stream;
    if(AttributeBase<T>::exists()){
      stream << *AttributeBase<T>::data;
    }
    return stream.str();
  }
};

/** string instanciation **/
template<>
class THIS<std::string>:public AttributeBase<std::string>{
  public:
  THIS<std::string>():AttributeBase<std::string>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<std::string>(name){
    initData(h,name);
  }
  THIS<std::string>(std::string name, std::string default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<std::string>(name){
    if(!initData(h,name)){
      AttributeBase<std::string>::data = new std::string(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      AttributeBase<std::string>::data = new std::string(result);
      return true;
    }
    else{ return false; }
  }

  Attribute<std::string>& operator =(const Attribute<std::string>& attrib){
    delete AttributeBase<std::string>::data;
    if(attrib.exists()){ AttributeBase<std::string>::data = new std::string(*attrib.getData()); }
    else{ AttributeBase<std::string>::data =0; }
    AttributeBase<std::string>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      return *data;
    }
    else{
      return std::string();
    }
  }
};

/** Enum::Altidude instanciation **/
template<>
class THIS<Enum::Altidude>:public AttributeBase<Enum::Altidude>{
  public:
  THIS<Enum::Altidude>():AttributeBase<Enum::Altidude>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Altidude>(name){
    initData(h,name);
  }

  THIS<Enum::Altidude>(std::string name, Enum::Altidude default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Altidude>(name){
    if(!initData(h,name)){
      AttributeBase<Enum::Altidude>::data = new Enum::Altidude( default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
     if(result == "absolute"){
        AttributeBase<Enum::Altidude>::data = new Enum::Altidude(Enum::ABSOLUTE);
      }
      if(result == "relative"){
        AttributeBase<Enum::Altidude>::data = new Enum::Altidude(Enum::RELATIVE_TO_GROUND);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Altidude>& operator =(const Attribute<Enum::Altidude>& attrib){
    delete AttributeBase<Enum::Altidude>::data;
    if(attrib.exists()){ AttributeBase<Enum::Altidude>::data = new Enum::Altidude(*attrib.data); }
    else{ data =0; }
    AttributeBase<Enum::Altidude>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::RELATIVE_TO_GROUND:{
          return "relative";
        }
        case Enum::ABSOLUTE:{
          return "absolute";
        }
      }
    }
    return std::string();
  }
};

/** bool instanciation **/
template<>
class THIS<bool>:public AttributeBase<bool>{
  public:
  THIS<bool>():AttributeBase<bool>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<bool>(name){
    initData(h,name);
  }

  THIS<bool>(std::string name, bool default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<bool>(name){
    if(!initData(h,name)){
      AttributeBase<bool>::data = new bool(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "true"){
        AttributeBase<bool>::data = new bool(true);
      }
      else{
        AttributeBase<bool>::data = new bool(false);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<bool>& operator =(const Attribute<bool>& attrib){
    delete AttributeBase<bool>::data;
    if(attrib.exists()){ AttributeBase<bool>::data = new bool(*attrib.data); }
    else{ AttributeBase<bool>::data =0; }
    AttributeBase<bool>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      if(*data){
        return "true";
      }
      else{
        return "false";
      }
    }
    return std::string();
  }
};

/** Enum::NodeType instanciation **/
template<>
class THIS<Enum::NodeType::Type>:public AttributeBase<Enum::NodeType::Type>{
  public:
  THIS<Enum::NodeType::Type>():AttributeBase<Enum::NodeType::Type>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::NodeType::Type>(name){
    initData(h,name);
  }

  THIS<Enum::NodeType::Type>(std::string name, Enum::NodeType::Type default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::NodeType::Type>(name){
    if(initData(h,name)){
      AttributeBase<Enum::NodeType::Type>::data = new Enum::NodeType::Type(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "JOINT"){
        AttributeBase<Enum::NodeType::Type>::data = new Enum::NodeType::Type(Enum::NodeType::JOINT);
      }
      if(result == "NODE"){
        AttributeBase<Enum::NodeType::Type>::data = new Enum::NodeType::Type(Enum::NodeType::NODE);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::NodeType::Type>& operator =(const Attribute<Enum::NodeType::Type>& attrib){
    delete AttributeBase<Enum::NodeType::Type>::data;
    if(attrib.exists()){ AttributeBase<Enum::NodeType::Type>::data = new Enum::NodeType::Type(*attrib.data); }
    else{ AttributeBase<Enum::NodeType::Type>::data =0; }
    AttributeBase<Enum::NodeType::Type>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::NodeType::JOINT:{return "JOINT";}
        case Enum::NodeType::NODE:{return "NODE";}
      }
    }
    return std::string();
  }
};

/** Enum::Semantic instanciaton**/
template<>
class THIS<Enum::Semantic>:public AttributeBase<Enum::Semantic>{
  public:
  THIS<Enum::Semantic>():AttributeBase<Enum::Semantic>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Semantic>(name){
    initData(h,name);
  }

  THIS<Enum::Semantic>(std::string name, Enum::Semantic default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Semantic>(name){
    if(!initData(h,name)){
      AttributeBase<Enum::Semantic>::data = data = new Enum::Semantic(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "BINORMAL"){data = new Enum::Semantic(Enum::BINORMAL);}
      if(result == "COLOR"){data = new Enum::Semantic(Enum::COLOR);}
      if(result == "CONTINUITY"){data = new Enum::Semantic(Enum::CONTINUITY);}
      if(result == "IMAGE"){data = new Enum::Semantic(Enum::IMAGE);}
      if(result == "INPUT"){data = new Enum::Semantic(Enum::INPUT);}
      if(result == "IN_TANGENT"){data = new Enum::Semantic(Enum::IN_TANGENT);}
      if(result == "INTERPOLATION"){data = new Enum::Semantic(Enum::INTERPOLATION);}
      if(result == "INV_BIND_MATRIX"){data = new Enum::Semantic(Enum::INV_BIND_MATRIX);}
      if(result == "JOINT"){data = new Enum::Semantic(Enum::JOINT);}
      if(result == "LINEAR_STEPS"){data = new Enum::Semantic(Enum::LINEAR_STEPS);}
      if(result == "MORPH_TARGET"){data = new Enum::Semantic(Enum::MORPH_TARGET);}
      if(result == "MORPH_WEIGHT"){data = new Enum::Semantic(Enum::MORPH_WEIGHT);}
      if(result == "NORMAL"){data = new Enum::Semantic(Enum::NORMAL);}
      if(result == "OUTPUT"){data = new Enum::Semantic(Enum::OUTPUT);}
      if(result == "OUT_TANGENT"){data = new Enum::Semantic(Enum::OUT_TANGENT);}
      if(result == "POSITION"){data = new Enum::Semantic(Enum::POSITION);}
      if(result == "TANGENT"){data = new Enum::Semantic(Enum::TANGENT);}
      if(result == "TEXBINORMAL"){data = new Enum::Semantic(Enum::TEXBINORMAL);}
      if(result == "TEXCOORD"){data = new Enum::Semantic(Enum::TEXCOORD);}
      if(result == "TEXTANGENT"){data = new Enum::Semantic(Enum::TEXTANGENT);}
      if(result == "UV"){data = new Enum::Semantic(Enum::UV);}
      if(result == "VERTEX"){data = new Enum::Semantic(Enum::VERTEX);}
      if(result == "WEIGHT"){data = new Enum::Semantic(Enum::WEIGHT);}
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Semantic>& operator =(const Attribute<Enum::Semantic>& attrib){
    delete AttributeBase<Enum::Semantic>::data;
    if(attrib.exists()){ AttributeBase<Enum::Semantic>::data = data = new Enum::Semantic(*attrib.data); }
    else{ AttributeBase<Enum::Semantic>::data =0; }
    AttributeBase<Enum::Semantic>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::BINORMAL :{return "BINORMAL";}
        case Enum::COLOR :{return "COLOR";}
        case Enum::CONTINUITY :{return "CONTINUITY";}
        case Enum::IMAGE :{return "IMAGE";}
        case Enum::INPUT :{return "INPUT";}
        case Enum::IN_TANGENT :{return "IN_TANGENT";}
        case Enum::INTERPOLATION :{return "INTERPOLATION";}
        case Enum::INV_BIND_MATRIX :{return "INV_BIND_MATRIX";}
        case Enum::JOINT :{return "JOINT";}
        case Enum::LINEAR_STEPS :{return "LINEAR_STEPS";}
        case Enum::MORPH_TARGET :{return "MORPH_TARGET";}
        case Enum::MORPH_WEIGHT :{return "MORPH_WEIGHT";}
        case Enum::NORMAL :{return "NORMAL";}
        case Enum::OUTPUT :{return "OUTPUT";}
        case Enum::OUT_TANGENT :{return "OUT_TANGENT";}
        case Enum::POSITION :{return "POSITION";}
        case Enum::TANGENT :{return "TANGENT";}
        case Enum::TEXBINORMAL :{return "TEXBINORMAL";}
        case Enum::TEXCOORD :{return "TEXCOORD";}
        case Enum::TEXTANGENT :{return "TEXTANGENT";}
        case Enum::UV :{return "UV";}
        case Enum::VERTEX :{return "VERTEX";}
        case Enum::WEIGHT :{return "WEIGHT";}
      }
    }
    return std::string();
  }
};

/** Enum::Method instanciation **/
template<>
class THIS<Enum::Method>:public AttributeBase<Enum::Method>{
  public:
  THIS<Enum::Method>():AttributeBase<Enum::Method>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Method>(name){
    initData(h,name);
  }

  THIS<Enum::Method>(std::string name, Enum::Method default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Method>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Method>::data = new Enum::Method(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "NORMALIZED"){
        AttributeBase<Enum::Method>::data = new Enum::Method(Enum::NORMALIZED);
      }
      if(result == "RELATIVE"){
        AttributeBase<Enum::Method>::data = new Enum::Method(Enum::RELATIVE);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Method>& operator =(const Attribute<Enum::Method>& attrib){
    delete AttributeBase<Enum::Method>::data;
    if(attrib.exists()){ AttributeBase<Enum::Method>::data = new Enum::Method(*attrib.data); }
    else{ AttributeBase<Enum::Method>::data =0; }
    AttributeBase<Enum::Method>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::NORMALIZED:{return "NORMALIZED";}
        case Enum::RELATIVE:{return "RELATIVE";}
      }
    }
    return std::string();
  }
};

/** Enum::Behavior instanciation **/
template<>
class THIS<Enum::Behavior>:public AttributeBase<Enum::Behavior>{
  public:
  THIS<Enum::Behavior>():AttributeBase<Enum::Behavior>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Behavior>(name){
    initData(h,name);
  }

  THIS<Enum::Behavior>(std::string name, Enum::Behavior default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Behavior>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Behavior>::data = new Enum::Behavior(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "UNDEFINED"){
        AttributeBase<Enum::Behavior>::data = new Enum::Behavior(Enum::UNDEFINED);
      }
      if(result == "CONSTANT"){
        AttributeBase<Enum::Behavior>::data = new Enum::Behavior(Enum::CONSTANT);
      }
      if(result == "GRADIENT"){
        AttributeBase<Enum::Behavior>::data = new Enum::Behavior(Enum::GRADIENT);
      }
      if(result == "CYCLE"){
        AttributeBase<Enum::Behavior>::data = new Enum::Behavior(Enum::CYCLE);
      }
      if(result == "OSCILLATE"){
        AttributeBase<Enum::Behavior>::data = new Enum::Behavior(Enum::OSCILLATE);
      }
      if(result == "CYCLE_RELATIVE"){
        AttributeBase<Enum::Behavior>::data = new Enum::Behavior(Enum::CYCLE_RELATIVE);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Behavior>& operator =(const Attribute<Enum::Behavior>& attrib){
    delete AttributeBase<Enum::Behavior>::data;
    if(attrib.exists()){ AttributeBase<Enum::Behavior>::data = new Enum::Behavior(*attrib.data); }
    else{ AttributeBase<Enum::Behavior>::data =0; }
    AttributeBase<Enum::Behavior>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::UNDEFINED:{return "UNDEFINED";}
        case Enum::CONSTANT:{return "CONSTANT";}
        case Enum::GRADIENT:{return "GRADIENT";}
        case Enum::CYCLE:{return "CYCLE";}
        case Enum::OSCILLATE:{return "OSCILLATE";}
        case Enum::CYCLE_RELATIVE:{return "CYCLE_RELATIVE";}
      }
    }
    return std::string();
  }
};

/** Enum::Operator instanciation **/
template<>
class THIS<Enum::Operator>:public AttributeBase<Enum::Operator>{
  public:
  THIS<Enum::Operator>():AttributeBase<Enum::Operator>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Operator>(name){
    initData(h,name);
  }

  THIS<Enum::Operator>(std::string name, Enum::Operator default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Operator>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Operator>::data = new Enum::Operator(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "REPLACE"){
        AttributeBase<Enum::Operator>::data = new Enum::Operator(Enum::REPLACE);
      }
      if(result == "MODULATE"){
        AttributeBase<Enum::Operator>::data = new Enum::Operator(Enum::MODULATE);
      }
      if(result == "ADD"){
        AttributeBase<Enum::Operator>::data = new Enum::Operator(Enum::ADD);
      }
      if(result == "ADD_SIGNED"){
        AttributeBase<Enum::Operator>::data = new Enum::Operator(Enum::ADD_SIGNED);
      }
      if(result == "INTERPOLATE"){
        AttributeBase<Enum::Operator>::data = new Enum::Operator(Enum::INTERPOLATE);
      }
      if(result == "SUBTRACT"){
        AttributeBase<Enum::Operator>::data = new Enum::Operator(Enum::SUBTRACT);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Operator>& operator =(const Attribute<Enum::Operator>& attrib){
    delete AttributeBase<Enum::Operator>::data;
    if(attrib.exists()){ AttributeBase<Enum::Operator>::data = new Enum::Operator(*attrib.data); }
    else{ AttributeBase<Enum::Operator>::data =0; }
    AttributeBase<Enum::Operator>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::REPLACE:{return "REPLACE";}
        case Enum::MODULATE:{return "MODULATE";}
        case Enum::ADD:{return "ADD";}
        case Enum::ADD_SIGNED:{return "ADD_SIGNED";}
        case Enum::INTERPOLATE:{return "INTERPOLATE";}
        case Enum::SUBTRACT:{return "SUBTRACT";}
      }
    }
    return std::string();
  }
};

/** Enum::Source::Value instanciation **/
template<>
class THIS<Enum::Source::Value>:public AttributeBase<Enum::Source::Value>{
  public:
  THIS<Enum::Source::Value>():AttributeBase<Enum::Source::Value>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Source::Value>(name){
    initData(h,name);
  }

  THIS<Enum::Source::Value>(std::string name, Enum::Source::Value default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Source::Value>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Source::Value>::data = new Enum::Source::Value(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "TEXTURE"){
        AttributeBase<Enum::Source::Value>::data = new Enum::Source::Value(Enum::Source::TEXTURE);
      }
      if(result == "CONSTANT"){
        AttributeBase<Enum::Source::Value>::data = new Enum::Source::Value(Enum::Source::CONSTANT);
      }
      if(result == "PRIMARY"){
        AttributeBase<Enum::Source::Value>::data = new Enum::Source::Value(Enum::Source::PRIMARY);
      }
      if(result == "PREVIOUS"){
        AttributeBase<Enum::Source::Value>::data = new Enum::Source::Value(Enum::Source::PREVIOUS);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Source::Value>& operator =(const Attribute<Enum::Source::Value>& attrib){
    delete AttributeBase<Enum::Source::Value>::data;
    if(attrib.exists()){ AttributeBase<Enum::Source::Value>::data = new Enum::Source::Value(*attrib.data); }
    else{ AttributeBase<Enum::Source::Value>::data =0; }
    AttributeBase<Enum::Source::Value>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::Source::TEXTURE:{return "TEXTURE";}
        case Enum::Source::CONSTANT:{return "CONSTANT";}
        case Enum::Source::PRIMARY:{return "PRIMARY";}
        case Enum::Source::PREVIOUS:{return "PREVIOUS";}
      }
    }
    return std::string();
  }
};

/** Enum::Operand instanciation **/
template<>
class THIS<Enum::Operand>:public AttributeBase<Enum::Operand>{
  public:
  THIS<Enum::Operand>():AttributeBase<Enum::Operand>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Operand>(name){
    initData(h,name);
  }

  THIS<Enum::Operand>(std::string name, Enum::Operand default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Operand>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Operand>::data = new Enum::Operand(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "SRC_COLOR"){
        AttributeBase<Enum::Operand>::data = new Enum::Operand(Enum::SRC_COLOR);
      }
      if(result == "ONE_MINUS_SRC_COLOR"){
        AttributeBase<Enum::Operand>::data = new Enum::Operand(Enum::ONE_MINUS_SRC_COLOR);
      }
      if(result == "SRC_ALPHA"){
        AttributeBase<Enum::Operand>::data = new Enum::Operand(Enum::SRC_ALPHA);
      }
      if(result == "ONE_MINUS_SRC_ALPHA"){
        AttributeBase<Enum::Operand>::data = new Enum::Operand(Enum::ONE_MINUS_SRC_ALPHA);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Operand>& operator =(const Attribute<Enum::Operand>& attrib){
    delete AttributeBase<Enum::Operand>::data;
    if(attrib.exists()){ AttributeBase<Enum::Operand>::data = new Enum::Operand(*attrib.data); }
    else{ AttributeBase<Enum::Operand>::data =0; }
    AttributeBase<Enum::Operand>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::SRC_COLOR:{return "SRC_COLOR";}
        case Enum::ONE_MINUS_SRC_COLOR:{return "ONE_MINUS_SRC_COLOR";}
        case Enum::SRC_ALPHA:{return "SRC_ALPHA";}
        case Enum::ONE_MINUS_SRC_ALPHA:{return "ONE_MINUS_SRC_ALPHA";}
      }
    }
    return std::string();
  }
};

/** Enum::Face **/
template<>
class THIS<Enum::Face>:public AttributeBase<Enum::Face>{
  public:
  THIS<Enum::Face>():AttributeBase<Enum::Face>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Face>(name){
    initData(h,name);
  }

  THIS<Enum::Face>(std::string name, Enum::Face default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Face>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Face>::data = new Enum::Face(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "POSITIVE_X"){
        AttributeBase<Enum::Face>::data = new Enum::Face(Enum::POSITIVE_X);
      }
      if(result == "NEGATIVE_X"){
        AttributeBase<Enum::Face>::data = new Enum::Face(Enum::NEGATIVE_X);
      }
      if(result == "POSITIVE_Y"){
        AttributeBase<Enum::Face>::data = new Enum::Face(Enum::POSITIVE_Y);
      }
      if(result == "NEGATIVE_Y"){
        AttributeBase<Enum::Face>::data = new Enum::Face(Enum::NEGATIVE_Y);
      }
      if(result == "POSITIVE_Z"){
        AttributeBase<Enum::Face>::data = new Enum::Face(Enum::POSITIVE_Z);
      }
      if(result == "NEGATIVE_Z"){
        AttributeBase<Enum::Face>::data = new Enum::Face(Enum::NEGATIVE_Z);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Face>& operator =(const Attribute<Enum::Face>& attrib){
    delete AttributeBase<Enum::Face>::data;
    if(attrib.exists()){ AttributeBase<Enum::Face>::data = new Enum::Face(*attrib.data); }
    else{ AttributeBase<Enum::Face>::data =0; }
    AttributeBase<Enum::Face>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::POSITIVE_X:{return "POSITIVE_X";}
        case Enum::NEGATIVE_X:{return "NEGATIVE_X";}
        case Enum::POSITIVE_Y:{return "POSITIVE_Y";}
        case Enum::NEGATIVE_Y:{return "NEGATIVE_Y";}
        case Enum::POSITIVE_Z:{return "POSITIVE_Z";}
        case Enum::NEGATIVE_Z:{return "NEGATIVE_Z";}
      }
    }
    return std::string();
  }
};

/** Enum::Channel **/
template<>
class THIS<Enum::Channel>:public AttributeBase<Enum::Channel>{
  public:
  THIS<Enum::Channel>():AttributeBase<Enum::Channel>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Channel>(name){
    initData(h,name);
  }

  THIS<Enum::Channel>(std::string name, Enum::Channel default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Channel>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Channel>::data = new Enum::Channel(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "RGB"){
        AttributeBase<Enum::Channel>::data = new Enum::Channel(Enum::RGB);
      }
      if(result == "RGBA"){
        AttributeBase<Enum::Channel>::data = new Enum::Channel(Enum::RGBA);
      }
      if(result == "RGBE"){
        AttributeBase<Enum::Channel>::data = new Enum::Channel(Enum::RGBE);
      }
      if(result == "L"){
        AttributeBase<Enum::Channel>::data = new Enum::Channel(Enum::L);
      }
      if(result == "LA"){
        AttributeBase<Enum::Channel>::data = new Enum::Channel(Enum::LA);
      }
      if(result == "D"){
        AttributeBase<Enum::Channel>::data = new Enum::Channel(Enum::D);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Channel>& operator =(const Attribute<Enum::Channel>& attrib){
    delete AttributeBase<Enum::Channel>::data;
    if(attrib.exists()){ AttributeBase<Enum::Channel>::data = new Enum::Channel(*attrib.data); }
    else{ AttributeBase<Enum::Channel>::data =0; }
    AttributeBase<Enum::Channel>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::RGB:{return "RGB";}
        case Enum::RGBA:{return "RGBA";}
        case Enum::RGBE:{return "RGBE";}
        case Enum::L:{return "L";}
        case Enum::LA:{return "LA";}
        case Enum::D:{return "D";}
      }
    }
    return std::string();
  }
};

/** Enum::Range **/
template<>
class THIS<Enum::Range>:public AttributeBase<Enum::Range>{
  public:
  THIS<Enum::Range>():AttributeBase<Enum::Range>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Range>(name){
    initData(h,name);
  }

  THIS<Enum::Range>(std::string name, Enum::Range default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Range>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Range>::data = new Enum::Range(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "SNOR"){
        AttributeBase<Enum::Range>::data = new Enum::Range(Enum::SNOR);
      }
      if(result == "UNOR"){
        AttributeBase<Enum::Range>::data = new Enum::Range(Enum::UNOR);
      }
      if(result == "SINT"){
        AttributeBase<Enum::Range>::data = new Enum::Range(Enum::SINT);
      }
      if(result == "UINT"){
        AttributeBase<Enum::Range>::data = new Enum::Range(Enum::UINT);
      }
      if(result == "FLOAT"){
        AttributeBase<Enum::Range>::data = new Enum::Range(Enum::FLOAT);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Range>& operator =(const Attribute<Enum::Range>& attrib){
    delete AttributeBase<Enum::Range>::data;
    if(attrib.exists()){ AttributeBase<Enum::Range>::data = new Enum::Range(*attrib.data); }
    else{ AttributeBase<Enum::Range>::data =0; }
    AttributeBase<Enum::Range>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::SNOR:{return "SNOR";}
        case Enum::UNOR:{return "UNOR";}
        case Enum::SINT:{return "SINT";}
        case Enum::UINT:{return "UINT";}
        case Enum::FLOAT:{return "FLOAT";}
      }
    }
    return std::string();
  }
};

/** Enum::Precision **/
template<>
class THIS<Enum::Precision>:public AttributeBase<Enum::Precision>{
  public:
  THIS<Enum::Precision>():AttributeBase<Enum::Precision>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Precision>(name){
    initData(h,name);
  }

  THIS<Enum::Precision>(std::string name, Enum::Precision default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Precision>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Precision>::data = new Enum::Precision(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "DEFAULT"){
        AttributeBase<Enum::Precision>::data = new Enum::Precision(Enum::DEFAULT);
      }
      if(result == "LOW"){
        AttributeBase<Enum::Precision>::data = new Enum::Precision(Enum::LOW);
      }
      if(result == "MID"){
        AttributeBase<Enum::Precision>::data = new Enum::Precision(Enum::MID);
      }
      if(result == "HIGH"){
        AttributeBase<Enum::Precision>::data = new Enum::Precision(Enum::HIGH);
      }
      if(result == "MAX"){
        AttributeBase<Enum::Precision>::data = new Enum::Precision(Enum::MAX);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Precision>& operator =(const Attribute<Enum::Precision>& attrib){
    delete AttributeBase<Enum::Precision>::data;
    if(attrib.exists()){ AttributeBase<Enum::Precision>::data = new Enum::Precision(*attrib.data); }
    else{ AttributeBase<Enum::Precision>::data =0; }
    AttributeBase<Enum::Precision>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::DEFAULT:{return "DEFAULT";}
        case Enum::LOW:{return "LOW";}
        case Enum::MID:{return "MID";}
        case Enum::HIGH:{return "HIGH";}
        case Enum::MAX:{return "MAX";}
      }
    }
    return std::string();
  }
};

/** Enum::Shader::Stage **/
template<>
class THIS<Enum::Shader::Stage>:public AttributeBase<Enum::Shader::Stage>{
  public:
  THIS<Enum::Shader::Stage>():AttributeBase<Enum::Shader::Stage>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Shader::Stage>(name){
    initData(h,name);
  }

  THIS<Enum::Shader::Stage>(std::string name, Enum::Shader::Stage default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Shader::Stage>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Shader::Stage>::data = new Enum::Shader::Stage(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "TESSELATION"){
        AttributeBase<Enum::Shader::Stage>::data = new Enum::Shader::Stage(Enum::Shader::TESSELATION);
      }
      if(result == "VERTEX"){
        AttributeBase<Enum::Shader::Stage>::data = new Enum::Shader::Stage(Enum::Shader::VERTEX);
      }
      if(result == "GEOMETRY"){
        AttributeBase<Enum::Shader::Stage>::data = new Enum::Shader::Stage(Enum::Shader::GEOMETRY);
      }
      if(result == "FRAGMENT"){
        AttributeBase<Enum::Shader::Stage>::data = new Enum::Shader::Stage(Enum::Shader::FRAGMENT);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Shader::Stage>& operator =(const Attribute<Enum::Shader::Stage>& attrib){
    delete AttributeBase<Enum::Shader::Stage>::data;
    if(attrib.exists()){ AttributeBase<Enum::Shader::Stage>::data = new Enum::Shader::Stage(*attrib.data); }
    else{ AttributeBase<Enum::Shader::Stage>::data =0; }
    AttributeBase<Enum::Shader::Stage>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::Shader::TESSELATION:{return "TESSELATION";}
        case Enum::Shader::VERTEX:{return "VERTEX";}
        case Enum::Shader::GEOMETRY:{return "GEOMETRY";}
        case Enum::Shader::FRAGMENT:{return "FRAGMENT";}
      }
    }
    return std::string();
  }
};

/** Enum::Opaque **/
template<>
class THIS<Enum::Opaque>:public AttributeBase<Enum::Opaque>{
  public:
  THIS<Enum::Opaque>():AttributeBase<Enum::Opaque>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Opaque>(name){
    initData(h,name);
  }

  THIS<Enum::Opaque>(std::string name, Enum::Opaque default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Opaque>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Opaque>::data = new Enum::Opaque(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "A_ONE"){
        AttributeBase<Enum::Opaque>::data = new Enum::Opaque(Enum::A_ONE);
      }
      if(result == "RGB_ZERO"){
        AttributeBase<Enum::Opaque>::data = new Enum::Opaque(Enum::RGB_ZERO);
      }
      if(result == "A_ZERO"){
        AttributeBase<Enum::Opaque>::data = new Enum::Opaque(Enum::A_ZERO);
      }
      if(result == "RGB_ONE"){
        AttributeBase<Enum::Opaque>::data = new Enum::Opaque(Enum::RGB_ONE);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Opaque>& operator =(const Attribute<Enum::Opaque>& attrib){
    delete AttributeBase<Enum::Opaque>::data;
    if(attrib.exists()){ AttributeBase<Enum::Opaque>::data = new Enum::Opaque(*attrib.data); }
    else{ AttributeBase<Enum::Opaque>::data =0; }
    AttributeBase<Enum::Opaque>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::A_ONE:{return "A_ONE";}
        case Enum::RGB_ZERO:{return "RGB_ZERO";}
        case Enum::A_ZERO:{return "A_ZERO";}
        case Enum::RGB_ONE:{return "RGB_ONE";}
      }
    }
    return std::string();
  }
};

/** Enum::Rgb::Operator **/
template<>
class THIS<Enum::Rgb::Operator>:public AttributeBase<Enum::Rgb::Operator>{
  public:
  THIS<Enum::Rgb::Operator>():AttributeBase<Enum::Rgb::Operator>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Rgb::Operator>(name){
    initData(h,name);
  }

  THIS<Enum::Rgb::Operator>(std::string name, Enum::Rgb::Operator default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Rgb::Operator>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "REPLACE"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::REPLACE);
      }
      if(result == "MODULATE"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::MODULATE);
      }
      if(result == "ADD"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::ADD);
      }
      if(result == "ADD_SIGNED"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::ADD_SIGNED);
      }
      if(result == "INTERPOLATE"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::INTERPOLATE);
      }
      if(result == "SUBTRACT"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::SUBTRACT);
      }
      if(result == "DOT3_RBG"){
        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::DOT3_RGB);
      }
      if(result == "DOT3_RGBA"){        AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(Enum::Rgb::DOT3_RGBA);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Rgb::Operator>& operator =(const Attribute<Enum::Rgb::Operator>& attrib){
    delete AttributeBase<Enum::Rgb::Operator>::data;
    if(attrib.exists()){ AttributeBase<Enum::Rgb::Operator>::data = new Enum::Rgb::Operator(*attrib.data); }
    else{ AttributeBase<Enum::Rgb::Operator>::data =0; }
    AttributeBase<Enum::Rgb::Operator>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::Rgb::REPLACE:{return "REPLACE";}
        case Enum::Rgb::MODULATE:{return "MODULATE";}
        case Enum::Rgb::ADD:{return "ADD";}
        case Enum::Rgb::ADD_SIGNED:{return "ADD_SIGNED";}
        case Enum::Rgb::INTERPOLATE:{return "INTERPOLATE";}
        case Enum::Rgb::SUBTRACT:{return "SUBTRACT";}
        case Enum::Rgb::DOT3_RGB:{return "DOT3_RGB";}
        case Enum::Rgb::DOT3_RGBA:{return "DOT3_RGBA";}
      }
    }
    return std::string();
  }
};

/** Math::Vector<float,4> **/
template<>
class THIS<Math::Vector<float,4> >:public AttributeBase<Math::Vector<float,4> >{
  public:
  THIS<Math::Vector<float,4> >():AttributeBase<Math::Vector<float,4> >(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Math::Vector<float,4> >(name){
    initData(h,name);
  }

  THIS<Math::Vector<float,4> >(std::string name, Math::Vector<float,4> default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Math::Vector<float,4> >(name){
    if(initData(h,name)){
      AttributeBase<Math::Vector<float,4> >::data = new Math::Vector<float,4>(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      data = new Math::Vector<float,4>;
      Utils::fromString(*data,result);
      return true;
    }
    else{ return false; }
  }

  Attribute<Math::Vector<float,4> >& operator =(const Attribute<Math::Vector<float,4> >& attrib){
    delete AttributeBase<Math::Vector<float,4> >::data;
    if(attrib.exists()){ AttributeBase<Math::Vector<float,4> >::data = new Math::Vector<float,4>(*attrib.data); }
    else{ AttributeBase<Math::Vector<float,4> >::data =0; }
    AttributeBase<Math::Vector<float,4> >::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      return Utils::toString(*data);
    }
    return std::string();
  }
};

/** Enum::Texenv::Operator **/
template<>
class THIS<Enum::Texenv::Operator>:public AttributeBase<Enum::Texenv::Operator>{
  public:
  THIS<Enum::Texenv::Operator>():AttributeBase<Enum::Texenv::Operator>(std::string()){}

  THIS(std::string name, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Texenv::Operator>(name){
    initData(h,name);
  }

  THIS<Enum::Texenv::Operator>(std::string name, Enum::Texenv::Operator default_value, TiXmlHandle h = TiXmlHandle(0)):AttributeBase<Enum::Texenv::Operator>(name){
    if(initData(h,name)){
      AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(default_value);
    }
  }

  bool initData(TiXmlHandle handle, const std::string& name){
    std::string result;
    TiXmlElement* element = handle.ToElement();
    if(!element){ return false; }
    if(element->QueryStringAttribute(name,&result) == TIXML_SUCCESS){
      if(result == "    REPLACE"){
        AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(Enum::Texenv::REPLACE);
      }
      if(result == "MODULATE"){
        AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(Enum::Texenv::MODULATE);
      }
      if(result == "DECAL"){
        AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(Enum::Texenv::DECAL);
      }
      if(result == "BLEND"){
        AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(Enum::Texenv::BLEND);
      }
      if(result == "ADD"){
        AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(Enum::Texenv::ADD);
      }
      return true;
    }
    else{ return false; }
  }

  Attribute<Enum::Texenv::Operator>& operator =(const Attribute<Enum::Texenv::Operator>& attrib){
    delete AttributeBase<Enum::Texenv::Operator>::data;
    if(attrib.exists()){ AttributeBase<Enum::Texenv::Operator>::data = new Enum::Texenv::Operator(*attrib.data); }
    else{ AttributeBase<Enum::Texenv::Operator>::data =0; }
    AttributeBase<Enum::Texenv::Operator>::name = attrib.name;
    return *this;
  }

  std::string toString()const{
    if(exists()){
      switch(*data){
        case Enum::Texenv::ADD:{return "ADD";}
        case Enum::Texenv::BLEND:{return "BLEND";}
        case Enum::Texenv::REPLACE:{return "REPLACE";}
        case Enum::Texenv::MODULATE:{return "MODULATE";}
        case Enum::Texenv::DECAL:{return "DECAL";}
      }
    }
    return std::string();
  }
};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
