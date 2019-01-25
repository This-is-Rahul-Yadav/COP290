#include <iostream>
#include "mkl.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

// int main()
// {
//   int i=0;
//   double A[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};
//   double B[6] = {0,0,0,-0,0,-1.0};
//   double C[9] = {0,0,0,0,0,0,0,0,0};
//   cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans,3,3,2,1,A, 3, B, 3,0,C,3);
//
//   for(i=0; i<9; i++)
//     printf("%lf ", C[i]);
//   printf("\n");
// 	return 0;
// }
// float** input;
//     input=new float*[n];
//     for(i=0;i<n;i++)
//         input[i]= new float[n];
vector<vector<float>> MatrixMultiplyMKL(vector<vector<float>> a,vector<vector<float>> b)
{
  double inpA[a.size()*a[0].size()];
  double inpB[b.size()*a[0].size()];
  double C[a.size()*b[0].size()];
  int k=0;
  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<a[0].size();j++)
    {
      inpA[k]=a[j][i];
      inpB[k]=b[j][i];
      k++;
    }
  }
  cblas_dgemm(CblasColMajor, CblasTrans, CblasTrans ,a.size(),b[0].size(),a[0].size(),1,inpA, a.size(), inpB, b.size(),0,C,a.size());
  for(int i=0; i<9; i++)
    printf("%lf ", C[i]);
  printf("\n");

  vector<vector<float>> matrix(a.size(),vector<float>(a.size(),0));

  k=0;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0; j<a.size(); j++)
		{
			matrix[j][i]=C[k];
			k++;
		}
	}

	return matrix;

}
 int main()
 {
  	vector<vector<float> > in = { {1,0,0}, {0,1,0}, {0,0,1}};
	  vector<vector<float> > ke = { {1,-2,0}, {-1,2,-1}, {1,2,0} };
    vector<vector<float> > vec=MatrixMultiplyMKL(in,ke);
    for (int i = 0; i < vec.size(); i++) {
       for (int j = 0; j < vec[i].size(); j++)
           cout << vec[i][j] << " ";
       cout << endl;
     }
 }
