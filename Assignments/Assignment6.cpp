/* Maria Sanchez
 * 4/12/17
 *
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;


// FUNCTION DECLARATIONS
void tableOfSquares(int arr[], int last, int place);
void power(int value, int pow);
long long sumOfSquares(int place, int last, long long total);
void minMax(int arr[], int count, int size, int *min, int *max);
void bubbleSort(int arr[], int size);
bool isMember(int arr[], int size, int value);
bool notMember(int arr[], int size, int key);
void isItPrime(int arr[], int size, int count);


int main()
{
    int size = 0;
    char choice;

    // INTRO
    cout << "Thinking Recursively" << endl;

    cout << "The function of this program is to " << endl;
    cout << "use recursion to :-" << endl;

    cout << "\t1. Display Squares of integers in ascending order from 1 to the " << endl;
    cout << "\t last element in the array" << endl;
    cout << "\t2. Raise the first number to a power of 2" << endl;
    cout << "\t3. Return the sums of squares of the numbers from 0 to the " << endl;
    cout << "\t fifth element in the array" << endl;
    cout << "\t4. Search the array for the array's max and min values" << endl;
    cout << "\t5. Sort the array in ascending order" << endl;
    cout << "\t6. Search the array for the first value in the array" << endl;
    cout << "\t7. Search the array for the number 600" << endl;
    cout << "\t8. Determine if a number is prime (processes all array values)" << endl << endl;

    // REPEAT PROMPT / MENU
    do
    {
        cout << "Select from the following menu" << endl;
        cout << "A. Enter Array Size that is >4." << endl;
        cout << "X. Terminate the program." << endl;
        cout << "INPUT :: ";
        cin >> choice;
        if (choice == 'A')
        {
            do
            {
                // ACCEPT ARRAY SIZE
                cout << "Enter array size: "; // Get size input
                cin.ignore();
                cin >> size;
                if (cin.fail())
                {
                    cout << "*** Invalid Array size value ***" << endl;
                    cout << "Enter an integer not a char: "<<endl;
                    cin.clear();
                }
                else if (size < 4)
                {
                    cout << "*** Invalid Array size value ***" << endl;
                }
            } while (size < 4);

            int arr[size];	// Create array

            // POPULATE ARRAY -- RANDOM VALUES 25 - 500 INCLUSIVE
            srand(time(NULL));
            for (int i = 0; i < size; i++)
            {
                int r = rand() % 475 + 25;   //create a random number in range 25-500
                arr[i] = r;
            }
            // ******************************************************************* //
            // DISPLAY GENERATED ARRAY
            cout << "The generated array is :: ";
            for (int i = 0; i < size; i++) {
                cout << " " << arr[i];
            }
            cout << endl << endl;
            // ******************************************************************* //
            // TABLE OF SQUARES

            int last = arr[size - 1];	// END POINT
            // DISPLAY
            cout << "Table of Square values 1 - " << last << endl;
            cout << endl << "N :: " << "N^2" << endl;
            tableOfSquares(arr, last, 1);			//commented out cuz it works but it clogs the output lmao **********
            cout << endl << endl;
            // ******************************************************************* //
            // POWER FUNCTION
            // DISPLAY
            cout << "Power Function :: " << endl;
            cout << arr[0] << " raised to the 2nd power is :: ";

            power(arr[0], 2);

            cout << endl << endl;
            // ******************************************************************* //
            // SUM OF SQUARES FUNCTION

            int secondToLast = arr[size - 2];
            cout << "Sum of Squares between 0 and " << secondToLast << " is :: ";

            long long total = 0;
            total = sumOfSquares(0, secondToLast, total);
            cout << total;
            cout << endl << endl;
            // ******************************************************************* //
            // MIN MAX FUNCTION
            int minimum = 500;
            int maximum = 0;

            int *min = &minimum;
            int *max = &maximum;

            minMax(arr, 0, size, min, max);		// Function call

            cout << "Min number of (";			// MIN display
            for (int i = 0; i < size; i++) {
                cout << " " << arr[i];
                if (i < size - 1)
                    cout << ",";
            }
            cout << " ) is :: " << *min << endl;

            cout << "Max number of ( ";			// MAX display
            for (int i = 0; i < size; i++) {
                cout << " " << arr[i];
                if (i < size - 1)
                    cout << ",";
            }
            cout << " ) is :: " << *max;
            cout << endl << endl;			// SPACING

            // ******************************************************************* //
            // BUBBLE SORT
            bubbleSort(arr, size);						// ***** NOT DONE YET ****** //
            cout << endl << endl;
            cout << "Sorted Array:" << endl;
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl << endl;
            // ******************************************************************* //
            // IS MEMBER FUNCTION

            cout << "Member functions :: " << endl;
            // ARR[3] TEST CASE
            cout << "Does the array : (";			//  display
            for (int i = 0; i < size; i++) {
                cout << " " << arr[i];
                if (i < size - 1)
                    cout << ",";
            }
            cout << " ) have the number " << arr[3] << "?";
            if (isMember(arr, size, arr[3]) == true)
                cout << " YES" << endl;
            else
                cout << " NO" << endl;

            // 600 TEST CASE
            cout << "Does the array : (";			//  display
            for (int i = 0; i < size; i++) {
                cout << " " << arr[i];
                if (i < size - 1)
                    cout << ",";
            }
            cout << " ) have the number 600?";
            if (notMember(arr, size, 600))
                cout << "  YES" << endl;
            else
                cout << "  NO" << endl;
            cout << endl << endl;
            // ******************************************************************* //
            // NOT MEMBER FUNCTION
            //notMember(arr, size);	// Did it through isMember
            //cout << endl << endl;
            // ******************************************************************* //
            // IS IT PRIME
            cout << "Is it Prime :: " << endl;		// Display
            isItPrime(arr, size, 0);	// Function call
            cout << endl << endl;

            // Add Iterator


        }
        else if (choice == 'X')
        {
            cout << "Kevin Zarzana & Maria Sanchez -- April 2017" << endl;
            break;
        }
        else
        {
            cout << "*** Invalid option ***"<<endl;
        }

    } while (choice != 'X');

    //	system("pause");
}

void tableOfSquares(int arr[], int last, int place) {

    cout << place << " :: " << place * place << endl;
    if (place < last) {
        tableOfSquares(arr, last, place + 1);
    }


}
void power(int value, int pow) {
    if (pow > 1) {
        value = value * value;
        pow--;
        power(value, pow);
    }
    else {
        cout << value << endl;
    }
}

long long sumOfSquares(int place, int last, long long total)
{
    if (place < last) {
        total = total + (place * place);
        place++;
        sumOfSquares(place, last, total);
    }
    else
        return total;

}


void minMax(int arr[], int count, int size, int *min, int *max) {

    if (count < size) {
        if (arr[count] < *min)
            *min = arr[count];
        if (arr[count] > *max)
            *max = arr[count];
        count++;
        minMax(arr, count, size, min, max);
    }

}
void bubbleSort(int arr[], int size)
{
    if(size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
        if (arr[i + 1] > arr[i])
            swap(arr[i], arr[i + 1]);

   bubbleSort(arr, size - 1);

}

bool isMember(int arr[], int size, int value) {

    size--;

    if (size < 0)
        return false;
    else if (arr[size] == value)
        return true;
    else
        isMember(arr, size, value);

}



bool notMember(int arr[], int size, int key){


    if(size == 0)
        return false;
    int midPoint = size / 2;

    //int temp[midPoint];

    if(arr[midPoint] == key){
        return true;
    }
    if( arr[midPoint] < key){
        notMember(arr, midPoint, key);
    }
    else {
        notMember(arr + midPoint + 1, midPoint, key);
    }

    return false;

// JUST DID IT THROUGH ISMEMBER FUNCTION
}


void isItPrime(int arr[], int size, int count) {
    if (count < size) {

        for (int i = 2; i < arr[count]; i++) {
            if (arr[count] % i == 0) {
                cout << arr[count] << " is Not Prime" << endl;
                break;
            }
            if (i == arr[count] - 1)
                cout << arr[count] << " is Prime" << endl;
        }
        count++;
        isItPrime(arr, size, count);
    }
}
