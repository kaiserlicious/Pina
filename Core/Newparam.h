
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

#ifndef COLLADA_NEWPARAM_H
#define COLLADA_NEWPARAM_H

#include "../Element.h"
#include "../Templates/TypelistConstructor64to128.h"
#include "../Types/SimpleTypes.h"

#define THIS Newparam
namespace PINA_NAMESPACE{

class  Annotate;
class  Semantic;
class  Modifier;
class  SIDREF;

/**
@brief A new parameter object
*/
class THIS: public Element{
  public:
  THIS(XmlElement* h = 0);
  std::string getName() const;
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Append<
      TL::Cons64to128<
      Annotate, //FX
      Semantic, //FX
      Modifier, //FX
      PINA_CG_PARAMETER_ELEMENTS, //FX
      PINA_GLSL_PARAMETER_ELEMENTS //FX
      >::List
      ,
      TL::Cons64to128<
      PINA_EFFECT_PARAMETER_ELEMENTS, //FX
      PINA_GLES_PARAMETER_ELEMENTS, //FX
      PINA_GLES2_PARAMETER_ELEMENTS, //FX
      Float, //FX
      Float2, //FX
      Float3, //FX
      Float4, //FX
      Sampler2D, //FX
      Float, //Kinematics
      Int, //Kinematics
      Bool, //Kinematics
      SIDREF //Kinematics
      >::List
   >::Result Types;

  /* attributes */
  Attribute<std::string> attrib_sid;

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
