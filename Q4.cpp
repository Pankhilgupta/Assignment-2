#include <iostream>
#include<cstring>
using namespace std;
// (a) Concatenate strings
void concatenateStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    cin>>str1;
    cout << "Enter second string: ";
    cin>>str2;
    cout << "Concatenated string: " << str1 + str2 << endl;
}
// (b) Reverse a string
void reverseString() {
    string str;
    cout << "Enter a string: ";
    cin>>str;
    cout << "Reversed string: ";
    int len=str.length();
    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}
// (c) Delete all vowels
void deleteVowels() {
    string str ;char result[100];
    cout << "Enter a string: ";
    cin>>str;
    int j = 0;
    for (int i = 0;i<str.length(); i++) {
        char ch = str[i];
        if(ch >= 'A' && ch <= 'Z'){
         	ch=ch+32;
        }
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            result[j] = ch;
	        j++;
        }
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
}
// (d) Sort strings alphabetically
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char arr[20][100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << (i + 1) << ": ";
        cin>>arr[i];
    }
    // Bubble sort 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
             if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
             }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
    // (e) Convert uppercase to lowercase
    void upperToLower() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; 
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "That is not an uppercase character!" << endl;
    }
}

int main() {
    int choice;
   do {
        cout << "\n  Menu \n"<< "1. Concatenate strings\n"<< "2. Reverse a string\n"<< "3. Delete all vowels from a string\n"<< "4. Sort strings in alphabetical order\n" << "5. Convert uppercase to lowercase\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: upperToLower(); break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
