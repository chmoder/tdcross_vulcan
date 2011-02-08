#include <stdio.h>
#include </home/tdcross/gmp/include/gmp.h>
#include <stdarg.h> 
//#include <iostream>

//using namespace std;

int main()
{
    int input = 1000000000;
    mpz_t r1, r2, one, zero;
    mpz_init(r1);
    mpz_init(r2);
    mpz_init(one);
    mpz_init(zero);
    
    mpz_set_si(r1, input);
    mpz_set_si(r2, input -1);
    mpz_set_si(one, 1);
    mpz_set_si(zero, 0);
    
    do
    {
        mpz_mul(r1, r1, r2);
        mpz_sub(r2, r2, one);
        //gmp_printf("%Zd \n", r2);
    }
    while(mpz_cmp(r2, zero) > 0);

    //mpz_out_str(FILE*stream
    gmp_printf("%Zd \n", r1);
    
    mpz_clear(r1);
    mpz_clear(r2);
    mpz_clear(one);
    return 0;
}
