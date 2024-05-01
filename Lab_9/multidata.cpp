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


template<typename T>
int iterativeSearch(vector<T>& v, T elem) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
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



template<typename T>
int binarySearch(vector<T> &v, int start, int end, T elem) {
    if (start > end) {
        return -1; // Terminating case: element is not present in the vector
    }
    
    int mid = start + (end - start) / 2; // Calculate the mid point to avoid overflow
    
    if (v[mid] == elem) {
        return mid; // Element found at mid index
    }
    
    if (v[mid] > elem) {
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




template<typename T>
void vecGen(const string& filename, vector<T>& v) {
    ifstream file(filename);
    T value;
    v.clear();
    while (file >> value) {
        v.push_back(value);
    }
    file.close();
}


int main() {
    // Populate v with 10000 sorted integers
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // Test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    // Timing binarySearch on vector of doubles
    vector<double> d;
    vecGen("10000_double.csv", d);  // Assume this file has sorted double values

    vector<double> double_to_find;
    vecGen("double_to_find.csv", double_to_find);  // Assume this file has double values to find

    double binary_total_time = 0;
    for (int i = 0; i < double_to_find.size(); i++) {
        double elem = double_to_find[i];

        clock_t start = clock();
        int index_if_found = binarySearch(d, 0, d.size() - 1, elem);
        clock_t end = clock();

        double elapsed_time_in_sec = double(end - start) / CLOCKS_PER_SEC;
        binary_total_time += elapsed_time_in_sec;
        cout << "BinarySearch - Index found: " << index_if_found << ", Time: " << elapsed_time_in_sec << " sec" << endl;
    }

    // Calculate and print average time for binarySearch on doubles
    double binary_avg_time = binary_total_time / double_to_find.size();
    cout << "Average time for binarySearch on doubles: " << binary_avg_time << " sec" << endl;

    return 0;
}