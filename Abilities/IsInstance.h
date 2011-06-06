
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

#ifndef COLLADA_IS_INSTANCE_H
#define COLLADA_IS_INSTANCE_H

#include "../Document.h"
#include "../Element.h"
#include "../Config.h"

#define THIS IsInstance
namespace PINA_NAMESPACE{

template<typename T>
class THIS{
  public:
  ~THIS(){
  }

  /**
  *@brief Get the instanciated Element
  *
  *Returns a pointer to the instanciated element. In case an error occurred the function will return 0.
  **/
  T* getElement(){
    std::string url;
    if(self->queryAttributeValue("url",url)){
      return dynamic_cast<T*>(self->document->getByURL(url));
    }
    else{
      return 0;
    }
  }

  protected:
  THIS(Element* s):self(s){

  }

  private:
  Element* self;

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
