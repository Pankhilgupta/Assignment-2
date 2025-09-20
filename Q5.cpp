#include <iostream>
using namespace std;
void Diagonal() {
    int a, b;
    cout << "Enter rows: ";
    cin >> a;
    cout << "Enter columns: ";
    cin >> b;
    int arr[100][100]={0};
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(i==j){
                cout << "Enter value for main diagonal (" << i << "," << j << "): ";
                cin >> arr[i][j];
            } else {
                arr[i][j] = 0;
            }
        }
    }

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void Tridiagonal() {
    int a, b;
    cout << "Enter rows: ";
    cin >> a;
    cout << "Enter columns: ";
    cin >> b;
    int arr[100][100] = {0};

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(i==j || i==j+1 || j==i+1){
                cout << "Enter value for (" << i << "," << j << "): ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void Lowertriangular() {
    int a, b;
    cout << "Enter rows: ";
    cin >> a;
    cout << "Enter columns: ";
    cin >> b;
    int arr[100][100] = {0};
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(i >= j){
                cout << "Enter value for (" << i << "," << j << "): ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void Uppertriangular() {
    int a, b;
    cout << "Enter rows: ";
    cin >> a;
    cout << "Enter columns: ";
    cin >> b;
    int arr[100][100] = {0};
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(i <= j){
                cout << "Enter value for (" << i << "," << j << "): ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void Symmetric() {
    int a, b;
    cout << "Enter rows: ";
    cin >> a;
    cout << "Enter columns: ";
    cin >> b;
    int arr[100][100] = {0};

    cout << "Enter values for upper triangle (including main diagonal):\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <b; j++) { 
            if(i<=j){
            cout << "Enter value for (" << i << "," << j << "): ";
            cin >> arr[i][j];
            arr[j][i] = arr[i][j]; 
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tridiagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: Diagonal(); break;
            case 2: Tridiagonal(); break;
            case 3: Lowertriangular(); break;
            case 4: Uppertriangular(); break;
            case 5: Symmetric(); break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 6);

    return 0;
}
