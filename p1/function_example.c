#include <stdio.h>

int readInt();
void printInt(int x);


int main()
{
	int a,b,c;
	a = readInt();
	b = readInt();
	c = (a + b) * (a - b);
	printInt(c);
	return 0;
}

int readInt()
{
	int result;
	printf("please type a an integer\n");
	scanf("%d", &result);
	return result;


}

void printInt(int x)
{

	printf("the result is %d\n", x);
}



