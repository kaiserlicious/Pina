
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

#ifndef COLLADA_NODE_H
#define COLLADA_NODE_H

#include "../Element.h"
#include "../Types/Enum.h"
#include "../Templates/TypelistConstructor16to32.h"

#define THIS Node
namespace PINA_NAMESPACE{

class Asset;
class Lookat;
class Matrix;
class Matrix;
class Rotate;
class Scale;
class Skew;
class Translate;
class Node;
class Extra;
class Instance_camera;
class Instance_controller;
class Instance_geometry;
class Instance_light;
class Instance_node;

/**
@brief Describes a node in the scenegraph
*/
class THIS: public Element{
  public:
   THIS(Document* d, XmlElement* h = 0);
  std::string getName();
  ~THIS();
  static const std::string Name;
  void order();
  STATIC_CHECKED_FUNCTIONS;
  typedef TL::Cons16to32<
  Asset,
  Lookat,
  Matrix,
  Rotate,
  Scale,
  Skew,
  Translate,
  Lookat,
  Matrix,
  Scale,
  Skew,
  Translate,
  Instance_camera,
  Instance_controller,
  Instance_geometry,
  Instance_light,
  Instance_node,
  Node,
  Extra
  >::List Types;

  /* attributes */
  Attribute<std::string> attrib_id;
  Attribute<std::string> attrib_name;
  Attribute<std::string> attrib_sid;
  Attribute<Enum::NodeType::Type> attrib_type;
  Attribute<std::string> attrib_layer;

  /*data*/

};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
