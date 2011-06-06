
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

#ifndef COLLADA_NURBS_SURFACE_H
#define COLLADA_NURBS_SURFACE_H

#include "../Element.h"


#define THIS Nurbs_surface

namespace PINA_NAMESPACE{

class Source;
class Control_vertices;
class Extra;






/**
@brief Describes a NURBS surface in 3D space.
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
  typedef TL::Cons<
      Source,
      Control_vertices,
      Extra
      >::List Types;

  /* attributes */
  Attribute<unsigned int> attrib_degree_u;
  Attribute<bool> attrib_closed_u;
  Attribute<unsigned int> attrib_degree_v;
  Attribute<bool> attrib_closed_v;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_NURBS_SURFACE_H*/
