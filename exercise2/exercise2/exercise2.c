#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int binaryNumber(int dec);
int main()
{
	int num;
	scanf("%d", &num);
	printf("The decimal value %d is %d in binary\n", num, binaryNumber(num));
	printf("The decimal value %d is %x in hexadecimal\n", num,num);
}

int binaryNumber(int dec) {
	int result = 0, temp = 1, yushu = 0;
	while (1) {
		yushu = dec % 2;
		dec /= 2;
		result += yushu * temp;
		temp *= 10;
		if (dec < 2)
		{
			result += dec * temp;
			break;
		}
	}
	return result;

}