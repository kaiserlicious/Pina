
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

#ifndef COLLADA_ACCESSOR_H
#define COLLADA_ACCESSOR_H

#include <vector>
#include "../Element.h"

#define THIS Accessor
namespace PINA_NAMESPACE{

class Param_data_flow;
class Source;

/**
@brief Describes how to access a data source
*/
class THIS: public Element{
  public:
  THIS(Document* d, XmlElement* h = 0);
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Param_data_flow
  >::List Types;

  /* attributes */
  Attribute<unsigned int> attrib_count;
  Attribute<unsigned int> attrib_offset;
  Attribute<std::string> attrib_source;
  Attribute<unsigned int> attrib_stride;

  /* functions */
  std::vector<bool> getPattern();
  unsigned int getParamSize();
  unsigned int getOffset();
  std::string getSource();

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
