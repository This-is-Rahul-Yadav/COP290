#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<vector<float> > convolveValid (vector<vector<float> > input, vector<vector<float> > filter)
{
    int N = input.size();
    int f = filter.size();

    //float matrix[(n-f+1)*(n-f+1)][f*f];

    vector<vector<float> > output(N-f+1, vector<float>(N-f+1));

    for(int i=0; i<= N-f;i++){
        for(int j=0; j<= N-f;j++){
            for(int m=0; m<f; m++){
                for(int n=0; n<f; n++){

                //    if (m<N && n<N && i-m<f && j-n<f)
                    output[i][j] += input[m+i][n+j] * filter[m][n];
                }
            }
        }
    }

    return output;
}
