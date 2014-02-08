#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void StackNew(stack *s)
{
    s->logicallen = 0;
    s->alloclength = 4;
    s->elemtns = malloc(4 * sizeof(int));
    assert(s->elemtns != NULL);
}

void StackDispose(stack *s)
{
    free(s->elemtns);
}

void StackPush(stack *s, int value)
{
    if (s->alloclength == s->logicallen) {
        s->alloclength *= 2;
        s->elemtns = realloc(s->elemtns, s->alloclength*sizeof(int));
        assert(s->elemtns != NULL);
    }
    s->elemtns[s->logicallen] = value;
    s->logicallen ++;
}

int StackPop(stack *s)
{
    assert(s->logicallen > 0);
    s->logicallen --;
    return s->elemtns[s->logicallen];
}

int main()
{
    stack s;// automatic allocate memory
    StackNew(&s);
    StackPush(&s, 12);
    StackPush(&s, 13);
    StackPush(&s, 14);
    printf("the number popped is %d \n", StackPop(&s));
    printf("the number popped is %d \n", StackPop(&s));
    printf("the number popped is %d \n", StackPop(&s));
    StackDispose(&s);
}
