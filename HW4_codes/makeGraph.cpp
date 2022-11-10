/************

Make First[0:Vsize]   Lables Vertice(nodes) from  0,.., Vsize-1;
Make Edge[[0:Esize]   Lables Edge[Esize]  from  0,..., Esize -1

The last fake vertex  Frist[Vsize] = Esize  point to the 
null facke edge with "null" value Edge[Esize] = -1.

The routine uses connection matrix 
A[Vsize][Vsize] 

with A[i][j] = 1 or edge 0 or no edge.

See https://en.wikipedia.org/wiki/Erdős–Rényi_model

 ************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> 
#include <string>
#include <chrono>
#include <math.h>
//#define Vsize  128

using namespace std;


int main(int argc, char *argv[])
{
  int Vsize = 0;
  Vsize =  atoi(argv[1]);

  int *First = new int[Vsize+1];
  int** A = new int*[Vsize];
  for(int i = 0; i < Vsize; ++i)
   A[i] = new int[Vsize];
 
  //int **A = new int A;
  // int First[Vsize+1] = {-1};
  // int A[Vsize][Vsize] = {0};
    
 /******************************************
Undirecte bounds: Pick ordered pairs subset of  V (V-1)/2 
 *******************************************************/
 
  double fanout = 1.0;   // aveage fanout is 1
    int Esize = 0;

  // iterated over Vsize*(Vsize -1)/2 ordered pairs 2 Vsize on.
     
  for(int i =0; i< Vsize; i++)
    for (int j = i+1; j < Vsize; j++)
      {
	if(rand() < (RAND_MAX*fanout)/(2.0*Vsize))
	{
	A[i][j] = 1;
	Esize++;
	A[j][i] = 1;
	Esize++;
	}
      }

  int Edge[Esize+1];
  Edge[Esize] = -1;

 int EdgeIndex = 0; 
 First[0] = 0;  

 for(int i =0; i< Vsize; i++)
   {
     First[i+1] = First[i];
     for (int j = 0; j < Vsize; j++)
      {
	if(A[i][j] == 1)
	  { 
	    Edge[EdgeIndex] = j;
	      EdgeIndex++;
	     First[i+1] += 1; // next one
	  }
      }
   }

   cout << endl <<" First Array " << endl;

    for(int v = 0;v < Vsize+1;v++)
        cout <<"for v = "<< v << "  " <<  First[v] <<  endl;

      cout << endl <<" Edge Neighbor Array " << endl;
      
   for(int e = 0;e< Esize+1;e++)
        cout <<"for e = "<< e << "  " <<  Edge[e] <<  endl;

   //Begin output forward Star Graph.
   char filename[20];
   sprintf(filename, "graph_%d_%d.txt", Vsize, Esize); 
   ofstream outfile(filename);
   outfile << Vsize << endl;
   outfile << Esize << endl;
   for(int v = 0;v < Vsize+1;v++)
      outfile << First[v] <<  endl;
   for(int e = 0;e< Esize+1;e++)
      outfile << Edge[e] <<  endl;
   outfile.close();

    //End output file

 
  return 0;
}

