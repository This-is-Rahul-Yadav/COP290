#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<vector<float>> MatrixMultiply(vector<vector<float>> a, vector<vector<float>> b)
{
	int arow=a.size();
	int acol=a[0].size();
	int brow=b.size();
	int bcol=b[0].size();
	vector<vector<float>> nmat(arow,vector<float>(bcol,0));
	for(int i=0;i<arow;i+=1)
	{
		for(int j=0;j<bcol;j+=1)
		{
			float sum=0;
			for(int k=0;k<brow;k+=1)
			{
				sum+=a[i][k]*b[k][j];
			}
			nmat[i][j]=sum;
		}
	}
	return nmat;
}
