/*Systems of Linear Equations*/

#include <stdio.h> /*Debug porpoises*/
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
  /*To be implemented*/
  return 0;
}

int forwrow(int n, double** A, double** b){
  /*To be implemented*/
  return 0;
}

int backcol(int n, double** A, double** b, int trans){
  /*To be implemented*/
  return 0;
}

int backrow(int n, double** A, double** b, int trans){
  /*To be implemented*/
  return 0;
}

/*General Systems*/

int lucol(int n, double*** A, int** p){
  /*To be implemented*/
  return 0;
}

int lurow(int n, double*** A, int** p){
  /*To be implemented*/
  return 0;
}

int sscol(int n, double** A, int* p, double** b){
  /*To be implemented*/
  return 0;
}

int ssrow(int n, double** A, int* p, double** b){
  /*To be implemented*/
  return 0;
}
