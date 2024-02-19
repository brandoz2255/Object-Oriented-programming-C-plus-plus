#include <cstdlib>
#include <iostream>

/*This code is supposed to print the status of x when its
less than 0 then increment it by 3 */

int main(){
    int x = 0;
    int y = 5;

    if (x < y){

        printf("%i\n", x);
        x +=  3; // Increment x by  3

    }else if (x % 2 == 0){
        printf("x is even: %i\n",x);

    }else {
        printf("x is odds: %i\n",x);

    }

    return 0;
    
}
