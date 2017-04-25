/* Maria Sanchez
 * 2/13/17
 *
 *
 * The purpose of this program is to display a matrix using a 2 Dimensional vector
 * In addition to creating the matrix, we check to see if it is considered a
 * "Perfect" Matrix. A "Perfect" Matrix is one which has a total / 3 equal to the sums
 * of its columns, rows, and diagonals.
 *
 *
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool inMatrix(vector< vector<int> > matrix, int r)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == r)           //if found in matrix, return true
            {
                return true;
            }
            
        }
    }
    return false;
}

vector< vector<int> > createMatrix(int n)
{
    vector< vector<int> > matrix;
    cout << "The perfect matrix that is created for size " << n << ": " << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int r = rand()%20 + 1;   //create a random number in range 1-15
            v.push_back(r);         //push that number in the vector
        }
        matrix.push_back(v);       //push that vector in the 2d vector array
        //print the vector
        for(int k = 0; k < n; k++)
            cout << v[k] <<"\t";
        cout << endl;
        v.clear();          //clear the 2d vector array
    }
    return matrix;          //return the 2d vector array
    
}

int main()
{
    cout << endl;
    cout << "Welcome to my perfect matrix program. The function of the program is to:" << endl;
    cout << endl;
    cout << "   1. Allow the user to enter the size of the perfect matrix, such as N. N>=2" << endl;
    cout << "   2. Create a 2 D vector array of size N x N" << endl;
    cout << "   3. Populate the 2 D vector array with distinct random numbers." << endl;
    cout << "   4. Display the sum for each row, column, and diagonals then " << endl;
    cout << "      determine whether the numbers in N x N vector array are" << endl;
    cout << "      perfect matrix numbers." << endl;
    cout << endl;
    
    bool keepRunning = true;
    
    do
    { // start of Repeat while loop
       
        
        int n;
        for( ; ; )
        {
            cout << "Enter the size of the matrix ( must be >=2 ): ";
            if( cin >> n && n >= 2 && cin.get() == '\n' )
            {
                break;
            }
            else
            {
                cout << "Invalid input.Try again!\n";
                cin.clear();
                while( cin.get() != '\n' ) ;
            }
        }
    

        
        vector< vector<int> > matrix;
        int sum, perfect_n;
        bool perfect = false;
        matrix = createMatrix(n);   //create matrix
        perfect_n = 0;              //perfect number
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                perfect_n += matrix[j][i];
            }
        }
        
        perfect_n = perfect_n/n;
        cout << endl;
        cout << "The perfect number is: " << perfect_n << endl;
        cout << endl;
        
        //sum of numbers in each row
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix[i][j];
            }
            cout << "Sum of numbers in Row # " << i+1 << " = " << sum << endl;
            if (sum != perfect_n)        //if sum of this row is not equal to perfect number, then set perfect to false
                perfect = false;
        }
        
        //sum of numbers in each col
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix[j][i];
            }
            cout << "Sum of numbers in Column # " << i+1 << " = " << sum << endl;
            if (sum != perfect_n)        //if sum of this column is not equal to perfect number, then set perfect to false
                perfect = false;
        }
        
        
        //sum of 1st diagonal
        cout << endl;
        sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += matrix[i][i];
        }
        
        cout<<"Sum of numbers in first diagonal = "<<sum<<endl;
        //sum of 2nd diagonal
        sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += matrix[i][n-1-i];
        }
        
        cout<<"Sum of numbers in second diagonal = "<<sum<<endl;
        cout<<endl;
        
        //sum of all numbers in each row and column compared with perfect number tells whether the matrix is perfect or not
        sum = 0;
        
        if (perfect)
            cout << "The above is a perfect matrix" << endl;
        else
            cout << "The above is not a perfect matrix" << endl;
        
        //ask whether user want to continue or not
        cout << endl;
        char response;
        
        try
        {
            while (response != 'y' || response != 'Y'){
                
                cout<< endl << "Would you like to find another perfect matrix - Enter y or Y for yes or n or N for no: ";
                cin >> response;
                
                if (response == 'n' || response == 'N'){
                    keepRunning = false;
                    throw response;
                }
                if (response == 'y' || response == 'Y'){
                    int x;
                    throw x;
                }
                
                cout << endl << "Invalid Choice, try again : ";
                
            }
        }
        catch (int z){
            cout << endl <<
            "Restarting Program ... " << endl << endl << endl;
        }
        catch (...){
            cout << endl << "Thank you for testing our program!" << endl;
        }
        
    }
    while(keepRunning);
    
    
    cout << endl << " This perfect matrix algorithm is implemented by Maria Sanchez and Kevin Zarzana"<< endl;
    cout << " February 13th - 2017" <<endl;
}
