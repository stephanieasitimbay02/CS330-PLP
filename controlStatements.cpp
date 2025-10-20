//
//  controlStatements.cpp
//  PLP3
//
//  Created by Stephanie Asitimbay on 10/20/25.
//

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

bool scTestFunc() {
    cout<< "fuction executed"<< endl;
    return true;
}

int main() {
    int x = 5;
    bool y = true;
    bool f = false;
    int z = 0;
    
    // boolean values (true/false and 1/0)
    cout<< y<< endl;
    cout<< f<< endl;
    
    // simple one condition if/else statement
    if (x==5) {
        cout<< "x equals 5"<< endl;
    } else {
        cout<< "x does not equal 5"<< endl;
    }
    
    // multi-condition if/else statement
    if (x > 1 && y == true) {
        cout<< "x is greater than 1 and y equals true"<< endl;
    } else {
        cout<< "x is not greater than 1 and y does not equal true"<< endl;
    }
    
    // if/else if/else statement
    if (x < 5) {
        cout<< "x is less than 5"<< endl;
    } else if (x > 5) {
        cout<< "x is greater than 5"<< endl;
    } else {
        cout<< "x is equal to 5"<< endl;
    }
    
    // using ints as booleans
    if (x) {
        cout<< "5 evaluates to true"<< endl;
    }
    
    if (z){
        cout<< "nothing"<< endl;
    } else {
        cout<< "0 evaluates to false"<< endl;
    }
    
    // does c++ short circuit? (yes)
    if (x == 5 || scTestFunc()) {
        cout<< "if 'function executed' is not printed, C++ short circuits if 1st condition is true in an or statement" << endl;
    }
    
    if (x != 5 && scTestFunc()) {
        cout<< "nothing" << endl;
    } else {
        cout<< "if 'function executed' is not printed, C++ short circuits if 1st condition is false in an and statement" << endl;
    }
    
    // switch case statements
    switch (x) {
        case 1:
            cout<< "x = 1"<< endl;
            break;
        case 2:
            cout<< "x = 2"<< endl;
            break;
        case 5:
            cout<< "x = 5"<< endl;
            break;
    }
    
    return 0;
}







