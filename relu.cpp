#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

vector<vector<float>> relu(vector<vector<float>> a)
{
	int rows = a.size();
	int cols = a[1].size();
	for(int i=0;i<cols;i=i+1)
	{
		for(int j=0,j1=0;j<rows;j=j+1)
		{
			if(a[i][j]<0)
				a[i][j]=0;
		}
	}
	return a;
}
