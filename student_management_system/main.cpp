#include "Admin.h"
#include <algorithm>
#include <iostream>
#include <sstream>


// Overloaded stream operators for Student class
ostream& operator<<(ostream& os, const Admin& admin) {
    os << admin.getUsername() << ","
       << admin.getPassword() << ","
       << admin.getContactInfo() << ",";
    return os;
}

istream& operator>>(istream& is, Admin& admin) {
    string username, password, contactInfo;
    is >> username >> password >> contactInfo;
    admin.setUsername(username);
    admin.setPassword(password);
    admin.setContactInfo(contactInfo);
    return is;
}


// Overloaded stream operators for Student class
ostream& operator<<(ostream& os, const Student& student) {
    os << student.getUsername() << ","
       << student.getPassword() << ","
       << student.getContactInfo() << ","
       << student.getGPA();
    return os;
}

istream& operator>>(istream& is, Student& student) {
    string username, password, contactInfo;
    double GPA;
    is >> username >> password >> contactInfo >> GPA;
    student.setUsername(username);
    student.setPassword(password);
    student.setContactInfo(contactInfo);
    student.setGPA(GPA);
    return is;
}


// Overloaded stream operators for UndergraduateCourse class
ostream& operator<<(ostream& os, const UndergraduateCourse& course) {
    os << course.getCourseName() << "," << course.getCourseCode();
    // Additional data for UndergraduateCourse class can be added here if needed
    return os;
}

istream& operator>>(istream& is, UndergraduateCourse& course) {
    string courseName, courseCode;
    is >> courseName >> courseCode;
    course.setCourseName(courseName);
    course.setCourseCode(courseCode);
    // Additional data for UndergraduateCourse class can be added here if needed
    return is;
}

// faculty and admin
template <typename T>
void readDataFromCSV(const string& filename, vector<T>& data) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            T obj;
            int count =0;
            string unam="";
            string pass="";
            string con="";

            for(int i=0;i<line.length();i++)
            {
                if(line[i] == '\0')
                {
                    break;
                }
                if(line[i] == ',')
                {
                    i++;
                    count++;
                }
                if(count == 0)
                {
                    unam+=line[i];
                }
                if(count == 1)
                {
                    pass+=line[i];
                }
                if(count == 2)
                {
                    con+=line[i];
                }

            }

            obj.setUsername(unam);
            obj.setPassword(pass);
            obj.setContactInfo(con);

            data.push_back(obj);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}



// course
template <typename T>
void readDataFromCSV2(const string& filename, vector<T>& data) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            T obj;
            int count =0;
            string unam="";
            string pass="";
            string con="";

            for(int i=0;i<line.length();i++)
            {
                if(line[i] == '\0')
                {
                    break;
                }
                if(line[i] == ',')
                {
                    i++;
                    count++;
                }
                if(count == 0)
                {
                    unam+=line[i];
                }
                if(count == 1)
                {
                    pass+=line[i];
                }
                if(count == 2)
                {
                    con+=line[i];
                }

            }
            obj.setCourseName(unam);
            obj.setCourseCode(pass);


            data.push_back(obj);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}


// student
template <typename T>
void readDataFromCSV1(const string& filename, vector<T>& data) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            T obj;
            int count =0;
            string unam="";
            string pass="";
            string con="";
            string num1 = "";
            string num2 = "";


            for(int i=0;i<line.length();i++)
            {
                if(line[i] == '\0')
                {
                    break;
                }
                if(line[i] == ',')
                {
                    i++;
                    count++;
                }
                if(count == 0)
                {
                    unam+=line[i];
                }
                if(count == 1)
                {
                    pass+=line[i];
                }
                if(count == 2)
                {
                    con+=line[i];
                }

                if(count == 3)
                {
                    num1+=line[i];
                }

                if(count == 4)
                {
                    num2+=line[i];
                }


            }
            obj.setUsername(unam);
            obj.setPassword(pass);
            obj.setContactInfo(con);
            stringstream ss1,ss2;
            double n1,n2;
            ss1 << num1;
            ss2 << num2;
            ss1 >> n1;
            ss2 >> n2;
            obj.setGPA(n1);
            obj.setgrade(n2);
            data.push_back(obj);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}

