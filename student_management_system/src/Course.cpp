#include "Course.h"

const string& Course::getCourseName() const {
    return courseName;
}

void Course::setCourseName(const string& name) {
    courseName = name;
}

const string& Course::getCourseCode() const {
    return courseCode;
}

void Course::setCourseCode(const string& code) {
    courseCode = code;
}
