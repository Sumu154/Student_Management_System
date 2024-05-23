
#include <fstream>
#include <vector>
#include "Student.h"

#include<iostream>
using namespace std;
class Admin : public Account {
public:
    void login() override;

    void addNewStudent(Student newStudent);

    void removeStudent(const std::string& username, std::vector<Student>& st);


    void createCourse(Course& newCourse);

    void updateCourse(Course& existingCourse);

    void deleteCourse(Course& existingCourse);

    void viewAdminInfo() const;
};

class Faculty : public Account {
private:
    vector<string> coursesTaught;
    vector<string> publications;

public:
    void login() override;

    const vector<string>& getCoursesTaught() const;
    void addCourseTaught(const string& course);
    Student uploadGrade( Student& student, double grade);
    const vector<string>& getPublications() const;
    void addPublication(const string& publication);

    void viewFacultyInfo() const;

};
