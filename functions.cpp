//
//  functions.cpp
//  PLP4
//
//  Created by Stephanie Asitimbay on 11/04/25.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//function that takes two numbers, multiplies them, and returns the sum
int multiply(int x, int y) {
    int sum = x * y;
    return sum;
}

//recursive function calculating the factorial of an int
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

//function to split a string by spaces
vector<string> simple_tokenizer(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    int num1 = 4;
    int num2 = 3;
    
    //calling multiply function and printing the output
    int sum = multiply(num1, num2);
    cout<< "the sum of "<<num1 << " and "<< num2<< " is "<< sum<< endl;
    
    //calling recursive function and printing the output
    int fac = factorial(num1);
    cout<< "the factorial of "<< num1<< " is "<< fac<< endl;
    
    //calling functiion to split string
    string myString = "Hello World";
    
    vector<string> myVec = simple_tokenizer(myString);
    
    for (string w : myVec) {
        cout<< w<<endl;
    }
    
    return 0;
}









