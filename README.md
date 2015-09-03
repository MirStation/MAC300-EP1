# MAC300 - 1st programming exercise

Authors: 
  António Castro Júnior
  António Martins Miranda
  
## Simple description:

### Part one: Positive-definite systems

C implementation of these functions:

  - **int cholcol (int n, double A[][nmax])** : cholesky factorization in column-oriented fashion;
  - **int cholrow (int n, double A[][nmax])** : cholesky factorization in row-oriented fashion;
  - **int forwcol (int n, double A[][nmax], double b[])** : solve Ax=b system with forward substitution and in           column-oriented fashion;
  - **int forwrow (int n, double A[][nmax], double b[])** : solve Ax=b system with forward substitution and in           row-oriented fashion;
  - **int backcol (int n, double A[][nmax], double b[], int trans)** : solve Ax=b system with backward substitution and   in column-oriented fashion;
  - **int backrow (int n, double A[][nmax], double b[], int trans)** : solve Ax=b system with backward substitution and   in row-oriented fashion.

### Part two: general systems

  - **int lucol (int n, double A[][nmax], int p[])** : LU factorization in column-oriented fashion;
  - **int lurow (int n, double A[][nmax], int p[])** : LU factorization in row-oriented fashion;
  - **int sscol (int n, double A[][nmax], int p[], double b[])** : solve LUx=Pb system in column-oriented fashion;
  - **int ssrow (int n, double A[][nmax], int p[], double b[])** : solve LUx=Pb system in row-oriented fashion.

Do a simple efficiency comparison between the all column-oriented functions and their respective row-oriented functions.

OBS: For more informations about the exercise, read the file ep1.pdf (in protuguese).


