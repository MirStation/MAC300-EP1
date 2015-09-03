# MAC300 - 1st programming exercise

Authors: 
  António Castro Júnior
  António Martins Miranda
  
## Description:

### Part one: Positive-definite systems

C implementation of these functions:

  - int cholcol (int n, double A[][nmax]) : cholesky factorization in column-oriented fashion
  - int cholrow (int n, double A[][nmax]) : cholesky factorization in row-oriented fashion
  - int forwcol (int n, double A[][nmax], double b[]) : solve Ax=b system with forward substitution and in                   column-oriented fashion;
  - int forwrow (int n, double A[][nmax], double b[]) : solve Ax=b system with forward substitution and in                   row-oriented fashion;
  - int backcol (int n, double A[][nmax], double b[], int trans) : solve Ax=b system with backward substitution and in       column-oriented fashion;
  - int backrow (int n, double A[][nmax], double b[], int trans) : solve Ax=b system with backward substitution and in       row-oriented fashion.
