
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

#ifndef COLLADA_EVALUATE_SCENE_H
#define COLLADA_EVALUATE_SCENE_H

#include "../Element.h"
#include "Asset.h"
#if PINA_FX
#include "../FX/Render.h" //in FX
#endif
#include "Extra.h"

/**
@brief Describes how to evaluate a visual scene
*/
#define THIS Evaluate_scene
namespace PINA_NAMESPACE{

class THIS: public Element{
  public:
  THIS(Document* d, TiXmlHandle h = TiXmlHandle(0));
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons<
  Asset,
  //Render,
  Extra
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;
  Attribute<std::string> attrib_sid;
  Attribute<bool> attrib_enable;

  private:

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif