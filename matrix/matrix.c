
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

double** initMatriz( const size_t n){
	double** m = mallocc( sizeof(double*) * n );
	for(int i=0; i<n; i++) m[i] = mallocc( sizeof(double) * n );
	return m;
}


bool setMatrizTriangular(double** m, const size_t n , int* fator ){
	if(seLinhaColunaNulo(m, n)) return false;
	int i, j, maxValueI = 0, maxValueJ = 0;
	double maxValue, mult = 0.0;
	*fator = 1;

	for(i=0; i<n-1; i++){
		maxValue = 0.0;
		for(int k=i; k<n; k++){
			if(m[i][k] > maxValue){
				maxValue = m[i][k];
				maxValueI = i;
				maxValueJ = k;
			}
		}
		for(int k=i; k<n; k++){
			if(m[k][i] > maxValue){
				maxValue = m[k][i];
				maxValueI = k;
				maxValueJ = i;
			}
		}

		if(maxValueJ != i || maxValueI != i){
			*fator = -*fator;
			double aux;
			for(int l=i; l<n; l++){
				aux = m[i][l];
				m[i][l] = m[maxValueI][l];
				m[maxValueI][l] = aux;

				aux = m[l][i];
				m[l][i] = m[l][maxValueJ];
				m[l][maxValueJ] = aux;
			}
		}
		for(j=i+1; j<n; j++){
			mult = (m[j][i] / m[i][i]);
			for(int o=0; o<n; o++)
				m[j][o]= m[j][o] - (mult*m[i][o]);
		}	
	}
	return true;
}

double determinante(double** m, bool hasDet , const size_t n , const int fator){
	if(!hasDet) return 0.0;
	double det = 1;
	for(int i=0; i<n; i++)
		det*=m[i][i];
	return fator*det;
}

bool seLinhaColunaNulo( double** m , const size_t n ){
	for(int i=0; i<n; i++){
		int cont = 0;
		for(int j=0; j<n; j++){
			if(m[i][j] == 0) cont++;
		}
		if(cont == n) return true;
	}
	for(int i=0; i<n; i++){
		int cont = 0;
		for(int j=0; j<n; j++){
			if(m[j][i] == 0) cont++;
		}
		if(cont == n) return true;
	}			
	return false;
}
