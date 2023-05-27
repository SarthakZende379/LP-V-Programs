#include <iostream>
#include <vector>
#include <limits.h>
#include <omp.h>

using namespace std;

void min_reduction(vector<int>& arr) {
    int min_value = INT_MAX;
#pragma omp parallel for reduction(min: min_value)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    cout << "Minimum value: " << min_value << endl;
}

void max_reduction(vector<int>& arr) {
    int max_value = INT_MIN;
#pragma omp parallel for reduction(max: max_value)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    cout << "Maximum value: " << max_value << endl;
}

void sum_reduction(vector<int>& arr) {
    int sum = 0;
#pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
}

void average_reduction(vector<int>& arr) {
    int sum = 0;
#pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    cout << "Average: " << (double)sum / arr.size() << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);
    return 0;
}

Output:

Test case 1:

Enter the size of the array: 5

Enter the elements of the array:

5 10 15 20 25

Expected Output:

Min value: 5

Max value: 25

Sum value: 75

Average value: 15

Test case 2:

Enter the size of the array: 6

Enter the elements of the array:

2 5 7 8 10 12

Expected Output:

Min value: 2

Max value: 12

Sum value: 44

Average value: 7.33333

Test case 3:

Enter the size of the array: 3

Enter the elements of the array:

-4 -2 -1

Expected Output:

Min value: -4

Max value: -1

Sum value: -7

Average value: -2.33333