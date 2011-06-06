
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

#ifndef TYPE_LIST_CONSTRUCTORS_CONS16TO32
#define TYPE_LIST_CONSTRUCTORS_CONS16TO32

namespace PINA_NAMESPACE{

class NullType;
template<class Head, class Tail>
class Typelist;

namespace TL{

template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17=NullType,class T18=NullType,class T19=NullType,class T20=NullType,
class T21=NullType,class T22=NullType,class T23=NullType,class T24=NullType,class T25=NullType,
class T26=NullType,class T27=NullType,class T28=NullType,class T29=NullType,class T30=NullType,
class T31=NullType,class T32=NullType
>
struct Cons16to32{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,
Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,
Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,
Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,
Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,
Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,
Typelist<T31,Typelist<T32,
NullType> > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > List;
};

/*template nr. 16*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,NullType > > > > > > > > > > > > > > > >  List;
};

/*template nr. 17*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,NullType > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 18*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,NullType > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 19*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,NullType > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 20*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,NullType > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 21*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,NullType > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 22*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,NullType > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 23*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,NullType > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 24*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,NullType > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 25*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,NullType > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 26*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,NullType > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 27*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 28*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 29*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 30*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

/*template nr. 31*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15,
class T16,class T17,class T18,class T19,class T20,
class T21,class T22,class T23,class T24,class T25,
class T26,class T27,class T28,class T29,class T30,
class T31
>
struct Cons16to32<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,Typelist<T16,Typelist<T17,Typelist<T18,Typelist<T19,Typelist<T20,Typelist<T21,Typelist<T22,Typelist<T23,Typelist<T24,Typelist<T25,Typelist<T26,Typelist<T27,Typelist<T28,Typelist<T29,Typelist<T30,Typelist<T31,NullType > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  List;
};

}/*TL*/

}/*PINA_NAMESPACE*/

#endif
