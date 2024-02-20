
#include<iostream>

using namespace std;
/** somOfThree
 * @brief returns the summation of x, y, z
 * @param x : is (int)
 * @param y : is (int)
 * @param z : is (int)
 * @return int 
*/

// full function here -->

int sumOfThree(int x, int y, int z){

   int answerSum = x+y+z;

   return answerSum;

}

/** division
 * @brief returns x/y
 * @param x : is (double)
 * @param y : is (double)
 * @return double
*/

//function here 

double division(double x , double y){

    double answerDiv = x/y;

    return answerDiv;
}


/** isGreaterThan
 * @brief returns whether x is greater than y
 * @param x : is (double)
 * @param y : is (int)
 * @return true : x is greater than y
 * @return false : x is less than or equal to y
*/

//function here 

bool isGreaterThan(double x , int y){


    if (x > y){
        cout << x <<" is greater than " << y << "\n"<< endl;
        return true;
    }else{
        cout << x << "x is less than or equal to" << y << "\n" << endl;
        return false;
    }
}

/** select
 * @brief output the statements based on func_type
 * funct_type : output
 * "sum" : "the sum is "
 * "division" : "the quotient is "
 * "comparison" : "the first value being greater than the other is"
 *  All the other pharases : "inva;id function type\n"
 * @param func_type : is (string)
 * return string
 */

string select(const std::string& func_type) {
    if (func_type == "sum") {
        return "the sum is ";
    } else if (func_type == "division") {
        return "the quotient is ";
    } else if (func_type == "comparison") {
        return "the first value being greater than the other is ";
    } else {
        return "invalid function type\n";
    }
}

//myPrint 

/** select
 * @brief calls the select () to print out the output with the correct prompt
 * 
 * @tparam T : (int, double, or string) output of sum, division, or isgreaterThan
 * @param func_Type : (string)
 * @param output 
 *
*/

//function here 

template <typename T>
void myPrint (string func_type, T output){
    cout << select(func_type) << output << endl;
}


int main() {

    //initializes 3 int parameters 
    int x1 = 1;
    int x2 = 2;
    int x3 = 3; 

    // call sumOfThree
    int sum_out = sumOfThree(x1,x2,x3); 

    // calls the my print
    myPrint("sum", sum_out);

    //intiailizes 2 double parameters 
    double dividend = 12345.1;
    double divisor = 234.123;

    //call division 
    double div_out = division(dividend, divisor);
    myPrint("division", div_out);

    //compare div_out and sum_out
    bool is_greater_out = isGreaterThan(div_out,sum_out);
    myPrint("comparison", is_greater_out);

    return 0;


}