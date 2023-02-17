#include <stdio.h>
int left_spin(char* s1, int size,char* s2);
void spin(char* str, int k);
int main()
{
	char s1[6] = "AABCD";
	char s2[6] = "BCDAA";
	int size = sizeof(s1) / sizeof(s1[0])-1;
	
	printf("%d", left_spin(s1, size, s2));
	return 0;
}
int left_spin(char* s1, int size, char* s2)
{
	for (int i = 0; i < size; i++)
	{
		spin(s1, size);
		if (s1 = s2)
		{
			return 1;
		}
	}
	return 0;
}
void spin(char* str, int k)
{
	char temp = str[0];
	for (int i = 0; i < k - 1; i++)
	{
		str[i] = str[i + 1];
	}
	str[k - 1] = temp;
}

int findRound(const char* src, char* find)
{
	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
	strcpy(tmp, src); //先拷贝一遍
	strcat(tmp, src); //再连接一遍
	return strstr(tmp, find) != NULL; //看看找不找得到
}