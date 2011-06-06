
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

#include "Utils.h"
#include <string>

namespace PINA_NAMESPACE{

namespace Utils{

  /*
  std::list<std::string> splitString(std::string c, std::string str){
    std::string substring;
    std::list<std::string> result;
    std::string::size_type index;
    while((index = str.find_first_of(c)) != std::string::npos)
    {
      substring = str.substr(0 , index);
      if (substring.size() != 0)
      {
        result.push_back(substring);
      }
      str.erase(0,index+1);
    }
    if (str.size() > 0)
    {
      result.push_back(str);
    }
    return result;
  }
   */
  
}/*Utils*/
  
}/*PINA_NAMESPACE*/
