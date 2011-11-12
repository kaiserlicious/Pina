
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

#ifndef COLLADA_SIMPLE_TYPES_H
#define COLLADA_SIMPLE_TYPES_H

#include "../Element.h"

namespace PINA_NAMESPACE{

/*forward declaration of types defined in their own header and source files (FX)*/
class Sampler1D;
class Sampler2D;
class Sampler3D;
class SamplerCUBE;
class SamplerDEPTH;
class SamplerRECT;
class Sampler_image;
class Sampler_states;
class Array;
class Usertype;

/* baseclass for simple types */
template<typename TYPE, unsigned int size>
class SimpleType:public Element{
  public:
  SimpleType(Document* d, XmlElement* h = 0):Element(d,h){
    XmlElement* element = handle;
    if(element){
      std::vector<TYPE> vec;
      Utils::fromString(vec,element->getText());
      for (unsigned int i=0; i<vec.size(); i++) {
        data[i]=vec[i];
      }
    } 
        
  }
  ~SimpleType(){
    /*nothing to do in destructor*/
  }
  void order(){
    /*nothing to do, because there are no children that could be sorted*/
  };
  XmlElement* toXmlElement(){
    XmlElement* element = XmlParser::environment->newElement(getName());
    std::stringstream stream;
    for(unsigned int i=0; i<size; i++){
      stream << Utils::toString(data[i]) << " ";
    }
    element->setText(stream.str());
    return element;
  }
  // static const std::string Name; // implemented in subclass
  // std::string getName(); //implemented in subclass

  typedef NullType Types;

  typename std::vector<TYPE>::reference operator [] (unsigned int index){
    return data[index];
  }

  typename std::vector<TYPE>::const_reference operator [] (unsigned int index) const{
    return data[index];
  }

  private:
  /* data */
  TYPE data[size];
};

/** baseclass simple types, specialzation for bool **/
template< unsigned int size>
class SimpleType<bool,size>:public Element{
  public:
  SimpleType(Document* d, XmlElement* h = 0):Element(d,h){
    XmlElement* element = handle;
    if(element){
      std::list<std::string> strings;
      Utils::fromString(strings,element->getText());
      std::list<std::string>::iterator iter;
      unsigned int i=0;
      for(iter = strings.begin(); iter != strings.end() && i<size; iter++){
        data[i] = (*iter == "true" ? true : false);
        i++;
      }
    }
  }
  ~SimpleType(){
    /*nothing to do in destructor*/
  }
  void order(){
    /*nothing to do, because there are no children that could be sorted*/
  };
  XmlElement* toXmlElement(){
    XmlElement* element = XmlParser::environment->newElement(getName());
    std::stringstream stream;
    for(unsigned int i=0; i<size; i++){
      stream << (data[i] ? "true" : "false") << " ";
    }
    element->setText(stream.str());
    return element;
  }
  // static const std::string Name; // implemented in subclass
  // std::string getName(); //implemented in subclass

  typedef NullType Types;

  std::vector<bool>::reference operator [] (unsigned int index){
    return data[index];
  }

  std::vector<bool>::const_reference operator [] (unsigned int index) const{
    return data[index];
  }

  private:
  /* data */
  bool data[size];
};

/** baseclass for simple array types **/
template<typename TYPE>
class SimpleArrayType:public Element{
  public:
  SimpleArrayType(Document* d, XmlElement* h = 0):Element(d,h){
    XmlElement* element = handle;
    if(element){
      Utils::fromString(data,element->getText());
    }
  }
  ~SimpleArrayType(){
    /*nothing to do in destructor*/
  }
  void order(){
    /*nothing to do, because there are no children that could be sorted*/
  };
  XmlElement* toXmlElement(){
    XmlElement* element = XmlParser::environment->newElement(getName());
    std::stringstream stream;
    typename std::vector<TYPE>::iterator iter;
    for(iter = data.begin(); iter != data.end(); iter++){
      stream << Utils::toString(*iter) << " ";
    }
    element->setText(stream.str());
    return element;
  }
  // static const std::string Name; // implemented in subclass
  // std::string getName(); //implemented in subclass

  typedef NullType Types;

  typename std::vector<TYPE>::reference operator [] (unsigned int index){
    return data[index];
  }

  typename std::vector<TYPE>::const_reference operator [] (unsigned int index) const {
    return data[index];
  }

  unsigned int getSize(){
    return data.size();
  }

  void getData(std::vector<TYPE>& out){
    out = data;
  }

