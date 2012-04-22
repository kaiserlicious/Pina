
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

#include "Node.h"
#include "../Templates/Ordering.h"

#include "Asset.h"
#include "Lookat.h"
#include "Matrix.h"
#include "Matrix.h"
#include "Rotate.h"
#include "Scale.h"
#include "Skew.h"
#include "Translate.h"
#include "Node.h"
#include "Extra.h"
#include "Instance_camera.h"
#include "Instance_controller.h"
#include "Instance_geometry.h"
#include "Instance_light.h"
#include "Instance_node.h"

#define THIS Node
namespace PINA_NAMESPACE{

THIS::THIS(XmlElement* h):Element(h){
  /* attributes */
  createAttribute(attrib_id,"id");
  createAttribute(attrib_name,"name");
  createAttribute(attrib_sid,"sid");
  createAttribute(attrib_type,"type",Enum::NodeType::NODE);
  createAttribute(attrib_layer,"layer");//TODO save as std::list<std::string>

  /** children**/
  buildChildren(Types());
}

std::string THIS::getName() const {
  return Name;
}

/* to maintain the correct order of transformations we cant use the standard ordering mechanisim */
void THIS::order(){
  /* build the lookuptable */
  std::map<TypeInfo,unsigned int> priorityLookup;
  priorityLookup[TypeInfo(typeid(Asset))]               = 9;
  priorityLookup[TypeInfo(typeid(Lookat))]              = 8;
  priorityLookup[TypeInfo(typeid(Matrix))]              = 8;
  priorityLookup[TypeInfo(typeid(Translate))]           = 8;
  priorityLookup[TypeInfo(typeid(Rotate))]              = 8;
  priorityLookup[TypeInfo(typeid(Scale))]               = 8;
  priorityLookup[TypeInfo(typeid(Skew))]                = 8;
  priorityLookup[TypeInfo(typeid(Lookat))]              = 8;
  priorityLookup[TypeInfo(typeid(Matrix))]              = 8;
  priorityLookup[TypeInfo(typeid(Scale))]               = 8;
  priorityLookup[TypeInfo(typeid(Skew))]                = 8;
  priorityLookup[TypeInfo(typeid(Instance_camera))]     = 7;
  priorityLookup[TypeInfo(typeid(Instance_controller))] = 6;
  priorityLookup[TypeInfo(typeid(Instance_geometry))]   = 5;
  priorityLookup[TypeInfo(typeid(Instance_light))]      = 4;
  priorityLookup[TypeInfo(typeid(Instance_node))]       = 3;
  priorityLookup[TypeInfo(typeid(Node))]                = 2;
  priorityLookup[TypeInfo(typeid(Extra))]               = 1;

  /* sort the children with the custom funtor and lookuptable */
  children.sort(PriorityOrdering(priorityLookup));

}

const std::string THIS::Name = "node";

THIS::~THIS(){
}

}/*PINA_NAMESPACE*/
#undef THIS
