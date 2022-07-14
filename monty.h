#ifndef __MONTY_H__
#define __MONTY_H__

#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <aio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define STACK_SIZE 1024
#define MAXLEN 100


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
void (*get_opcode(char *op))(stack_t **top, unsigned int line);
void push(stack_t **top, unsigned int line);
void pall(stack_t **top, unsigned int line);
void pint(stack_t **top, unsigned int line);
void pop(stack_t **top, unsigned int line);
void pop(stack_t **top, unsigned int line);
void swap(stack_t **top, unsigned int line);
void add(stack_t **top, unsigned int line);
void nop(stack_t **top, unsigned int line);

#endif /* __MONTY_H__ */