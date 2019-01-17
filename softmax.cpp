#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<float> softmax(vector<float> v)
{
	float sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum=sum+exp(v[i]);
	}
	for(int i=0;i<v.size();i++)
	{
		v[i]=exp(v[i])/sum;
	}
	return v;
}
