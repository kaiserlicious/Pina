
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

#ifndef COLLADA_EFFECT_H
#define COLLADA_EFFECT_H

#include "../Element.h"


#define THIS Effect

namespace PINA_NAMESPACE{

class Asset;
class Annotate;
class Newparam;
class Extra;





class Profile_BRIDGE;
class Profile_CG;
class Profile_GLES;
class Profile_GLES2;
class Profile_GLSL;
class Profile_COMMON;

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
  typedef TL::Cons<
  Asset,
  Annotate,
  Newparam,
  Extra,
  Profile_BRIDGE,
  Profile_CG,
  Profile_GLES,
  Profile_GLES2,
  Profile_GLSL,
  Profile_COMMON
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;

  /* data */

private:

};




}/*PINA_NAMESPACE*/
#undef THIS

#endif /*COLLADA_EFFECT_H*/
