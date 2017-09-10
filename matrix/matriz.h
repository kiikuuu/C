#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdbool.h>
#include "../mallocc/mallocc.h"

double** initMatriz( const size_t n);
bool setMatrizTriangular(double** m, const size_t n , int* fator );
double determinante(double** m, bool hasDet , const size_t n , const int fator);
bool seLinhaColunaNulo( double** m , const size_t n );

#endif
