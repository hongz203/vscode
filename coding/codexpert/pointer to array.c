#include <stdio.h>

int main()
{
    char a[3] = {'a','b','c'};

    printf("%p\n",a);
    printf("%c\n",a[1]);
    printf("%c\n",a[2]);
#if 0
    printf("%p\n",a);
    printf("%p\n", &(a[0]));
    printf("%p\n", &a[0]);

    printf("%s\n",a);
#endif
    return 0;
}