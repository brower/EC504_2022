#include<iostream>
#include<iomanip>
#include <cstdlib> 
#include <time.h>
#include <math.h>
#include "sorting.h"
using namespace std;

#define Debug 1

// Debugging routine: (Good Software would put this in seperate test.h)
void printArray(int a[], int N)
{ 
  cout << "N =" << N << endl;
  for(int i = 0;i<N;i++)
    cout << a[i] << "\n";
}

int main()
{
  // Put loop around N to make data for scaling  
  int N = 8;
  int a[N];
  int a_save[N];
  int a_tmp[N];

  srand(137); // fixes intial seed 
  // Choose a random list of N integers: Could also pick more lists.
  for(int i = 0;i<N;i++) 
    a[i] = (rand() +1)%1000000  ;
 
  
  int Ncases = 3;  // run over a set of re_ordering lists
  
  for(int j = 0; j < Ncases; j++)
    {
      
     for(int i = 0;i<N;i++) a_save[i] = a[i]; // keep random array

#if Debug
     cout <<" Before Sorting " << endl ;
    printArray(a, N);
#endif

    //Test insertionSort     
     swapCount = 0;
     insertionsort(a, N);
     cout << "Case = " << j << "  insertionSort swapCount " << swapCount << endl;

#if Debug
     printf("Insertion Sorted array:\n");
       printArray(a, N);
#endif
     //Test mergeSort
     swapCount = 0;
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     mergeSort(a,  a_tmp, 0, N-1);
     cout << "Case = " << j << " Merge  swapCount " << swapCount << endl;

#if Debug
      printf("mergeSorted array:\n");
      printArray(a, N);
#endif
     
     //Test quickSort
     swapCount = 0;
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     quicksort(a, 0,N-1);
     cout << "Case = " << j << " Quick  swapCount " << swapCount << endl;

#if Debug
     printf("quickSorted array:\n");
     printArray(a, N);
#endif
     
     //Test shellSort
     swapCount = 0;
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     shellsort(a,N);
     cout << "Case = " << j << " Shell Sort  swapCount " << swapCount << endl;

#if Debug
     printf("sellSorted array:\n");
     printArray(a, N);
#endif
     
     // Get new permutation of random array.
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     initialize_and_permute(a , N);
    
#if Debug
      cout << "New Permuted Array " << endl;
      printArray(a, N);
#endif
    }
  
 return 0;
}
