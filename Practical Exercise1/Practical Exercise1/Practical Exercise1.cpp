// Practical Exercise 2 (Non-Assessed).cpp : Defines the entry point for the console application.
//

#include <iostream>

int main()
{
	char message1[] = "Give me a first number: ";
	char message2[] = "\bGive me a second number: ";
	char message3[] = "\nThe numbers are equal!\n";
	// char message4[] = "\nThe numbers are not equal!\n";
	char message5[] = "Type in any integer and press ENTER key to finish: ";
	char format[] = "%d";	// format string for the scanf function

	char message6[] = "\nThe first number is greater!\n";	// new addition
	char message7[] = "\nThe second number is greater!\n";	// new addition

	int first;
	int second;
	int end;

	_asm {
		lea		eax, message1
		push	eax
		call	printf; printing the first message
		add		esp, 4

		lea		eax, first
		push	eax
		lea		eax, format
		push	eax
		call	scanf_s; reading the first number
		add		esp, 8

		lea		eax, message2
		push	eax
		call	printf; printing the second message
		add		esp, 4

		lea		eax, second
		push	eax
		lea		eax, format
		push	eax
		call	scanf_s; reading the second number
		add		esp, 8

		mov		eax, first
		mov		ebx, second
		cmp		eax, ebx; compare two numbers, jump to nequal if flag is not zero
		jg		firstNumGreater
		jl		secondNumGreater

		equal :
		lea		eax, message3
			push	eax
			call	printf; printing the third message
			add		esp, 4
			jmp		finish

			firstNumGreater :
		lea		eax, message6
			push	eax
			call	printf; printing the sixth message
			add		esp, 4
			jmp		finish

			secondNumGreater :
		lea		eax, message7
			push	eax
			call	printf; printing the seventh message
			add		esp, 4

			finish:
		lea		eax, message5
			push	eax
			call	printf; printing the fifth message
			add		esp, 4

			lea		eax, end
			push	eax
			lea		eax, format
			push	eax
			call	scanf_s; reading any integer to end program
			add		esp, 8
	}
	return 0;
}