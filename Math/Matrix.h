
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

#ifndef PINA_MATH_MATRIX_H
#define PINA_MATH_MATRIX_H

#include <sstream>
#include <iostream>
#include <string.h>
#include "../Config.h"

namespace PINA_NAMESPACE{
namespace Math{

template<bool>
struct AssertQuadratcMatrix{
  static void NotAQuadraticMatrix();
};

template<>
struct AssertQuadratcMatrix<true>{
  static void NotAQuadraticMatrix(){};
};

template<>
struct AssertQuadratcMatrix<false>{
  static void NotAQuadraticMatrix();
};

/*layout:
  MxN = M rows, N columns
  2 x 3:
  (1,0) (1,0) (2,0)
  (0,1) (1,1) (2,1)
*/
template<typename T,unsigned int M ,unsigned int N>
class Matrix{

  public:
  Matrix(){
  };
  
  // initialize from other Matrix
  Matrix( const Matrix<T,M,N>& m ){
    for (unsigned int i=0; i<M*N; i++) {
      matrix[i] = m[i];
    }
  }

  // initalize with single value
  Matrix(const T& initValue){
    for(unsigned int i=0;i<M*N;i++){
      matrix[i] = initValue;
    }
  };

  //the static union matrix, only available for square
  static Matrix<T,M,N> unionMatrix(){
    //TODO insert static check if matrix is square
    Matrix<T,N,M> out(0);
    for(unsigned int i=0;i<M;i++){
      out.matrix[i+N*i] = 1;
    }
    return out;
  }

  //transpose matrix
  Matrix<T,N,M> transpose(){
    Matrix<T,N,M> matrix_out;
    for(unsigned int i=0; i<M; i++){
      for(unsigned int j=0; j<N; j++){
        matrix_out.matrix[j*M+i] = matrix[i*M+j];
      }
    }
    return matrix_out;
  }

  T& operator [ ] (unsigned int index){
    return matrix[index];
  }

  const T& operator [ ] (unsigned int index) const{
    return matrix[index];
  }

  Matrix<T,M,N>& operator = (Matrix<T,M,N> m){
    for (unsigned int i=0; i<M*N; i++) {
      matrix[i] = m.matrix[i];
    }
    return *this;
  }

  // operator ==
  bool operator == (Matrix<T,M,N> m){
    for (unsigned int i=0; i<M*N; i++) {
  		if (! matrix[i] == m.matrix[i]){
        return false;
      }
    }
    return true;
  }

  // operator !=
  bool operator != (Matrix<T,M,N> m){
    for (unsigned int i=0; i<M*N; i++) {
      if (! matrix[i] != m.matrix[i]){
        return true;
      }
    }
    return false;
  }

  // operator * (for matrices)
  template<unsigned int m_size>
  Matrix<T,M,m_size> operator * (Matrix<T,N,m_size> m){
    Matrix<T,M,m_size> result;
    T temp=0; //NOTE This will fail for types you cant assign 0 to
    for(unsigned int i=0; i<M; i++){
      for(unsigned int j=0;  j< m_size; j++){
        temp=0;
        for(unsigned int k=0; k<N; k++){
          temp = temp + matrix[i*m_size+k] * m[k*m_size+j];
        }
        result[i*m_size+j] = temp;
      }
    }
    return result;
  }

  private:
  T matrix[M*N];
};

// operator * (for scalars)
template<typename T,unsigned int R,unsigned int C>
Matrix<T,R,C> operator*(T scale,Matrix<T,R,C>matrix_right){
  Matrix<T,R,C> matrix_out;
  for(unsigned int i=0; i<R*C; i++){
  matrix_out.get(0,i) = scale*matrix_right.get(0,i);
  }
  return matrix_out;
}

// operator +
template<typename T,unsigned int R,unsigned int C>
Matrix<T,R,C> operator+(Matrix<T,R,C>matrix_left,Matrix<T,R,C>matrix_right){
  Matrix<T,R,C> matrix_out;
  for(unsigned int i=0; i<R*C; i++){
  matrix_out.get(0,i) = matrix_left.get(0,i)+matrix_right.get(0,i);
  }
  return matrix_out;
}
 
// operator <<
template<typename T,unsigned int M,unsigned int N>
std::ostream& operator<<(std::ostream& str, Matrix<T,M,N>matrix){
  for(unsigned int i=0;i<M*N-1;i++){
      str << matrix[i] << ' ';
  }
  str << matrix[M*N-1];
  return str;
}

}//Math namespace
}//PINA_NAMESPACE
#endif
