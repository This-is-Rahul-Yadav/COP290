#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
vector<vector<float>> avgpooling(vector<vector<float>> a, int k)
{
	int rows = a.size();
	int cols = a[1].size();
	vector<vector<float>> matrix(rows/k, vector<float>(cols/k));
	for(int i=0,i1=0;i<cols;i=i+k,i1=i1+1)
	{
		for(int j=0,j1=0;j<rows;j=j+k,j1=j1+1)
		{
			int i2=0,j2=0;
			float sum=0.0;
			while(i2<k)
			{
				j2=0;
				while(j2<k)
				{
					sum=sum+a[i+i2][j+j2];
					j2=j2+1;
				}
				i2=i2+1;
			}
			matrix[i1][j1]=sum/(k*k);
		}
	}
	return matrix;
}
