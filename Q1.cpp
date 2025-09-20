#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " of array: ";
        cin >> arr[i];
    }
    int k;
    cout << "Enter the required element: ";
    cin >> k;
    // Sorting the array (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Binary Search
    int low = 0, end = n - 1;
   int found = 0;
    while (low <= end) {
        int m = (low + end) / 2;
        if (arr[m] == k) {
            cout << "The required element is present at index: " << m << endl;
            found++;
            break;
        } else if (arr[m] < k) {
            low = m + 1;
        } else {
            end = m - 1;
        }
    }
    if (found==0) {
        cout << "Element not found" << endl; }
    return 0;
}
