#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // NOLINT
#include "functions.h"

void main(void)
{
	int program_run = 1;
	int input_flag = 0;
	int input = 0;
	int choice;

	while (program_run)
	{
		printf("*************Main Menu*************\n\n");
		printf(" 1 - Enter an Integer\n");
		printf(" 2 - Sign Check\n");
		printf(" 3 - Parity Check\n");
		printf(" 4 - Display Number of Digits\n");
		printf(" 5 - Display Addition Table\n");
		printf(" 6 - Display Multiplication Table\n");
		printf(" 7 - Exit\n\n");

		printf("Enter your choice and press return: ");

		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			input = get_number();
			input_flag = 1;
			break;

		case 2:
			if (input_flag)
			{
				check_sign(input);
			}
			else
			{
				printf("Enter a number first!\n\n");
			}
			break;

		case 3:
			if (input_flag)
			{
				check_parity(input);
			}
			else
			{
				printf("Enter a number first!\n\n");
			}
			break;

		case 4:
			if (input_flag)
			{
				num_digits(input);
			}
			else
			{
				printf("Enter a number first!\n\n");
			}
			break;

		case 5:
			print_add_table();
			break;

		case 6:
			print_mul_table();
			break;

		case 7:
			printf("End of program.\n\n");
			program_run = 0;
			break;

		default:
			printf("Not a valid choice, choose again.\n\n");
			printf("Enter your choice and press return: ");

			scanf("%d", &choice);
			break;
		}
	}

	// Below prevents console window from closing after program completion
	while (getchar() != '\n');
	printf("press enter to continue...\n");
	getchar();
}

