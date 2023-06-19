#include <stdio.h>
#include "example.h"

void say_hello()
{
	printf("hello\n");

}

void say_goodbye()
{
	printf("goodbye\n");


}

void repeat_function(int n, greeting_function_t callback )
{
	int i;
	for(i = 0; i < n; i++)
	{
		callback();
	}

}

int add_numbers(int x, int y)
{
	return x + y;
}

int main()
{
	//* Declare a new variable named greeting *//
	greeting_function_t greeting;	

	// & 붙이고 안붙이고 결과는 같으나 다른사람이 보기 위해서 붙인다.
	// 파이썬은 &안붙이나 C프로그램은 & 붙이는게 관습이다.
	greeting = &say_hello;



	(*greeting)();


	meters_t height = 5.0;



	printf("The thing is %2.f meters tall\n", height);




	repeat_function(10, say_hello);


	greeting = say_goodbye;

	greeting();


	return 0;
}

