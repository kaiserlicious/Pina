
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

#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"
#include <math.h>
#include <sstream>
#include <iostream>

namespace PINA_NAMESPACE{
namespace Math{

template<typename T,unsigned int size>
class Vector{

  public:
  Vector(){}

  //initialize the Vector with one value
  Vector(const T& v){
    for(unsigned int i=0;i<size;i++){
      vector[i] = v;
    }
  }
  
  //initialize from array
  Vector(const T* p){
    for(unsigned int i=0;i<size;i++){
      vector[i] = p[i];
    }
  }
  
  //initialize from a Matrix
  Vector(Matrix<T,size, 1> const& matrix){
    for(unsigned int i=0;i<size;i++){
      vector[i] = matrix.get(i,0);
    }
  }

  //convert to std::string
  const std::string toString() const{
    std::stringstream str;
    for(unsigned int i=0;i<size-1;i++){
      str << vector[i] << ' ';
    }
    str << vector[size-1];
    return str.str();
  }

  //convert to Matrix
  const Matrix<T,size,1> toMatrix() const{
    Matrix<T,size,1> matrix;
    for(unsigned int i=0; i<size; i++){
      matrix.get(i,0) = vector[i];
    }
    return matrix;
  }

  // get the euclidean length
  const T length() const{
    T t=vector[0]*vector[0];
    for(unsigned int i=1;i<size;i++){
      t = t+vector[i]*vector[i];
    }
    return sqrt(t);
  }

  void normalize(){
    T scale = length();
    if( scale != 0){
      for(unsigned int i=0;i<size;i++){
        vector[i] = vector[i]/scale;
      }
    }
  }

  // operator [ ]
  T& operator[ ](const unsigned int index){
    return vector[index];
  }

  // operator [ ] const
  T const& operator[ ](const unsigned int index) const{
    return vector[index];
  }

  // operator =
  const Vector<T,size>& operator = (const Vector<T,size>& v){
    for(unsigned int i=0; i<size; i++){
      vector[i]=v[i];
    }
    return *this;
  }

  // operator * (for Vectors)
  const T operator*(const Vector<T,size>& v) const{
    T t=v[0]*vector[0];
    for(unsigned int i=1; i<size; i++){
      t=t+v[i]*vector[i];
    }
    return t;
  }

  // operator + (for Vectors)
  const Vector<T,size> operator+(const Vector<T,size>& v) const{
    Vector<T,size> out;
    for(unsigned int i=0; i<size; i++){
      out[i]=v[i]+vector[i];
    }
    return out;
  }

  // operator - (for Vectors)
  const Vector<T,size> operator-(const Vector<T,size>& v) const{
    Vector<T,size> out;
    for(unsigned int i=0; i<size; i++){
      out[i]=v[i]-vector[i];
    }
    return out;
  }

  // operator ==
  bool operator == (const Vector<T,size>& v) const{
    for(unsigned int i=0; i<size; i++){
      if(v[i] != vector[i]){return false;}
    }
    return true;
  }

  // operator !=
  bool operator != (const Vector<T,size>& v) const{
    for(unsigned int i=0; i<size; i++){
      if(v[i] != vector[i]){return true;}
    }
    return false;
  }

  private:
  T vector[size];
};

  // compute the cross product from two three-dimensional Vectors
  template<typename T>
  static const Vector<T,3> crossProduct(Vector<T,3> const& a,Vector<T,3> const& b){
    Vector<T,3> out;
    out[0]= a[1] * b[2] - a[2]*b[1];
    out[1]= a[2] * b[0] - a[0]*b[2];
    out[2]= a[0] * b[1] - a[1]*b[0];
    return out;
  }

// operator * (for scalars)
template<typename T,unsigned int size>
const Vector<T,size> operator*(Vector<T,size> vector,const T& scale){
  Vector<T,size> v_out;
  for(unsigned int i=0; i<size; i++){
    v_out[i]=vector[i]*scale;
  }
  return v_out;
}

template<typename T,unsigned int size>
const Vector<T,size> operator*(const T& scale,Vector<T,size> vector){
  Vector<T,size> v_out;
  for(unsigned int i=0; i<size; i++){
    v_out[i]=vector[i]*scale;
  }
  return v_out;
}

// operator * (for matrix*vector)
template<typename T,unsigned int VEC_SIZE,unsigned int ROWS>
const Vector<T,ROWS> operator*(Matrix<T,ROWS,VEC_SIZE> matrix,Vector<T,VEC_SIZE> vec){
  Vector<T,ROWS> vec_out;
  T temp=0;
  for(unsigned int i=0;i<ROWS;i++){
    for(unsigned int j=0;j<VEC_SIZE;j++){
      temp=temp+matrix.get(i,j)*vec[j];
    }
    vec_out[i]=temp;
    temp=0;
  }
  return vec_out;
}

// operator <<
template<typename T,unsigned int size>
std::ostream& operator<<(std::ostream& str, Vector<T,size>vec){
 for(unsigned int i=0;i<size;i++){
    str << vec[i] << ' ';
  }
  return str;
}

}//Math namespace
}//PINA_NAMESPACE
#endif
