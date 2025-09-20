#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter total number of elements (including missing): ";
    cin >> n;
    int arr[100];
    cout << "Enter sorted elements of array (without missing number) :  ";
    for (int i = 0; i < n - 1; i++)  //n-1 bcz n is with missing number
  {
        cin >> arr[i];
    }
    // Step 1: Find common difference (d)
    int d = abs(arr[1] - arr[0]);
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff < d){ d = diff;}
    }
    // Step 2: Find the missing number
    int missing = 0;
    int m=0;
    for (int i = 0; i < n - 2; i++) {
        if (arr[i + 1] - arr[i] != d) {
            missing = arr[i] + d;
            m++;
            break;
        }
    }
    if (m ==0 ) {
        missing = arr[0] + (n - 1) * d;
    }
    cout << "Missing number is: " << missing << endl;
    return 0;
}
