#ifndef FFT_H
#define FFT_H
#define _USE_MATH_DEFINES
#include "common.h"
#include "complex.h"
#include "math.h"
void fft(double *input, int input_length, Complex *output, int Npoints);
#endif;