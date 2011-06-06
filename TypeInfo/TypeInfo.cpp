
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

#include "TypeInfo.h"

#define THIS TypeInfo
namespace PINA_NAMESPACE{

THIS::THIS():t_info(&typeid(void)){
}

THIS::THIS(const THIS& copy){
  t_info = copy.t_info;
}

THIS::THIS(const std::type_info& type){
  t_info = &type;
}

}/*PINA_NAMESPACE*/

#undef THIS
