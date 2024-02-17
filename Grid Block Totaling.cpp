// Johnny Fields sec 002
// Grid Block Totaling SHort program 3

#include <iostream>
#include <ctime>

const int ROWCOUNT = 10;
const int COLCOUNT = 20;

using namespace std;

void arraySet(int array[][20]) 
{
    for (int i = 0; i < ROWCOUNT; i++) 
    {
        for (int j = 0; j < COLCOUNT; j++) 
        {
            array[i][j] =  (rand()%2);
        }

    }
}

void printArray(int array[][20])
{
    for (int i = 0; i < ROWCOUNT; i++) 
    {
        for (int j = 0; j < COLCOUNT; j++) 
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void arrayAdd(const int array[][20], int sumBlockArray[][20], int rows, int cols) {
    for (int i = 0; i < rows; ++i) //Iterating through rows
    {
        for (int j = 0; j < cols; ++j) //Iterating through columns
        { 
            int total = 0;

            for (int k = max(0, i - 1); k < min(rows, i + 2); ++k) //Utilizng min and max to stay within bounds of array
            { 
                for (int l = max(0, j - 1); l < min(cols, j + 2); ++l) 
                {
                    total = array[k][l] + total; // Continously adds each index, once it exits out the 3rd and 4th loop it will add that total to the array
                }
            }
            sumBlockArray[i][j] = total; // This is the actual sum of the block surrounding each index, which is saved in the new array and displayed at the end
        }
    }
}

int main() 
{
    srand((unsigned)time(NULL)); // Utilizing a seed gen dependent on time <-- Given

    int array[ROWCOUNT][COLCOUNT]; // Random gen grid
    int theArray[ROWCOUNT][COLCOUNT]; // Sum of the rdm gen grid

    arraySet(array);

    cout << "Initial Grid" << endl;
    printArray(array);
    cout << endl;
    cout << endl;

    arrayAdd(array, theArray, ROWCOUNT, COLCOUNT);

    cout << "Grid Block Totaling" << endl;
    printArray(theArray);

    return 0;
}
