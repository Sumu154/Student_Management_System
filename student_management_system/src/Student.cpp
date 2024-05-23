
// Student.cpp
#include "Student.h"
#include <iostream>

void Student::login() {
    cout << "Student login" << endl;

    cout << "Enter password: ";
    cin >> password;

    if (password != "studentpass123") {
        cout << "Authentication failed. Exiting..." << endl;
        exit(0);
    }

    cout << "Authentication successful!" << endl;
}



void Student::viewCourses() const {
    cout << "\nEnrolled Courses: ";
    for (const auto& course : enrolledCourses) {
        cout << course << ", ";
    }
    cout << endl << endl;
}

void Student::enrollUndergraduateCourse(const UndergraduateCourse& course) {
    enrolledCourses.push_back(course.getCourseCode());
    cout << "\nEnrolled in Undergraduate course: " << course.getCourseName() << endl;
}

void Student::enrollPostgraduateCourse(const PostgraduateCourse& course) {
    enrolledCourses.push_back(course.getCourseCode());
    cout << "\nEnrolled in Postgraduate course: " << course.getCourseName() << endl;
}

void Student::enrollProfessionalDevelopmentCourse(const ProfessionalDevelopmentCourse& course) {
    enrolledCourses.push_back(course.getCourseCode());
    cout << "\nEnrolled in Professional Development course: " << course.getCourseName() << endl;
}

const vector<string>& Student::getEnrolledCourses() const {
    return enrolledCourses;
}

void Student::addEnrolledCourse(const string& course) {
    enrolledCourses.push_back(course);
}

double Student::getGPA() const {
    return GPA;
}

void Student::setGPA(double gpa) {
    GPA = gpa;
}


double  Student::getgrade() const
{
    return grade;
}
void  Student::setgrade(double s) {
    grade = s;
}

void Student::viewStudentInfo()  {


    cout << "\nStudent Information:\n";
    cout << "------------------------\n";
    cout << "Username: " << getUsername() << "\n";
    cout << "Contact Info: " << getContactInfo() << "\n";
    cout << "Enrolled Courses: ";
    for (const auto& course : enrolledCourses) {
        cout << course << ", ";
    }
    cout << "\nGPA: " << getGPA();
    cout<<"\nGrade : "<< getgrade()<< endl <<endl;
}
