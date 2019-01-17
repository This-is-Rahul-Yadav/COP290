#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

vector<vector<float> > convolveWithoutPadding(vector<vector<float> > input, vector<vector<float> > filter)
{
    return convolvePadding(input, filter, 0);
}
