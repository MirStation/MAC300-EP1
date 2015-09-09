#include "help.h"

double diff_t_s(struct timespec start_t, struct timespec end_t){
  double start_t_s = ((double)start_t.tv_sec) + ((double)start_t.tv_nsec/SECOND_TO_NANOSECOND);
  double end_t_s = ((double)end_t.tv_sec) + ((double)end_t.tv_nsec/SECOND_TO_NANOSECOND);
  return end_t_s - start_t_s;
}

void input_handler(char** argv, int* n, double*** A, double** b){
  int i, j, k, n_2;
  double v;
  scanf("%d\n", n);
  n_2 = (*n) * (*n);
  *A = (double**) malloc((*n) * sizeof(double*));
  assert(*A);
  for(k = 0; k < (*n); k++){
    (*A)[k] = (double*) calloc(*n, sizeof(double));
    assert((*A)[k]);
  }
  *b = (double*) malloc((*n) * sizeof(double));
  assert(*b);
  for(k = 0; k < n_2; k++){
    scanf("%d %d %lf\n", &i, &j, &v);
    (*A)[i][j] = v;
  }
  for(k = 0; k < (*n); k++){
    scanf("%d %lf\n", &i, &v);
    (*b)[i] = v;
  }

  /*DEBUG
  printf("n:\n %d\n", *n);
  puts("A:");
  for(i = 0; i < *n; i++){
    for(j = 0; j < *n; j++){
      printf(" %.20e", (*A)[i][j]);
    }
    putchar('\n');
  }
  puts("b:");
  for(i = 0; i < *n; i++){
    printf(" %.20e", (*b)[i]);
  }
  putchar('\n');
  */
}
