
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

#ifndef COLLADA_SAMPLER1D_H
#define COLLADA_SAMPLER1D_H

#include "../Element.h"


#define THIS Sampler1D

namespace PINA_NAMESPACE{

class Extra;





class Instance_image;
class Texcoord;
class Wrap_s;
class Wrap_t;
class Wrap_p;
class Minfilter;
class Magfilter;
class Mipfilter;
class Border_color;
class Mip_max_level;
class Mip_min_level;
class Mip_bias;
class Max_anisotropy;

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
  Instance_image,
  Texcoord,
  Wrap_s,
  Wrap_t,
  Wrap_p,
  Minfilter,
  Magfilter,
  Mipfilter,
  Border_color,
  Mip_max_level,
  Mip_min_level,
  Mip_bias,
  Max_anisotropy,
  Extra
  >::List Types;

  /* attributes */

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_SAMPLER1D_H*/
