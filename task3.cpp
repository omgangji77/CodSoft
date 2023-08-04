#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    float grade;
};

vector<Student> get_student_data() {
    vector<Student> students;
    while (true) {
        Student student;
        cout << "Enter student name (or 'exit' to finish): ";
        getline(cin, student.name);
        if (student.name == "exit")
            break;
        cout << "Enter student grade: ";
        cin >> student.grade;
        cin.ignore(); 
        students.push_back(student);
    }
    return students;
}

float calculate_average_grade(const vector<Student>& students) {
    float total_grades = 0;
    for (const auto& student : students) {
        total_grades += student.grade;
    }
    return total_grades / students.size();
}

const Student& get_highest_grade(const vector<Student>& students) {
    return *max_element(students.begin(), students.end(),
                        [](const Student& a, const Student& b) {
                            return a.grade < b.grade;
                        });
}

const Student& get_lowest_grade(const vector<Student>& students) {
    return *min_element(students.begin(), students.end(),
                        [](const Student& a, const Student& b) {
                            return a.grade < b.grade;
                        });
}

int main() {
    cout << "Student Grade Management System" << endl;
    cout << "Enter student names and their grades. Type 'exit' for the name to stop." << endl;

    vector<Student> students = get_student_data();

    if (students.empty()) {
        cout << "No data entered. Exiting the program." << endl;
        return 0;
    }

    float average_grade = calculate_average_grade(students);
    const Student& highest_student = get_highest_grade(students);
    const Student& lowest_student = get_lowest_grade(students);

    cout << "\nResults:" << endl;
    cout << "Average Grade: " << average_grade << endl;
    cout << "Highest Grade: " << highest_student.name << " - " << highest_student.grade << endl;
    cout << "Lowest Grade: " << lowest_student.name << " - " << lowest_student.grade << endl;

    return 0;
}
