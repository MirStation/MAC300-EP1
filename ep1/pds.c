#include "help.h"
#include "sle.h"

/*Positives Definites Systems*/
int main(int argc, char** argv){
  double **A_col, **A_row;
  double *b_col, *b_row;
  int res, n, i;

  input_handler(&n,&A_col,&b_col);

  A_row = sq_matrix_cpy(n, A_col);
  b_row = array_cpy(n, b_col);

  /*Column*/
  
  clock_gettime(CLOCK_REALTIME, &start_t);
  res=cholcol(n, &A_col);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("cholcol:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
  if(res == 0){
    clock_gettime(CLOCK_REALTIME, &start_t);
    res=forwcol(n, A_col, &b_col);
    clock_gettime(CLOCK_REALTIME, &end_t);
    printf("forwcol:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
    if(res == 0){
      clock_gettime(CLOCK_REALTIME, &start_t);
      res=backcol(n, A_col, &b_col, 1);
      clock_gettime(CLOCK_REALTIME, &end_t);
      printf("backcol(trans=1):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
      /* -- When trans is  zero (0). 
      clock_gettime(CLOCK_REALTIME, &start_t);
      res=backcol(n, A_col, &b_col, 0);
      clock_gettime(CLOCK_REALTIME, &end_t);
      printf("backcol(trans=0):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
      */
    }
  }
  
  /*Row*/

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=cholrow(n, &A_row);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("cholrow:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
  if(res == 0){
    clock_gettime(CLOCK_REALTIME, &start_t);
    res=forwrow(n, A_row, &b_row);
    clock_gettime(CLOCK_REALTIME, &end_t);
    printf("forwrow:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
    if(res == 0){
      clock_gettime(CLOCK_REALTIME, &start_t);
      res=backrow(n, A_row, &b_row, 1);
      clock_gettime(CLOCK_REALTIME, &end_t);
      printf("backrow(trans=1):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
      /* -- When trans is zero (0). 
      clock_gettime(CLOCK_REALTIME, &start_t);
      res=backrow(n, A_row, &b_row, 0);
      clock_gettime(CLOCK_REALTIME, &end_t);
      printf("backrow(trans=0):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
      */
    }
  }

  /* DEBUG   
  puts("A_col:");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf(" %lf", A_col[i][j]);
    }
    putchar('\n');
  }
  
  puts("A_row:");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf(" %lf", A_row[i][j]);
    }
    putchar('\n');
  }
  
  puts("b_col:");
  for(i = 0; i < n; i++){
    printf(" %lf", b_col[i]);
  }
  putchar('\n');
  
  puts("b_row:");
  for(i = 0; i < n; i++){
    printf(" %lf", b_row[i]);
  }
  putchar('\n');
  */

  /*Releasing memory*/
  
  for(i = 0; i < n; i++){
    free(A_col[i]);
    free(A_row[i]);
  }
  free(A_col);
  free(A_row);
  free(b_col);
  free(b_row);

  /*End of program*/
  return 0;
}
