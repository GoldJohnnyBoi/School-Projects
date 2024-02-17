#include <iostream>
#include <ctime>

using namespace std;

int DiceRoll() { //Actually generator random rolls <-- Given
    return rand() % 6 + 1;
}

int roll(int& a, int& b) { //Roll mechanic
    a = DiceRoll();
    b = DiceRoll();
    return a + b;
}

int main() {

    srand((unsigned)time(NULL)); // Utilizing a seed gen dependent on time <-- Given

    cout << "Welcome to the Craps game!" << endl;

    int a, b, sum;
    sum = roll(a, b);

    cout << "First Roll: " << a << " + " << b << " = " << sum << endl; // Initial statements

    switch (sum) { //More efficient than a bunch of if else statements, more effective too
        case 7:
        case 11:
            cout << "Lucky first roll! Rolling player wins!" << endl;
            cout << endl;
            cout << "See you later!";
            return 0; // if they win it closes program
            break;
        case 2:
        case 3:
        case 12:
            cout << "Bad first roll! Rolling player loses!" << endl;
            cout << endl;
            cout << "See you later!";
            return 0; // If they lose it closes program
            break;
        default: //transitions into actual game
            int point = sum;

            
    while (true) {  //while statement that will continously iterate until it enters 
        sum = roll(a, b);
        cout << "No result yet! Roll again!" << endl;
        cout << endl;
        cout << "Point = " << point << endl;
        cout << "Roll: " << a << " + " << b << " = " << sum << endl;

        if (sum == point) {
            cout << "Alright! Rolling player wins!" << endl;
            break;
    }   else if (sum == 7) {
            cout << "Oh No! Rolling player loses!" << endl;
            cout << endl;
            cout << "See you later!";
            break;
      }  
        }
            
            }
    

    return 0;
}

