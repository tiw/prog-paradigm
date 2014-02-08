typedef struct {
     int *elemtns;
     int logicallen;
     int alloclength;
} stack;


void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);
