
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

#ifndef COLLADA_INPUT_SHARED_H
#define COLLADA_INPUT_SHARED_H

#include "../Element.h"
#include "Source.h"

#define THIS Input_shared
namespace PINA_NAMESPACE{

/**
@brief Describes the sematics and source of an input
*/
class THIS: public Element{
  public:
  THIS(XmlElement* h = 0);
  std::string getName() const;
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef NullType Types;

  /* attributes */
  Attribute<unsigned int> attrib_offset;
  Attribute<unsigned int> attrib_set;
  Attribute<Enum::Semantic> attrib_semantic;
  Attribute<std::string> attrib_source;

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
