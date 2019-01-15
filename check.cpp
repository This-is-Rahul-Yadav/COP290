#include <iostream>
#include <vector>
#include <type_traits>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  float x;
  cin>>x;
  float sum=0;
  sum=(exp(2*x)-1)/(exp(2*x)+1);
  cout<<sum;
  return 0;
}
