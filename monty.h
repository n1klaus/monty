#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define STD_OUT 1
#define STD_ERR 2
#define STACK_SIZE 1024
#define MAXLEN 100
#define ISUNKNOWN 1;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int file_stream(int ac, char **av);
int (*get_opcode(char *op))(stack_t **top, unsigned int line);
int push(stack_t **top, unsigned int line);
int pall(stack_t **top, unsigned int line);
int pint(stack_t **top, unsigned int line);
int pop(stack_t **top, unsigned int line);
int pop(stack_t **top, unsigned int line);
int swap(stack_t **top, unsigned int line);
int add(stack_t **top, unsigned int line);
int nop(stack_t **top, unsigned int line);

#endif /* __MONTY_H__ */