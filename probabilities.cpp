#include <iostream>
#include <vector>
#include <type_traits>
#include <bits/stdc++.h>

using namespace std;
vector<vector<float>> MatrixMultiply(vector<vector<float>> a, vector<vector<float>> b);
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

vector<float> sigmoid(vector<float> v)
{
	for(int i=0;i<v.size();i++)
	{
		v[i]=1/(1+exp(-v[i]));
	}
	return v;
}

vector<vector<float>> maxpooling(vector<vector<float>> a, int k)
{
	int rows = a.size();
	int cols = a[1].size();
	vector<vector<float>> matrix(rows/k, vector<float>(cols/k));
	for(int i=0,i1=0;i<rows;i=i+k,i1=i1+1)
	{
		for(int j=0,j1=0;j<cols;j=j+k,j1=j1+1)
		{
			int i2=0,j2=0;
			float max=a[i][j];
			while(i2<k)
			{
				j2=0;
				while(j2<k)
				{
					if(a[i+i2][j+j2]>max)
					{
						max=a[i+i2][j+j2];
					}
					j2=j2+1;
				}
				i2=i2+1;
			}
			matrix[i1][j1]=max;
		}
	}
	return matrix;
}

vector<vector<float>> avgpooling(vector<vector<float>> a, int k)
{
	int rows = a.size();
	int cols = a[1].size();
	vector<vector<float>> matrix(rows/k, vector<float>(cols/k));
	for(int i=0,i1=0;i<cols;i=i+k,i1=i1+1)
	{
		for(int j=0,j1=0;j<rows;j=j+k,j1=j1+1)
		{
			int i2=0,j2=0;
			float sum=0.0;
			while(i2<k)
			{
				j2=0;
				while(j2<k)
				{
					sum=sum+a[i+i2][j+j2];
					j2=j2+1;
				}
				i2=i2+1;
			}
			matrix[i1][j1]=sum/(k*k);
		}
	}
	return matrix;
}

vector<vector<float>> relu(vector<vector<float>> a)
{
	int rows = a.size();
	int cols = a[1].size();
	for(int i=0;i<cols;i=i+1)
	{
		for(int j=0,j1=0;j<rows;j=j+1)
		{
			if(a[i][j]<0)
				a[i][j]=0;
		}
	}
	return a;
}

vector<vector<float>> tanh(vector<vector<float>> a)
{
	int rows = a.size();
	int cols = a[1].size();
	for(int i=0;i<cols;i=i+1)
	{
		for(int j=0;j<rows;j=j+1)
		{
				float x=a[i][j];
				a[i][j]=(exp(2*x)-1)/(exp(2*x)+1);
		}
	}
	return a;
}

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


	vector<vector<float>> nmatt=MatrixMultiply(nmat,kvect);
	vector<vector<float>> mat;
	int traversal=0;
	for(int i=0; i<arows-krows+1;i++)
	{
		vector<float> vect;
		for(int j=0; j<arows-krows+1;j++)
		{
			vect.push_back(nmatt[traversal][0]);
			traversal++;
		}
		mat.push_back(vect);
	}
	return mat;
}

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

vector<vector<float>> flipper(vector<vector<float>> a)
{
	vector<vector<float>> matrix;

	for(int i=a.size()-1; i>=0; i--)
	{
		vector<float> vect;
		for(int j=a[0].size()-1; j>=0;j--)
		{
			vect.push_back(a[i][j]);
		}
		matrix.push_back(vect);
	}
	return matrix;
}


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

int main()
{
	//vector<float> me={4.67f,3.45f,8.98f};
	//me=softmax(me);
	//vector<float> u=sigmoid(me);
	//cout<<"here" <<me[1] << u[1];

	vector<vector<float> > in = { {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };
	vector<vector<float> > ke = { {1,-2,0}, {-1,2,-1}, {1,2,0} };
	vector<vector<float> > keFlip = { {0,2,1}, {-1,2,-1}, {0,-2,1} };

	vector<vector<float> > vect{ { 1.2, -32.74, -32.73 ,3 ,5 ,67},
															{ -87.4, -5.87, 6.98, 54,87,53 },
															{ 7, -88.09, 9.89, 76, 73,91 },
														{ 98.87, -388.09, 0.89, -976, -3,91 },
													{ 7.87, 9.09, 3.89, 7.6, 73.9, 91 },
												{ 7, -88.09, 9.89, 7.06 , 3.90 ,9.1 } };
	//cout << vect[2][5];
	//vect=avgpooling(vect,2);
	vector<vector<float>> me={{4.67,3.45,8.98},{4.67,-98,8.98},{4.67,3.45,8.98}};
	//vector<vector<float>> vec = convolutionMULT(in,ke);
	vector<vector<float>> vec = convolveMULTPadding(in, ke, 0);
		for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
			}
	return 0;
}
