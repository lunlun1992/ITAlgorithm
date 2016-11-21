#include "common.h"
#include "complex.h"
#include "fft.h"

const char file[100] = "D:\\fft.txt";

int main()
{
	int i;
	int Npoints = 1 << POINTS_DEPTH;
	double input[1 << POINTS_DEPTH];
	double freq = FREQ;
	
	ofstream out = ofstream(file, ofstream::out);
	
	for (i = 0; i < Npoints; i++)
	{
		double sample = (double)(i + 1) / SAMPLE_FREQ;
		input[i] = sin(2 * M_PI * freq * sample);

	}
	Complex *output = (Complex *)malloc(sizeof(Complex) * Npoints);
	fft(input, Npoints, output, POINTS_DEPTH);
	for (i = 0; i < Npoints; i++)
	{
		out << output[i].norm()<< endl;
	}
	out.close();
	free(output);
}