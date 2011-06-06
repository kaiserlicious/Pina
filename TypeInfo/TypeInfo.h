
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

#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include "../Config.h"
#include <string>
#include <typeinfo>

#define THIS TypeInfo
namespace PINA_NAMESPACE{

class THIS{
  public:
  THIS();
  THIS(const THIS&);
  THIS(const std::type_info&);
  /*
  template<typename T>
  THIS(T):t_info(&typeid(T)){
  }
  */
  std::string name(){
    return std::string(t_info->name());
  }

  THIS& operator = (const std::type_info& type){
    t_info = &type;
    return *this;
  }

  bool operator == (THIS compare) const{
    return *t_info == *compare.t_info;
  }

  bool operator != (THIS compare) const {
    return *t_info != *compare.t_info;
  }

  bool operator < (THIS compare) const{
    return t_info->before(*compare.t_info);
  }

  private:
  const std::type_info* t_info;

};

}/*PINA_NAMESPACE*/

#undef THIS
#endif
