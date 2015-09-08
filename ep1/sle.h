#ifndef SYSTEM_LINEAR_EQUATION_H
#define SYSTEM_LINEAR_EQUATION_H

/*Positive Definite Systems*/

int cholcol(int n, double*** A);
int cholrow(int n, double*** A);
int forwcol(int n, double** A, double** b);
int forwrow(int n, double** A, double** b);
int backcol(int n, double** A, double** b, int trans);
int backrow(int n, double** A, double** b, int trans);

/*General Systems*/

int lucol(int n, double*** A, int** p);
int lurow(int n, double*** A, int** p);
int sscol(int n, double** A, int* p, double** b);
int ssrow(int n, double** A, int* p, double** b);

#endif
