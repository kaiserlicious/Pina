
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

#ifndef PINA_LOG
#define PINA_LOG

#include "../Config.h"
#include "../Log/Log.h"
#include "../Types/Enum.h"

#include <string>

#define THIS LogEntry

namespace PINA_NAMESPACE{

class AbstractLogEntry{

  public:
  AbstractLogEntry( std::string e, std::string m):elementName(e),message(m){
  }

  virtual Enum::DebugLevel getLevel()=0;

  std::string getElementName(){
    return elementName;
  }

  std::string getMessage(){
    return message;
  }

  private:
  std::string elementName;
  std::string message;
};

template<Enum::DebugLevel level>
class THIS: public AbstractLogEntry{

  public:

  THIS( std::string e, std::string m):AbstractLogEntry(e,m){
  }

  Enum::DebugLevel getLevel(){
    return level;
  }

};

}/*PINA_NAMESPACE*/

#undef THIS
#endif
