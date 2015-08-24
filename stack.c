/* stack.c
 * the implementation of the
 * stack functions */
#include <stddef.h>
#include <stdlib.h>

#include "stack.h"

struct node {
    int value;
    struct node *next;
};

int init_stack(struct stack *stack_)
{
    if(!stack_)
        return EXIT_FAILURE;
    stack_->head = NULL;
    return EXIT_SUCCESS;
}

int push(int value, struct stack *stack_)
{
    struct node *to_insert;
    if(!stack_)
        return EXIT_FAILURE;
    to_insert = malloc(sizeof(*to_insert));
    if(!to_insert)
        return EXIT_FAILURE;

    to_insert->value = value;
    to_insert->next = stack_->head;
    stack_->head = to_insert;
    return EXIT_SUCCESS;
}

int is_empty(struct stack *stack_)
{
    if(!stack_ || !stack_->head)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int pop(struct stack *stack_)
{
    struct node *temp;
    int to_return;
    temp = stack_->head;
    stack_->head = stack_->head->next;
    to_return = temp->value;
    free(temp);
    return to_return;
}

/* helper function for free_stack_data */
static int free_at(struct node*);

int free_stack_data(struct stack *stack_)
{
    struct node *temp;
    if(!stack_)
        return EXIT_FAILURE;
    temp = stack_->head;
    stack_->head = NULL;
    return free_at(temp);
}

int free_at(struct node *current)
{
    struct node *temp;
    if(!current)
        return EXIT_SUCCESS;
    temp = current->next;
    free(current);
    return free_at(temp);
}
