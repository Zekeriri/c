#include <stdio.h>
void bin_ope(int num)
{
	printf("odd:\n");
	for (int i = 31; i>=1 ; i-=2)
	{
		printf("%d", (num >>i)&1);
	}
	printf("\n");
	printf("even:\n");
	for (int i = 30; i >=0 ; i -=2)
	{
		printf("%d", (num>>i&1));
	}
	printf("\n");
}

int main()
{
	int num = -1;
	bin_ope(num);
}