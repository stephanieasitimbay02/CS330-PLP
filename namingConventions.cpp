//
//  namingConventions.cpp
//  PLP2
//
//  Created by Stephanie Asitimbay on 9/30/25.
//

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
    // creating variables
    // int
    int myInt = 2;
    
    // float
    float myFloat = 4.6;
    
    // double
    double myDouble = 2.2;
    
    // char
    char myChar = 's'; //char uses single quotes
    
    // string
    string myString = "hello world"; //string uses double quotes
    
    // boolean
    bool myBool = false;
    
    // array
    int myInts[3] = {1, 2, 3};
    string myStrings[2] = {"hello", "world"};
    
    /* you always have to declare the type before creating the variable*/
    
    // dictionary/map
    //ordered map is sorted by the keys
    map<int, string> dict;
    dict[1] = "Hello";
    dict[2] = "World";
    dict[3] = "!";
    
    //unordered map is not kept in any specific order
    unordered_map<int, string> myMap;
    myMap[1] = "Order";
    myMap[3] = "Doesn't";
    myMap[2] = "Matter";
    
    //C++ also has pointer variables that store the memory address of other variables
    //create int variable, intVar
    int intVar = 12;
    //declare pointer and store the address of intVar
    int* pntr = &intVar;
    cout<< "value of intVar: "<< intVar<< endl;
    cout<< "address of intVar: "<< &intVar<< endl;
    cout<< "value of pntr: "<< pntr<< endl;
    cout<< "value pointed to by pntr: "<< *pntr<< endl;
    
    //when adding ints to floats, the int will be converted into a float
    float sum = myInt + myFloat;
    cout<< "sum is " << sum<< endl;
    
    //adding a string to an int will not work
    string x = "5" + 6;
    cout<< "value of x: "<< x<< endl;
    
    // when ints are divided by ints the answer will be an int, even when declaring float
    float fanswer = 5/6;
    cout<< "answer is "<< fanswer<< endl;
    int ianswer = 5/6;
    cout<< "answer is "<< ianswer<< endl;
    
    // when dividing an int by a float or a float by an int you will get a float
    float answer = 3.0/4;
    cout<< "answer is "<< answer<< endl;
    float answer2 = 5/2.0;
    cout<< "answer is "<< answer2<< endl;
    
    // float divided by a float will return a float
    float answer3 = 7.0/2.0;
    cout<< "answer is "<< answer3<< endl;
    
    return 0;
}





