#include <stdio.h>

int main() {

int a, b;
scanf("%d %d", &a, &b);

if(a <= 0)  {
    printf("please insert postive integer\n");
    return 0;
}

if(b >= 10) {
    printf("please insert less than 10 integer\n");
    return 0;
}

printf("%d\n", a+b);

return 0;
}