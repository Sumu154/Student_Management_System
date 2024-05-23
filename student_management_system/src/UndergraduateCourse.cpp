#include "UndergraduateCourse.h"
#include <iostream>


const string& UndergraduateCourse::getCourseName() const {
    return courseName;
}

void UndergraduateCourse::setCourseName(const string& name) {
    courseName = name;
}

const string& UndergraduateCourse::getCourseCode() const {
    return courseCode;
}

void UndergraduateCourse::setCourseCode(const string& code) {
    courseCode = code;
}


void UndergraduateCourse::createCourse() {
    cout << "\nCreated Undergraduate Course" <<  endl << endl;
}

void UndergraduateCourse::modifyCourse() {
    cout << "\nModifying Undergraduate Course" << endl;
    cout << "-----------------------------------\n";
}

void UndergraduateCourse::deleteCourse() {
    cout << "Deleting Undergraduate Course" << endl;
}




const string& PostgraduateCourse::getCourseName() const {
    return courseName;
}

void PostgraduateCourse::setCourseName(const string& name) {
    courseName = name;
}

const string& PostgraduateCourse::getCourseCode() const {
    return courseCode;
}

void PostgraduateCourse::setCourseCode(const string& code) {
    courseCode = code;
}



void PostgraduateCourse::createCourse() {
    cout << "\nCreated Postgraduate Course" << endl << endl;
}

void PostgraduateCourse::modifyCourse() {
    cout << "\nModifying Postgraduate Course" << endl;
    cout << "------------------------------------\n";
}

void PostgraduateCourse::deleteCourse() {
    cout << "Deleting Postgraduate Course" << endl;
}




const string& ProfessionalDevelopmentCourse::getCourseName() const {
    return courseName;
}

void ProfessionalDevelopmentCourse::setCourseName(const string& name) {
    courseName = name;
}

const string& ProfessionalDevelopmentCourse::getCourseCode() const {
    return courseCode;
}

void ProfessionalDevelopmentCourse::setCourseCode(const string& code) {
    courseCode = code;
}



void ProfessionalDevelopmentCourse::createCourse() {
    cout << "\nCreated Professional Development Course" << endl << endl;
}

void ProfessionalDevelopmentCourse::modifyCourse() {
    cout << "\nModifying Professional Development Course" << endl;
    cout << "-----------------------------------------------\n";
}

void ProfessionalDevelopmentCourse::deleteCourse() {
    cout << "Deleting Professional Development Course" << endl;
}
