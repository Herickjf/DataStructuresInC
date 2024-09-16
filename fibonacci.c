#include <stdio.h>

long long fibonacci(int);
// 1 1 2 3 5 8 
int main(){
    printf("%lld\n", fibonacci(5));
    return 0;
}

long long fibonacci(int n){
    if(n<2) return 1;
    long long a = fibonacci(n-1);
    long long b = fibonacci(n-2);
    return ( a + b );
}