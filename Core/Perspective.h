
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

#ifndef COLLADA_PERSPECTIVE_H
#define COLLADA_PERSPECTIVE_H

#include "../Element.h"
#include "Xfov.h"
#include "Yfov.h"
#include "Aspect_ratio.h"
#include "Znear.h"
#include "Zfar.h"

#define THIS Perspective
namespace PINA_NAMESPACE{

/**
@brief Describes the view of a perspective camera.
*/
class THIS: public Element{
  public:
  THIS(XmlElement* h = 0);
  std::string getName() const;
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Xfov,
  Yfov,
  Aspect_ratio,
  Znear,
  Zfar
  >::List Types;

  /* attributes */

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
