//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_STACK_H
#define UNTITLED1_STACK_H
#include "moves.h"


/**
 * @brief Structure for the stack of integers
 */
typedef struct s_stack
{
    int *values;
    int size;
    int nbElts;
} t_stack;

/**
 * @brief Function to create a stack
 * @param size : the size of the stack
 * @return the stack
 */
t_stack createStack(int);

/**
 * @brief Function to push a value in the stack
 * @param pointer to the stack
 * @param value : the value to push
 * @return none
 */
void push(t_stack *, int);

/**
 * @brief Function to pop a value from the stack
 * @param : pointer to the stack
 * @return the value popped
 */
int pop(t_stack *);

/**
 * @brief Function to get the top value of the stack
 * @param stack : the stack
 * @return the top value
 */
int top(t_stack);

/**
 * @brief Function to remove a value from the stack
 * @param stack : the stack
 * @param value : the value to remove
 * @return none
 */
void removevalfromstack(t_stack *stack, int value);

/**
 * @brief Function to check if the stack is empty
 * @param stack : the stack
 * @return 1 if the stack is empty, 0 otherwise
 */
int is_stack_empty(t_stack*);

/**
 * @brief Function to copy a stack
 * @param stack : the stack to copy
 * @return the copy of the stack
 */
t_stack copy_stack(t_stack);

/**
 * @brief Function to free the stack
 * @param stack : the stack to free
 * @return none
 */
void free_stack(t_stack);

/**
 * @brief Function to remove the last element of the stack
 * @param stack : the stack
 * @return none
 */
t_stack remove_current_move_from_stack(t_stack *stack, t_move move);

/**
 * @brief Function to display the stack
 * @param stack : the stack to display
 * @return none
 */
void displayStack(t_stack);




#endif //UNTITLED1_STACK_H
