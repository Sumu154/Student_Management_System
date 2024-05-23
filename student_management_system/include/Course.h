
#include <iostream>
#include <string>

#include<iostream>
using namespace std;
class Course {
protected:
    string courseName;
    string courseCode;

public:
    virtual void createCourse() = 0;
    virtual void modifyCourse() = 0;
    virtual void deleteCourse() = 0;

    const string& getCourseName() const;
    void setCourseName(const string& name);

    const string& getCourseCode() const;
    void setCourseCode(const string& code);
};
