#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

void A(int* murder)
{
	murder[1] = 0;
}
void B(int* murder)
{
	murder[3] = 1;
}
void C(int* murder)
{
	murder[4] = 1;
}
void D(int* murder)
{
	murder[4] = 0;
}
int check(int* murder)
{
	int j = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (murder[i] == 1)
		{
			j++;
		}
	}
	if (j == 1)
	{
		return 1;
	}
	return 0;
}

void print(int* murder)
{
	for (int i = 1; i <= 4; i++)
	{
		printf("%d", murder[i]);
	}
	printf("\n");
}

int main()
{
	
	for (int i = 1; i <= 4; i++)
	{
		int murder[5] = { 0 };
		switch (i)
		{
		case 1:
			B(murder);
			C(murder);
			D(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		case 2:
			A(murder);
			C(murder);
			D(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		case 3:
			B(murder);
			A(murder);
			D(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		case 4:
			B(murder);
			C(murder);
			A(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		default:
			break;
		}

	}
}