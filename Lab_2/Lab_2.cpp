

//Lab_2.cpp

/***
 * examples of the data type obejcts 
  ***/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    //numerical
    int int_var = 1;
    float float_var = 1.23;
    double double_var = 1.44;

    //non-numerical
    char char_var = 'a';
    bool bool_var = true;


    //size of number obejcts 

    cout << "Integer variable example -> " << sizeof(int_var) << endl;
    cout << "Float variable example -> " << sizeof(float_var) << endl;
    cout << "Double variable example -> " << sizeof(double_var) << endl;

    // sixe of char and bool variables 
    cout << "Char variable example -> " << sizeof(char_var) << endl;
    cout << "Bool variable example -> " << sizeof(bool_var) << endl;

    return 0; 

}