#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    string input;
    vector<int> arr;

    cout << "Enter elements: ";
    getline(cin, input);

    stringstream ss(input);
    int num;

    while(ss >> num) {
        arr.push_back(num);
    }

    // Operations
    int minimum = *min_element(arr.begin(), arr.end());
    int maximum = *max_element(arr.begin(), arr.end());
    int total = accumulate(arr.begin(), arr.end(), 0);
    float average = (float)total / arr.size();

    // Output
    cout << "\nMinimum : " << minimum << endl;
    cout << "Maximum : " << maximum << endl;
    cout << "Sum : " << total << endl;
    cout << "Average : " << average << endl;

    return 0;
}