
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

#ifndef TYPE_LIST_CONSTRUCTORS_CONS32TO64
#define TYPE_LIST_CONSTRUCTORS_CONS32TO64

namespace PINA_NAMESPACE{

class NullType;
template<class Head, class Tail>
class Typelist;

namespace TL{

template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33=NullType,class T34=NullType,class T35=NullType,
class T36=NullType,class T37=NullType,class T38=NullType,class T39=NullType,class T40=NullType,
class T41=NullType,class T42=NullType,class T43=NullType,class T44=NullType,class T45=NullType,
class T46=NullType,class T47=NullType,class T48=NullType,class T49=NullType,class T50=NullType,
class T51=NullType,class T52=NullType,class T53=NullType,class T54=NullType,class T55=NullType,
class T56=NullType,class T57=NullType,class T58=NullType,class T59=NullType,class T60=NullType,
class T61=NullType,class T62=NullType,class T63=NullType,class T64=NullType
>
struct Cons32to64{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,
Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,
Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,
Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,
Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,
Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,
Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,
Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,
Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,
Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,
Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,
Typelist<T56,Typelist<T57,Typelist<T58,Typelist<T59,Typelist<T60,
Typelist<T61,Typelist<T62,Typelist<T63,Typelist<T64,
NullType> > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > List;
};

/*template nr. 32*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 33*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 34*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 35*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 36*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 37*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 38*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 39*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 40*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 41*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 42*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 43*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 44*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 45*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 46*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 47*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 48*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 49*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 50*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 51*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 52*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 53*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 54*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 55*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 56*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 57*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 58*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57,class T58
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,Typelist<T58,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 59*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57,class T58,class T59
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,Typelist<T58,Typelist<T59,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 60*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57,class T58,class T59,class T60
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,T60,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,Typelist<T58,Typelist<T59,Typelist<T60,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 61*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57,class T58,class T59,class T60,
class T61
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,T60,T61,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,Typelist<T58,Typelist<T59,Typelist<T60,Typelist<T61,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 62*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57,class T58,class T59,class T60,
class T61,class T62
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,T60,T61,T62,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,Typelist<T58,Typelist<T59,Typelist<T60,Typelist<T61,Typelist<T62,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 63*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31,class T32,class T33,class T34,class T35,
class T36,class T37,class T38,class T39,class T40,
class T41,class T42,class T43,class T44,class T45,
class T46,class T47,class T48,class T49,class T50,
class T51,class T52,class T53,class T54,class T55,
class T56,class T57,class T58,class T59,class T60,
class T61,class T62,class T63
>
struct Cons32to64<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,T60,T61,T62,T63,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,Typelist<T32,Typelist<T33,Typelist<T34,Typelist<T35,Typelist<T36,Typelist<T37,Typelist<T38,Typelist<T39,Typelist<T40,Typelist<T41,Typelist<T42,Typelist<T43,Typelist<T44,Typelist<T45,Typelist<T46,Typelist<T47,Typelist<T48,Typelist<T49,Typelist<T50,Typelist<T51,Typelist<T52,Typelist<T53,Typelist<T54,Typelist<T55,Typelist<T56,Typelist<T57,Typelist<T58,Typelist<T59,Typelist<T60,Typelist<T61,Typelist<T62,Typelist<T63,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

}/*TL*/

}/*PINA_NAMESPACE*/

#endif
