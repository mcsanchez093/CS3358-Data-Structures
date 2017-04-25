#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include "MyGradesDT.h"

using namespace std;


// SETTER METHODS
void MyGrades::setQuizGrade(){
    
    double value;
    cout << endl << "Enter Quiz grade:   ";
    cin >> value;
    
    if(value <= 10.0){
        
        quizzes.push_back(value);
    }
    else
        cout << "Invalid value" << endl;
    
}

void MyGrades::setAssignmentGrade(){
    double value;
    cout << endl << "Enter A Programming Assignment grade :    ";
    cin >> value;
    
    if(value <= 10.0){
        
        assignments.push_back(value);
    }
    else
        cout << "Invalid value" << endl;
    
}

void MyGrades::settestGrade(){
    double value;
    cout << endl << "Enter A test grade :    ";
    cin >> value;
    
    if(value <= 20.0){
        
        tests.push_back(value);
    }
    else
        cout << "Invalid value" << endl;
    
    
}

// DISPLAY FUNCTIONS
void MyGrades::displayQuiz(){
    cout<<endl;
    cout << endl << "Show all Quiz grades with average." << endl;
    if(quizzes.size() == 0){
        cout << "No Quizzes are recorded" << endl;
    }
    else {
        cout << "Quiz grades are as follows" << endl;
        for(int i = 0; i < quizzes.size(); i++){
            cout << quizzes[i] << "\t";
        }
        cout << endl << "Average quiz grade is " << Average(quizzes) << " out of 10" << endl;
    }
    
}

void MyGrades::displayAssignment(){
    
    cout << endl << "Show all Assignment grades with average." << endl;
    if(assignments.size() == 0){
        cout << "No Assignmentss are recorded" << endl;
    }
    else {
        cout << "Assignment grades are as follows" << endl;
        for(int i = 0; i < assignments.size(); i++){
            cout << assignments[i] << "\t";
        }
        cout << endl << "Average assignment grade is " << Average(assignments)*2 << " out of 20" << endl;
    }
}

void MyGrades::displaytest(){
    
    cout << endl << "Show all Test grades with average." << endl;
    if(tests.size() == 0){
        cout << "No Test are recorded" << endl;
    }
    else {
        cout << "Test grades are as follows" << endl;
        for(int i = 0; i < tests.size(); i++){
            cout << tests[i] << "\t";
        }
        cout << endl << "Average test grade is " << Average(tests) << " out of 20" << endl;
    }
    
}

void MyGrades::displayoverall(){
    
    displayQuiz();
    displayAssignment();
    displaytest();
    
    
    double total = 0.0;
    /*for(int i = 0; i < tests.size(); i++){
        total = tests[i];
    }
    for(int i = 0; i < assignments.size(); i++){
        total = assignments[i];
    }
    for(int i = 0; i < quizzes.size(); i++){
        total = quizzes[i];
    }*/
    total = Average(assignments)*2 + Average(quizzes) + Average(tests);

    double totalPoints;

    if(tests.size() != 0){
        totalPoints += tests.size()*20;
    }
    if(assignments.size() != 0){
        totalPoints += 20;
    }
    if(quizzes.size() != 0){
        totalPoints += 10;
    }
    
    
    cout << endl << "overall total --> " << total << " out of " << totalPoints << endl;
    
    
}

// AVERAGING
double MyGrades::Average(vector<double> grades){
    
    double sum = 0.0;
    double avg = 0.0;
    for(int i = 0; i < grades.size(); i ++){
        sum += grades[i];
    }
    if(grades.size() != 0)
        avg = sum / grades.size();
    return avg;
    
}
