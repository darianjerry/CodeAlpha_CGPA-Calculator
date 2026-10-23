#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

struct Course {
    string coursename;
    //Score is out of 100
    double score;
    double gradepoint;
    int credithours;
    char grade;
};

int getValidIntInput(string prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid data type! Please enter a valid integer." << endl;
        } else if (value < min || value > max) {
            cout << "Invalid range! Value must be between " << min << " and " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double getValidDoubleInput(string prompt, double min, double max) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid data type! Please enter a valid number." << endl;
        } else if (value < min || value > max) {
            cout << "Invalid score! Score must be between " << min << " and " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void assignGradeAndPoint(Course &c) {
    if(c.score >= 80.00 && c.score <= 100.00) {
       c.gradepoint = 4.00;
       c.grade = 'A';
    } else if(c.score >= 75.00) {
        c.gradepoint = 3.75;
        c.grade = 'B';
    } else if(c.score >= 70.00) {
        c.gradepoint = 3.50;
        c.grade = 'B';
    } else if(c.score >= 65.00) {
        c.gradepoint = 3.25;
        c.grade = 'C';
    } else if(c.score >= 60.00) {
        c.gradepoint = 3.00;
        c.grade = 'C';
    } else if(c.score >= 55.00) {
        c.gradepoint = 2.75;
        c.grade = 'D';
    } else if(c.score >= 50.00) {
        c.gradepoint = 2.50;
        c.grade = 'D';
    } else if(c.score >= 45.00) {
        c.gradepoint = 2.00;
        c.grade = 'E';
    } else if(c.score >= 40.00) {
        c.gradepoint = 1.50;
        c.grade = 'F';
    } else {
       c.gradepoint = 0.00;
       c.grade = 'F';
    }
}

double CalculateGPA(double totalcreditpoints, int totalcredithours) {
    if (totalcredithours == 0) return 0.0;
    return totalcreditpoints / totalcredithours;
}

double CalculateCGPA(double prev_credit_points, double totalcreditpoints, int prev_credit_hours, int totalcredithours) {
    int total_hours = prev_credit_hours + totalcredithours;
    if (total_hours == 0) return 0.0;
    return (prev_credit_points + totalcreditpoints) / total_hours;
}

int main() {
    int no_of_courses = getValidIntInput("Enter number of courses: ", 1, 100);
    vector<Course> courses(no_of_courses);
    double totalcreditpoints = 0.0;
    int totalcredithours = 0;
    double finalGPA = 0.0;

    double prev_credit_points = getValidDoubleInput("Enter previous total accumulated grade points (0 if none): ", 0.0, 1000.0);
    int prev_credit_hours = getValidIntInput("Enter previous total accumulated credit hours (0 if none): ", 0, 200);

    for(int i = 0; i < no_of_courses; i++) {
        cout << "Enter course title: ";
        cin >> ws;
        getline(cin, courses[i].coursename);

        courses[i].score = getValidDoubleInput("Enter student score: ", 0.00, 100.00);

        courses[i].credithours = getValidIntInput("Enter credit hours (1 to 3): ", 1, 3);

        assignGradeAndPoint(courses[i]);

        totalcreditpoints = totalcreditpoints + (courses[i].gradepoint * courses[i].credithours);
        totalcredithours = totalcredithours + courses[i].credithours;
    }
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "======================" << endl;
    cout << "    STUDENT RESULTS    " << endl;
    cout << "======================" << endl;


    finalGPA = CalculateGPA(totalcreditpoints, totalcredithours);
    double cumulativeGPA = CalculateCGPA(prev_credit_points, totalcreditpoints, prev_credit_hours, totalcredithours);

    cout << fixed << setprecision(2);
    cout << " 1. Total Credit Hours: " << totalcredithours << endl;
    cout << " 2. The calculated G.P.A is: " << finalGPA << endl;
    cout << " 3. The calculated C.G.P.A is: " << cumulativeGPA << endl;
    cout << " The courses taken and grades attained are: " << endl;
    for(int i = 0; i < no_of_courses; i++) {
        cout << "Course: " << courses[i].coursename << " | Score: " << courses[i].score << " | Credit Hours: " << courses[i].credithours << " | Grade Point: " << courses[i].gradepoint << " | Grade: " << courses[i].grade << endl;
    }

    if(cumulativeGPA >= 3.60) {
        cout << "Class: First Class" << endl;
    } else if(cumulativeGPA >= 3.00) {
        cout << "Class: Second Class Upper" << endl;
    } else if(cumulativeGPA >= 2.00) {
        cout << "Class: Second Class Lower" << endl;
    } else if(cumulativeGPA >= 1.50) {
        cout << "Class: Third Class" << endl;
    } else {
        cout << " 3. Class: Pass/Fail" << endl;
    }

    return 0;
}