  private:
  /* data */
  std::vector<TYPE> data;
};

/** baseclass for simple array types, specialization for bool **/
template<>
class SimpleArrayType<bool>:public Element{
  public:
  SimpleArrayType(Document* d, XmlElement* h = 0):Element(d,h){
    XmlElement* element = handle;
    if(element){
      std::list<std::string> strings;
      Utils::fromString(strings,element->getText());
      std::list<std::string>::iterator iter;
      for(iter = strings.begin(); iter != strings.end(); iter++){
        data.push_back((*iter) == "true" ? true : false);
      }
    }
  }
  ~SimpleArrayType(){
    /*nothing to do in destructor*/
  }
  void order(){
    /*nothing to do, because there are no children that could be sorted*/
  };
  XmlElement* toXmlElement(){
    XmlElement* element = XmlParser::environment->newElement(getName());
    std::stringstream stream;
    std::vector<bool>::iterator iter;
    for(iter = data.begin(); iter != data.end(); iter++){
      stream << ((*iter) ? "true" : " false") << " ";
    }
    element->setText(stream.str());
    return element;
  }
  // static const std::string Name; // implemented in subclass
  // std::string getName(); //implemented in subclass

  typedef NullType Types;

  std::vector<bool>::reference operator [] (unsigned int index){
    return data[index];
  }

  std::vector<bool>::const_reference operator [] (unsigned int index) const{
    return data[index];
  }

  unsigned int getSize(){
    return data.size();
  }

  void getData(std::vector<bool>& out){
    out = data;
  }

  private:
  /* data */
  std::vector<bool> data;
};

/* simple value types */

// bool2_type
class Bool2_type: public SimpleType<bool,2>{
  public:
  Bool2_type(Document* d, XmlElement* h = 0):SimpleType<bool,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool3_type
class Bool3_type: public SimpleType<bool,3>{
  public:
  Bool3_type(Document* d, XmlElement* h = 0):SimpleType<bool,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool4_type
class Bool4_type: public SimpleType<bool,4>{
  public:
  Bool4_type(Document* d, XmlElement* h = 0):SimpleType<bool,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float_type
class Float_type: public SimpleType<float,1>{
  public:
  Float_type(Document* d, XmlElement* h = 0):SimpleType<float,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2_type
class Float2_type: public SimpleType<float,2>{
  public:
  Float2_type(Document* d, XmlElement* h = 0):SimpleType<float,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x2_type
class Float2x2_type: public SimpleType<float,2*2>{
  public:
  Float2x2_type(Document* d, XmlElement* h = 0):SimpleType<float,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x3_type
class Float2x3_type: public SimpleType<float,2*3>{
  public:
  Float2x3_type(Document* d, XmlElement* h = 0):SimpleType<float,2*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x4_type
class Float2x4_type: public SimpleType<float,2*4>{
  public:
  Float2x4_type(Document* d, XmlElement* h = 0):SimpleType<float,2*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3_type
class Float3_type: public SimpleType<float,3>{
  public:
  Float3_type(Document* d, XmlElement* h = 0):SimpleType<float,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x2_type
class Float3x2_type: public SimpleType<float,3*2>{
  public:
  Float3x2_type(Document* d, XmlElement* h = 0):SimpleType<float,3*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x3_type
class Float3x3_type: public SimpleType<float,3*3>{
  public:
  Float3x3_type(Document* d, XmlElement* h = 0):SimpleType<float,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x4_type
class Float3x4_type: public SimpleType<float,3*4>{
  public:
  Float3x4_type(Document* d, XmlElement* h = 0):SimpleType<float,3*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4_type
class Float4_type: public SimpleType<float,4>{
  public:
  Float4_type(Document* d, XmlElement* h = 0):SimpleType<float,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x2_type
class Float4x2_type: public SimpleType<float,4*2>{
  public:
  Float4x2_type(Document* d, XmlElement* h = 0):SimpleType<float,4*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x3_type
class Float4x3_type: public SimpleType<float,4*3>{
  public:
  Float4x3_type(Document* d, XmlElement* h = 0):SimpleType<float,4*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x4_type
class Float4x4_type: public SimpleType<float,4*4>{
  public:
  Float4x4_type(Document* d, XmlElement* h = 0):SimpleType<float,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float7_type
class Float7_type: public SimpleType<float,7>{
  public:
  Float7_type(Document* d, XmlElement* h = 0):SimpleType<float,7>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int_type
class Int_type: public SimpleType<int,1>{
  public:
  Int_type(Document* d, XmlElement* h = 0):SimpleType<int,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int2_type
class Int2_type: public SimpleType<int,2>{
  public:
  Int2_type(Document* d, XmlElement* h = 0):SimpleType<int,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int2x2_type
class Int2x2_type: public SimpleType<int,2*2>{
  public:
  Int2x2_type(Document* d, XmlElement* h = 0):SimpleType<int,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3_type
class Int3_type: public SimpleType<int,3>{
  public:
  Int3_type(Document* d, XmlElement* h = 0):SimpleType<int,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3x3_type
class Int3x3_type: public SimpleType<int,3*3>{
  public:
  Int3x3_type(Document* d, XmlElement* h = 0):SimpleType<int,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int4_type
class Int4_type: public SimpleType<int,4>{
  public:
  Int4_type(Document* d, XmlElement* h = 0):SimpleType<int,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int4x4_type
class Int4x4_type: public SimpleType<int,4*4>{
  public:
  Int4x4_type(Document* d, XmlElement* h = 0):SimpleType<int,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// list_of_bools_type
class List_of_bools_type: public SimpleArrayType<bool>{
  public:
  List_of_bools_type(Document* d, XmlElement* h = 0):SimpleArrayType<bool>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// list_of_floats_type
class List_of_floats_type: public SimpleArrayType<float>{
  public:
  List_of_floats_type(Document* d, XmlElement* h = 0):SimpleArrayType<float>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// list_of_hexBinary_type 
/*customized implementation because of hex input/output*/
class List_of_hexBinary_type:public Element{
  public:
  List_of_hexBinary_type(Document* d, XmlElement* h = 0):Element(d,h){
    XmlElement* element = handle;
    if(element){
      std::list<std::string> strings;
      Utils::fromString(strings,element->getText());
      std::stringstream stream;
      stream << std::hex; /*set the stream to read hex*/
      long value;
      std::list<std::string>::iterator iter;
      for(iter = strings.begin(); iter != strings.end(); iter++){
        stream << *iter;
        stream >> value;
        data.push_back(value);
        stream.clear();
      }
    }
  }
  ~List_of_hexBinary_type(){
    /*nothing to do in destructor*/
  }
  void order(){
    /*nothing to do, because there are no children that could be sorted*/
  };
  XmlElement* toXmlElement(){
    XmlElement* element = XmlParser::environment->newElement(getName());
    std::stringstream stream;
    stream << std::hex; /*here is the magic, set stream to hex output*/
    std::vector<long>::iterator iter;
    for(iter = data.begin(); iter != data.end(); iter++){
      stream << *iter << " ";
    }
    element->setText(stream.str());
    return element;
  }

