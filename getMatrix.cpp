#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

vector<vector<float>> getMatrix(string a, int n)
{
	vector<vector<float>> matrix(n,vector<float>(n,0));
	vector<float> inp(n*n);
	ifstream file(a);
	string content;
	int k=0;
	while(file >> content)
	{
		int m=stoi(content);
		inp[k]=m;
		k++;
	}
	k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0; j<n; j++)
		{
			matrix[j][i]=inp[k];
			k++;
		}
	}

	return matrix;
}
