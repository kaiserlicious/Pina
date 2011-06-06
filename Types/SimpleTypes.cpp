
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

#include "SimpleTypes.h"

namespace PINA_NAMESPACE{
const std::string Bool2_type::Name = "bool2_type";
const std::string Bool3_type::Name = "bool3_type";
const std::string Bool4_type::Name = "bool4_type";
const std::string Float_type::Name = "float_type";
const std::string Float2_type::Name = "float2_type";
const std::string Float2x2_type::Name = "float2x2_type";
const std::string Float2x3_type::Name = "float2x3_type";
const std::string Float2x4_type::Name = "float2x4_type";
const std::string Float3_type::Name = "float3_type";
const std::string Float3x2_type::Name = "float3x2_type";
const std::string Float3x3_type::Name = "float3x3_type";
const std::string Float3x4_type::Name = "float3x4_type";
const std::string Float4_type::Name = "float4_type";
const std::string Float4x2_type::Name = "float4x2_type";
const std::string Float4x3_type::Name = "float4x3_type";
const std::string Float4x4_type::Name = "float4x4_type";
const std::string Float7_type::Name = "float7_type";
const std::string Int_type::Name = "int_type";
const std::string Int2_type::Name = "int2_type";
const std::string Int2x2_type::Name = "int2x2_type";
const std::string Int3_type::Name = "int3_type";
const std::string Int3x3_type::Name = "int3x3_type";
const std::string Int4_type::Name = "int4_type";
const std::string Int4x4_type::Name = "int4x4_type";
const std::string List_of_bools_type::Name = "list_of_bools_type";
const std::string List_of_floats_type::Name = "list_of_floats_type";
const std::string List_of_hexBinary_type::Name = "list_of_hexBinary_type";
const std::string List_of_ints_type::Name = "list_of_ints_type";
const std::string List_of_uints_type::Name = "list_of_uints_type";
const std::string Bool::Name = "bool";
const std::string Bool2::Name = "bool2";
const std::string Bool3::Name = "bool3";
const std::string Bool4::Name = "bool4";
const std::string Int::Name = "int";
const std::string Int2::Name = "int2";
const std::string Int3::Name = "int3";
const std::string Int4::Name = "int4";
const std::string Float::Name = "float";
const std::string Float2::Name = "float2";
const std::string Float3::Name = "float3";
const std::string Float4::Name = "float4";
const std::string Float2x2::Name = "float2x2";
const std::string Float3x3::Name = "float3x3";
const std::string Float4x4::Name = "float4x4";
const std::string Enum_gsl::Name = "enum_gsl";
const std::string Bool2x1::Name = "bool2x1";
const std::string Bool2x2::Name = "bool2x2";
const std::string Bool2x3::Name = "bool2x3";
const std::string Bool2x4::Name = "bool2x4";
const std::string Bool3x1::Name = "bool3x1";
const std::string Bool3x2::Name = "bool3x2";
const std::string Bool3x3::Name = "bool3x3";
const std::string Bool3x4::Name = "bool3x4";
const std::string Bool4x1::Name = "bool4x1";
const std::string Bool4x2::Name = "bool4x2";
const std::string Bool4x3::Name = "bool4x3";
const std::string Bool4x4::Name = "bool4x4";
const std::string Int2x1::Name = "int2x1";
const std::string Int2x2::Name = "int2x2";
const std::string Int2x3::Name = "int2x3";
const std::string Int2x4::Name = "int2x4";
const std::string Int3x1::Name = "int3x1";
const std::string Int3x2::Name = "int3x2";
const std::string Int3x3::Name = "int3x3";
const std::string Int3x4::Name = "int3x4";
const std::string Int4x1::Name = "int4x1";
const std::string Int4x2::Name = "int4x2";
const std::string Int4x3::Name = "int4x3";
const std::string Int4x4::Name = "int4x4";
const std::string Float2x1::Name = "float2x1";
const std::string Float2x3::Name = "float2x3";
const std::string Float2x4::Name = "float2x4";
const std::string Float3x1::Name = "float3x1";
const std::string Float3x2::Name = "float3x2";
const std::string Float3x4::Name = "float3x4";
const std::string Float4x1::Name = "float4x1";
const std::string Float4x2::Name = "float4x2";
const std::string Float4x3::Name = "float4x3";
const std::string Half::Name = "half";
const std::string Half2::Name = "half2";
const std::string Half3::Name = "half3";
const std::string Half4::Name = "half4";
const std::string Half2x1::Name = "half2x1";
const std::string Half2x2::Name = "half2x2";
const std::string Half2x3::Name = "half2x3";
const std::string Half2x4::Name = "half2x4";
const std::string Half3x1::Name = "half3x1";
const std::string Half3x2::Name = "half3x2";
const std::string Half3x3::Name = "half3x3";
const std::string Half3x4::Name = "half3x4";
const std::string Half4x1::Name = "half4x1";
const std::string Half4x2::Name = "half4x2";
const std::string Half4x3::Name = "half4x3";
const std::string Half4x4::Name = "half4x4";
const std::string Fixed::Name = "fixed";
const std::string Fixed2::Name = "fixed2";
const std::string Fixed3::Name = "fixed3";
const std::string Fixed4::Name = "fixed4";
const std::string Fixed1x1::Name = "fixed1x1";
const std::string Fixed2x1::Name = "fixed2x1";
const std::string Fixed2x2::Name = "fixed2x2";
const std::string Fixed2x3::Name = "fixed2x3";
const std::string Fixed2x4::Name = "fixed2x4";
const std::string Fixed3x1::Name = "fixed3x1";
const std::string Fixed3x2::Name = "fixed3x2";
const std::string Fixed3x3::Name = "fixed3x3";
const std::string Fixed3x4::Name = "fixed3x4";
const std::string Fixed4x1::Name = "fixed4x1";
const std::string Fixed4x2::Name = "fixed4x2";
const std::string Fixed4x3::Name = "fixed4x3";
const std::string Fixed4x4::Name = "fixed4x4";
const std::string Enumeration::Name = "enum";
const std::string String::Name = "string";
const std::string Float1x1::Name = "float1x1";
const std::string Float1x2::Name = "float1x2";
const std::string Float1x3::Name = "float1x3";
const std::string Float1x4::Name = "float1x4";
const std::string Bvec2::Name = "bvec2";
const std::string Bvec3::Name = "bvec3";
const std::string Bvec4::Name = "bvec4";
const std::string Ivec2::Name = "ivec2";
const std::string Ivec3::Name = "ivec3";
const std::string Ivec4::Name = "ivec4";
const std::string Vec2::Name = "vec2";
const std::string Vec3::Name = "vec3";
const std::string Vec4::Name = "vec4";
const std::string Mat2::Name = "mat2";
const std::string Mat3::Name = "mat3";
const std::string Mat4::Name = "mat4";
const std::string List_of_names_type::Name = "list_of_names_type";
const std::string List_of_tokens_type::Name = "list_of_tokens_type";
const std::string Sid_type::Name = "sid_type";
const std::string Sidref_type::Name = "sidref_type";
const std::string Urifragment_type::Name = "urifragment_type";


}/*PINA_NAMESPACE*/

