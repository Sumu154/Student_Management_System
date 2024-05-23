
#include "UndergraduateCourse.h"
#include <vector>
#include "Account.h"
#include<iostream>
using namespace std;
class Student : public Account {
private:
    vector<string> enrolledCourses;
    double GPA;
    double grade;

public:
    void login() override;
    void viewCourses() const;

    void enrollUndergraduateCourse(const UndergraduateCourse& course);
    void enrollPostgraduateCourse(const PostgraduateCourse& course);
    void enrollProfessionalDevelopmentCourse(const ProfessionalDevelopmentCourse& course);

    const vector<string>& getEnrolledCourses() const;
    void addEnrolledCourse(const string& course);

    double getGPA() const;
    void setGPA(const double gpa) ;

    double getgrade() const;
    void setgrade(const double s) ;

    void viewStudentInfo() ;
};
