
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

#ifndef COLLADA_SETPARAM_H
#define COLLADA_SETPARAM_H

#include "../Element.h"
#include "../Types/SimpleTypes.h"
#include "../Templates/TypelistConstructor64to128.h"

#define THIS Setparam
namespace PINA_NAMESPACE{

/**
@brief Set a previously defined parameter to a new value.
*/
class THIS: public Element{
  public:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons64to128<
  PINA_UNIQUE_SIMPLE_TYPES
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_ref;

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
