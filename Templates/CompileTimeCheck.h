
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

#ifndef COMPILE_TIME_CHECK
#define COMPILE_TIME_CHECK

#include "../Config.h"

namespace PINA_NAMESPACE{

  template<bool> class StaticCheck{};
  template<> class StaticCheck<true>{
    public: static bool eval;
  };



  template<typename Error>
  class Check{
  public:
    static void eval(bool exp) throw(Error){
      if(!exp){ throw Error(); }
    }
    static void eval(bool exp,std::string message) throw(Error){
      if(!exp){ throw Error(message); }
    }
  };

}//PINA_NAMESPACE
#endif
