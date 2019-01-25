#include <bits/stdc++.h>
#include <chrono>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std:: chrono;

using namespace std;

//#define DIM 8
#define MAX_THREAD 4

int step_i=0;
// int matA[DIM][DIM];
// int matB[DIM][DIM];
// int matC[DIM][DIM];
//tuple<int*,int, vector<vector<float>>, vector<vector<float>>, vector<vector<float>> > couple;
struct args{
  int dim;
  vector<vector<float>> inp_a;
  vector<vector<float>> inp_b;
  vector<vector<float>> out_c;
  int* p1;
};
// void* multi(void* input)
// {
//     int core = step_i++;
//     int len=((struct args*)input)->dim;
//     vector<vector<float>> matA=((struct args*)input)->inp_a;
//     vector<vector<float>> matB=((struct args*)input)->inp_b;
//     vector<vector<float>> matC(len,vector<float>(len,0));
//     for (int i = core * len / 4; i < (core + 1) * len / 4; i++){
//         for (int j = 0; j < len; j++){
//             for (int k = 0; k < len; k++)
//                 matC[i][j] += matA[i][k] * matB[k][j];
//         }
//     }
//      for (int i = 0; i < len; i++) {
//          for (int j = 0; j < len; j++)
//              cout << matC[i][j] << " ";
//          cout << endl;
//        }
//
// }

void* multi(void* inputt)
{
    struct args *input = *(struct args **)inputt;
    int core = step_i++;
    int len=((struct args*)input)->dim;
    vector<vector<float>> matA=((struct args*)input)->inp_a;
    vector<vector<float>> matB=((struct args*)input)->inp_b;
  //  vector<vector<float>> matC=((struct args*)input)->out_c;
    for (int i = core * len / 4; i < (core + 1) * len / 4; i++){
        for (int j = 0; j < len; j++){
            for (int k = 0; k < len; k++)
                (((struct args*)input)->out_c)[j][i] += matA[i][k] * matB[k][j];
        }
    }
     // for (int i = 0; i < len; i++) {
     //     for (int j = 0; j < len; j++)
     //         cout << matC[i][j] << " ";
     //     cout << endl;
     //   }

}
void matrix_mult_threading(vector<vector<float>> a, vector<vector<float>> b)
{
   //global int step_i=0;
   pthread_t threads[MAX_THREAD];
   struct args *input=(struct args *)malloc(sizeof(struct args));
   input -> dim=a.size();
   input ->inp_a=a;
   input ->inp_b=b;
   vector<vector<float>> matC(a.size(),vector<float>(a.size(),0));
   input ->out_c=matC;
   for(int i=0;i<MAX_THREAD;i++)
   {
     //input -> p1=int* p;
     pthread_create(&threads[i], NULL, multi, (void*)(&input));
   }
   // for (int i = 0; i < MAX_THREAD; i++) {
   //     int* p;
   //     pthread_create(&threads[i], NULL, multi, (void*)(p));
   // }



   // for (int i = 0; i < MAX_THREAD; i++) {
   //     int* p;
   //     vector<vector<float>> c;
   //     couple=make_tuple(p,a.size(), a, b)
   //     pthread_create(&threads[i], NULL, multi, (void*)(couple));
   // }

   for (int i = 0; i<MAX_THREAD; i++)
     pthread_join(threads[i], NULL);
   //input ->out_c=matC;
   for (int i = 0; i < a.size(); i++) {
       for (int j = 0; j < a.size(); j++)
           cout << (input ->out_c)[i][j] << " ";
       cout << endl;
     }
  }
int main()
{
  vector<vector<float> > in = { {1,0,0}, {0,1,0}, {0,0,1}};
  vector<vector<float> > ke = { {1,-2,0}, {-1,2,-1}, {1,2,0} };
  matrix_mult_threading(in,ke);
  return 0;

}
