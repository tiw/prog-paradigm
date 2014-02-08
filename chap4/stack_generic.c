#include "stack_generic.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void StackNew(stack *s, int elemSize)
{
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->logicallength = 0;
    s->alloclength = 4;
    s->elems = malloc(4*s->elemSize);
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

static void StackGrow(stack *s)
{
    s->alloclength *= 2;
    s->elems = realloc(s->elems, s->logicallength * s->elemSize);
}

void StackPush(stack *s, void *elemAddr)
{
    if (s->logicallength == s->alloclength) {
        StackGrow(s);
    }
    void *target = (char *)s->elems + s->logicallength * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logicallength++;

}

void StackPop(stack *s, void *elemAddr)
{
    void *source = (char *) s->elems + (s->logicallength - 1) * s->elemSize;
    memcpy(elemAddr, source, s->elemSize);
    s->logicallength--;
}


typedef struct {
    int x;
    int y;
} axis;

int main()
{
    stack s;
    StackNew(&s, sizeof(int));
    int two = 2;
    StackPush(&s, &two);
    int three = 3;
    StackPush(&s, &three);
    int top;
    StackPop(&s, &top);
    printf("the last element is %d\n", top);
    int result;
    memcpy(&result, s.elems, sizeof(int));
    printf("the result is %d\n", result);
    printf("the size of int is %lu\n", sizeof(int));


    stack floatStack;
    StackNew(&floatStack, sizeof(float));
    float f = 1.2;
    StackPush(&floatStack, &f);
    float f2 = 2.3;
    StackPush(&floatStack, &f2);
    float topf;
    StackPop(&floatStack, &topf);
    printf("the last element is %f\n", topf);
    

    stack axisStack;
    printf("the size of axis is: %lu\n", sizeof(axis));
    StackNew(&axisStack, sizeof(axis));
    axis a1 = {2, 2};
    StackPush(&axisStack, &a1);
    axis a2 = {3, 4};
    StackPush(&axisStack, &a2);
    axis atop;
    StackPop(&axisStack, &atop);
    printf("the last elements x is: %d, the y is %d\n", atop.x, atop.y);


    stack stringStack;
    StackNew(&stringStack, sizeof(char*));
    char *a = "hello";
    StackPush(&stringStack, &a);

    char *b = "world";
    StackPush(&stringStack, &b);

    char *r;
    StackPop(&stringStack, &r);
    printf("the word is: %s", r);

}
