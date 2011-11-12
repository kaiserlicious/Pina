
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

#ifndef COLLADA_SPLINE_H
#define COLLADA_SPLINE_H

#include "../Element.h"
#include "Source.h"
#include "Control_vertices.h"
#include "Extra.h"

#define THIS Spline
namespace PINA_NAMESPACE{

/**
@brief Describes a spline.
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
  Source,
  Control_vertices,
  Extra
  >::List Types;

  /* attributes */
  bool attrib_closed;

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