  static const std::string Name;

  std::string getName(){
    return Name;
  }

  typedef NullType Types;

  std::vector<long>::reference operator [] (unsigned int index){
    return data[index];
  }

  std::vector<long>::const_reference operator [] (unsigned int index) const{
    return data[index];
  }

  private:
  /* data */
  std::vector<long> data;
};

// list_of_ints_type
class List_of_ints_type: public SimpleArrayType<int>{
  public:
  List_of_ints_type(Document* d, XmlElement* h = 0):SimpleArrayType<int>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// list_of_uints_type
class List_of_uints_type: public SimpleArrayType<unsigned int>{
  public:
  List_of_uints_type(Document* d, XmlElement* h = 0):SimpleArrayType<unsigned int>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

/* GLSL Parameter Elements (glsl_value_group) */

// bool
class Bool: public SimpleType<bool,1>{
  public:
  Bool(Document* d, XmlElement* h = 0):SimpleType<bool,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//bool2
class Bool2: public SimpleType<bool,2>{
  public:
  Bool2(Document* d, XmlElement* h = 0):SimpleType<bool,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool3
class Bool3: public SimpleType<bool,3>{
  public:
  Bool3(Document* d, XmlElement* h = 0):SimpleType<bool,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool4
class Bool4: public SimpleType<bool,4>{
  public:
  Bool4(Document* d, XmlElement* h = 0):SimpleType<bool,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int
class Int: public SimpleType<int,1>{
  public:
  Int(Document* d, XmlElement* h = 0):SimpleType<int,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int2
class Int2: public SimpleType<int,2>{
  public:
  Int2(Document* d, XmlElement* h = 0):SimpleType<int,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3
class Int3: public SimpleType<int,3>{
  public:
  Int3(Document* d, XmlElement* h = 0):SimpleType<int,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//int4
class Int4: public SimpleType<int,4>{
  public:
  Int4(Document* d, XmlElement* h = 0):SimpleType<int,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//float
class Float: public SimpleType<float,1>{
  public:
  Float(Document* d, XmlElement* h = 0):SimpleType<float,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2
class Float2: public SimpleType<float,2>{
  public:
  Float2(Document* d, XmlElement* h = 0):SimpleType<float,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3
class Float3: public SimpleType<float,3>{
  public:
  Float3(Document* d, XmlElement* h = 0):SimpleType<float,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4
class Float4: public SimpleType<float,4>{
  public:
  Float4(Document* d, XmlElement* h = 0):SimpleType<float,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x2
class Float2x2: public SimpleType<float,2*2>{
  public:
  Float2x2(Document* d, XmlElement* h = 0):SimpleType<float,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x3
class Float3x3: public SimpleType<float,3*3>{
  public:
  Float3x3(Document* d, XmlElement* h = 0):SimpleType<float,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x4
class Float4x4: public SimpleType<float,4*4>{
  public:
  Float4x4(Document* d, XmlElement* h = 0):SimpleType<float,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// enum_gsl
class Enum_gsl: public SimpleType<std::string,1>{
  public:
  Enum_gsl(Document* d, XmlElement* h = 0):SimpleType<std::string,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

/*
sampler1D, sampler2D, sampler3D, samplerCUBE, samplerDEPTH and samplerRECT are
implemented in their own header and source files in FX
*/

/*CG Parameter Elements (cg_param_group)*/

// bool /*already implemented*/
// bool2 /*already implemented*/
// bool3 /*already implemented*/
// bool4 /*already implemented*/
// bool2x1
class Bool2x1: public SimpleType<bool,2*1>{
  public:
  Bool2x1(Document* d, XmlElement* h = 0):SimpleType<bool,2*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool2x2
class Bool2x2: public SimpleType<bool,2*2>{
  public:
  Bool2x2(Document* d, XmlElement* h = 0):SimpleType<bool,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool2x3
class Bool2x3: public SimpleType<bool,2*3>{
  public:
  Bool2x3(Document* d, XmlElement* h = 0):SimpleType<bool,2*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool2x4
class Bool2x4: public SimpleType<bool,2*4>{
  public:
  Bool2x4(Document* d, XmlElement* h = 0):SimpleType<bool,2*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool3x1
class Bool3x1: public SimpleType<bool,3*1>{
  public:
  Bool3x1(Document* d, XmlElement* h = 0):SimpleType<bool,3*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool3x2
class Bool3x2: public SimpleType<bool,3*2>{
  public:
  Bool3x2(Document* d, XmlElement* h = 0):SimpleType<bool,3*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool3x3
class Bool3x3: public SimpleType<bool,3*3>{
  public:
  Bool3x3(Document* d, XmlElement* h = 0):SimpleType<bool,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool3x4
class Bool3x4: public SimpleType<bool,3*4>{
  public:
  Bool3x4(Document* d, XmlElement* h = 0):SimpleType<bool,3*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool4x1
class Bool4x1: public SimpleType<bool,4*1>{
  public:
  Bool4x1(Document* d, XmlElement* h = 0):SimpleType<bool,4*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool4x2
class Bool4x2: public SimpleType<bool,4*2>{
  public:
  Bool4x2(Document* d, XmlElement* h = 0):SimpleType<bool,4*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool4x3
class Bool4x3: public SimpleType<bool,4*3>{
  public:
  Bool4x3(Document* d, XmlElement* h = 0):SimpleType<bool,4*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bool4x4
class Bool4x4: public SimpleType<bool,4*4>{
  public:
  Bool4x4(Document* d, XmlElement* h = 0):SimpleType<bool,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int /*already implemented*/
// int2 /*already implemented*/
// int3 /*already implemented*/
// int4 /*already implemented*/

// int2x1
class Int2x1: public SimpleType<int,2*1>{
  public:
  Int2x1(Document* d, XmlElement* h = 0):SimpleType<int,2*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int2x2
class Int2x2: public SimpleType<int,2*2>{
  public:
  Int2x2(Document* d, XmlElement* h = 0):SimpleType<int,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int2x3
class Int2x3: public SimpleType<int,2*3>{
  public:
  Int2x3(Document* d, XmlElement* h = 0):SimpleType<int,2*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int2x4
class Int2x4: public SimpleType<int,2*4>{
  public:
  Int2x4(Document* d, XmlElement* h = 0):SimpleType<int,2*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3x1
class Int3x1: public SimpleType<int,3*1>{
  public:
  Int3x1(Document* d, XmlElement* h = 0):SimpleType<int,3*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3x2
class Int3x2: public SimpleType<int,3*2>{
  public:
  Int3x2(Document* d, XmlElement* h = 0):SimpleType<int,3*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3x3
class Int3x3: public SimpleType<int,3*3>{
  public:
  Int3x3(Document* d, XmlElement* h = 0):SimpleType<int,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int3x4
class Int3x4: public SimpleType<int,3*4>{
  public:
  Int3x4(Document* d, XmlElement* h = 0):SimpleType<int,3*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int4x1
class Int4x1: public SimpleType<int,4*1>{
  public:
  Int4x1(Document* d, XmlElement* h = 0):SimpleType<int,4*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int4x2
class Int4x2: public SimpleType<int,4*2>{
  public:
  Int4x2(Document* d, XmlElement* h = 0):SimpleType<int,4*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int4x3
class Int4x3: public SimpleType<int,4*3>{
  public:
  Int4x3(Document* d, XmlElement* h = 0):SimpleType<int,4*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int4x4
class Int4x4: public SimpleType<int,4*4>{
  public:
  Int4x4(Document* d, XmlElement* h = 0):SimpleType<int,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float /*already implemented*/
// float2 /*already implemented*/
// float3 /*already implemented*/
// float4 /*already implemented*/

// float2x1
class Float2x1: public SimpleType<float,2*1>{
  public:
  Float2x1(Document* d, XmlElement* h = 0):SimpleType<float,2*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x2 /*already implemented*/

// float2x3
class Float2x3: public SimpleType<float,2*3>{
  public:
  Float2x3(Document* d, XmlElement* h = 0):SimpleType<float,2*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x4
class Float2x4: public SimpleType<float,2*4>{
  public:
  Float2x4(Document* d, XmlElement* h = 0):SimpleType<float,2*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x1
class Float3x1: public SimpleType<float,3*1>{
  public:
  Float3x1(Document* d, XmlElement* h = 0):SimpleType<float,3*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x2
class Float3x2: public SimpleType<float,3*2>{
  public:
  Float3x2(Document* d, XmlElement* h = 0):SimpleType<float,3*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float3x3 /*already implemented*/

// float3x4
class Float3x4: public SimpleType<float,3*4>{
  public:
  Float3x4(Document* d, XmlElement* h = 0):SimpleType<float,3*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x1
class Float4x1: public SimpleType<float,4*1>{
  public:
  Float4x1(Document* d, XmlElement* h = 0):SimpleType<float,4*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x2
class Float4x2: public SimpleType<float,4*2>{
  public:
  Float4x2(Document* d, XmlElement* h = 0):SimpleType<float,4*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x3
class Float4x3: public SimpleType<float,4*3>{
  public:
  Float4x3(Document* d, XmlElement* h = 0):SimpleType<float,4*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float4x4 /*already implemented*/

// half
class Half: public SimpleType<short,1>{
  public:
  Half(Document* d, XmlElement* h = 0):SimpleType<short,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half2
class Half2: public SimpleType<short,2>{
  public:
  Half2(Document* d, XmlElement* h = 0):SimpleType<short,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half3
class Half3: public SimpleType<short,3>{
  public:
  Half3(Document* d, XmlElement* h = 0):SimpleType<short,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half4
class Half4: public SimpleType<short,4>{
  public:
  Half4(Document* d, XmlElement* h = 0):SimpleType<short,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half2x1
class Half2x1: public SimpleType<short,2*1>{
  public:
  Half2x1(Document* d, XmlElement* h = 0):SimpleType<short,2*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half2x2
class Half2x2: public SimpleType<short,2*2>{
  public:
  Half2x2(Document* d, XmlElement* h = 0):SimpleType<short,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half2x3
class Half2x3: public SimpleType<short,2*3>{
  public:
  Half2x3(Document* d, XmlElement* h = 0):SimpleType<short,2*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half2x4
class Half2x4: public SimpleType<short,2*4>{
  public:
  Half2x4(Document* d, XmlElement* h = 0):SimpleType<short,2*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half3x1
class Half3x1: public SimpleType<short,3*1>{
  public:
  Half3x1(Document* d, XmlElement* h = 0):SimpleType<short,3*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half3x2
class Half3x2: public SimpleType<short,3*2>{
  public:
  Half3x2(Document* d, XmlElement* h = 0):SimpleType<short,3*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half3x3
class Half3x3: public SimpleType<short,3*3>{
  public:
  Half3x3(Document* d, XmlElement* h = 0):SimpleType<short,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half3x4
class Half3x4: public SimpleType<short,3*4>{
  public:
  Half3x4(Document* d, XmlElement* h = 0):SimpleType<short,3*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half4x1
class Half4x1: public SimpleType<short,4*1>{
  public:
  Half4x1(Document* d, XmlElement* h = 0):SimpleType<short,4*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half4x2
class Half4x2: public SimpleType<short,4*2>{
  public:
  Half4x2(Document* d, XmlElement* h = 0):SimpleType<short,4*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half4x3
class Half4x3: public SimpleType<short,4*3>{
  public:
  Half4x3(Document* d, XmlElement* h = 0):SimpleType<short,4*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// half4x4
class Half4x4: public SimpleType<short,4*4>{
  public:
  Half4x4(Document* d, XmlElement* h = 0):SimpleType<short,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed
class Fixed: public SimpleType<float,1>{
  public:
  Fixed(Document* d, XmlElement* h = 0):SimpleType<float,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed2
class Fixed2: public SimpleType<float,2>{
  public:
  Fixed2(Document* d, XmlElement* h = 0):SimpleType<float,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed3
class Fixed3: public SimpleType<float,3>{
  public:
  Fixed3(Document* d, XmlElement* h = 0):SimpleType<float,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed4
class Fixed4: public SimpleType<float,4>{
  public:
  Fixed4(Document* d, XmlElement* h = 0):SimpleType<float,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed1x1
class Fixed1x1: public SimpleType<float,1*1>{
  public:
  Fixed1x1(Document* d, XmlElement* h = 0):SimpleType<float,1*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed2x1
class Fixed2x1: public SimpleType<float,2*1>{
  public:
  Fixed2x1(Document* d, XmlElement* h = 0):SimpleType<float,2*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed2x2
class Fixed2x2: public SimpleType<float,2*2>{
  public:
  Fixed2x2(Document* d, XmlElement* h = 0):SimpleType<float,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed2x3
class Fixed2x3: public SimpleType<float,2*3>{
  public:
  Fixed2x3(Document* d, XmlElement* h = 0):SimpleType<float,2*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed2x4
class Fixed2x4: public SimpleType<float,2*4>{
  public:
  Fixed2x4(Document* d, XmlElement* h = 0):SimpleType<float,2*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed3x1
class Fixed3x1: public SimpleType<float,3*1>{
  public:
  Fixed3x1(Document* d, XmlElement* h = 0):SimpleType<float,3*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed3x2
class Fixed3x2: public SimpleType<float,3*2>{
  public:
  Fixed3x2(Document* d, XmlElement* h = 0):SimpleType<float,3*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed3x3
class Fixed3x3: public SimpleType<float,3*3>{
  public:
  Fixed3x3(Document* d, XmlElement* h = 0):SimpleType<float,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed3x4
class Fixed3x4: public SimpleType<float,3*4>{
  public:
  Fixed3x4(Document* d, XmlElement* h = 0):SimpleType<float,3*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed4x1
class Fixed4x1: public SimpleType<float,4*1>{
  public:
  Fixed4x1(Document* d, XmlElement* h = 0):SimpleType<float,4*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed4x2
class Fixed4x2: public SimpleType<float,4*2>{
  public:
  Fixed4x2(Document* d, XmlElement* h = 0):SimpleType<float,4*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed4x3
class Fixed4x3: public SimpleType<float,4*3>{
  public:
  Fixed4x3(Document* d, XmlElement* h = 0):SimpleType<float,4*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// fixed4x4
class Fixed4x4: public SimpleType<float,4*4>{
  public:
  Fixed4x4(Document* d, XmlElement* h = 0):SimpleType<float,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

/*
sampler1D, sampler2D, sampler3D, samplerCUBE, samplerDEPTH and samplerRECT are
implemented in their own header and source files in FX
*/

// enum
class Enumeration: public SimpleType<std::string,1>{
  public:
  Enumeration(Document* d, XmlElement* h = 0):SimpleType<std::string,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// string
class String: public SimpleType<std::string,1>{
  public:
  String(Document* d, XmlElement* h = 0):SimpleType<std::string,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

/* array, usertype are implemented in their own header and source files in FX*/

/* GLES Parameter Elements (gles_param_group) */

// bool /*already implemented*/
// bool2 /*already implemented*/
// bool3 /*already implemented*/
// bool4 /*already implemented*/
// int /*already implemented*/
// int2 /*already implemented*/
// int3 /*already implemented*/
// int4 /*already implemented*/
// float /*already implemented*/
// float2 /*already implemented*/
// float3 /*already implemented*/
// float4 /*already implemented*/

// float1x1
class Float1x1: public SimpleType<float,1*1>{
  public:
  Float1x1(Document* d, XmlElement* h = 0):SimpleType<float,1*1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float1x2
class Float1x2: public SimpleType<float,1*2>{
  public:
  Float1x2(Document* d, XmlElement* h = 0):SimpleType<float,1*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float1x3
class Float1x3: public SimpleType<float,1*3>{
  public:
  Float1x3(Document* d, XmlElement* h = 0):SimpleType<float,1*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float1x4
class Float1x4: public SimpleType<float,1*4>{
  public:
  Float1x4(Document* d, XmlElement* h = 0):SimpleType<float,1*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float2x1 /*already implemented*/
// float2x2 /*already implemented*/
// float2x3 /*already implemented*/
// float2x4 /*already implemented*/
// float3x1 /*already implemented*/
// float3x2 /*already implemented*/
// float3x3 /*already implemented*/
// float3x4 /*already implemented*/
// float4x1 /*already implemented*/
// float4x2 /*already implemented*/
// float4x3 /*already implemented*/
// float4x4 /*already implemented*/
// Sampler2D /*implemented in its own header and source files*/
// Enumeration /*already implemented*/

/* GLES2 Parameter Elements (gles2_value_group) */

// bool /*already implemented*/

// bvec2
class Bvec2: public SimpleType<bool,2>{
  public:
  Bvec2(Document* d, XmlElement* h = 0):SimpleType<bool,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bvec3
class Bvec3: public SimpleType<bool,3>{
  public:
  Bvec3(Document* d, XmlElement* h = 0):SimpleType<bool,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// bvec4
class Bvec4: public SimpleType<bool,4>{
  public:
  Bvec4(Document* d, XmlElement* h = 0):SimpleType<bool,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// int /*already implemented*/

// ivec2
class Ivec2: public SimpleType<int,2>{
  public:
  Ivec2(Document* d, XmlElement* h = 0):SimpleType<int,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// ivec3
class Ivec3: public SimpleType<int,3>{
  public:
  Ivec3(Document* d, XmlElement* h = 0):SimpleType<int,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// ivec4
class Ivec4: public SimpleType<int,4>{
  public:
  Ivec4(Document* d, XmlElement* h = 0):SimpleType<int,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// float /*already implemented*/

// vec2
class Vec2: public SimpleType<float,2>{
  public:
  Vec2(Document* d, XmlElement* h = 0):SimpleType<float,2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// vec3
class Vec3: public SimpleType<float,3>{
  public:
  Vec3(Document* d, XmlElement* h = 0):SimpleType<float,3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// vec4
class Vec4: public SimpleType<float,4>{
  public:
  Vec4(Document* d, XmlElement* h = 0):SimpleType<float,4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// mat2
class Mat2: public SimpleType<float,2*2>{
  public:
  Mat2(Document* d, XmlElement* h = 0):SimpleType<float,2*2>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// mat3
class Mat3: public SimpleType<float,3*3>{
  public:
  Mat3(Document* d, XmlElement* h = 0):SimpleType<float,3*3>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

// mat4
class Mat4: public SimpleType<float,4*4>{
  public:
  Mat4(Document* d, XmlElement* h = 0):SimpleType<float,4*4>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

/* sampler2D, sampler3D, samplerCUBE, samplerDEPTH, array, usertype are
implemented in their own header and source files*/

/* Effect Parameter Elements (fx_newparam_group) */
// bool /*already implemented*/
// bool2 /*already implemented*/
// bool3 /*already implemented*/
// bool4 /*already implemented*/
// int /*already implemented*/
// int2 /*already implemented*/
// int3 /*already implemented*/
// int4 /*already implemented*/
// float /*already implemented*/
// float2 /*already implemented*/
// float3 /*already implemented*/
// float4 /*already implemented*/
// float2x1 /*already implemented*/
// float2x2 /*already implemented*/
// float2x3 /*already implemented*/
// float2x4 /*already implemented*/
// float3x1 /*already implemented*/
// float3x2 /*already implemented*/
// float3x3 /*already implemented*/
// float3x4 /*already implemented*/
// float4x1 /*already implemented*/
// float4x2 /*already implemented*/
// float4x3 /*already implemented*/
// float4x4 /*already implemented*/
/* sampler1D, sampler2D, sampler3D, samplerCUBE, samplerRECT, samplerDEPTH,
are implemented in their own header and source files
*/

// Enumeration /*already implemented*/

/* Instance_Effect Parameter Elements (fx_setparam_group) */
// bool /*already implemented*/
// bool2 /*already implemented*/
// bool3 /*already implemented*/
// bool4 /*already implemented*/
// int /*already implemented*/
// int2 /*already implemented*/
// int3 /*already implemented*/
// int4 /*already implemented*/
// float /*already implemented*/
// float2 /*already implemented*/
// float3 /*already implemented*/
// float4 /*already implemented*/
// float2x1 /*already implemented*/
// float2x2 /*already implemented*/
// float2x3 /*already implemented*/
// float2x4 /*already implemented*/
// float3x1 /*already implemented*/
// float3x2 /*already implemented*/
// float3x3 /*already implemented*/
// float3x4 /*already implemented*/
// float4x1 /*already implemented*/
// float4x2 /*already implemented*/
// float4x3 /*already implemented*/
// float4x4 /*already implemented*/
// Enumeration /*already implemented*/
/* sampler_image, sampler_states are implemented in their own header and source files*/


/*other simple Types*/

//list_of_names_type
class List_of_names_type: public SimpleArrayType<std::string>{
  public:
  List_of_names_type(Document* d, XmlElement* h = 0):SimpleArrayType<std::string>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//list_of_tokens_type
class List_of_tokens_type: public SimpleArrayType<std::string>{
  public:
  List_of_tokens_type(Document* d, XmlElement* h = 0):SimpleArrayType<std::string>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//sid_type
class Sid_type: public SimpleType<std::string,1>{
  public:
  Sid_type(Document* d, XmlElement* h = 0):SimpleType<std::string,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//sidref_type
class Sidref_type: public SimpleType<std::string,1>{
  public:
  Sidref_type(Document* d, XmlElement* h = 0):SimpleType<std::string,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};

//urifragment_type
class Urifragment_type: public SimpleType<std::string,1>{
  public:
  Urifragment_type(Document* d, XmlElement* h = 0):SimpleType<std::string,1>(d,h){
  }
  static const std::string Name;
  std::string getName(){
    return Name;
  }
};


/*param or value types*/
//all param or value types are implemented as makro
/*common_sidref_or_param_type*/
#define PINA_COMMON_SIDREF_OR_PARAM_TYPE SIDREF, Param
/*common_float_or_param_type*/
#define PINA_COMMON_FLOAT_OR_PARAM_TYPE Float, Param
/*common_float2_or_param_type*/
#define PINA_COMMON_Float2_OR_PARAM_TYPE Float2, Param
/*common_int_or_param_type*/
#define PINA_COMMON_INT_OR_PARAM_TYPE Int, Param
/*common_bool_or_param_type*/
#define PINA_COMMON_BOOL_OR_PARAM_TYPE Bool, Param

/* Makro for GLSL Parameter Elements (glsl_value_group) */
#define PINA_GLSL_PARAMETER_ELEMENTS \
Bool,Bool2,Bool3,Bool4,\
Int,Int2,Int3,Int4,Float,Float2,Float3,Float4,\
Float2x2,Float3x3,Float4x4,\
Sampler1D,Sampler2D,Sampler3D,\
SamplerCUBE,SamplerRECT,SamplerDEPTH,Enumeration,Array

/* Makro for CG Parameter Elements (cg_param_group) */
#define PINA_CG_PARAMETER_ELEMENTS Bool,Bool2,Bool3,Bool4,Bool2x1,Bool2x2,Bool2x3,Bool2x4,Bool3x1,Bool3x2,Bool3x3,Bool3x4,Bool4x1,Bool4x2,Bool4x3,Bool4x4,\
Int,Int2,Int3,Int4,Int2x1,Int2x2,Int2x3,Int2x4,Int3x1,Int3x2,Int3x3,Int3x4,Int4x1,Int4x2,Int4x3,Int4x4,\
Float,Float2,Float3,Float4,Float2x1,Float2x2,Float2x3,Float2x4,Float3x1,Float3x2,Float3x3,Float3x4,Float4x1,Float4x2,Float4x3,Float4x4,\
Half,Half2,Half3,Half4,Half2x1,Half2x2,Half2x3,Half2x4,Half3x1,Half3x2,Half3x3,Half3x4,Half4x1,Half4x2,Half4x3,Half4x4,\
Fixed,Fixed2,Fixed3,Fixed4,Fixed1x1,Fixed2x1,Fixed2x2,Fixed2x3,Fixed2x4,Fixed3x1,Fixed3x2,Fixed3x3,Fixed3x4,Fixed4x1,Fixed4x2,Fixed4x3,Fixed4x4,\
Sampler1D,Sampler2D,Sampler3D,SamplerCUBE,SamplerRECT,SamplerDEPTH,Enumeration,String,Array,Usertype

/* Makro for GLES Parameter Elements (gles_param_group) */
#define PINA_GLES_PARAMETER_ELEMENTS Bool,Bool2,Bool3,Bool4,\
Int,Int2,Int3,Int4,Float,\
Float2,Float3,Float4,Float1x1,Float1x2,Float1x3,Float1x4,Float2x1,Float2x2,Float2x3,Float2x4,Float3x1,Float3x2,Float3x3,Float3x4,Float4x1,Float4x2,Float4x3,Float4x4,\
Sampler2D,Enumeration

/* Makro for GLES2 Parameter Elements (gles2_value_group) */
#define PINA_GLES2_PARAMETER_ELEMENTS Bool,Bvec2,Bvec3,Bvec4,\
Int,Ivec2,Ivec3,Ivec4,\
Float,Vec2,Vec3,Vec4,\
Mat2,Mat3,Mat4\
,Sampler2D,Sampler3D,SamplerCUBE,SamplerDEPTH,Array,Usertype

/* Makro for Effect Parameter Elements (fx_newparam_group) */
#define PINA_EFFECT_PARAMETER_ELEMENTS Bool,Bool2,Bool3,Bool4,\
Int,Int2,Int3,Int4,\
Float,Float2,Float3,Float4,Float2x1,Float2x2,Float2x3,Float2x4,Float3x1,Float3x2,Float3x3,Float3x4,Float4x1,Float4x2,Float4x3,Float4x4,\
Sampler1D,Sampler2D,Sampler3D,SamplerCUBE,SamplerRECT,SamplerDEPTH,Enumeration

/* Makro for Instance_Effect Parameter Elements (fx_setparam_group) */
#define PINA_INSTANCE_EFFECT_PARAMETER_ELEMENTS Bool,Bool2,Bool3,Bool4,\
Int,Int2,Int3,Int4,\
Float,Float2,Float3,Float4,Float2x1,Float2x2,Float2x3,Float2x4,Float3x1,Float3x2,Float3x3,Float3x4,Float4x1,Float4x2,Float4x3,Float4x4,\
Enumeration,Sampler_image,Sampler_states

/*unique simple types*/
#define PINA_UNIQUE_SIMPLE_TYPES \
Bool, Bool2, Bool2x1, Bool2x2, Bool2x3, Bool2x4, Bool3, Bool3x1, Bool3x2, Bool3x3, Bool3x4, Bool4, Bool4x1, Bool4x2, Bool4x3, Bool4x4,\
Bvec2, Bvec3, Bvec4,\
Array, Sampler1D, Sampler2D, Sampler3D, SamplerCUBE, SamplerDEPTH, SamplerRECT, Sampler_image, Sampler_states,\
Usertype, Enumeration,\
Fixed, Fixed2, Fixed3x1, Fixed3x2, Fixed3x3, Fixed3x4, Fixed4x1, Fixed4x2, Fixed4x3, Fixed4x4,\
Float, Float1x1, Float1x2, Float1x3, Float1x4, Float2, Float2x1, Float2x2, Float2x3, Float2x4, Float3, Float3x1, Float3x2, Float3x3, Float3x4, Float4, Float4x1, Float4x2, Float4x3, Float4x4,\
Half, Half2, Half2x1, Half2x2, Half2x3, Half2x4, Half3, Half3x1, Half3x2, Half3x3, Half3x4, Half4, Half4x1, Half4x2, Half4x3, Half4x4, Int, Int2, Int2x1, Int2x2, Int2x3, Int2x4, Int3, Int3x1, Int3x2, Int3x3, Int3x4, Int4, Int4x1, Int4x2, Int4x3, Int4x4, Ivec2, Ivec3, Ivec4, Mat2, Mat3, Mat4, String, Vec2, Vec3, Vec4, Fixed1x1, Fixed2x1, Fixed2x2, Fixed2x3, Fixed2x4, Fixed3, Fixed4


}/*PINA_NAMESPACE*/

#endif
