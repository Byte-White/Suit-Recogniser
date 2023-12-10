#include <iostream>
#include <stdio.h>
#include <time.h>

#include "spatiq.h"
#include "karo.h"
#include "kupa.h"
#include "pika.h"

#define INPUT_SIZE 784


#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float()
{
	return (float) rand()/	(float)RAND_MAX;
}

float reLU(float x)
{
    return x>0.f?x:0.f;
}

float cost(float w[INPUT_SIZE],float b)
{  
	float result = 0.0f;

    {//spatiq
        for(int i = 0; i<INPUT_SIZE;i++)
            int x = w[i];
    }

    {//karo

    }

    {//kupa

    }

    {//pika

    }
	result /= 4;
	return result;
}

int main (int argc, char *argv[]) 
{
	srand(time(0));
	//y = x*w + b;
	float w[INPUT_SIZE];
    for(int i = 0; i<INPUT_SIZE;i++)
    w[i] = rand_float()*10.f;
	float b = rand_float()*5.f;

	float eps = 1e-3;
	float rate = 1e-3;
	
	//distance cost
	for(int i = 0; i<50000;i++)
	{
		float dw = (cost(w+eps,b) - cost(w,b))/eps; // finite difference
		float db = (cost(w,b+eps) - cost(w,b))/eps;
		w -= rate*dw;
        b -= rate*db;
		printf("cost: %f, w: %f, bias: %f\n",cost(w,b),w,b);
    }
    printf("-----------------------------\n");
    printf("final- w:%f ; b:%f\n",w,b);
	std::cout<<"input: ";
	float inp;
	std::cin>>inp;
	std::cout<<"output: "<< inp*w + b<<std::endl;
	return 0;
}
