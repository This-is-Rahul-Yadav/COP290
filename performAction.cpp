#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

void performAction(string input, bool* stop){

    string delimiter = " ";
    vector<string> command;
    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        command.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
		token = input.substr(0, pos);
		command.push_back(token);
		input.erase(0, pos + delimiter.length());
    int padding;
    vector<vector<float>> inputMatrix1;
    int size1;
    vector<vector<float>> inputMatrix2;
    int size2;
    vector<vector<float>> outputMatrix;
    vector<float> inputVector;
    vector<float> outputVector;

    if(command[0] == "convolution_withoutpadding"){
        if (command.size() != 5){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        size2 = stoi(command[4]);
        inputMatrix1 = getMatrix(command[1], size1);
        inputMatrix2 = getMatrix(command[3], size2);
        outputMatrix = convolveWithoutPadding(inputMatrix1, inputMatrix2);
        printMatrix(outputMatrix);
    }else if(command[0] == "convolution_withpadding"){
        if (command.size() != 6){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[3]);
        size2 = stoi(command[5]);
        padding = stoi(command[1]);
        inputMatrix1 = getMatrix(command[2], size1);
        inputMatrix2 = getMatrix(command[4], size2);
        outputMatrix = convolvePadding(inputMatrix1, inputMatrix2, padding);
        printMatrix(outputMatrix);
    }else if(command[0] == "convolution_withoutpadding_matrixmul"){
        if (command.size() != 5){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        size2 = stoi(command[4]);
        inputMatrix1 = getMatrix(command[1], size1);
        inputMatrix2 = getMatrix(command[3], size2);
        outputMatrix = convolutionMULT(inputMatrix1, inputMatrix2);
        printMatrix(outputMatrix);
    }else if(command[0] == "convolution_withpadding_matrixmul"){
        if (command.size() != 6){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[3]);
        size2 = stoi(command[5]);
        padding = stoi(command[1]);
        inputMatrix1 = getMatrix(command[2], size1);
        inputMatrix2 = getMatrix(command[4], size2);
        outputMatrix = convolveMULTPadding(inputMatrix1, inputMatrix2, padding);
        printMatrix(outputMatrix);
    }else if(command[0] == "relu"){
        if (command.size() != 3){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        inputMatrix1 = getMatrix(command[1], size1);
        outputMatrix = relu(inputMatrix1);
        printMatrix(outputMatrix);
    }else if(command[0] == "tanh"){
        if (command.size() != 3){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        inputMatrix1 = getMatrix(command[1], size1);
        outputMatrix = tanh(inputMatrix1);
        printMatrix(outputMatrix);
    }else if(command[0] == "average_pooling"){
        if (command.size() != 4){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        size2 = stoi(command[3]);
        inputMatrix1 = getMatrix(command[1], size1);
        outputMatrix = avgpooling(inputMatrix1, size2);
        printMatrix(outputMatrix);
    }else if(command[0] == "max_pooling"){
        if (command.size() != 4){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        size2 = stoi(command[3]);
        inputMatrix1 = getMatrix(command[1], size1);
        outputMatrix = maxpooling(inputMatrix1,size2);
        printMatrix(outputMatrix);
    }else if(command[0] == "sigmoid"){
        if (command.size() != 3){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        inputVector = getVector(command[1], size1);
        outputVector = sigmoid(inputVector);
        printVector(outputVector);
    }else if(command[0] == "softmax"){
        if (command.size() != 3){ cout << "Incorrect number of arguments provided" << endl; help(); return;}
        size1 = stoi(command[2]);
        inputVector = getVector(command[1], size1);
        outputVector = softmax(inputVector);
        printVector(outputVector);
    }else if(command[0] == "quit"){
        *stop = true;
    }else{
        help();
    }
}
