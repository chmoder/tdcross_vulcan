#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <cctype>
#include <stdarg.h>
#include </home/tdcross/gmp/include/gmp.h>

using namespace std;

#define NUM_THREADS     8
 
struct gCounter
{
    mpz_t counter;
};

void *PrintHello(void *threadid)
{
   long tid;
 
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
	
    int max = numeric_limits<int>::max();
    cout << max << endl;
    max = 99999999;
   
    int *array = new int[max];
    
    for( int i = 0; i < max; ++i )
    {
        array[i] = i;
        //array[i] = randomNumber(max);
    }
    	printf("\n");

   pthread_exit(NULL);
}
 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void *multiply( void )
{
    struct gCounter total;
    struct operand oper;
    pthread_mutex_lock( &mutex1  );
    
    mpz_mul(z.counter, z.counter, point);
    gmp_printf("counter value: %Z\n", z.counter);

    pthread_mutex_unlock( &mutex1 );
}

int main (int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    struct gCounter z;

   int rc;
   int i;
   mpz_t t, one;
   mpz_init(t);
   mpz_init(one);
   mpz_set_si(one,1);
   mpz_set_si(t, 8);
    
    mpz_init(z.counter);
    mpz_set_si(z.counter,1);
    
    for(i=0; i<NUM_THREADS; ++i)
    {
      printf("In main: creating thread %d\n", i);
      
        rc = pthread_create(&threads[i], NULL, multiply, &t);
 
      if (rc)
      {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   pthread_exit(NULL);

   mpz_clear(t);
}
