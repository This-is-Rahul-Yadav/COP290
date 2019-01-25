#include <bits/stdc++.h> 
#include <chrono>

using namespace std:: chrono;

using namespace std; 
  
// maximum size of matrix 
#define MAX 4 
  
// maximum number of threads 
#define MAX_THREAD 4 
  
int matA[MAX][MAX]; 
int matB[MAX][MAX]; 
int matC[MAX][MAX]; 
int step_i = 0; 
  
vector<vector<float>> MatrixMultiply(vector<vector<float>> a, vector<vector<float>> b)
{
	int arow=a.size();
	int acol=a[0].size();
	int brow=b.size();
	int bcol=b[0].size();
	vector<vector<float>> nmat(arow,vector<float>(bcol,0));
	for(int i=0;i<arow;i+=1)
	{
		for(int j=0;j<bcol;j+=1)
		{
			float sum=0;
			for(int k=0;k<brow;k+=1)
			{
				sum+=a[i][k]*b[k][j];
			}
			nmat[i][j]=sum;
		}
	}
	return nmat;
}

// Driver Code 

int main() 
{ 
    auto start = high_resolution_clock::now(); 

    // Generating random values in matA and matB 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++) { 
            matA[i][j] = rand() % 10; 
            matB[i][j] = rand() % 10; 
        } 
    } 
  
    // Displaying matA 
    cout << endl 
         << "Matrix A" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matA[i][j] << " "; 
        cout << endl; 
    } 
  
    // Displaying matB 
    cout << endl 
         << "Matrix B" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matB[i][j] << " ";         
        cout << endl; 
    } 
  
       
  
    // Displaying the result matrix 
    cout << endl 
         << "Multiplication of A and B" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matC[i][j] << " ";         
        cout << endl; 
    } 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << duration.count() << endl; 

    return 0; 
}
