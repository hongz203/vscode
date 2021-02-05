#include <stdio.h>

// 0 <= N <= 12

long long fact(int n)
{
    if (n == 1 || n ==0)
        return 1;
    
    return n * fact(n-1);
}

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