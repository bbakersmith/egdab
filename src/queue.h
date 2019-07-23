/**
 * @file queue.h
 *
 * @brief General purpose queue implementations.
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * The contents and metadata of a circular FIFO queue with 255 values.
 */
typedef volatile struct QueueFifo {
  uint8_t count;
  uint8_t head;
  uint8_t max;
} QueueFifo;

/**
 * Create a new circular FIFO queue with space reserved for 255 uint8 values.
 * Drops oldest value in queue on rollover.
 *
 * @return Queue
 */
QueueFifo queue_fifo_new(uint8_t max);

/**
 * Check if queue is empty.
 *
 * @return True if empty
 */
bool queue_fifo_is_empty(QueueFifo *queue);

/**
 * Push value onto the back of the queue.
 */
uint8_t queue_fifo_push(QueueFifo *queue);

/**
 * Return the value at head without modifying the queue.
 *
 * @return Value at head of queue
 */
uint8_t queue_fifo_peek(QueueFifo *queue);

/**
 * Return the value at head and move head to next value.
 *
 * @return Value at head of queue
 */
uint8_t queue_fifo_pop(QueueFifo *queue);

#endif
