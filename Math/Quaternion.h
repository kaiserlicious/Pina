
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

#ifndef PINA_QUATERNION_H
#define PINA_QUATERNION_H

#include "Math.h"
#include <sstream>
#include <iostream>
#include "../Config.h"

namespace PINA_NAMESPACE{
namespace Math{


template<typename T>
class Quaternion{

public:

  Quaternion(){};

  Quaternion(T t0, T t1, T t2, T t3){
    values[0]=t0;
    values[1]=t1;
    values[2]=t2;
    values[3]=t3;
  }

  Vector<T,3> toVector(){
    Vector<T,3> result;
    result[0] = values[1];
    result[1] = values[2];
    result[2] = values[3];
    return result;
  }

  void constructRotation(Vector<T,3> axis, T degree){
    T radiantAngle = degree * M_PI/180;
    T sinAngle = sin(radiantAngle);

    values[0]= cos(radiantAngle);
    values[1]=axis[0]*sinAngle;
    values[2]=axis[1]*sinAngle;
    values[3]=axis[2]*sinAngle;
  }

  static Vector<T,3> quaternionRotation(Vector<T,3> vec,Vector<T,3> axis, T degree){
    float radiantAngle = degree * M_PI/180;
    float sinAngle = sin(radiantAngle);

    Quaternion<T> rotation(cos(radiantAngle),axis[0]*sinAngle,axis[1]*sinAngle,axis[2]*sinAngle);
    Quaternion<T> vector(0,vec[0],vec[1],vec[2]);
    Quaternion<T> result = rotation*vector*rotation.getConjugate();
    return result.toVector();
  }

  void conjugate(){
    values[1] = -values[1];
    values[2] = -values[2];
    values[3] = -values[3];
  }

  Quaternion<T> getConjugate(){
    Quaternion<T> result(values[0], -values[1], -values[2], -values[3]);
    return result;
  }

  T length(){
    return sqrt(values[0]*values[0] + values[1]*values[1] + values[2]*values[2] + values[3]*values[3]);
  }

  void normalize(){
    T l = length();
    if(l != 0){
    values[0] = values[0]/l;
    values[1] = values[1]/l;
    values[2] = values[2]/l;
    values[3] = values[3]/l;
    }
  }

  const Quaternion<T> inverse(){
    return (this->conjugate()) / (this->length() * this->length());
  }

  T&  operator [] (unsigned int i){
    return values[i];
  }

private:

  T values[4];

};

template<typename T>
const Quaternion<T> operator / (Quaternion<T> q, T t){
   return Quaternion<T>(q[0] / t, q[1] / t, q[2] / t, q[3] / t);
}

template<typename T>
const Quaternion<T> operator + (Quaternion<T> q1, Quaternion<T> q2){
   return Quaternion<T>(q1[0]+q2[0], q1[1]+q2[1], q1[2]+q2[2], q1[3]+q2[3]);
}

template<typename T>
const Quaternion<T> operator - (Quaternion<T> q1, Quaternion<T> q2){
   return Quaternion<T>(q1[0]-q2[0], q1[1]+q2[1], q1[2]+q2[2], q1[3]+q2[3]);
}

template<typename T>
const Quaternion<T> operator * (Quaternion<T> q1, Quaternion<T> q2){ 
  Quaternion<T> result;
    result[0] =
        q1[0]*q2[0] -
        q1[1]*q2[1] -
        q1[2]*q2[2] -
        q1[3]*q2[3];

    result[1] =
        q1[0]*q2[1] +
        q1[1]*q2[0] +
        q1[2]*q2[3] -
        q1[3]*q2[2];

    result[2] =
        q1[0]*q2[2] +
        q1[2]*q2[0] +
        q1[3]*q2[1] -
        q1[1]*q2[3];

    result[3] =
        q1[0]*q2[3] +
        q1[3]*q2[0] +
        q1[1]*q2[2] -
        q1[2]*q2[1];

    return result;
}

/** operator << **/
template<typename T>
std::ostream& operator<< (std::ostream& str, Quaternion<T> quat){
      str << quat[0] << " + " << quat[1] << " *i + " << quat[2] << " *j + " << quat[3] << " *k"   ;
    return str;
}

}//Math namespace
}//PINA_NAMESPACE
#endif
