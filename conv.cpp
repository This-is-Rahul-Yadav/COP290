#include <iostream>
#include <vector>

using namespace std;



vector<vector<float> > convolveLarge (vector<vector<float> > input, vector<vector<float> > filter){
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

vector<vector<float> > convolveValid (vector<vector<float> > input, vector<vector<float> > filter){
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

//remove f-1/2 rows
vector<vector<float> > convolvePadding(vector<vector<float> > input, vector<vector<float> > filter, int padding){
    int p = padding;
    int N = input.size();
    int f = filter.size();

    vector<vector<float> > paddedInput(N + 2*p, vector<float>(N + 2*p));

    for (int i=p; i< p+N; i++){
        for (int j=p; j< p+N; j++){
            paddedInput[i][j] = input[i-p][j-p];
        }
    }

    vector<vector<float> > temp = convolveValid(paddedInput, filter);

    vector<vector<float> > output(N, vector<float>(N, 0));

    return temp;
}


//remove f-1 rows
vector<vector<float> > convolveWithoutPadding(vector<vector<float> > input, vector<vector<float> > filter){
    // int N = input.size();
    // int f = filter.size();
    //
    // int padding = f-1;
    // vector<vector<float> > temp = convolveLarge(input, filter);
    //
    // vector<vector<float> > output(N-f+1, vector<float>(N-f+1, 0));
    // for(int i=padding; i< N; i++){
    //     for(int j=padding; j< N; j++){
    //         output[i-padding][j-padding] = temp[i][j];
    //     }
    // }
    // return output;

    return convolvePadding(input, filter, 0);
}


int main(){
    vector<vector<float> > in = { {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };
    vector<vector<float> > ke = { {1,-2,0}, {-1,2,-1}, {1,2,0} };
    vector<vector<float> > keFlip = { {0,2,1}, {-1,2,-1}, {0,-2,1} };

    vector<vector<float> > out = convolvePadding(in, ke, 1);
    vector<vector<float> > out2 = convolveWithoutPadding(in, ke);

    for(int i=0; i<out.size(); i++){
        for(int j=0; j<out[i].size(); j++){
            cout << out[i][j] << " ";
        } cout << endl;
    }

    for(int i=0; i<out2.size(); i++){
        for(int j=0; j<out2[i].size(); j++){
            cout << out2[i][j] << " ";
        } cout << endl;
    }

    return 0;
}
