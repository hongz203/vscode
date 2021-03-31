#include <stdio.h>

// 0 <= N <= 12

long long fact(int n)
{
    if (n == 1 || n ==0)
        return 1;
    
    return n * fact(n-1);
}

/*
//n =5 ¶ó¸é
return 5 * fact(4);
       5 * 4 * fact(3)
       5 * 4 * 3 * fact(2)
       5 * 4 * 3 * 2 * fact(1)
       5 * 4 * 3 * 2 * 1
*/     

int main()
{
    int n;

    scanf("%d", &n);
    if(n < 0 || n > 12) {
        printf("Out of bounds\n");
        return 0;
    }
        
    printf("%lld", fact(n));
}