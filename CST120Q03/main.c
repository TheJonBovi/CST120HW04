#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define PI 3.14
#define area(r) PI*r*r
#define circ(r) PI*r*2

void main(void)
{
	int run_program = 1;

	while (run_program)
	{
		double input;
		printf("Enter an radius in meters: ");

		scanf("%lf", &input);

		double const circumference = circ(input);
		double const area = area(input);

		printf("The circumference of a circle with radius %0.2lf is %0.2lf.\n", input, circumference);
		printf("The area f a circle with radius %0.2lf is %0.2lf.\n", input, area);

		char run_again;
		printf("\nEnter Y or y to run again: ");
		scanf(" %c", &run_again);

		// ASCII Values for Y and y, respectivly
		if (run_again == 89 || run_again == 121)
		{
			run_program = 1;
			getchar();
		}
		else
		{
			run_program = 0;
		}
	}
}