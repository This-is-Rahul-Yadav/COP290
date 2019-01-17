#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<vector<float>> maxpooling(vector<vector<float>> a, int k)
{
	int rows = a.size();
	int cols = a[1].size();
	vector<vector<float>> matrix(rows/k, vector<float>(cols/k));
	for(int i=0,i1=0;i<rows;i=i+k,i1=i1+1)
	{
		for(int j=0,j1=0;j<cols;j=j+k,j1=j1+1)
		{
			int i2=0,j2=0;
			float max=a[i][j];
			while(i2<k)
			{
				j2=0;
				while(j2<k)
				{
					if(a[i+i2][j+j2]>max)
					{
						max=a[i+i2][j+j2];
					}
					j2=j2+1;
				}
				i2=i2+1;
			}
			matrix[i1][j1]=max;
		}
	}
	return matrix;
}
