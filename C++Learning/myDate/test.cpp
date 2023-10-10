#include"date.h"

void testDate()
{
	Date d1(2023,10,6);
	Date d2(1999, 1, 1);
	cout << d1-d2;
}
int main()
{
	testDate();
}