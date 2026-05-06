#include <iostream>
#include <vector>
#include <sstream>
#include <omp.h>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right) {

        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= right) {
        temp.push_back(arr[j++]);
    }

    for(int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {

    if(left < right) {

        int mid = (left + right) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSort(arr, left, mid);

            #pragma omp section
            mergeSort(arr, mid + 1, right);
        }

        merge(arr, left, mid, right);
    }
}

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

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted Array: ";

    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}