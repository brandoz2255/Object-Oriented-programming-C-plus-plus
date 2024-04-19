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

int iterativeSearch(vector<int> v, int elem) {
    // use a for loop where the index, i, goes from 0 to the size of v
    for (int i = 0; i < v.size(); i++) {
        // inside the for loop, use an if statement to check whether the element at i (e.g. v[i]) equals elem
        if (v[i] == elem) {
            // inside the if statement return i
            return i;
        }
    }
    // outside of the for loop return -1 if the element is not found
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


int binarySearch(vector<int>& v, int start, int end, int elem) {

    int mid = start + (end - start) / 2;  // Calculate the midpoint to avoid overflow

    if (v[mid] == elem) {
        // If the element at mid is the target, return the index
        return mid;
    } else if (v[mid] > elem) {
        // If the element at mid is greater than the target, search the left half
        return binarySearch(v, start, mid - 1, elem);
    } else {
        // If the element at mid is less than the target, search the right half
        return binarySearch(v, mid + 1, end, elem);
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
    //populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_number.csv", v);

    //test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);


    // reads through all 10 of the test_elem values and calls iterates search
    // and records how long each search took (leave as is)

    cout << "Iterative Search Results:" << endl;

    for(int i = 0; i < elem_to_find.size(); i++){
        // gets to elem to search for
        int elem = elem_to_find[i];

        //stopwatch the time
        clock_t start = clock();                        // start time
        int index_if_found = iterativeSearch(v, elem);  // CALL search
        clock_t end = clock();                          // end time
        
        // calculates the total time its took in seconds
        double elapsed_time_in_sec = (double(end - start) /CLOCKS_PER_SEC);

        //prints the index and how long it took to find it
        cout << index_if_found << ": " << elapsed_time_in_sec << endl;
    }


    // repeat the for loop above so that it records the time
    // it takes for binarySearch to do the same operation

    // Testing binarySearch
    cout << "Binary Search Results:" << endl;
    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];

        clock_t start = clock();
        int index_if_found = binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        
        double elapsed_time_in_sec = (double(end - start) /CLOCKS_PER_SEC);
        cout << "Index --> " << index_if_found << "Time Elapsed --> " << elapsed_time_in_sec << " sec" << endl;
    }

    return 0; 

 }