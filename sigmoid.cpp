#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<float> sigmoid(vector<float> v)
{
	for(int i=0;i<v.size();i++)
	{
		v[i]=1/(1+exp(-v[i]));
	}
	return v;
}
