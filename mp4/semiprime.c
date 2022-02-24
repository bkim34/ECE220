#include <stdlib.h>
#include <stdio.h>

/* Partners: jaejin2, thomasp6
For the is_prime function, I swapped the o and 1 because it is supposed to return 1 not 0 if it is prime.
I also swapped i%j to i/j in print_semiprimes since it would always send 0 with %. lastly, I added a ret 1
 and break inside the final if statement in print_semiprimes, since the program is supposed to return 1 if 
the number is a semi prime and if it passes 
all those if statements it is. the break added makes sure there arent multiple of the same semi prime.
*/
/*
 * is_prime: determines whether the provided number is prime or not
 * Input    : a number
 * Return   : 0 if the number is not prime, else 1
 */
int is_prime(int number)
{
    int i;
    if (number == 1) {return 0;}
    for (i = 2; i < number; i++) { //for each number smaller than it
        if (number % i == 0) { //check if the remainder is 0
            return 0;
        }
    }
    return 1;
}


/*
 * print_semiprimes: prints all semiprimes in [a,b] (including a, b).
 * Input   : a, b (a should be smaller than or equal to b)
 * Return  : 0 if there is no semiprime in [a,b], else 1
 */
int print_semiprimes(int a, int b)
{
    int i, j, k;
    int ret = 0;
    for (i = a; i <=b; i++) { //for each item in interval
        //check if semiprime
        for (j = 2; j <= i; j++) {
            if (i%j == 0) {
                if (is_prime(j)) {
                    k = i/j;
                    if (is_prime(k)) {
                        printf("%d ", i);
                        ret = 1;
                        break;
                    }
                }
            }
        }

    }
    printf("\n");
    return ret;
}
