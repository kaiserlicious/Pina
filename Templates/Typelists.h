
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

#ifndef PINA_TYPELISTS_H
#define PINA_TYPELISTS_H

#include "../Config.h"
#include "TypelistConstructor.h"

namespace PINA_NAMESPACE{

struct NullType{};
struct EmptyType{};

template<typename T, typename U>
struct Typelist{
  typedef T Head;
  typedef U Tail;
};

namespace TL{

/*Append*/
template<class List1, class List2>
struct Append{
    typedef Typelist<typename List1::Head, typename Append<typename List1::Tail, List2>::Result> Result;
};

template<class List2>
struct Append<NullType, List2>{
    typedef List2 Result;
};

/* Length */
template<typename TList>
struct Length;

template<>
struct Length<NullType>{
  enum{ value =0 };
};

template<typename T, typename U>
struct Length<Typelist<T,U> >{
  enum{ value = 1 + Length<U>::value };
};

/* IndexOf */
template<typename TList, typename T >
struct IndexOf;

template<typename T>
struct IndexOf<NullType,T>{
  enum{ value = -1};
};

template<typename T, typename Tail>
struct IndexOf<Typelist<T,Tail>,T>{
  enum{ value =0 };
};

template<typename Head ,typename Tail, typename T>
struct IndexOf<Typelist<Head,Tail>,T>{
  private:
  enum{ temp = IndexOf<Tail,T>::value };
  public:
  enum{ value = temp == -1 ? -1 : 1+temp };
};

/* Is in*/
template<typename TList, typename T>
struct IsInList{
  enum{value = (IndexOf<TList,T>::value == -1) ? 0 : 1};
};

/* Type At*/
template<typename T, unsigned i>
struct TypeAt;

template<typename Head,typename Tail>
struct TypeAt<Typelist<Head,Tail>,0>{
  typedef Head Result;
};

template<typename Head,typename Tail,unsigned int i>
struct TypeAt<Typelist<Head,Tail>,i>{
  typedef typename TypeAt<Tail,i-1>::Result Result;
};

}//namespace TL

}/*PINA_NAMESPACE*/
#endif
