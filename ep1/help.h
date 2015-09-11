#ifndef HELP_H
#define HELP_H

#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define SECOND_TO_NANOSECOND 1000000000

struct timespec start_t;
struct timespec end_t;

double diff_t_s(struct timespec start_t, struct timespec end_t);
void input_handler(char** argv, int* n, double*** A, double** b);
double** sq_matrix_cpy(int n, double** src_matrix);
double* array_cpy(int n, double* src_array);

#endif
