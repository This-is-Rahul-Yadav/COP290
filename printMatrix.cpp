#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

void printMatrix(vector<vector<float>> vec)
{
	for (int i = 0; i < vec.size(); i++) {
	         for (int j = 0; j < vec[i].size(); j++)
	             cout << vec[i][j] << " ";
	         cout << endl;
	 			}
}
