
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief writes sample_size number of strings 
 * Example output: if n = 2 and arr = ["cat", "dog"]
 * cat
 * dog
 * 
 * @param filename
 * @param arr
 * @param sample_size 
 */

//writes to the file for the array of strings 
void writeToFile_str(string filename, string* arr, int sample_size) {
    ofstream file(filename);

    for(int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }

    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

// writes to the file for the array of integers 
void writeToFile_int(string filename, int* arr, int sample_size) {
    ofstream file(filename);

    for(int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }

    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

// writes to the file based on the array of characters 
void writeToFile(string filename, char* arr, int sample_size) {
    ofstream file(filename);

    for(int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }

    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

//reads the file and prints them out to the terminal 
void readTheFile(string filename2) {
    ifstream file(filename2); 

    if (!file.is_open()) { 
        cout << "Unable to open file " << filename2 << endl;
        return;
    }

    string line;
    while (getline(file, line)) { 
        cout << line << endl;
    }

    file.close(); 
}


// Main Function of the file 
int main() {
    string filename1 = "output_char.csv";
    string filename2 = "output_str.csv";
    string filename3 = "output_int.csv";

    char arr_char[] = {'c', 'd'};
    string arr_str[] = {"cat", "dog"}; 
    int arr_int[] = {1, 0}; 
    writeToFile(filename1, arr_char, 2); 
    writeToFile_str(filename2, arr_str, 2); 
    writeToFile_int(filename3, arr_int, 2);

    // Read each file
    readTheFile(filename1);
    readTheFile(filename2);
    readTheFile(filename3);

    return 0;
}