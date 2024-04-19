#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterateiveSearch starts at the first index and iterates sequentiality to the next until it either
 * finds the element or until it reaches the end (i.e. element does not exist)
 *
 * @param v : vector of elements
 * @param elem : integer to look for 
 * @return int
 */


int iterativeSearch(vector<int>v, int elem){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == elem){
            return i;
        }
    }
    return -1;
}




/**
* @brief returns the index of elem, if it exists in v. Otherwise it returns -1,
* binary Search is recursive (i.e. function calls itself).
* It utilizes the fact that v is increasing order (e.g. values go up and 
* duplicates are not allowed).)
*
* it calculates the mid from the start and end index. It compare v[mid] (i.e. value
* at mid) with elem and decides wether to search the left half (lower values)
* or right half (upper values).
*
*
* @param v : vector of elements
* @param start : leftmost index (starting value is 0)
* @param end : rightmost index (starting value is v.size())
* @param elem : integer to look for
* @return int
*/


int binarySearch(vector<int> &v, int start, int end, int elem){

    if(start > end) {
        return -1; // Terminating case: element is not present in the vector
    }
    
    int mid = start + (end - start) / 2; // Calculate the mid point to avoid overflow

    if(v[mid] == elem) {
        return mid; // Element found at mid index
    }
    
    if(v[mid] > elem) {
        return binarySearch(v, start, mid - 1, elem); // Search in the left half
    } else {
        return binarySearch(v, mid + 1, end, elem); // Search in the right half
    }
}

/**
 * @brief updates v to contain the values from filename (leave as is)
 *
 * It is as expected that the files contain values ranging from one to 
 * one hundred million in ascending order (no duplicates).
 *
 * @param filename : string
 * @param v: vector
 */

 void vecGen(string filename, vector <int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
 }



int main(){
    // populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    double iterative_total_time = 0;
    double binary_total_time = 0;


    // Timing iterativeSearch
    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];
        
        clock_t start = clock();
        int index_if_found = iterativeSearch(v, elem);
        clock_t end = clock();
        
        double elapsed_time_in_sec = double(end - start) / CLOCKS_PER_SEC;
        iterative_total_time += elapsed_time_in_sec; // Add the time to the total
        cout << "iterativeSearch - Index found: " << index_if_found << ", Time: " << elapsed_time_in_sec << " sec" << endl;
    }

     // Calculate and print average time for iterativeSearch
    double iterative_avg_time = iterative_total_time / elem_to_find.size();
    cout << "Average time for iterativeSearch: " << iterative_avg_time << " sec" << endl;


    // Timing binarySearch
    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];
        
        clock_t start = clock();
        int index_if_found = binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        
        double elapsed_time_in_sec = double(end - start) / CLOCKS_PER_SEC;
        binary_total_time += elapsed_time_in_sec; // Summing the time for average calculation later
        cout << "BinarySearch - Index found: " << index_if_found << ", Time: " << elapsed_time_in_sec << " sec" << endl;
    }

  

    // Calculate and print average time for binarySearch
    double binary_avg_time = binary_total_time / elem_to_find.size();
    cout << "Average time for binarySearch: " << binary_avg_time << " sec" << endl;

    return 0;
}
