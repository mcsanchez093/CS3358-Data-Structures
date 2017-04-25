/* Maria Sanchez
 * 2/22/17
 * The purpose of this program is to create a main menu with 7 options. The options being methods to set 
 * grades for assignments, quizzes, and exams; and to display said grades along with an overral grade.
 * The grades and weighted averages are meant to reflect the scoring for this class 3358.
 */


#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include "MyGradesDT.h"

using namespace std;

//Main functionality goes here.
int main(){
    
    MyGrades gradeObj;
    int userChoice=0;
    cout<< endl << "\tWelcome to my grades APP."  << endl << endl;
    
    while(true){
        
        cout << endl <<  "Main Menu" << endl << endl;
        cout << "\t 1. Set A Quiz Grade" << endl;
        cout << "\t 2. Set A Programming Assignment Grade" << endl;
        cout << "\t 3. Set A Test Grade" << endl;
        cout << "\t 4. Show All Quiz Grades" << endl;
        cout << "\t 5. Show All Programming Assignment Grades" << endl;
        cout << "\t 6. Show All Test Grades" << endl;
        cout << "\t 7. Show Overall grades" << endl;
        cout << "\t 9. Exit The Program" << endl << endl;
        
        cout << "Enter your choice ---> \t";
        
        while(!(cin >> userChoice)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // checks for numbers only.
            cout << "Error *** Incorrect input - You entered a character" << endl;
            cout << "Enter a Positive Integer" << endl;
            cout << endl <<  "Enter your choice ---> ";
        }
        
        switch(userChoice){
            case 1:
                gradeObj.setQuizGrade();
                break;
            case 2:
                gradeObj.setAssignmentGrade();
                break;
            case 3:
                gradeObj.settestGrade();
                break;
            case 4:
                gradeObj.displayQuiz();
                break;
            case 5:
                gradeObj.displayAssignment();
                break;
            case 6:
                gradeObj.displaytest();
                break;
            case 7:
                gradeObj.displayoverall();
                break;
            case 9:
                exit(0);
            default:
                cout << "Outside the range (1 to 7 or 9).";
                
        }
    }
    
}
