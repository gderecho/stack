/* test_stack.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    const int test_values[] = {2,5,2,3,2,6,4,2,3,7,2,3,2,2,7,5,3,2};
    int *test_values_compare;
    int test_values_len = sizeof(test_values)/sizeof(test_values[0]);
    int i,j;
    struct stack test_stack;

    test_values_compare = malloc(sizeof(test_values));

    init_stack(&test_stack);
    for(i=0; i<test_values_len; i++) {
        push(test_values[i],&test_stack);
    }

    printf("Expected: ");
    for(j = test_values_len-1; j!=-1; j--) {
        printf("%d ", test_values[j]);
    }

    printf("\nActual:   ");

    j = test_values_len;
    while(!is_empty(&test_stack)) {
        i=pop(&test_stack);
        printf("%d ",i);
        j--;
        test_values_compare[j] = i;
        if(test_values_compare[j] != test_values[j])
            printf("TEST FAILED\n");
    }
    printf("\ntest passed!\n");
    free_stack_data(&test_stack);
    free(test_values_compare);
    return 0;
}
