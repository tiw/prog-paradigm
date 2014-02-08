typedef struct {
    void *elems;
    int elemSize;
    int logicallength;
    int alloclength;
} stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
