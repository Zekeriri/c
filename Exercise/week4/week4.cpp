#include <iostream>

int main()
{
	int array[3] = { 3,2,1 };

	_asm 
	{		
					lea esi, array
					mov ecx, 3

		outerLoop:  
					mov edx, ecx

		innerLoop : 
					cmp edx, ecx
					jz noExchange

					mov eax, [esi + ecx * 4 - 4]
					mov ebx, [esi + edx * 4 - 4]

					cmp ebx, eax
					jl noExchange

					mov[esi + ecx * 4 - 4], ebx
					mov[esi + edx * 4 - 4], eax
		noExchange : 
					dec edx
					jnz innerLoop

					loop outerLoop
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}