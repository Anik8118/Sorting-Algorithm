#include <iostream>
#include <algorithm>
using namespace std;
void countingSort(int arr[], int n) {
    // Find the maximum element in the array
    int max_val = *max_element(arr, arr + n);

    // Create a count array to store the count of each unique element
    int *count = new int[max_val + 1]();

    // Store the count of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array such that each element at each index
    // stores the sum of previous counts
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // Output array to store the sorted array
    int *output = new int[n];

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    countingSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
