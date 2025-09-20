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
    int distinctCount = 0;
    for (int i = 0; i < n; i++) {
        int duplicate =0;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                duplicate++;
                break;
            }
        }
        if (duplicate==0) {
            distinctCount++;
            cout<<arr[i]<<" "<<endl;
        }
    }
    cout << "Number of distinct elements are: " << distinctCount << endl;
    return 0;
}
