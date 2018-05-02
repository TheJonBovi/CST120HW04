#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <stdio.h>  // NOLINT

// Code help from https://stackoverflow.com/questions/11277641/input-data-validation-in-c
// TODO: Does not ask for new number if float is input
int get_number()
{
	double result = 1'000'001;
	char input[80]; // arbitrary size buffer
	printf("Enter a number between -1,000,000 and 1,000,000: ");
	getchar();

	while (result == OOB)
	{
		char* cp = fgets(input, sizeof(input), stdin);
		if (cp == input)
		{
			char* badc; // badc is for detecting extraneous chars in the input
			int const n = sscanf(input, "%lf %c", &result, &badc);
			printf("\n");

			if (n != 1) // if badc captured an extraneous char
			{
				printf("Error! Please enter an integer: ");
				result = OOB;
			}
			else if (result < -1'000'000 || result > 1'000'000)
			{
				printf("Error! Integer out of range, enter a different integer: ");
				result = OOB;
			}
		}
	}
	return result;
}

void check_sign(int const number)
{
	if (number >= 0)
	{
		printf("The number %d is positive.\n\n", number);
	}
	else
	{
		printf("The number %d is negative.\n\n", number);
	}
}

void check_parity(int const number)
{
	if (number % 2 == 0)
	{
		printf("The number %d is even.\n\n", number);
	}
	else
	{
		printf("The number %d is odd.\n\n", number);
	}
}

void num_digits(int const number)
{
	long n = number;
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		++count;
	}

	printf("The number %d has %d digits.\n\n", number, count);
}

void print_add_table()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// Output formatting depending on number of digits
			if (i + j < 10)
			{
				printf(" %d ", i + j);
			}
			else
			{
				printf("%d ", i + j);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void print_mul_table()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// Special formatting for first row - show the index
			if (i == 0)
			{
				if ( j == 0)
				{
					printf(" %d ", j);
				}
				else if (j < 10)
				{
					printf("  %d ", j);
				}
			}
			// Special formatting for first column - show the index
			else if (j == 0)
			{
				printf(" %d ", i);

			}
			// Special formatting for final row due to 3 digit number
			else if (i == 10)
			{
				if ( j <= 1)
				{
					printf("%d ", i * j);
				}
				else if (j < 10)
				{
					printf(" %d ", i * j);
				}
			}
			// Fill rest of table with products
			else if (i * j < 10)
			{
				printf("  %d ", i * j);
			}
			else if (i * j < 100)
			{
				printf(" %d ", i * j);
			}
		}
		printf("\n");
	}
	printf("\n");
}
