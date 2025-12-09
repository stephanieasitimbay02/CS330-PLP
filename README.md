# C++ Tutorial
## History
C++ was created by Bjarne Stroustrup, a Danish computer scientist, at Bell Telephone Laboratories in Murray Hill, New Jersey, and first released in 1985. Stroustrup wanted a language similar to C but with the addition of active type checking, basic inheritance, classes, etc. C++ is used for a variety of things, including operating systems, game development, databases, and so much more. 
Sources: 
- https://www.codecademy.com/resources/blog/what-is-c-plus-plus-used-for
- https://www.geeksforgeeks.org/cpp/history-of-c/
- https://en.wikipedia.org/wiki/C%2B%2B

## Installation 
In order to run C++ on Mac, I had to download XCode from the App Store. The Apple Clang compiler comes included with XCode, so there's no need to download anything else. C++ does not come with a recommended programming environment, so I will be using XCode. 
Single-line comments in C++ start with two forward slashes (//)
Multi-line comments start with /* and end with */

Simple Hello World Program in C++:
```c++
#include <iostream>
using namespace std;
int main() {
    
    cout << "Hello, World!" << endl;
    return 0;
}
```
The first line imports the iostream library, which enables us to use input/output commands such as cout.
The second line tells the compiler that we are using the standard namespace, allowing us to use cout instead of std::cout every time.
We then define our main function, which must return an int. 0 normally signifies successful program execution, whereas another number may indicate errors. 
We use the cout command to print "Hello, World!" to the terminal, and endl will create a new line after our string. We then return 0 to indicate a successful program execution.
## Data Types and Naming Conventions
- C++ does have keywords that can not be used as variable names. C++20 has 81 keywords.
- Variables must start with an alphabet, but they can include underscores and numbers.
- Both camelCase and snake_case are acceptable to use for naming variables in C++
- C++ is statically typed, meaning if you declare a variable as an int, you cannot later store a string in that variable.
- There's some debate on whether C++ is more strongly or weakly typed because it does allow for some implicit conversions, making it not as strong as it could be
- C++ is generally explicitly typed because you must always declare variable types.
Sources:
- https://en.cppreference.com/w/cpp/keywords.html
- https://www.geeksforgeeks.org/cpp/naming-convention-in-c/
- https://www.geeksforgeeks.org/cpp/cpp-keywords/
- https://www.w3schools.com/cpp/cpp_arrays.asp
- https://www.geeksforgeeks.org/cpp/how-to-create-a-dictionary-in-cpp/
- ​​https://www.geeksforgeeks.org/cpp/cpp-pointers/

## Control Statements
- C++ has boolean values of true and false and 0 and 1. However, all integers besides 0 will evaluate to true as well.
- C++ supports if, else if, else, and switch statements
- The beginning and end of code blocks under each condition in if/else if/else statements are marked by curly brackets
- The example below will evaluate to true and print "5 evaluates to true"
 ```c++
int x = 5;

if (x) {
        cout<< "5 evaluates to true"<< endl;
    }
```
- The beginning of a code block under a case in a switch statement is marked by a semicolon and indentation. All cases and their code blocks are inside curly brackets
- C++ does use short-circuit evaluation for && and || statements
- For switch statements, you must use break to prevent the program from continuing to the next case

## Functions
- The syntax for declaring a function in C++ is: return type function name(parameter type parameter) {function code}
- Functions should be defined above their function calls. For example, if you're calling all your functions inside main(), all function definitions should come before main()
- C++ fully supports recursive functions
- Functions can accept as many parameters as you want, and they can be of various data types.
- Functions in C++ do not allow you to return multiple values at the same time, but there are ways around this issue:
  - You can use pointers to pass variables by their address and make changes using a pointer variable
  - You can return multiple values using structures. Structures are user-defined data types that allow you to store items of different data types.
  - You can return multiple values in an array, but they must be of the same data type.
- C++ uses both pass-by-value and pass-by-reference. The default is pass-by-value, but you can pass-by-reference using pointers.
- Arguments, parameters, and local variables are stored as values on the stack, but they can be stored as references to the heap by using the keyword "new" followed by the constructor of what you want to allocate.

## Classes and Inheritance
- C++ supports objects through classes and structs, which are extremely similar and can achieve the same functionality with one key difference.
- Struct's members and base classes are public by default, whereas Class's members and base classes are private by default. Both of these default values can be easily overridden, however, to public, private, or protected.
- Though they are very similar, the typical convention in C++ is to use structs for simple groupings of data with minimal to no member functions and classes for more complex objects that will have many methods and attributes.
- Classes and objects will typically use UpperCamelCase where the first letter of each word is uppercase. Their methods and functions will typically be in camelCase where the first letter is lowercase, or snake_case with all lowercase letters.
- C++ does not have any standard methods for functions that serve a similar purpose across all objects, such as __str__() in Python or toString() in Java.
