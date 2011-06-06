
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

#ifndef TYPE_LIST_CONSTRUCTORS
#define TYPE_LIST_CONSTRUCTORS

namespace PINA_NAMESPACE{

class NullType;
template<class Head, class Tail>
class Typelist;

namespace TL{

template<
class T1=NullType,class T2=NullType,class T3=NullType,class T4=NullType,class T5=NullType,
class T6=NullType,class T7=NullType,class T8=NullType,class T9=NullType,class T10=NullType,
class T11=NullType,class T12=NullType,class T13=NullType,class T14=NullType,class T15=NullType,
class T16=NullType
>
struct Cons{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,
Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,
Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,
Typelist<T16,
NullType> > > > > > > > > > > > > > > > List;
};

/*template nr. 1*/
template<
class T1
>
struct Cons<
T1,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,NullType >  List;
};

/*template nr. 2*/
template<
class T1,class T2
>
struct Cons<
T1,T2,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,NullType > >  List;
};

/*template nr. 3*/
template<
class T1,class T2,class T3
>
struct Cons<
T1,T2,T3,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,typename Cons<T2,T3>::List >  List;
};

/*template nr. 4*/
template<
class T1,class T2,class T3,class T4
>
struct Cons<
T1,T2,T3,T4,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,NullType > > > >  List;
};

/*template nr. 5*/
template<
class T1,class T2,class T3,class T4,class T5
>
struct Cons<
T1,T2,T3,T4,T5,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,NullType > > > > >  List;
};

/*template nr. 6*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6
>
struct Cons<
T1,T2,T3,T4,T5,T6,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,NullType > > > > > >  List;
};

/*template nr. 7*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,NullType > > > > > > >  List;
};

/*template nr. 8*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,NullType,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,NullType > > > > > > > >  List;
};

/*template nr. 9*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,NullType,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,NullType > > > > > > > > >  List;
};

/*template nr. 10*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,NullType,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,NullType > > > > > > > > > >  List;
};

/*template nr. 11*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,NullType,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,NullType > > > > > > > > > > >  List;
};

/*template nr. 12*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,NullType,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,NullType > > > > > > > > > > > >  List;
};

/*template nr. 13*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,NullType,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,NullType > > > > > > > > > > > > >  List;
};

/*template nr. 14*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,NullType,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,NullType > > > > > > > > > > > > > >  List;
};

/*template nr. 15*/
template<
class T1,class T2,class T3,class T4,class T5,
class T6,class T7,class T8,class T9,class T10,
class T11,class T12,class T13,class T14,class T15
>
struct Cons<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,NullType>{
typedef
Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,Typelist<T5,Typelist<T6,Typelist<T7,Typelist<T8,Typelist<T9,Typelist<T10,Typelist<T11,Typelist<T12,Typelist<T13,Typelist<T14,Typelist<T15,NullType > > > > > > > > > > > > > > >  List;
};

}/*TL*/

}/*PINA_NAMESPACE*/

#endif
