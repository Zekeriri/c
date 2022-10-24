#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int num[5];
	double dnum[5];
	double sum=0;
	double meanValue=0;
	double max = 0;
	printf("The random real numbers are: ");
	for (int i = 0; i < 5; i++)
	{
		num[i] = rand() % (1000 - 200 + 100) + 200;
		dnum[i] = num[i] / 100.00;
		printf("%.2lf ", dnum[i]);
	}
	//mean value
	for (int i = 0; i < 5; i++)
	{
		sum = sum + dnum[i];
	}
	meanValue = sum / 5;
	printf("\nThe mean value is: %.2lf\n", meanValue);
	//standard deviation
	sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum = sum + (meanValue - dnum[i]) * (meanValue - dnum[i]);
	}
	printf("The standard deviation is: %.2lf\n", sqrt(sum / 5));
	//maximal sum of 2 continuous numbers
	for (int i = 0; i < 4; i++)
		if (dnum[i] + dnum[i + 1] >= max)
			max = dnum[i] + dnum[i + 1];
	printf("The maximal sum of 2 continuous numbers is: %.2lf\n",max);
	return 0;
}