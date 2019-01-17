#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
vector<vector<float> > convolveMULTPadding(vector<vector<float> > input, vector<vector<float> > filter, int padding)
{
    int p = padding;
    int N = input.size();
    int f = filter.size();

    vector<vector<float> > paddedInput(N + 2*p, vector<float>(N + 2*p));

    for (int i=p; i< p+N; i++){
        for (int j=p; j< p+N; j++){
            paddedInput[i][j] = input[i-p][j-p];
        }
    }
		return convolutionMULT(paddedInput, filter);
	}
