#include "help.h"
#include "sle.h"

#include <time.h>

/*General Systems*/
int main(int argc, char** argv){
  int* p;
  double** A;
  double* b;
  int res, n;

  input_handler(argv,&n,&A,&b);

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=lucol(n, &A, &p);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("lucol:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=sscol(n, A, p, &b);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("sscol:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=lurow(n, &A, &p);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("lurow:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));

  clock_gettime(CLOCK_REALTIME, &start_t);
  res=sscol(n, A, p, &b);
  clock_gettime(CLOCK_REALTIME, &end_t);
  printf("ssrow:\n  result: %d\n  time: %f\n", res, diff_t_s(start_t,end_t));

  return 0;
}
