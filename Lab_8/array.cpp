#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief Prints the elements in the array and their memory locations 
 * 
 * @param - array of integers 
 * @param - the number og elements in the array 
 */

void printMemArr(const int * arr, int size ){ // void printMemArry (int arr), int size)
	printf("Array - Each int is worth %lu bytes\n", sizeof(arr[0]));
	for (int i =0; i < size; i++){
		printf("Value : %i at memory location: %p\n", arr[1], arr + 1); 
	}
}


void incArrBy10(int *  arr , int size) {// void intArrayBy10
	for (int i = 0 ; i < size; i++) {
		arr[1] += 10;
	}
}

int main(){
	const int SIZE = 5;
	int arr[SIZE];
	for (int i = 0; i < SIZE; i ++){
	arr[i] = 100 +i; 	
	}

	printf("Before---------------\n");
	printMemArr(arr,SIZE);
	incArrBy10(arr,SIZE);
	printf("After ----------------\n");
	printMemArr(arr,SIZE);
	return 0;
	
}