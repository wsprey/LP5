#include <iostream>
#include <vector>
#include <sstream>
#include <omp.h>

using namespace std;

// Merge Function
void merge(vector<int>& arr, int left, int mid, int right) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right) {

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid)
        temp.push_back(arr[i++]);

    while(j <= right)
        temp.push_back(arr[j++]);

    for(int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

// Parallel Merge Sort
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

    vector<int> arr, bubbleArr, mergeArr;

    string input;
    int num;

    cout << "Enter elements: ";
    getline(cin, input);

    stringstream ss(input);

    while(ss >> num) {
        arr.push_back(num);
    }

    bubbleArr = arr;
    mergeArr = arr;

    int n = bubbleArr.size();

    // -------- Parallel Bubble Sort --------
    for(int i = 0; i < n; i++) {

        if(i % 2 == 0) {

            #pragma omp parallel for
            for(int j = 0; j < n - 1; j += 2) {

                if(bubbleArr[j] > bubbleArr[j + 1]) {
                    swap(bubbleArr[j], bubbleArr[j + 1]);
                }
            }
        }
        else {

            #pragma omp parallel for
            for(int j = 1; j < n - 1; j += 2) {

                if(bubbleArr[j] > bubbleArr[j + 1]) {
                    swap(bubbleArr[j], bubbleArr[j + 1]);
                }
            }
        }
    }

    // -------- Parallel Merge Sort --------
    mergeSort(mergeArr, 0, mergeArr.size() - 1);

    // Output Bubble Sort
    cout << "\nParallel Bubble Sort: ";

    for(int x : bubbleArr) {
        cout << x << " ";
    }

    // Output Merge Sort
    cout << "\nParallel Merge Sort: ";

    for(int x : mergeArr) {
        cout << x << " ";
    }

    return 0;
}