//Athavan Jesunesan

#include <time.h>
#include <stdio.h>

unsigned long long factorial_it(unsigned long long x, int n);
unsigned long long factorial_rec(unsigned long long n); //declaring the recursive method with the parameters being the factorial number

int main(){

    /* Iterative Version */

    int n;
    printf("Enter a number: ");
    scanf("%d",&n);      //The number we are applying factorial to

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    unsigned long long x = factorial_it(1, n); //finding the factorial in iterative method

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Iterative Factorial of %d is: %llu(%Lf seconds to exectute) \n", n, x, cpu_time_used);

    /* Recursive Version */

    start = clock();
    x = factorial_rec(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Recursive Factorial of %d is: %llu(%Lf seconds to exectute) \n", n, x, cpu_time_used);

}

unsigned long long factorial_it(unsigned long long x, int n){
    for(unsigned long long i=1;i<n+1;i++){
            x = x*i;
        }
    return x;
}

unsigned long long factorial_rec(unsigned long long n){

    if(n==1){
        return 1;
    }
    else{
        return n*factorial_rec(n-1);
    }
}








