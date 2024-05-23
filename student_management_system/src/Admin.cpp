#include "Admin.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void Admin::login() {
    cout << "Admin login" << endl;

    cout << "Enter password: ";
    cin >> password;

    if (password != "adminpass123") {
        cout << "Authentication failed. Exiting..." << endl;
        exit(0);
    }

    cout << "Authentication successful!" << endl;
}

void Admin::addNewStudent(Student newStudent) {
    ofstream outFile("student.csv", ios::app);
    outFile << newStudent.getUsername() << ","
            << newStudent.getPassword() << ","
            << newStudent.getContactInfo() << ","
            << newStudent.getGPA() << ","
            << newStudent.getgrade() << "\n";
    outFile.close();
}

void Admin::removeStudent(const string& username, vector<Student>& st) {
    auto it = find_if(st.begin(), st.end(), [&](const Student& student) {
        return student.getUsername() == username;
    });

    if (it != st.end()) {
        cout << "Removing student with username: " << username << endl;
        st.erase(it);

        // Print the remaining students
        cout << "\n\nRemaining students: " << endl;
        cout << "--------------------------\n";

        cout<<"Name\t\tPassword\t\tContact Info\n";
        cout<< "---------------------------------------------------------\n";


        for (const auto& remainingStudent : st) {
            cout << remainingStudent.getUsername() << "\t\t"
                 << "  *****  " << "\t\t"
                 << remainingStudent.getContactInfo() << endl;
        }


        // update the csv students
        ofstream outFile("student.csv", ios::out);
        for (const auto& remainingStudent : st) {

        outFile << remainingStudent.getUsername() << ","
                << remainingStudent.getPassword() << ","
                << remainingStudent.getContactInfo() << ","
                << remainingStudent.getGPA() << ","
                << remainingStudent.getgrade() << "\n";
        }
        cout<<"\n\nStudent file updated\n\n";
        outFile.close();


    } else {
        cout << "Student with username " << username << " not found." << endl;
    }
}



void Admin::createCourse(Course& newCourse) {
    newCourse.createCourse();
}

void Admin::updateCourse(Course& existingCourse) {
    existingCourse.modifyCourse();
}

void Admin::deleteCourse(Course& existingCourse) {
    existingCourse.deleteCourse();
}

void Admin::viewAdminInfo() const {
    cout << "\n";
    cout << "Admin Information:\n";
    cout << "-------------------\n";
    cout << "Username: " << getUsername() << "\n";
    cout << "---------\n";
    cout << "Contact Info: " << getContactInfo() << "\n";
    cout << "-------------";
}


void Faculty::login() {
    cout << "Faculty login" << endl;

    cout << "Enter password: ";
    string enteredPassword;
    cin >> enteredPassword;

    if (enteredPassword == "facultypass123") {
        cout << "Authentication successful!\n";
    } else {
        cout << "Authentication failed. Exiting...\n";
        exit(0);
    }
}

const vector<string>& Faculty::getCoursesTaught() const {
    return coursesTaught;
}

void Faculty::addCourseTaught(const string& course) {
    coursesTaught.push_back(course);
}

const vector<string>& Faculty::getPublications() const {
    return publications;
}

void Faculty::addPublication(const string& publication) {
    publications.push_back(publication);
}

void Faculty::viewFacultyInfo() const {
    cout << "\nFaculty Information:\n";
    cout << "----------------------------\n";
    cout << "Username: " << getUsername() << "\n";
    cout << "Contact Info: " << getContactInfo() << "\n";
    cout << "\n\n";
}

Student Faculty::uploadGrade( Student& student, double grade) {
    cout << "Uploading grade for student " << student.getUsername() << ": " << grade << endl;
    cout<<"Updated\n"<<endl;
    student.viewStudentInfo();
    return student;




}



