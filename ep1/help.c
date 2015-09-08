#include "help.h"

double diff_t_s(struct timespec start_t, struct timespec end_t){
  double start_t_s = ((double)start_t.tv_sec) + ((double)start_t.tv_nsec/SECOND_TO_NANOSECOND);
  double end_t_s = ((double)end_t.tv_sec) + ((double)end_t.tv_nsec/SECOND_TO_NANOSECOND);
  return end_t_s - start_t_s;
}

void input_handler(char** argv, int* n, double*** A, double** b){
  /*To be implemented*/
}
