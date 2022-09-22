/************

Google 

https://en.wikipedia.org/wiki/Fibonacci_number

https://stackoverflow.com/questions/34556986/wrong-output-in-recursive-fibonacci-number-program

Call recusive max of 50 with 40,730,022,147 calls 
unless you have lot of time to waste

https://en.wikipedia.org/wiki/C_data_types

unsigned long long int [0,18,446,744,073,709,551,615]
**************/

#include <iostream> // need to cin and cout
#include <fstream>
#include <chrono>
#include <cstring>
#include <math.h>
#include "fib.h"


using namespace std;


// 2.2360679774997896964
#define  Sqrt5   2.236067
//#define  Sqrt5   2.2360679774997896964

unsigned long long int r = 0;
unsigned long int fib(int n) {
  printf("k =  %llu fib n =  %d", r++, n);
  if (n==0 )
    {
      printf("\n");
      return 0;
    }
  else  if (n==1 )
    {
      printf("\n");
      return 1;
    }	  
  else
    { 
      printf(" + \n");
      return fib(n-1) + fib(n-2); 
    }
}

unsigned long int fibClean (int n) {
     r++;
    if (n==0) return 0;
    else if (n==1) return 1;
    else return fibClean(n-1) + fibClean(n-2);
}

double fibFloat(int n) {
  return  (pow((1 + Sqrt5)/2.0,(double) n) -   pow((1 - Sqrt5)/2.0,(double) n))/Sqrt5;
    }
  

unsigned long int fibIterate(int n) {
  double fib[n+1];
  fib[0] = 0;
  fib[1] = 1;
  int iter;
  for(iter = 2; iter < n+1; iter++)
    fib[iter] = fib[iter-1] + fib[iter - 2];
   return fib[n];
}
#endif

int main(int argc, char **argv) {
  int n;
  cout << "Stat value of Fibinacci ? ";
  cin >> n;

   FILE * outfile;
  outfile = fopen("CompareFib.txt", "w");

  // if(argc = 1)
  //  int n = atoi(argv[1]);
    int nmax = 8;
    r = 0;
     unsigned long   int f = fib(nmax);
     printf("\n  Recursive tree for n = %d  : %lu  calls %llu  \n",nmax, f, r);
       
     unsigned long  int iterF = fibIterate(n);
     printf("\n Iterative  return: %lu  Number of calls %d \n", iterF,n);

    r = 0;
    unsigned long  int recF = fibClean(nmax);
  printf("\n  Recursive return: %lu  Number of calls;   %llu\n", recF,r);


    unsigned long  int intFib;
    double fibFP; 
    unsigned long  int nearestInt;
    signed long  int error;

    for(int k = 0; k < n+1; k++)
      {
	  intFib = fibIterate(k);
	  fibFP = fibFloat(k);
	  nearestInt = round(fibFP);
	  error =  intFib - nearestInt ; 
	  fprintf(outfile," %8d   %35.10f %20lu  %20lu    %20ld \n",
		  k, fibFP, intFib  , nearestInt,  error );
      }
  
     fclose(outfile);
     
    return 1;
}
  