// Function to write data to CSV file
template <typename T>
void writeDataToCSV(const string& filename, const vector<T>& data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& obj : data) {
            file << obj << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << " for writing" << endl;
    }
}

int main() {

    cout<<"\n \t\t\t\t\t ------------------------   Student Management System   ------------------------------";
cout<<"\n \t\t\t\t ------------------------------------------------------------------------------------------------------------\n\n\n";



    vector<Admin> admins;
    vector<Student> students;
    vector<UndergraduateCourse> ugcourses;
    vector<PostgraduateCourse> pgcourses;
    vector<ProfessionalDevelopmentCourse> prcourses;
    vector<Faculty> faculties;


    readDataFromCSV("admin.csv", admins);
    readDataFromCSV1("student.csv", students);
    readDataFromCSV2("ugcourse.csv", ugcourses);
    readDataFromCSV("faculty.csv", faculties);
    readDataFromCSV2("pgcourse.csv", pgcourses);
    readDataFromCSV2("prcourse.csv", prcourses);

    Admin admin;
    Student student;
    Faculty faculty;

    string enteredUsername, enteredPassword, entercontact;

    while (true) {
        cout << "Press 1 to login as admin\n";
        cout << "Press 2 to login as student\n";
        cout << "Press 3 to login as faculty\n";
        cout << "Press 4 to exit\n";
        cout << "\n\nEnter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nAdmin login:" << endl;
            cout << "----------------------\n";
            cout << "\nEnter Username : ";
            cin >> enteredUsername;
            cout << "Enter Password : ";
            cin >> enteredPassword;

            bool loggedIn = false;

            for (const auto& a : admins) {
                if (a.getUsername() == enteredUsername && a.getPassword() == enteredPassword) {
                    loggedIn = true;
                    admin = a;
                    break;
                }
            }

            if (loggedIn) {
                admin.viewAdminInfo();

                while(1)
                {



                cout << "\n\t\t\t\t\t1. Add new student\n";
                cout << "\t\t\t\t\t2. Remove student\n";
                cout << "\t\t\t\t\t3. Create course\n";
                cout << "\t\t\t\t\t4. Update course\n";
                cout << "\t\t\t\t\t5. Delete course\n";
                cout << "\t\t\t\t\t6. Go back\n";

                cout << "\nEnter your choice: ";

                cin >> choice;
                if(choice == 6)
                {
                    break;
                }

                switch (choice) {
                    case 1: {
                        Student newStudent;
                        cout << "\nEnter student details:";
                            cout << "\n------------------------\n";
                            cout << "Username: ";
                            cin >> enteredUsername;
                            newStudent.setUsername(enteredUsername);
                            cout << "Password: ";
                            cin >> enteredPassword;
                            newStudent.setPassword(enteredPassword);

                            while (true)
                            {
                                try
                                {
                                    cout << "Contact Info:  +88";
                                    cin >> entercontact;

                                    if (entercontact.size() > 11 || entercontact.size()< 11)
                                    {
                                        throw std::out_of_range("Invalid phone number. Please provide a valid phone number");
                                    }

                                    // If we reach here, the input is valid
                                    break;
                                }
                                catch (const std::out_of_range& e)
                                {
                                    cout << e.what() << endl;
                                    cin.clear(); // clear input buffer to restore cin to a usable state
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
                                }
                            }

                            newStudent.setContactInfo(entercontact);
                            cout << "GPA: ";
                            double gpa;
                            cin >> gpa;
                            double grade;
                        cout << "Grade: ";
                        cin>>grade;
                        newStudent.setgrade(grade);
                        newStudent.setGPA(gpa);
                        admin.addNewStudent(newStudent);
                        newStudent.viewStudentInfo();
                        cout << "\nNew student Added\n\n";
                        students.push_back(newStudent);
                        break;
                    }
                    case 2: {
                        cout<<"\n\nAvailable students are \n";
                        cout<<"Name\t\tPassword\t\tContact Info\n";
                        cout<< "---------------------------------------------------------\n";

                        for(int i=0;i<students.size();i++)
                        {
                            cout<<students[i].getUsername()<<"\t\t"<< " ******* "<<"\t\t"<<students[i].getContactInfo()<<"\t"<<endl;
                        }

                        cout << "\n\nEnter student username to remove: ";
                        cin >> enteredUsername;

                        admin.removeStudent(enteredUsername,students);

                        break;
                    }

                    // add
                    case 3: {
                         while (1) {
                            int ch;
                            cout << "\n\n";

                            cout << "~~PRESS 1 FOR UNDERGRADUATE COURSE\n";
                            cout << "~~PRESS 2 FOR POSTGRADUATE COURSE\n";
                            cout << "~~PRESS 3 FOR PROFESSIONAL DEVELOPER COURSE\n";
                            cout << "~~PRESS 4 to go back\n\n";
                            cout << "Enter your choice : ";
                            cin >> ch;
                            if (ch == 4) {
                                cout << "\n\n";
                                break;
                            }

                            switch (ch) {
                                case 1: {
                                    UndergraduateCourse newCourse;

                                    cout << "\nEnter undergraduate course details:\n";
                                    cout << "---------------------------------------\n";
                                    cout << "Course Name: ";
                                    cin >> enteredUsername;
                                    newCourse.setCourseName(enteredUsername);
                                    cout << "Course Code: ";
                                    cin >> enteredPassword;
                                    newCourse.setCourseCode(enteredPassword);
                                    admin.createCourse(newCourse);
                                    ugcourses.push_back(newCourse);


                                    ofstream outFile("ugcoursenew.csv", ios::app);


                                    for(int i=0;i<ugcourses.size();i++)
                                    {

                                        outFile << ugcourses[i].getCourseName() << ","
                                                << ugcourses[i].getCourseCode() << "\n";
                                    }



                                    outFile.close();


                                    remove("ugcourse.csv");
                                    rename("ugcoursenew.csv", "ugcourse.csv");
                                    outFile.close();


                                    break;
                                }

                                case 2: {
                                    PostgraduateCourse newCourse;
                                    cout << "\nEnter postgraduate course details:\n";
                                    cout << "----------------------------------------\n";
                                    cout << "Course Name: ";
                                    cin >> enteredUsername;
                                    newCourse.setCourseName(enteredUsername);
                                    cout << "Course Code: ";
                                    cin >> enteredPassword;
                                    newCourse.setCourseCode(enteredPassword);
                                    admin.createCourse(newCourse);
                                    pgcourses.push_back(newCourse);

                                    ofstream outFile("pgcoursenew.csv", ios::app);

                                    for(int i=0;i<pgcourses.size();i++)
                                    {

                                        outFile << pgcourses[i].getCourseName() << ","
                                                << pgcourses[i].getCourseCode() << "\n";
                                    }



                                    outFile.close();


                                    remove("pgcourse.csv");
                                    rename("pgcoursenew.csv", "pgcourse.csv");


                                    break;
                                }

                                case 3: {

                                    ProfessionalDevelopmentCourse newCourse;
                                    cout << "\nEnter professional developer course details:\n";
                                    cout << "-----------------------------------------------\n";
                                    cout << "Course Name: ";
                                    cin >> enteredUsername;
                                    newCourse.setCourseName(enteredUsername);
                                    cout << "Course Code: ";
                                    cin >> enteredPassword;
                                    newCourse.setCourseCode(enteredPassword);
                                    admin.createCourse(newCourse);
                                    prcourses.push_back(newCourse);

                                    ofstream outFile("prcoursenew.csv", ios::app);


                                    for(int i=0;i<prcourses.size();i++)
                                    {

                                        outFile << prcourses[i].getCourseName() << ","
                                                << prcourses[i].getCourseCode() << "\n";
                                    }



                                    outFile.close();


                                    remove("prcourse.csv");
                                    rename("prcoursenew.csv", "prcourse.csv");


                                    break;
                                }

                                default:
                                    cout << "Invalid choice. Please try again.\n";
                            }
                        }
                    }

                    // modify
                    case 4: {
                        while (1) {
                            int ch;

                            cout << "\n\n";

                            cout << "~~PRESS 1 FOR UNDERGRADUATE COURSE\n";
                            cout << "~~PRESS 2 FOR POSTGRADUATE COURSE\n";
                            cout << "~~PRESS 3 FOR PROFESSIONAL DEVELOPER COURSE\n";
                            cout << "~~PRESS 4 to go back\n\n";
                            cout << "Enter your choice : ";
                            cin >> ch;

                            if (ch == 4) {
                                break;
                            }

                            switch (ch) {
                                case 1: {
                                    // Update Undergraduate Course
                                    UndergraduateCourse existingCourse;
                                    cout << "\nEnter existing course details to update:\n";
                                    cout << "---------------------------------------------\n";
                                    cout << "Course Name: ";
                                    cin >> enteredUsername;
                                    int k=0;
                                    existingCourse.setCourseName(enteredUsername);
                                    cout << "Course Code: ";
                                    cin >> enteredPassword;
                                    existingCourse.setCourseCode(enteredPassword);

                                    auto it = find_if(ugcourses.begin(), ugcourses.end(), [&](const UndergraduateCourse& course) {
                                        return course.getCourseName() == existingCourse.getCourseName() &&
                                               course.getCourseCode() == existingCourse.getCourseCode();
                                    });

                                    if (it != ugcourses.end()) {
                                        // Update the course

                                        //this one to delete the previous one
                                        ugcourses.erase(it);
                                        admin.updateCourse(existingCourse);
                                        cout << "Enter new Course Name: ";
                                        cin >> enteredUsername;
                                        existingCourse.setCourseName(enteredUsername);
                                        cout << "Enter new Course Code: ";
                                        cin >> enteredPassword;
                                        existingCourse.setCourseCode(enteredPassword);


                                        ugcourses.push_back(existingCourse);

                                        ofstream outFile("ugcoursenew.csv", ios::app);


                                        for(int i=0;i<ugcourses.size();i++)
                                        {

                                            outFile << ugcourses[i].getCourseName() << ","
                                                    << ugcourses[i].getCourseCode() << "\n";
                                        }



                                        outFile.close();


                                        remove("ugcourse.csv");
                                        rename("ugcoursenew.csv", "ugcourse.csv");



                                         // Print the updated courses
                                        cout << "\nUpdated Undergraduate Courses:\n\n";
                                        cout << "Course Name" << "\t" << "Course Code" << endl;
                                        cout << "---------------------------------------------------------------------------------\n";
                                        for (const auto& course : ugcourses) {
                                            // Print course details as needed
                                            cout << "  " << course.getCourseName() << "\t\t  "
                                                 <<  course.getCourseCode()  << endl;
                                        }
                                    } else {
                                        cout << "\nCourse not found. Update failed.\n\n";
                                    }



                                    break;
                                }

                                case 2: {
                                    // Update Postgraduate Course
                                    PostgraduateCourse existingCourse;
                                    cout << "\nEnter existing postgraduate course details to update:\n";
                                    cout << "------------------------------------------------------------\n";
                                    cout << "Course Name: ";
                                    cin >> enteredUsername;
                                    existingCourse.setCourseName(enteredUsername);
                                    cout << "Course Code: ";
                                    cin >> enteredPassword;
                                    existingCourse.setCourseCode(enteredPassword);

                                    auto it = find_if(pgcourses.begin(), pgcourses.end(), [&](const PostgraduateCourse& course) {
                                        return course.getCourseName() == existingCourse.getCourseName() &&
                                               course.getCourseCode() == existingCourse.getCourseCode();
                                    });

                                    if (it != pgcourses.end()) {
                                        //delete the previous one
                                        pgcourses.erase(it);
                                        // Update the course
                                        admin.updateCourse(existingCourse);
                                        cout << "Enter new Course Name: ";
                                        cin >> enteredUsername;
                                        existingCourse.setCourseName(enteredUsername);
                                        cout << "Enter new Course Code: ";
                                        cin >> enteredPassword;
                                        existingCourse.setCourseCode(enteredPassword);


                                        pgcourses.push_back(existingCourse);

                                        ofstream outFile("pgcoursenew.csv", ios::app);


                                        for(int i=0;i<pgcourses.size();i++)
                                        {

                                            outFile << pgcourses[i].getCourseName() << ","
                                                    << pgcourses[i].getCourseCode() << "\n";
                                        }



                                        outFile.close();


                                        remove("pgcourse.csv");
                                        rename("pgcoursenew.csv", "pgcourse.csv");




                                         // Print the updated courses
                                        cout << "\nUpdated Postgraduate Courses:\n\n";
                                        cout << "Course Name" << "\t" << "Course Code" << endl;
                                        cout << "---------------------------------------------------------------------------------\n";
                                        for (const auto& course : pgcourses) {
                                            // Print course details as needed
                                            cout << "  " << course.getCourseName() << "\t\t  "
                                                 << course.getCourseCode() << endl;
                                        }
                                    } else {
                                        cout << "\nPostgraduate course not found. Update failed.\n\n";
                                    }
                                    break;
                                }

                                case 3: {
                                    // Update Professional Developer Course
                                    ProfessionalDevelopmentCourse existingCourse;
                                    cout << "\nEnter existing professional developer course details to update:\n";
                                    cout << "---------------------------------------------------------------------\n";
                                    cout << "Course Name: ";
                                    cin >> enteredUsername;
                                    existingCourse.setCourseName(enteredUsername);
                                    cout << "Course Code: ";
                                    cin >> enteredPassword;
                                    existingCourse.setCourseCode(enteredPassword);

                                    auto it = find_if(prcourses.begin(), prcourses.end(), [&](const ProfessionalDevelopmentCourse& course) {
                                        return course.getCourseName() == existingCourse.getCourseName() &&
                                               course.getCourseCode() == existingCourse.getCourseCode();
                                    });

                                    if (it != prcourses.end()) {
                                        //delete the previous one
                                        prcourses.erase(it);

                                        // Update the course
                                        admin.updateCourse(existingCourse);
                                        cout << "Enter new Course Name: ";
                                        cin >> enteredUsername;
                                        existingCourse.setCourseName(enteredUsername);
                                        cout << "Enter new Course Code: ";
                                        cin >> enteredPassword;
                                        existingCourse.setCourseCode(enteredPassword);


                                        prcourses.push_back(existingCourse);

                                        ofstream outFile("prcoursenew.csv", ios::app);


                                        for(int i=0;i<prcourses.size();i++)
                                        {

                                            outFile << prcourses[i].getCourseName() << ","
                                                    << prcourses[i].getCourseCode() << "\n";
                                        }



                                        outFile.close();


                                        remove("prcourse.csv");
                                        rename("prcoursenew.csv", "prcourse.csv");





                                         // Print the updated courses
                                        cout << "Updated professional Development Courses:\n";

                                        cout << "Course Name" << "\t\t" << "Course Code" << endl;
                                        cout << "---------------------------------------------------------------------------------\n";
                                        for (const auto& course : prcourses) {
                                            // Print course details as needed
                                            cout << "  " << course.getCourseName() << "\t\t  "
                                                 << course.getCourseCode() << endl;
                                        }



                                    } else {
                                        cout << "\nProfessional developer course not found. Update failed.\n\n";
                                    }
                                    break;
                                }

                                default:
                                    cout << "\nInvalid choice. Please try again.\n\n";
                            }
                        }

                        break;
                    }

                    // remove
                    case 5: {
                            while (1) {
                                int ch;

                                cout << "\n\n";

                                cout << "~~PRESS 1 FOR UNDERGRADUATE COURSE\n";
                                cout << "~~PRESS 2 FOR POSTGRADUATE COURSE\n";
                                cout << "~~PRESS 3 FOR PROFESSIONAL DEVELOPER COURSE\n";
                                cout << "~~PRESS 4 to go back\n\n";
                                cout << "Enter your choice : ";
                                cin >> ch;

                                if (ch == 4) {
                                    break;
                                }

                                switch (ch) {
                                    case 1: {
                                        // Remove Undergraduate Course
                                        UndergraduateCourse existingCourse;
                                        cout << "\nEnter existing course details to remove:\n";
                                        cout << "---------------------------------------------------------------------\n";
                                        cout << "Course Name: ";
                                        cin >> enteredUsername;
                                        existingCourse.setCourseName(enteredUsername);
                                        cout << "Course Code: ";
                                        cin >> enteredPassword;
                                        existingCourse.setCourseCode(enteredPassword);

                                        auto it = find_if(ugcourses.begin(), ugcourses.end(), [&](const UndergraduateCourse& course) {
                                            return course.getCourseName() == existingCourse.getCourseName() &&
                                                   course.getCourseCode() == existingCourse.getCourseCode();
                                        });

                                        if (it != ugcourses.end())
                                        {
                                            // Remove the course
                                            ugcourses.erase(it);
                                            cout << "\nCourse removed successfully.\n\n";

                                            ofstream outFile("ugcoursenew.csv", ios::app);


                                            for(int i=0; i<ugcourses.size(); i++)
                                            {

                                                outFile << ugcourses[i].getCourseName() << ","
                                                        << ugcourses[i].getCourseCode() << "\n";
                                            }



                                            outFile.close();


                                            remove("ugcourse.csv");
                                            rename("ugcoursenew.csv", "ugcourse.csv");
                                            outFile.close();


                                            // Print the remaining courses
                                            cout << "\nRemaining Undergraduate Courses:\n\n";

                                            cout << "Course Name" << "\t" << "Course Code" << endl;
                                            cout << "---------------------------------------------------------------------------------\n";
                                            for (const auto& course : ugcourses) {
                                                // Print course details as needed
                                                cout << "  " << course.getCourseName() << "\t\t  "
                                                     << course.getCourseCode() << endl;
                                            }
                                        } else {
                                            cout << "\nUndergraduate course not found. Removal failed.\n\n";
                                        }
                                        break;
                                    }

                                    case 2: {
                                        // Remove Postgraduate Course
                                        PostgraduateCourse existingCourse;
                                        cout << "\nEnter existing postgraduate course details to remove:\n";
                                        cout << "---------------------------------------------------------------------\n";
                                        cout << "Course Name: ";
                                        cin >> enteredUsername;
                                        existingCourse.setCourseName(enteredUsername);
                                        cout << "Course Code: ";
                                        cin >> enteredPassword;
                                        existingCourse.setCourseCode(enteredPassword);

                                        auto it = find_if(pgcourses.begin(), pgcourses.end(), [&](const PostgraduateCourse& course) {
                                            return course.getCourseName() == existingCourse.getCourseName() &&
                                                   course.getCourseCode() == existingCourse.getCourseCode();
                                        });

                                        if (it != pgcourses.end())
                                        {
                                            // Remove the course
                                            pgcourses.erase(it);
                                            cout << "\nCourse removed successfully.\n\n";

                                            ofstream outFile("pgcoursenew.csv", ios::app);

                                            for(int i=0; i<pgcourses.size(); i++)
                                            {

                                                outFile << pgcourses[i].getCourseName() << ","
                                                        << pgcourses[i].getCourseCode() << "\n";
                                            }



                                            outFile.close();


                                            remove("pgcourse.csv");
                                            rename("pgcoursenew.csv", "pgcourse.csv");


                                            // Print the remaining courses
                                            cout << "\nRemaining Postgraduate Courses:\n\n";
                                            outFile.close();
                                            cout << "Course Name" << "\t" << "Course Code" << endl;
                                            cout << "---------------------------------------------------------------------------------\n";
                                            for (const auto& course : pgcourses) {
                                                // Print course details as needed
                                                cout << "  " << course.getCourseName() << "\t\t  "
                                                     << course.getCourseCode() << endl;
                                            }
                                        } else {
                                            cout << "\nPostgraduate course not found. Removal failed.\n\n";
                                        }
                                        break;
                                    }

                                    case 3: {
                                        // Remove Professional Developer Course
                                        ProfessionalDevelopmentCourse existingCourse;
                                        cout << "\nEnter existing professional developer course details to remove:\n";
                                        cout << "---------------------------------------------------------------------\n";
                                        cout << "Course Name: ";
                                        cin >> enteredUsername;

                                        existingCourse.setCourseName(enteredUsername);
                                        cout << "Course Code: ";
                                        cin >> enteredPassword;
                                        existingCourse.setCourseCode(enteredPassword);

                                        auto it = find_if(prcourses.begin(), prcourses.end(), [&](const ProfessionalDevelopmentCourse& course) {
                                            return course.getCourseName() == existingCourse.getCourseName() &&
                                                   course.getCourseCode() == existingCourse.getCourseCode();
                                        });

                                        if (it != prcourses.end())
                                        {
                                            // Remove the course
                                            prcourses.erase(it);
                                            cout << "\nCourse removed successfully.\n\n";



                                            ofstream outFile("prcoursenew.csv", ios::app);


                                            for(int i=0; i<prcourses.size(); i++)
                                            {

                                                outFile << prcourses[i].getCourseName() << ","
                                                        << prcourses[i].getCourseCode() << "\n";
                                            }



                                            outFile.close();


                                            remove("prcourse.csv");
                                            rename("prcoursenew.csv", "prcourse.csv");



                                            // Print the remaining courses
                                            cout << "\nRemaining Professional Developer Courses:\n\n";

                                            cout << "Course Name" << "\t" << "Course Code" << endl;
                                            cout << "---------------------------------------------------------------------------------\n";
                                            for (const auto& course : prcourses)
                                            {
                                                // Print course details as needed
                                                cout << "  " << course.getCourseName() << "/t/t "
                                                     << course.getCourseCode() << endl;
                                            }
                                        }
                                        else
                                        {
                                            cout << "\nProfessional developer course not found. Removal failed.\n\n";
                                        }
                                        break;
                                    }

                                    default:
                                        cout << "\nInvalid choice. Please try again.\n\n";
                                }
                            }

                            break;
                            }

                    default:
                        cout << "\nInvalid choice\n\n";
                }
            }} else {
                cout << "\nInvalid username or password\n\n";
            }

        }


        // for student log in
        if (choice == 2) {
            cout << "\nStudent login:" << endl;
            cout << "----------------------\n";
            cout << "Enter Username: ";
            cin >> enteredUsername;
            cout << "Enter Password: ";
            cin >> enteredPassword;

            bool loggedIn = false;

            for (const auto& s : students) {
                if (s.getUsername() == enteredUsername && s.getPassword() == enteredPassword) {
                    loggedIn = true;
                    student = s;
                    break;
                }
            }

            if (loggedIn) {
                student.viewStudentInfo();

                while(1){
                cout << "\n\t\t\t\t1. View courses\n";
                cout << "\t\t\t\t2. Enroll in a course\n";
                cout << "\t\t\t\t3. Go back\n";
                cout << "\n\nEnter your choice: ";
                cin >> choice;

                if(choice == 3){
                    cout << endl << endl;
                    break;
                }

                switch (choice) {
                    case 1:{
                        student.viewCourses();
                        break;
                    }
                    case 2: {
                            while (1) {
                                int ch=10;

                                cout << "\n\n";

                                cout << "~~PRESS 1 FOR UNDERGRADUATE COURSE ENROLL\n";
                                cout << "~~PRESS 2 FOR POSTGRADUATE COURSE ENROLL\n";
                                cout << "~~PRESS 3 FOR PROFESSIONAL DEVELOPER COURSE ENROLL\n";
                                cout << "~~PRESS 4 to go back\n\n";
                                cout << "\n\nEnter your choice : ";
                                cin >> ch;
                                fflush(stdin);

                                if (ch == 4) {
                                    break;
                                }

                                switch (ch) {
                                    case 1: {
                                        UndergraduateCourse course;
                                        string str;

                                        cout << "\nEnter course code to enroll: ";
                                        cin >> str;

                                        auto it = find_if(ugcourses.begin(), ugcourses.end(), [&](const UndergraduateCourse& ugc) {
                                            return ugc.getCourseCode() == str;
                                        });

                                        if (it != ugcourses.end()) {
                                            course.setCourseCode(str);
                                            student.enrollUndergraduateCourse(course);


                                        } else {
                                            cout << "\nCourse not found. Enroll failed.\n\n";
                                        }
                                        break;
                                    }

                                    case 2: {
                                        PostgraduateCourse course;
                                        string str;
                                        cout << "\nEnter course code to enroll: ";
                                        cin >> str;

                                        auto it = find_if(pgcourses.begin(), pgcourses.end(), [&](const PostgraduateCourse& pgc) {
                                            return pgc.getCourseCode() == str;
                                        });

                                        if (it != pgcourses.end()) {
                                            course.setCourseCode(str);
                                            student.enrollPostgraduateCourse(course);


                                        } else {
                                            cout << "\nCourse not found. Enroll failed.\n\n";
                                        }
                                        break;
                                    }

                                    case 3: {
                                        ProfessionalDevelopmentCourse course;
                                        string str;
                                        cout << "\nEnter course code to enroll: ";
                                        cin >> str;

                                        auto it = find_if(prcourses.begin(), prcourses.end(), [&](const ProfessionalDevelopmentCourse& prc) {
                                            return prc.getCourseCode() == str;
                                        });

                                        if (it != prcourses.end()) {
                                            course.setCourseCode(str);
                                            student.enrollProfessionalDevelopmentCourse(course);


                                        } else {
                                            cout << "\nCourse not found. Enroll failed.\n\n";
                                        }
                                        break;
                                    }

                                    default:
                                        cout << "\nInvalid choice\n\n";
                                }
                            }
                            break;
                        }





                    }

                }
            }
                    else {
                        cout << "\nInvalid username or password\n\n";
                    }
        }


        //for faculty
        if (choice == 3) {
            cout << "\nFaculty login:" << endl;
            cout << "----------------------\n";

            cout << "Enter Username: ";
            cin >> enteredUsername;
            cout << "Enter Password: ";
            cin >> enteredPassword;

            bool loggedIn = false;

            for ( auto& f : faculties) {
                if (f.getUsername() == enteredUsername && f.getPassword() == enteredPassword) {
                    loggedIn = true;
                    faculty = f;
                    break;
                }
            }

            if (loggedIn) {
                faculty.viewFacultyInfo();

                while(1){
                cout << "\t\t\t1. View students\n";
                cout << "\t\t\t2. Upload grade\n";
                cout << "\t\t\t3. Go to back\n";
                cout << "\n\nEnter your choice: ";
                cin >> choice;

                if(choice == 3){
                    cout << endl << endl;
                    break;
                }

                switch (choice) {
                    case 1:
                        cout<<"\n\nAvailable students are \n";
                        cout<<"Name\t\tPassword\tContact Info\n";
                        cout<<"---------------------------------------------------------------------------------------\n";

                        for(int i=0;i<students.size();i++)
                        {
                            cout<<students[i].getUsername()<<"\t\t"<< "  ***  "<<"\t\t"<<students[i].getContactInfo()<<"\t\t"<<endl;
                        }

                        cout << endl << endl;

                        break;
                    case 2: {
                        Student student;
                        cout << "\nEnter student username to upload grade: ";
                        cin >> enteredUsername;
                        student.setUsername(enteredUsername);
                        cout << "\nEnter grade: ";
                        double grade;
                        cin >> grade;
                        student = faculty.uploadGrade(student, grade);

                        for(int i=0;i<students.size();i++)
                        {
                            if(students[i].getUsername() == student.getUsername())
                            {
                                students[i].setContactInfo(student.getContactInfo());
                                students[i].setGPA(student.getGPA());
                                students[i].setgrade(student.getgrade());
                                students[i].setPassword(student.getPassword());
                                students[i].setUsername(student.getUsername());

                            }

                        }

                        ofstream outFile("student.csv", ios::out);

                        for(int i=0;i<students.size();i++)
                        {

                        outFile << students[i].getUsername() << ","
                                << students[i].getPassword() << ","
                                << students[i].getContactInfo() << ","
                                << students[i].getGPA() << ","
                                << students[i].getgrade() << "\n";


                        }
                        outFile.close();


                        break;
                    }
                    default:
                        cout << "\nInvalid choice\n\n";
                }
                }
            } else {
                cout << "\nInvalid username or password\n\n";
            }




        }

        if (choice == 4) {
            cout << "\n\nExiting\n\n";
            break;
        }
    }


    return 0;
}
