#include <vector>
#include <cstdlib>


using namespace std;

class MyGrades{
private:
    vector<double> quizzes;
    vector<double> assignments;
    vector<double> tests;
    
public:
    void setQuizGrade();
    void setAssignmentGrade();
    void settestGrade();
    void displayQuiz();
    void displayAssignment();
    void displaytest();
    void displayoverall();
    double Average(vector<double>);
};
