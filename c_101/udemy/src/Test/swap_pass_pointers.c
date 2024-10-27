#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;  /* save the value at address x in temp*/ 
    *x = *y;    /* put y to x */
    *y = temp;  /* put temp to y */

    return;
}

int main()
{
    /* local variable definition */
    int a = 100;
    int b = 200;

    printf("Before swap, value of a: %d\n", a);
    printf("Before swap, value of b: %d\n", b);

    swap(&a, &b);

    printf("Aftere swap, value of a: %d\n", a);
    printf("After swap, value of b: %d\n", b);

    return 0;
}