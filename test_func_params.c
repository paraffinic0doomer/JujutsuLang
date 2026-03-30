/* Parser-generated C from JujutsuLang source */
#include <stdio.h>

int result;
int x;
int y;

int add(int a, int b)
{
    return a + b;
}

int main(void) {
    printf("%s\n", "Enter value of x:");
    scanf("%d", &x);
    printf("%s\n", "Enter value of y:");
    scanf("%d", &y);
    result = add(x, y);
    printf("%s\n", "Result from add(x,y):");
    printf("%g\n", (double)(result));
    return 0;
}
