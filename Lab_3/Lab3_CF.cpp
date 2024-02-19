#include <cstdlib>
#include <iostream>

/*This code is supposed to print the status of x when its
less than 0 then increment it by 3 */

int main(){
    int x = 0;
    int y = 5;

   // The for loop will continue to execute as long as x is less than y
    for (; x < y; x +=  3) { // Note that the initialization is left empty
        printf("%i\n", x); // Print the current value of x
    }

    if (x % 2 == 0){
        printf("x is even: %i\n",x);

    }else {
        printf("x is odds: %i\n",x);

    }

    return 0;
    
}
