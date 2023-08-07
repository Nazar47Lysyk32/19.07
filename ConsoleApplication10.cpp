#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_SUBJECTS = 10;

class Student {
public:
    Student(const string& name) : name(name) {}

    string getName() const { return name; }
    void setMark(int subjectIndex, int mark) { marks[subjectIndex] = mark; }
    int getMark(int subjectIndex) const { return marks[subjectIndex]; }

private:
    string name;
    int marks[MAX_SUBJECTS] = { 0 };
};

int main() {
    Student students[MAX_STUDENTS];
    string subjects[MAX_SUBJECTS];

    string studentsFileName, subjectsFileName;
    cout << "Enter the filename for student list: ";
    cin >> studentsFileName;
    cout << "Enter the filename for subjects list: ";
    cin >> subjectsFileName;

    ifstream studentsFile(studentsFileName);
    ifstream subjectsFile(subjectsFileName);

    int numStudents, numSubjects;
    studentsFile >> numStudents;
    subjectsFile >> numSubjects;

    for (int i = 0; i < numStudents; ++i) {
        string studentName;
        studentsFile >> studentName;
        students[i] = Student(studentName);
    }

    for (int i = 0; i < numSubjects; ++i) {
        subjectsFile >> subjects[i];
    }

    for (int i = 0; i < numStudents; ++i) {
        for (int j = 0; j < numSubjects; ++j) {
            int mark;
            cin >> mark;
            students[i].setMark(j, mark);
        }
    }

    cout << "Student\t";
    for (int i = 0; i < numSubjects; ++i) {
        cout << subjects[i] << "\t";
    }
    cout << "Average" << endl;

    for (int i = 0; i < numStudents; ++i) {
        cout << students[i].getName() << "\t";
        int totalMarks = 0;
        for (int j = 0; j < numSubjects; ++j) {
            cout << students[i].getMark(j) << "\t";
            totalMarks += students[i].getMark(j);
        }
        double average = static_cast<double>(totalMarks) / numSubjects;
        cout << average << endl;
    }

    return 0;
}
