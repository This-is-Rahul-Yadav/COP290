#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

int main(){
    bool stop = false;
    string input;


    while (!stop){
			 getline(cin, input);
        performAction(input, &stop);
    }

    return 0;
}
