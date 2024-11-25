//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_QUEUE_H
#define UNTITLED1_QUEUE_H

#include "loc.h"

/**
 * @brief Structure for the queue of integers
 */
typedef struct s_queue
{
    t_position *values;
    int size;
    int last;
    int first;
} t_queue;

/**
 * @brief Structure for the queue of integers, it is used for the creation of the tree
 */
typedef struct s_queue2
{
    int *values;
    int size;
    int last;
    int first;
} t_queue_int;

/**
 * @brief Function to create a queue
 * @param size : the size of the queue
 * @return the queue
 */
t_queue createQueue(int);

/**
 * @brief Function to create a queue that contains integers
 * @param size : the size of the queue
 * @return the queue
 */
t_queue_int createQueue_int(int);

/**
 * @brief Function to enqueue a value in the queue
 * @param p_queue : pointer to the queue
 * @param value : the position to enqueue
 * @return none
 */
void enqueue(t_queue *,t_position);

/**
 * @brief Function to dequeue a value from the queue
 * @param p_queue : pointer to the queue
 * @return the value dequeued
 */
t_position dequeue(t_queue *);

/**
 * @brief Function to enqueue an int in the queue
 * @param size : the size of the queue
 * @return nothing
 */
void new_enqueue(t_queue_int *p_queue,int move);

/**
 * @brief Function to dequeue an int from the queue
 * @param size : the size of the queue
 * @return nothing
 */
int new_dequeue(t_queue_int *p_queue);

#endif //UNTITLED1_QUEUE_H
