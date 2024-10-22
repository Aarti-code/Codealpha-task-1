
    #include <iostream>
using namespace std;

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    float totalGradePoints = 0.0;
    float totalCredits = 0.0;

    for (int i = 0; i < numSubjects; i++) {
        float gradePoint, credits;
        cout << "Enter grade point for subject " << (i + 1) << ": ";
        cin >> gradePoint;
        cout << "Enter credits for subject " << (i + 1) << ": ";
        cin >> credits;

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    if (totalCredits != 0) {
        float cgpa = totalGradePoints / totalCredits;
        cout << "Your CGPA is: " << cgpa << endl;
    } else {
        cout << "Total credits cannot be zero." << endl;
    }

    return 0;
}
