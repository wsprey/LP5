#include <iostream>
#include <vector>
#include <sstream>
#include <omp.h>

using namespace std;

int main() {

    vector<int> arr;
    string input;
    int temp;

    cout << "Enter elements: ";
    getline(cin, input);

    stringstream ss(input);

    while(ss >> temp) {
        arr.push_back(temp);
    }

    int n = arr.size();

    // Parallel Bubble Sort
    #pragma omp parallel for
    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "\nSorted Array: ";

    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}