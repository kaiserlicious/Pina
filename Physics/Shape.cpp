
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

#include "Shape.h"
#include "../Templates/Ordering.h"

#include "../Core/Extra.h"
#include "../Core/Instance_geometry.h"
#include "../Core/Rotate.h"
#include "../Core/Translate.h"
#include "../Core/Extra.h"

#include "Hollow.h"
#include "Mass.h"
#include "Density.h"
#include "Physics_material.h"
#include "Instance_physics_material.h"
#include "Plane.h"
#include "Box.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Capsule.h"

#if PINA_PHYSICS
#define THIS Shape
namespace PINA_NAMESPACE{
#if PINA_SUBNAMESPACES
//namespace PINA_PHYSICS_NAMESPACE{
#endif /*PINA_SUBNAMESPACES*/

THIS::THIS(Document* d, TiXmlHandle h):Element(d,h){

  /* attributes */

  /* children */
  buildChildren(Types());

  /* data */

}

std::string THIS::getName(){
  return Name;
}

void THIS::order(){
  /* build the lookuptable */
  std::map<TypeInfo,unsigned int> priorityLookup;
  priorityLookup[TypeInfo(typeid(Hollow))]                     =13;
  priorityLookup[TypeInfo(typeid(Mass))]                       =12;
  priorityLookup[TypeInfo(typeid(Density))]                    =11;
  priorityLookup[TypeInfo(typeid(Physics_material))]           =10;
  priorityLookup[TypeInfo(typeid(Instance_physics_material))]  =9;
  priorityLookup[TypeInfo(typeid(Plane))]                      =8;
  priorityLookup[TypeInfo(typeid(Box))]                        =7;
  priorityLookup[TypeInfo(typeid(Sphere))]                     =6;
  priorityLookup[TypeInfo(typeid(Cylinder))]                   =5;
  priorityLookup[TypeInfo(typeid(Capsule))]                    =4;
  priorityLookup[TypeInfo(typeid(Instance_geometry))]          =3;
  priorityLookup[TypeInfo(typeid(Rotate))]                     =2;
  priorityLookup[TypeInfo(typeid(Translate))]                  =2;
  priorityLookup[TypeInfo(typeid(Extra))]                      =1;

  /* sort the children with the custom funtor and lookuptable */
  children.sort(PriorityOrdering(priorityLookup));
}

const std::string THIS::Name = "shape";

THIS::~THIS(){
}

#if PINA_SUBNAMESPACES
//}/*PINA_PHYSICS_NAMESPACE*/
#endif /*PINA_SUBNAMESPACES*/
}/*PINA_NAMESPACE*/
#undef THIS
#endif /*PINA_PHYSICS*/

