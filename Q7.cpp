#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << " of array: ";
        cin >> arr[i];
    }
    int inversion = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversion++;
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
    cout << "There are " << inversion << " inversions in this array." << endl;
    return 0;
}
