#include "stack.h"
#include <assert.h>
#include <stdlib.h>

void StackNew(stack *s)
{
    s->logicallen = 0;
    s->alloclength = 4;
    s->elemtns = malloc(4 * sizeof(int));
    assert(s->elemtns != NULL);
}

int main()
{
    stack s;// automatic allocate memory
    StackNew(&s);
}
