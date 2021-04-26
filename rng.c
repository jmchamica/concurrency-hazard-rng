#include <stdio.h>
#include <omp.h>

int main()
{
	int chaos = 10000;
	int bound = 10;

	int i;

	// RNG will purposefully cause concurrency hazard
	// by incrementing this variable
	long hazard = 0;

	#pragma omp parallel for schedule(guided)
	for (i = 0; i < chaos; i++)
		hazard++;

	printf("%ld\n", hazard % bound);
}

