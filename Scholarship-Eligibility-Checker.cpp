#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student {
protected:
    string name;
    int rollNo;
    float marks;
    string category;  
public:
    void getDetails() {
        cout << "\nEnter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Marks (%): ";
        cin >> marks;
        cout << "Enter Category (Merit/Sports/Community): ";
        cin >> category;
    }
    virtual bool checkEligibility() = 0; 
    virtual void displayResult() = 0;    
};
class Performance : public Student {
    float attendance;
    string activity;
    bool eligible;
public:
    void getPerformance() {
        cout << "Enter Attendance Percentage: ";
        cin >> attendance;
        cout << "Enter Co-curricular Activity (Yes/No): ";
        cin >> activity;
    }	
    bool checkEligibility() override {
        if (category == "Merit" || category == "merit") {
            eligible = (marks >= 85 && attendance >= 80);
        }
        else if (category == "Sports" || category == "sports") {
            eligible = (marks >= 60 && activity == "Yes" && attendance >= 75);
        }
        else if (category == "Community" || category == "community") {
            eligible = (marks >= 70 && attendance >= 80);
        }
        else {
            eligible = false;
        }
        return eligible;
    }
    void displayResult() override {
        cout << "\n----------------------------------";
        cout << "\nScholarship Eligibility Report";
        cout << "\n----------------------------------";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nCategory: " << category;
        cout << "\nMarks: " << marks << "%";
        cout << "\nAttendance: " << attendance << "%";
        cout << "\nActivity: " << activity;
        cout << "\nEligibility Status: " << (eligible ? "ELIGIBLE" : "NOT ELIGIBLE");
        cout << "\n----------------------------------\n";
        ofstream file("Scholarship_Report.txt", ios::app);
        file << "----------------------------------\n";
        file << "Scholarship Eligibility Report\n";
        file << "----------------------------------\n";
        file << "Name: " << name << endl;
        file << "Roll No: " << rollNo << endl;
        file << "Category: " << category << endl;
        file << "Marks: " << marks << "%" << endl;
        file << "Attendance: " << attendance << "%" << endl;
        file << "Activity: " << activity << endl;
        file << "Eligibility Status: " << (eligible ? "ELIGIBLE" : "NOT ELIGIBLE") << endl;
        file << "----------------------------------\n\n";
        file.close();
    }
};
int main() {
    Performance p;
        cout << "=== Scholarship Eligibility Checker ===\n";
    p.getDetails();
    p.getPerformance();
    p.checkEligibility();
    p.displayResult();
    cout << "\nReport successfully saved to 'Scholarship_Report.txt'\n";
    return 0;
}


