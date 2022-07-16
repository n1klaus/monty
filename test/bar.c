#include "somefile.h"
extern volatile unsigned int stop_now;
/**
 * bar_function - print depending on state of extern variable
 * 
 * Return: Nothing
 */
void bar_function(void)
{
	/* if stop_now == 0 */
	if (!stop_now)
	{
		printf("Hello, bar!\n");
		sleep(1);
	}
	/* if stop_now == 1 */
	else
	{
		printf("Goodbye, bar!\n");
		sleep(1);
	}
}