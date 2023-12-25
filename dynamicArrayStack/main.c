#include "dynamicArrayStack.h"
#include "common.h"
#include <stdio.h>


#define BUFFER_SIZE 5


int main()
{
    dynamicArrayStack *stack;

    /* 怎么解决套壳问题 */
    dynamicArrayStackInit(&stack);

    int buffer[BUFFER_SIZE] = {5, 32, 21, 56, 87};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        dynamicArrayStackPush(stack, &buffer[idx]);
    }

    int size = 0;
    dynamicArrayStackGetSize(stack, &size);
    printf("size: %d\n", size);

    int *val = NULL;
    while(!dynamicArrayStackIsEmpty(stack))
    {
        dynamicArrayStackTop(stack, (void **)&val);
        printf("val: %d\n", *val);
        dynamicArrayStackPop(stack);
    }

    /* 栈的销毁 */
    //dynamicArrayStackDestroy(stack);

    
    return 0;
}