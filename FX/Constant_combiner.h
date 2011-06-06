
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

#ifndef COLLADA_CONSTANT_COMBINER_H
#define COLLADA_CONSTANT_COMBINER_H

#include "../Element.h"
#include "../Math/Math.h"

#if PINA_FX
#define THIS Constant_combiner

namespace PINA_NAMESPACE{
#if PINA_SUBNAMESPACES
//namespace PINA_FX_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/

/**
@brief
*/
class THIS: public Element{
  public:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));
  std::string getName();
  ~THIS();
  /*TiXmlElement* toTiXmlElement();*/
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef NullType Types;

  /* attributes */
  Attribute<Math::Vector<float,4> > attrib_value;
  Attribute<std::string> attrib_param;

  /* data */

private:

};

#if PINA_SUBNAMESPACES
//}/*PINA_FX_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_FX*/
#endif /*COLLADA_CONSTANT_COMBINER_H*/