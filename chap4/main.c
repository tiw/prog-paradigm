#include <stdio.h>
#include <string.h>

void swap(int *ap, int *bp){
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}

void generic_swap(void *a, void *b, int size) {
    char buffer[size];
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
}

int main() {
    int *ap, *bp;
    int a, b;
    a = 2;
    b = 3;
    ap = &a;
    bp = &b;
    swap(ap, bp);
    printf("The value of ap is: %d\n", *ap);
    printf("The value of bp is: %d\n", *bp);

    float fa, fb;
    fa = 1.2;
    fb = 2.3;
    float *pfa, *pfb;
    pfa = &fa;
    pfb = &fb;
    generic_swap(pfa, pfb, sizeof(float));
    printf("The value of pfa is: %f\n", *pfa);
    printf("The value of pfb is: %f\n", *pfb);
    return 1;
}
