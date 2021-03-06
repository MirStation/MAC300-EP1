#include "help.h"
#include "sle.h"

#include <time.h>

/*General Systems*/
int main(int argc, char** argv){
  int *p;
  double **A_col, **A_row;
  double *b_col, *b_row;
  int res, n, i;

  input_handler(&n,&A_col,&b_col);

  p = (int*) malloc(n*sizeof(int));
  assert(p);
  for(i = 0; i < n; i++){
    p[i] = i;
  }

  A_row = sq_matrix_cpy(n, A_col);
  b_row = array_cpy(n, b_col);
  
  clock_gettime(CLOCK_REALTIME, &start_t);
  res=lucol(n, &A_col, &p);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("lucol:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));

  if(res == 0){
    clock_gettime(CLOCK_REALTIME, &start_t);
    res=sscol(n, A_col, p, &b_col);
    clock_gettime(CLOCK_REALTIME, &end_t);
    printf("sscol:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));
  }
  
  for(i = 0; i < n; i++){
    p[i] = i;
  }
  
  clock_gettime(CLOCK_REALTIME, &start_t);
  res=lurow(n, &A_row, &p);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("lurow:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));
  
  if(res == 0){
    clock_gettime(CLOCK_REALTIME, &start_t);
    res=sscol(n, A_row, p, &b_row);
    clock_gettime(CLOCK_REALTIME, &end_t);
    printf("ssrow:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));
  }
  
  for(i = 0; i < n; i++){
    free(A_col[i]);
    free(A_row[i]);
  }
  free(A_col);
  free(A_row);
  free(b_col);
  free(b_row);
  free(p);
  
  return 0;
}
