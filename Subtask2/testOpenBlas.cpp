#include <iostream>
#include <cblas.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

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
