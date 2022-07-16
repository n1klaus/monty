#include "somefile.h"
volatile unsigned int stop_now = 0;
/**
 * main - test extern storage classes 
 * 
 * Return: Always 0
 */
int main(void)
{
	int counter = 0;
	while (BAR)
	{
		bar_function();
		stop_now = 1;
		if (counter == 1 || counter == 3)
			stop_now = 0;
		if (counter == 5 && stop_now)
			break;
		counter++;
	}
	return (0);
}