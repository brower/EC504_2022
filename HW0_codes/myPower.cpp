#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include <math.h>
#include "rng.h"
using namespace std;

/***********************************************************
Main progam template for practice exercise HomeworkZero
************************************************************/

double slowPower(double x, long int N);
double fastPower(double x, long int N);
double  cPower(double x, long int N);
double veryfastPower(double x, long int N);


int main(int argc, char **argv) 
{
  //default values
  unsigned long int N = 3141592653; // Max 4,294,967,295
  double x =  1.00000001; ;  // Max 1.79769e+308
  
  if(argc==1){
    printf("Provide command line args for  x and  N to compute pow( %.12f,%lu)! \n",x,N);
    printf("Without them the default is  x = %.12f and N = %lu \n",x,N);
  }
  else if(argc==3)
    {
      x = atof(argv[1]);
      N =  std::stoul(argv[2]);
      printf("\n x = %.12f  and N =  %lu  \n", x, N);   
    }
  else
    {printf("Error need two command line args for x and N\n");
      return 0;
    }

  /* Timeing and IO setup */
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_sec_slow; // Holds the final run time
  double difference_in_sec_fast; // Holds the final run time
  double difference_in_sec_c; // Holds the final run time
  double difference_in_sec_veryfast; // final run time  

 
  start = chrono::steady_clock::now();
  double power_c = cPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_c= double(difference_in_time.count());
  
  start = chrono::steady_clock::now();
  double power_slow = slowPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_slow= double(difference_in_time.count());
  
  start = chrono::steady_clock::now();
  double power_fast = fastPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_fast= double(difference_in_time.count());

  start = chrono::steady_clock::now();
  double power_veryfast = veryfastPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_veryfast= double(difference_in_time.count());
  
  cout << "powerC =    " << power_c   << "  Time = " <<  difference_in_sec_c << endl;
  cout << "powerSlow = " << power_slow <<"  Time = " <<  difference_in_sec_slow << endl;
  cout << "powerFast = " << power_fast <<"  Time = " <<  difference_in_sec_fast << endl;
  cout << "powerveryFast = " << power_veryfast <<"  Time = " <<  difference_in_sec_veryfast << endl;

  
  return 0;
}

/****************************************
Funtions provided below
****************************************/

double cPower(double x, long int N)
{
  return pow(x, (double)N);
}

double slowPower(double x, long int N)
{
  double pow = 1.0;
  int i;
  for( i = 0;  i < N && i < 1000000000; i++)
    {
  pow *= x;
     }

  if(i < N)   cout <<"Slow Failed with iteration stop at i = " << i << endl;
  return pow ;
}
//This function needs to be fixed!
double  fastPower(double x, long int N)
{
  double square = x;
  double pow = 1.0;
  while(N > 0)
    { 
      if(N%2) pow *= 1 ; // Update pow 
      N = N/2;
      // Update square
    }
  return pow;
}

double veryfastPower(double x, long int N)
{
    double pow = 1.0;
    for (;;)
    {
      if (N & 1)  //Copies a bit to the result if it exists in both operands.
            pow *= x;
      N >>= 1;  //Binary Right Shift Operator. 
      if (!N)  // Check for zero
            break;
        x *= x;
    }

    return pow;
}


