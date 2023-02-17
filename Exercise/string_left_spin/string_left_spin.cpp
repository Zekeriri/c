#include <stdio.h>
//void left_spin(char* str, int);
//void spin(char* str,int k);
//int main()
//{
//	char str[5] = "ABCD";
//	int k = 2;
//	left_spin(str, k);
//	printf("%s", str);
//	return 0;
//}
//void left_spin(char* str, int k)
//{
//	for (int i = 0; i < k; i++)
//	{
//		spin(str, 4);
//	}
//}
//void spin(char* str,int k)
//{
//	char temp = str[0];
//	for (int i = 0; i < k-1; i++)
//	{
//		str[i] = str[i + 1];
//	}
//	str[k - 1] = temp;
//}

void leftRound(char* src, int time)
{
	int i, j, tmp;
	int len = strlen(src);
	time %= len; //长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
	for (i = 0; i < time; i++) //执行k次的单次平移
	{
		tmp = src[0];
		for (j = 0; j < len - 1; j++) //单次平移
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}