#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int convertChartoNum(char letter) { //Would have been better to take ASCII values and subtract the constant between the indexing & ASCII Values. 
    switch (letter) {
        case 'a': 
            return 10;
        case 'b': 
            return 11;
        case 'c': 
            return 12;
        case 'd': 
            return 13;
        case 'e': 
            return 14;
        case 'f': 
            return 15;
        case 'g': 
            return 16;
        case 'h': 
            return 17;
        case 'i': 
            return 18;
        case 'j': 
            return 19;
        case 'k': 
            return 20;
        case 'l': 
            return 21;
        case 'm': 
            return 22;
        case 'n': 
            return 23;
        case 'o': 
            return 24;
        case 'p': 
            return 25;
        case 'q': 
            return 26;
        case 'r': 
            return 27;
        case 's': 
            return 28;
        case 't': 
            return 29;
        case 'u': 
            return 30;
        case 'v': 
            return 31;
        case 'w': 
            return 32;
        case 'x': 
            return 33;
        case 'y': 
            return 34;
        case 'z': 
            return 35;
        default: 
            cout << "broke" << endl;
            return 0;
    }
}

void printChar(int theArray[]) { //Makes printing out everything a breeze, no need to manually cout the alphabet
    for (int i = 0; i <= 9; ++i) {
        cout << i << ":    " << theArray[i] << ":";
        for (int j = 1; j <= theArray[i]; j++) {
            cout << 'O';
        }
        cout << endl;
    }

    for (char i = 'a'; i <= 'z'; ++i) {
        cout << i << ":    " << theArray[i - 'a' + 10] << ":";
        for (int j = 1; j <= theArray[i - 'a' + 10]; j++) {
            cout << 'O';
        }
        cout << endl;

    }
}

int main() {
    int countArray[36] = {0};
    char Check;

    ifstream fileA("a.txt");

    cout << "Results for a.txt" << endl;
    cout << endl;

    if (fileA.is_open()) {
        while (fileA.get(Check)) {
            if (isdigit(Check)) {
                countArray[Check - '0'] += 1; // proper indexing for digits
            }
            else if (isalpha(Check)) {
                Check = tolower(Check);
                int numIndex = convertChartoNum(Check);
                countArray[numIndex] += 1; // proper indexing for letters
            }
        }
        fileA.close();
    }
    else {
        cout << "Opening A fail" << endl;
    }

    printChar(countArray);   //prints a.txt
    int newArray[36] = {0};  //new array for b.txt
    cout << endl;
    cout << endl;
    cout << "Results for b.txt" << endl;
    cout << endl;
    cout << endl;

    ifstream fileB("b.txt");

    if (fileB.is_open()) {
        while (fileB.get(Check)) {
            if (isdigit(Check)) {
                newArray[Check - '0'] += 1;
            }
            else if (isalpha(Check)) {
                Check = tolower(Check);
                int numIndex = convertChartoNum(Check);
                newArray[numIndex] += 1; 
            }
        }
        fileB.close();
    }
    else {
        cout << "Opening B fail" << endl;
    }

    printChar(newArray);

    return 0;
}
