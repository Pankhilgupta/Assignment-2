#include <iostream>
using namespace std;

int MAX = 100;
void set(int mat[100][3], int &terms) {
    cout << "Enter number of rows, cols and non-zero elements: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];   // rows, cols, non-zero
    terms = mat[0][2];
    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 1; i <= terms; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}
void display(int mat[100][3]) {
    int terms = mat[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= terms; i++) {
        cout << mat[i][0] << "  " << mat[i][1] << "  " << mat[i][2] << endl;
    }
}
void transpose(int mat[100][3], int result[100][3]) {
    int rows = mat[0][0], cols = mat[0][1], terms = mat[0][2];
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = terms;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= terms; i++) {
            if (mat[i][1] == c) {
                result[k][0] = mat[i][1];
                result[k][1] = mat[i][0];
                result[k][2] = mat[i][2];
                k++;
            }
        }
    }
}
void add(int a[100][3], int b[100][3], int result[100][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible!\n";
        return;
    }
    int t1 = a[0][2], t2 = b[0][2];
    result[0][0] = a[0][0];
    result[0][1] = a[0][1];
    int i = 1, j = 1, k = 1;
    while (i <= t1 && j <= t2) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        } else {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        }
    }
    while (i <= t1) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= t2) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }
    result[0][2] = k - 1;
}

void multiply(int a[100][3], int b[100][3], int result[100][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible!\n";
        return;
    }

    int rows = a[0][0], cols = b[0][1];
    int temp[100][100] = {0};

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                temp[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }

    result[0][0] = rows;
    result[0][1] = cols;
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (temp[i][j] != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = temp[i][j];
                k++;
            }
        }
    }
    result[0][2] = k - 1;
}

int main() {
    int a[100][3], b[100][3], c[100][3];
    int n1, n2;
    int choice;
    do {
        cout << "\nMENU:\n 1. Transpose 2. Addition 3. Multiplication "<<endl;
       cout<<"Enter choice:  ";
       cin >> choice;

        if (choice == 1) {
            set(a, n1);
            transpose(a, c);
            cout << "Transpose is:\n";
            display(c);
        } 
        else if (choice == 2) {
            cout << "Matrix A:\n";
            set(a, n1);
            cout << "Matrix B:\n";
            set(b, n2);
            add(a, b, c);
            cout << "Addition result:\n";
            display(c);
        } 
        else {
            cout << "Matrix A:\n";
            set(a, n1);
            cout << "Matrix B:\n";
            set(b, n2);
            multiply(a, b, c);
            cout << "Multiplication result:\n";
            display(c);
        } 
        
   } while(choice>4);
    
    return 0;
}
