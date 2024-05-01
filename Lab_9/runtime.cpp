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





int iterativeSearch(const vector<int>& v, int elem) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i; // Found
        }
    }
    return -1; // Not found
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

void writeTimes(string filename, const vector<double>& times, const vector<int>& file_sizes) {
    ofstream myFile(filename); 

    myFile << "File Size (n),Iterative Time (sec),Binary Time (sec)\n"; // Use commas here
    for (int i = 0; i < file_sizes.size(); i++) {
        myFile << file_sizes[i] << "," << times[i * 2] << "," << times[i * 2 + 1] << "\n"; // Separate fields with commas
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;  
}


double average(const vector<double> a){
    if (a.empty()){
        return 0;
    }

    double sum = 0;

    for(double num : a){
        sum += num; // sums all elements in the vector 
    }

    return sum / a.size(); //divide the sum by the number of elements

}

/**
 * 
 * THE MAIN FUNCTION
 * 
 */




int main() {
    vector<int> file_size;
    vecGen("sizes.csv", file_size); // Load file sizes

    vector<int> v;
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find); // Load elements to search for

    vector<double> times; // Will hold times for both iterative and binary searches
    vector<double> avg; // Will hold the average times for both searches, consecutively

    for (int size : file_size) {
        string filename = to_string(size) + "_numbers.csv";
        vecGen(filename, v); // Populate v with numbers for this file size
        cout << "Processing file: " << filename << endl;

        // Measure the time for iterative search
        for (int elem : elem_to_find) {
            clock_t start = clock();
            iterativeSearch(v, elem);
            clock_t end = clock();
            times.push_back(static_cast<double>(end - start) / CLOCKS_PER_SEC);
        }
        // Record the average time for iterative search
        avg.push_back(average(times));
        times.clear(); // Clear times for binary search measurements

        // Measure the time for binary search
        for (int elem : elem_to_find) {
            clock_t start = clock();
            binarySearch(v, 0, v.size() - 1, elem);
            clock_t end = clock();
            times.push_back(static_cast<double>(end - start) / CLOCKS_PER_SEC);
        }
        // Record the average time for binary search
        avg.push_back(average(times));
        times.clear(); // Clear times for next file size
    }

    // Assuming avg[0], avg[2], avg[4], ... are for iterative search
    // and avg[1], avg[3], avg[5], ... are for binary search.
    // Write the averaged times to a file
    writeTimes("combined_search_times.csv", avg, file_size);

    return 0;
}
