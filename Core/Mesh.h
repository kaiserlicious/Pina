
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

#ifndef COLLADA_MESH_H
#define COLLADA_MESH_H

#include "../Element.h"
#include "Source.h"
#include "Vertices.h"
#include "Lines.h"
#include "Linestrips.h"
#include "Polygons.h"
#include "Polylist.h"
#include "Triangles.h"
#include "Trifans.h"
#include "Tristrips.h"
#include "Extra.h"

#define THIS Mesh
namespace PINA_NAMESPACE{

/**
@brief Describes a geometric mesh of primitives
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
  Vertices,
  Lines,
  Linestrips,
  Polygons,
  Polylist,
  Triangles,
  Trifans,
  Tristrips,
  Extra
  >::List Types;

  /* attributes */

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
