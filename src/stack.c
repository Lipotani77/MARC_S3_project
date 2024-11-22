//
// Created by flasque on 19/10/2024.
//

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "../include/stack.h"

/**
 * @brief Function to create a stack
 * @param size : the size of the stack
 * @return the stack
 */
t_stack createStack(int size)
{
    // the size of the stack must be positive
    assert(size > 0);
    t_stack stack;
    stack.size = size;
    stack.nbElts = 0;
    stack.values = (int *)malloc(size * sizeof(int));
    return stack;
}

/**
 * @brief Function to push a value in the stack
 * @param stack : the stack
 * @param value : the value to push
 * @return none
 */
void push(t_stack *p_stack, int value)
{
    // the stack must not be full
    assert(p_stack->nbElts < p_stack->size);
    p_stack->values[p_stack->nbElts] = value;
    p_stack->nbElts++;
    return;
}

/**
 * @brief Function to pop a value from the stack
 * @param stack : the stack
 * @return the value popped
 */
int pop(t_stack *p_stack)
{
    // the stack must not be empty
    assert(p_stack->nbElts > 0);
    p_stack->nbElts--;
    return p_stack->values[p_stack->nbElts];
}

/**
 * @brief Function to get the top value of the stack
 * @param stack : the stack
 * @return the top value
 */
int top(t_stack stack)
{
    // the stack must not be empty
    assert(stack.nbElts > 0);
    return stack.values[stack.nbElts - 1];
}

void removevalfromstack(t_stack *stack, int value){
    t_stack temp ;
    temp = createStack(10);
    int found = 0 ;
    int tempval ;
    int counter =0 ;
    while (found == 0){

        tempval = pop(stack);
        if (tempval == value){
            found = 1;
        }
        else{
            push(&temp, tempval);
        }
        counter++;
    }

    while (counter >1){
        push(stack, pop(&temp));
        counter --;
    }

}

int is_stack_empty(t_stack* stack)
{
    return (stack->nbElts == 0);
}

t_stack copy_stack(t_stack stack)
{
    t_stack copy;

    copy.size = stack.size;
    copy.nbElts = stack.nbElts;
    copy.values = malloc(copy.nbElts * sizeof(t_move));

    for (int i = 0; i < stack.size; i++) {
        copy.values[i] = stack.values[i];
    }

    return copy;
}

void free_stack(t_stack stack)
{
    if (stack.values != NULL)
    {
        free(stack.values);
        stack.values = NULL;
    }

    stack.size = 0;
    stack.values = 0;
}


