#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>


vector<vector<float> > convolveLarge (vector<vector<float> > input, vector<vector<float> > filter)
{
	    int N = input.size();
	    int f = filter.size();

	    //float matrix[(n-f+1)*(n-f+1)][f*f];

	    vector<vector<float> > output(N+f-1, vector<float>(N+f-1));

	    for(int i=0; i< output.size();i++){
	        for(int j=0; j< output[i].size();j++){
	            for(int m=0; m<=i; m++){
	                for(int n=0; n<=j; n++){

	                    if (m<N && n<N && i-m<f && j-n<f)
	                    output[i][j] += input[m][n] * filter[i-m][j-n];
	                }
	            }
	        }
	    }

	    return output;
	}
