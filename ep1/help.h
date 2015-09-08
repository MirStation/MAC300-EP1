#ifndef HELP_H
#define HELP_H

#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SECOND_TO_NANOSECOND 1000000000

struct timespec start_t;
struct timespec end_t;

double diff_t_s(struct timespec start_t, struct timespec end_t);

void input_handler(char** argv, int* n, double*** A, double** b);

#endif
