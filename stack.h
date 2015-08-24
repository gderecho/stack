#ifndef STACK_STACK_H_
#define STACK_STACK_H_
/* stack.h */

struct stack {
    struct node *head;
};

int init_stack(struct stack*);
int is_empty(struct stack*);
int push(int, struct stack*);
int pop(struct stack*);
int free_stack_data(struct stack*);

#endif /* STACK_STACK_H_ */
