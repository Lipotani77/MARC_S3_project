//
// Created by flasque on 19/10/2024.
//

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "../include/stack.h"

/**
 * @brief Function to create a stack
 * @param size : the physical size of the stack
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
    t_stack copy = createStack(stack.size); // create an empty stack with the same size

    if (stack.values == NULL) { // if the stack is empty, return the empty stack
        printf("The stack you are trying to copy is empty\n");
        return copy;
    }
    else{
        for (int i = 0; i < stack.size; i++) { // copy the values
            copy.values[i] = stack.values[i];
        }
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

t_stack remove_current_move_from_stack(t_stack *stack, t_move move)
{
    // Create a new stack to hold elements excluding the given move
    t_stack new_stack = createStack(stack->size);

    // Temporary stack to iterate through the original stack without modifying it
    t_stack temp_stack = copy_stack(*stack);

    // Flag to know if the move has already been found and removed
    int found = 0;

    // Iterate through the copied stack
    while (!is_stack_empty(&temp_stack))
    {
        int current_move = pop(&temp_stack); // Pop from the copied stack
        if (!found && current_move == move)
        {
            found = 1; // Mark the move as found, and skip adding it to the new stack
            continue;
        }

        // Add to the new stack if it doesn't match the move
        push(&new_stack, current_move);
    }

    return new_stack;
}


void displayStack(t_stack stack)
{
    if (stack.nbElts == 0)
    {
        printf("The stack is empty.\n");
        return;
    }

    for (int i = 0; i != stack.nbElts; i++)
    {
        printf("%d, ", stack.values[i]);
    }
    printf("\n");
}




