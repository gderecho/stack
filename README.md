#stack

A very bland C implementation of a stack of integers.

Usage:
```c
struct stack my_stack;
init_stack(&my_stack);
push(3, &stack);
printf("Let's pop the value now: %d\n", 
        pop(&stack));
free_stack_data(&my_stack);
```
