#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<vector<float>> convolutionMULT(vector<vector<float>> a, vector<vector<float>> k)
{
	int arows=a.size();
	int acols=a[0].size();
	int krows=k.size();
	int kcols=k[0].size();
	//cout << arows << "   "<< krows;
	vector<vector<float>> nmat;
	//cout << nmat.size() << "  "<<nmat[0].size()<< " hbjhvvcuiacuavcuiavcuyavcyuvcyu";
	int count=0;
	for(int i=0;i<arows-krows+1;i=i+1)
	{
		for(int j=0;j<acols-krows+1;j=j+1)
		{
			int i2=0,j2=0;
			vector<float> vect;
			while(i2<krows)
			{
				j2=0;
				while(j2<krows)
				{
					vect.push_back(a[i+i2][j+j2]);
					j2=j2+1;
				}
				i2=i2+1;
			}
			nmat.push_back(vect);
		}
	}
	vector<vector<float> > kvect;
	for(int i=0;i<krows;i++)
	{
		for(int j=0;j<krows;j++)
			kvect.push_back(vector<float>(1,k[i][j]));
	}
