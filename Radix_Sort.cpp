#include <iostream>
using namespace std;

// A function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp (10^i).
void countingSort(int arr[], int n, int exp) {
    int *output = new int[n]; // output array
    int count[10] = {0}; // initialize count array as 0

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr, n);
    

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// A utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to test the above functions
int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n]; // dynamically allocate memory for the array

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);
    
    radixSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
