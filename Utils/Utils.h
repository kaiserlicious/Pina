
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

#ifndef PINA_UTILS_H
#define PINA_UTILS_H

#include "../Config.h"
#include "../Math/Math.h"
#include <sstream>
#include <vector>
#include <list>

namespace PINA_NAMESPACE{

namespace Utils{

  template<typename T>
  void fromString(T& t,std::string str){
    std::istringstream stream(str);
    stream >> t;
  }
  
  template<typename T, unsigned int size>
  void fromString(Math::Vector<T,size>& vec,std::string str){
    std::istringstream stream(str);
    unsigned int i=0;
    while((i < size) && ((stream.rdstate() & std::istringstream::eofbit ) == 0)){
      stream >> vec[i];
      i++;
    }
  }
  
  template<typename T, unsigned int width, unsigned int height>
  void fromString(Math::Matrix<T,width,height>& matrix,std::string str){
    std::istringstream stream(str);
    unsigned int i=0;
    while((i < width*height) && ((stream.rdstate() & std::istringstream::eofbit ) == 0)){
      stream >> matrix[i];
      i++;
    }
  }
  
  template<template<typename,typename> class Container,typename T,typename ALLOC>
  void fromString(Container<T,ALLOC>& vec,std::string str){
    std::istringstream stream(str);
    while((stream.rdstate() & std::istringstream::eofbit ) == 0){
      vec.push_back(T());
      stream >> vec.back();
    }
  }
  
  template<template<typename,typename> class Container,typename T,typename ALLOC>
  std::string toString(const Container<T,ALLOC>& con){
    std::ostringstream stream;
    typename Container<T,ALLOC>::iterator iter;
    for(iter = con.begin();iter != con.end(); iter++){
      stream << (*iter);
    }
    return stream.str();
  }
  
  template<typename T>
	std::string toString(const T& t){
    std::stringstream stream;
    stream << t;
    return stream.str();
  };
  

//  std::list<std::string> splitString(std::string c, std::string str);

/*
static void trim(std::string& str, char c = ' '){
  std::string::size_type index = str.find_first_not_of(c);
  str.erase(0,index);
  index = str.find_last_not_of(c);
  str.erase(index+1);
}

static void removeDuplicateBlanks(std::string& str){
  std::string::size_type index = str.find("  ");
  while(index != std::string::npos){
    str.erase(index,1);
    index = str.find("  ",index);
  }
}
*/
 
}/*Utils*/

}/*PINA_NAMESPACE*/
#endif
