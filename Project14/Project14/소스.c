#include <stdio.h>

void convert(double *grades, double *scores, int size);
int main()
{

	double grades[10] = { 3.5, 4.0, 3.2, 4.1, 3.4, 2.7, 1.0, 2.9, 3.8, 4.4 }; 
	double scores[10] = { 0 };
	int i;
	convert(grades, scores,1);
	for (i = 0; i < 10; i++) {
		printf("%lf \n",scores[i]);
	}
}

void convert(double *grades, double *scores, int size)
{
	int i;
	for (i = 0; i < 10; i++) {
		scores[i] = grades[i] * 100 / 4.5;
	}
}