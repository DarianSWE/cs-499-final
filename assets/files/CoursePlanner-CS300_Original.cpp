//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Darian Gernand
// Version     : 1.0
// Description : Project Two
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Course structure to store course information
struct Course {
    string courseID;
    string title;
    vector<string> prerequisites;
};

// Custom HashMap implementation
class HashMap {
private:
    static const int TABLE_SIZE = 100;
    vector<Course> table[TABLE_SIZE];

    // Hash function
    int hash(string key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    void insert(Course course) {
        int index = hash(course.courseID);
        table[index].push_back(course);
    }

    Course* search(string courseID) {
        int index = hash(courseID);
        for (auto& course : table[index]) {
            if (course.courseID == courseID) {
                return &course;
            }
        }
        return nullptr;
    }

    vector<Course> getAllCourses() {
        vector<Course> courses;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto& course : table[i]) {
                courses.push_back(course);
            }
        }
        return courses;
    }
};

// Helper function to load courses from a file
void loadCourses(string filename, HashMap& courses) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Course course;
        string prereq;

        getline(ss, course.courseID, ',');
        getline(ss, course.title, ',');
        while (getline(ss, prereq, ',')) {
            course.prerequisites.push_back(prereq);
        }

        courses.insert(course);
    }

    cout << "Courses loaded successfully!" << endl;
   
}


// Helper function to print course list
void printCourseList(HashMap& courses) {
    vector<Course> allCourses = courses.getAllCourses();
    sort(allCourses.begin(), allCourses.end(), [](Course& a, Course& b) {
        return a.courseID < b.courseID;
        });

    cout << "Here is a sample schedule:" << endl;
    for (auto& course : allCourses) {
        cout << course.courseID << ", " << course.title << endl;
    }
}

// Helper function to print specific course details
void printCourseDetails(HashMap& courses, string courseID) {
    Course* course = courses.search(courseID);
    if (!course) {
        cout << "Course not found!" << endl;
        return;
    }

    cout << course->courseID << ", " << course->title << endl;
    cout << "Prerequisites: ";
    for (size_t i = 0; i < course->prerequisites.size(); ++i) {
        cout << course->prerequisites[i];
        if (i < course->prerequisites.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

// Main function
int main() {
    HashMap courses;
    int choice;
    string filename, courseID;

    cout << "Welcome to the course planner." << endl;

    do {
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter file name: ";
            cin >> filename;
            loadCourses(filename, courses);
            break;

        case 2:
            printCourseList(courses);
            break;

        case 3:
            cout << "What course do you want to know about? ";
            cin >> courseID;
            transform(courseID.begin(), courseID.end(), courseID.begin(), ::toupper); // Convert to uppercase
            printCourseDetails(courses, courseID);
            break;

        case 9:
            cout << "Thank you for using the course planner." << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}

