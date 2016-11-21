#include "fft.h"

void fft(double *input, int input_length, Complex *output, int Ndepth)
{
	int i, j, k;
	int Npoints = 1 << Ndepth;
	Complex *input_seq, *temp_seq, *Wn;

	if (input_length > Npoints)
	{
		printf("input length is too long\n");
		return;
	}

	input_seq = (Complex *)malloc(sizeof(Complex) * Npoints);
	temp_seq = (Complex *)malloc(sizeof(Complex) * Npoints);
	Wn = (Complex *)malloc(sizeof(Complex) * Npoints / 2);

	memset(input_seq, 0, sizeof(Complex) * Npoints);
	memset(temp_seq, 0, sizeof(Complex) * Npoints);
	memset(Wn, 0, sizeof(Complex) * Npoints / 2);

	for (i = 0; i < input_length; i++)
	{
		input_seq[i] = Complex(input[i], 0);
	}
	for (i = 0; i < Npoints / 2; i++)
	{
		double coeff = 2 * M_PI * i / Npoints;
		Wn[i] = Complex(cos(coeff), -sin(coeff));
	}

	for (i = 0; i < Ndepth; i++)
	{
		for (j = 0; j < (1 << i); j++)
		{
			int stride = 1 << (Ndepth - i);
			for (k = 0; k < stride / 2; k++)
			{
				int s = j * stride;
				temp_seq[k + s] = input_seq[k + s] + input_seq[k + s + stride / 2];
				temp_seq[k + s + stride / 2] = (input_seq[k + s] - input_seq[k + s + stride / 2]) * Wn[k * (1 << i)];
			}
		}
		Complex *tmp = input_seq;
		input_seq = temp_seq;
		temp_seq = tmp;
	}


	for (i = 0; i < Npoints; i++)
	{
		int p = 0;
		int reg = i;
		for (j = 0; j < Ndepth; j++)
		{
			if (i & (1 << j))
			{
				p += 1 << (Ndepth - 1 - j);
			}
		}
		output[i] = input_seq[p];
	}

	free(input_seq);
	free(Wn);
	free(temp_seq);
}

