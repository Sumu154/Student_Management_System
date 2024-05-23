
#include "Course.h"

#include<iostream>
using namespace std;
class UndergraduateCourse : public Course {
protected:
    string courseName;
    string courseCode;
public:
    void createCourse() override;
    void modifyCourse() override;
    void deleteCourse() override;

    const string& getCourseName() const;
    void setCourseName(const string& name);

    const string& getCourseCode() const;
    void setCourseCode(const string& code);
};

class PostgraduateCourse : public Course {
protected:
    string courseName;
    string courseCode;
public:
    void createCourse() override;
    void modifyCourse() override;
    void deleteCourse() override;

    const string& getCourseName() const;
    void setCourseName(const string& name);

    const string& getCourseCode() const;
    void setCourseCode(const string& code);
};

class ProfessionalDevelopmentCourse : public Course {
protected:
    string courseName;
    string courseCode;
public:
    void createCourse() override;
    void modifyCourse() override;
    void deleteCourse() override;

    const string& getCourseName() const;
    void setCourseName(const string& name);

    const string& getCourseCode() const;
    void setCourseCode(const string& code);
};
