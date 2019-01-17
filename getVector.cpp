#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

vector<float> getVector(string a, int n)
{
	vector<float> inp(n);
	ifstream file(a);
	string content;
	int k=0;
	while(file >> content)
	{
		int m=stoi(content);
		inp[k]=m;
		k++;
	}
	return inp;
}
