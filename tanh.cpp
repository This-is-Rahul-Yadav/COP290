#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;
vector<vector<float>> tanh(vector<vector<float>> a)
{
	int rows = a.size();
	int cols = a[1].size();
	for(int i=0;i<cols;i=i+1)
	{
		for(int j=0;j<rows;j=j+1)
		{
				float x=a[i][j];
				a[i][j]=(exp(2*x)-1)/(exp(2*x)+1);
		}
	}
	return a;
}
