#pragma once

// 2.2360679774997896964
//#define  Sqrt5   2.236067
#define  Sqrt5   2.2360679774997896964

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

double fibFloat(int k) {
  double phi = (1 + Sqrt5)/2.0;
  double phihat=  (1 - Sqrt5)/2.0;
 return  (1.0/Sqrt5)*( pow(phi,(double) k) -  pow(phihat,(double) k));
  // return instead  correct equation using Sqrt5 and  pow(phi,(double) k) and  pow(phihat,(double) k)
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
