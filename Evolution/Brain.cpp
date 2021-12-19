#include "Brain.h"
#include <stdlib.h>
#include <cmath>

inline float max(float x,float y)
{
	return x > y ? x : y;
}
inline float min(float x, float y)
{
	return x < y ? x : y;
}

void Brain::initialize_params()
{
	for (size_t i = 0; i < inp_size * hl_size; i++)
	{
		W1[i] = randVal();
	}
	for (size_t i = 0; i < out_size * hl_size; i++)
	{
		W2[i] = randVal();
	}
	for (size_t i = 0; i <  hl_size; i++)
	{
		b1[i] = randVal();
	}
	for (size_t i = 0; i <  out_size; i++)
	{
		b1[i] = randVal();
	}
}
float randVal()
{
	return ((float(rand() % 1000000)) / 1000000.0 - 0.5) * 2;
}



void Brain::feed_forward(float input[])
{

	//hidden layer
	for (size_t i = 0; i < hl_size; i++)
	{
		for (size_t j = 0; j < inp_size; j++)
		{
			z1[i] += input[i] * W1[(i * inp_size) + j];
		}
		z1[i] += b1[i];
		a1[i] += ReLU(z1[i]);
	}
	//output 
	for (size_t i = 0; i < out_size; i++)
	{
		for (size_t j = 0; j < hl_size; j++)
		{
			z2[i] += a2[i] * W2[(i * hl_size) + j];
		}
		z2[i] += b2[i];
		a2[i] = Sigmoid(z2[i]);
	}
}



int Brain::GetAction(float input[])
{
	feed_forward(input);
	return get_highest_index(a2, out_size);
}

int get_highest_index(float input[], int n)
{
	int highest = 0;
	for (size_t i = 1; i < n; i++)
	{
		if (input[i] > input[highest])
			highest = i;
	}
	return highest;
}


float ReLU(float x)
{
	return max(0, x);
}
float Sigmoid(float x)
{
	return 1 / (1 + exp(-x));
}