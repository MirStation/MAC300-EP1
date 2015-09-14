/*Systems of Linear Equations*/

#include <stdio.h> /*Debug porpoises*/
#include <stdlib.h>
#include <math.h>
#include "sle.h"

/*Positive Definite Systems*/

int cholcol(int n, double*** A){
  int i, j, k;

  for(j = 0; j < n; j++){
    for(k = 0; k < j; k++){
      for(i = j; i < n; i++){
	(*A)[i][j] = (*A)[i][j] - (*A)[i][k] * (*A)[j][k];
      }
    }
    if((*A)[j][j] <= 0){
      return -1;
    }
    (*A)[j][j] = sqrt((*A)[j][j]);
    for(k = j + 1; k < n; k++){
      (*A)[k][j] = (*A)[k][j] / (*A)[j][j];
    }
  }

  return 0;
}

int cholrow(int n, double*** A){
  int i, j, k;

  for(i = 0; i < n; i++){
    for(j = 0; j < i; j++){
      for(k = 0; k < j; k++){
	(*A)[i][j] = (*A)[i][j] - (*A)[i][k] * (*A)[j][k];
      }
      (*A)[i][j] = (*A)[i][j] / (*A)[j][j];
    }
    for(j = 0; j < i; j++){
      (*A)[i][i] = (*A)[i][i] - (*A)[i][j] * (*A)[i][j];
    }
    if((*A)[i][i] <= 0){
      return -1;
    }
    (*A)[i][i] = sqrt((*A)[i][i]);
  }

  return 0;
}

int forwcol(int n, double** A, double** b){
  int i,j;

  for(j = 0; j < n; j++){
    if(A[j][j] == 0){
      return -1;
    }
    (*b)[j] = (*b)[j] / A[j][j];
    for(i = j + 1; i < n; i++){
      (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];
    }
  }

  return 0;
}

int forwrow(int n, double** A, double** b){
  int i, j;

  for(i = 0; i < n; i++){
    for(j = 0; j < i; j++){
      (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];
    }
    if(A[i][i] == 0){
      return -1;
    }
    (*b)[i] = (*b)[i] / A[i][i];
  }

  return 0;
}

int backcol(int n, double** A, double** b, int trans){
    int i, j;

    if (trans  == 1) {
        for (i = n - 1; i >= 0; i--){
            for (j = i + 1; j < n; j++)
                (*b)[i] = (*b)[i] - A[j][i] * (*b)[j];

            if (A[i][i] == 0) return -1;

            (*b)[i] = (*b)[i] / A[i][i];
        }
    }
    else {
        for (j = n - 1; j >= 0; j--){
            if (A[j][j] == 0) return -1;

            (*b)[j] = (*b)[j] / A[j][j];

            for (i = j - 1; i >= 0; i--)
                (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];
        }
    }

    return 0;
}

int backrow(int n, double** A, double** b, int trans){
    int i, j;

    if (trans == 1){
        for (j = n - 1; j >= 0; j--) {
            if (A[j][j] == 0) return -1;

            (*b)[j] = (*b)[j] / A[j][j];

            for (i = j - 1; i >= 0; i--)
                (*b)[i] = (*b)[i] - A[j][i] * (*b)[j];
        }
    }
    else{
        for (i = n - 1; i >= 0; i--){
            for (j = i + 1; j < n; j++)
                (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];

            if (A[i][i] == 0) return -1;

            (*b)[i] = (*b)[i] / A[i][i];
        }
    }

    return 0;
}

/*General Systems*/

int lucol(int n, double*** A, int** p){
  int k, i, j, imax, itmp;
  double tmp;
  
  for (k = 0; k < (n - 1); k++){
    imax = k;
    for (i = k+1; i < n; i++){
      if (fabs((*A)[i][k]) > fabs((*A)[imax][k])){
	imax = i;
      }
    }
    
    itmp = (*p)[k]; 
    (*p)[k] = imax;
    (*p)[imax] = itmp;
    
    if ((*p)[k] != k) {
      for (j = 0; j < n; j++){
	tmp = (*A)[k][j];
	(*A)[k][j] = (*A)[(*p)[k]][j];
	(*A)[(*p)[k]][j] = tmp;
      }
    }
    
    if ((*A)[k][k] == 0) return -1;
    
    for (i = k+1; i < n; i++){
      (*A)[i][k] = (*A)[i][k] / (*A)[k][k];
    }
    
    for (j = k + 1; j < n; j++){
      for (i = k + 1; i < n; i++){
	(*A)[i][j] = (*A)[i][j] - (*A)[k][j] * (*A)[i][k];
      }
    }
    
    if ((*A)[n-1][n-1] == 0) return -1;
  }
  
  return 0;
}

int lurow(int n, double*** A, int** p){
  int i, j, k, imax, itmp;
  double tmp;
  
  for (k = 0; k < (n - 1); k++){
    imax = k;
    
    for (i = k + 1; i < n; i++){
      if (fabs((*A)[i][k]) > fabs((*A)[imax][k]))
	imax = i;
    }
    
    itmp = (*p)[k]; 
    (*p)[k] = imax;
    (*p)[imax] = itmp;
    
    if ((*p)[k] != k){
      for (j = 0; j < n; j++){
	tmp = (*A)[k][j];
	(*A)[k][j] = (*A)[(*p)[k]][j];
	(*A)[(*p)[k]][j] = tmp;
      }
    }
    
    if ((*A)[k][k] == 0) return -1;
    
    for (i = k + 1; i < n; i++){
      (*A)[i][k] = (*A)[i][k] / (*A)[k][k];
      for (j = k + 1; j < n; j++)
	(*A)[i][j] = (*A)[i][j] - (*A)[k][j] * (*A)[i][k];
    }
    
    if ((*A)[n-1][n-1] == 0) return -1;
  }
  
  return 0;
}

int sscol(int n, double** A, int* p, double** b){
  int i, j;
  double tmp;
  
  for (i = 0; i < (n - 1); i++){
    tmp = (*b)[i];
    (*b)[i] = (*b)[p[i]];
    (*b)[p[i]] = tmp;
  }
  
  for (j = 0; j < n; j++)
    for (i = j + 1; i < n; i++)
      (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];
    
  for (j = n - 1; j >= 0; j--){
    if (A[j][j] == 0) return -1;
    
    (*b)[j] = (*b)[j] / A[j][j];
    
    for (i = j - 1; i >= 0; i--)
      (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];
  }
  
  return 0;
}

int ssrow(int n, double** A, int* p, double** b){  
  int i, j;
  double tmp;
  
  for (i = 0; i < (n - 1); i++){
    tmp = (*b)[i];
    (*b)[i] = (*b)[p[i]];
    (*b)[p[i]] = tmp;
  }
  
  for (i = 0; i < n; i++)
    for (j = 0; j < (i - 1); j++)
      (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];

  for (i = n - 1; i >= 0; i--) {
    if (A[i][i] == 0) return -1;
    for (j = i + 1; j < n; j++)
      (*b)[i] = (*b)[i] - A[i][j] * (*b)[j];
    (*b)[i] = (*b)[i] / A[i][i];
  }
  
  return 0;
}
