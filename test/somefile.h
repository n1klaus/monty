#include <stdio.h>
#include <unistd.h>

#define BAR 1

/**
 * <----- RULES ON USING EXTERN ----->
 * 1. You can't initialize and declare extern at the same time
 *     i.e in the header file 
 * 2. Best to declare the variables before function definition 
 * 3. Use the volatile qualifier for the global variables 
 *     accessed and modified by multiple tasks*
 * 4. The instance of the declared variable has to be initialized
 *     if it will be modified
 * 5. The other instance(s) of the declared variable is declared with
 *     the extern keyword beforehand with no initialization value
 *     i.e where it will be only used and no modification will be made
 */
extern volatile unsigned int stop_now;
void bar_function(void);