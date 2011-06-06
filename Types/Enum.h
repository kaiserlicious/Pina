
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

#ifndef COLLADA_ENUM_H
#define COLLADA_ENUM_H

#include "../Config.h"

namespace PINA_NAMESPACE{

namespace Enum{

namespace Shader{
  enum Stage{
  TESSELATION,
  VERTEX,
  GEOMETRY,
  FRAGMENT,
  };
}/*namespace Shader*/

namespace Texenv{
  enum Operator{
    REPLACE,
    MODULATE,
    DECAL,
    BLEND,
    ADD
  };
} /*namespace Textenv*/

namespace Rgb{
  enum Operator{
  REPLACE,
  MODULATE,
  ADD,
  ADD_SIGNED,
  INTERPOLATE,
  SUBTRACT,
  DOT3_RGB,
  DOT3_RGBA,
  };
} /*namespace RGB*/

enum Modifier{
CONST,
UNIFORM,
VARYING,
STATIC,
VOLATILE,
EXTERN,
SHARED,
};

enum Filter{
NONE,
NEAREST,
LINEAR,
ANISOTROPIC,
};

enum Wrap{
WRAP,
MIRROR,
CLAMP,
BORDER,
MIRROR_ONCE,
};

enum Opaque{
A_ONE,
RGB_ZERO,
A_ZERO,
RGB_ONE,
};

enum Precision{
DEFAULT,
LOW,
MID,
HIGH,
MAX,
};

enum Range{
SNOR,
UNOR,
SINT,
UINT,
FLOAT,
};

enum Channel{
RGB,
RGBA,
RGBE,
L,
LA,
D,
};

enum Face{
POSITIVE_X,
NEGATIVE_X,
POSITIVE_Y,
NEGATIVE_Y,
POSITIVE_Z,
NEGATIVE_Z,
};

enum Operand{
  SRC_COLOR,
  ONE_MINUS_SRC_COLOR,
  SRC_ALPHA,
  ONE_MINUS_SRC_ALPHA,
};

/*extra namespace due to conflicting declaration in Enum::Behavior*/
namespace Source{
  enum Value{
  TEXTURE,
  CONSTANT,
  PRIMARY,
  PREVIOUS,
  };
}

enum Operator{
REPLACE,
MODULATE,ADD,
ADD_SIGNED,
INTERPOLATE,
SUBTRACT,
};

enum DebugLevel{
  Debug, /* Event that often occurs in normal operation (Element has been created)*/
  Info, /* Event that occurs by user request, and that is successfull (element queried successfull) */
  Error, /* Event that failed, but without harm (cant find queried element)*/
  Severe, /* something that shoud not happen happen (failed to read file)*/
  Fatal, /* error that might crash the programm (division by zero)*/
};

enum Altidude{
RELATIVE_TO_GROUND = 0,
ABSOLUTE = 1
};

/*extra namespace due to conflicting declaration in Enum::Semantic*/
namespace NodeType{
  enum Type{
    JOINT = 0,
    NODE = 1
  };
};

enum Method{
  NORMALIZED,
  RELATIVE,
};

enum Behavior{
 UNDEFINED,
 CONSTANT,
 GRADIENT,
 CYCLE,
 OSCILLATE,
 CYCLE_RELATIVE,
};

enum Semantic{
  BINORMAL =1,
  COLOR =2,
  CONTINUITY =3,
  IMAGE =4,
  INPUT =5,
  IN_TANGENT =6,
  INTERPOLATION =7,
  INV_BIND_MATRIX =8,
  JOINT =9,
  LINEAR_STEPS =10,
  MORPH_TARGET =11,
  MORPH_WEIGHT =12,
  NORMAL =13,
  OUTPUT =14,
  OUT_TANGENT =15,
  POSITION =16,
  TANGENT =17,
  TEXBINORMAL =18,
  TEXCOORD =19,
  TEXTANGENT =20,
  UV =21,
  VERTEX =22,
  WEIGHT =23,
};

}/*Enum*/

}/*PINA_NAMESPACE*/
#endif
