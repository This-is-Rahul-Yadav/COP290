//#include <cblas.h>

#include <mkl.h>
#include <stdio.h>

void main()
{
  int i=0;
  double A[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};         
  double B[6] = {0,0,0,-0,2,-1.0};  
  double C[9] = {0,0,0,0,0,0,0,0,0}; 
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans,3,3,2,1,A, 3, B, 2,0,C,3);

  for(i=0; i<9; i++)
    printf("%lf ", C[i]);
  printf("\n");
}
