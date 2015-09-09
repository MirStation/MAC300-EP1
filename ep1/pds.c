#include "help.h"
#include "sle.h"

/*Positives Definites Systems*/
int main(int argc, char** argv){
  double** A;
  double* b;
  int res, n, i;

  input_handler(argv,&n,&A,&b);

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=cholcol(n, &A);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("cholcol:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
  

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=forwcol(n, A, &b);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("forwcol:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=backcol(n, A, &b, 0);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("backcol(trans=0):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));

  /*
  clock_gettime(CLOCK_REALTIME, &start_t);
  res=backcol(n, A, &b, 1);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("backcol(trans=1):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
  */

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=cholrow(n, &A);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("cholrow:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=forwrow(n, A, &b);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("forwrow:\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=backrow(n, A, &b, 0);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("backrow(trans=0):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));

  /*
  clock_gettime(CLOCK_REALTIME, &start_t);
  res=backrow(n, A, &b, 1);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("backrow(trans=1):\n  result: %d\n  time: %f\n",res,diff_t_s(start_t,end_t));
  */
  
  for(i = 0; i < n; i++){
    free(A[i]);
  }
  free(A);
  free(b);

  return 0;
}
