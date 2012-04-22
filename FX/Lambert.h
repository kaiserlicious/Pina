
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

#ifndef COLLADA_LAMBERT_H
#define COLLADA_LAMBERT_H

#include "../Element.h"


#define THIS Lambert

namespace PINA_NAMESPACE{




class Emission;
class Ambient_fx;
class Diffuse;
class Reflective;
class Reflectivity;
class Transparent;
class Transparency;
class Index_of_refraction;

/**
@brief
*/
class THIS: public Element{
  public:
  THIS(XmlElement* h = 0);
  std::string getName() const;
  ~THIS();
  /*XmlElement* toXmlElement();*/
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Emission,
  Ambient_fx,
  Diffuse,
  Reflective,
  Reflectivity,
  Transparent,
  Transparency,
  Index_of_refraction
  >::List Types;

  /* attributes */

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_LAMBERT_H*/
