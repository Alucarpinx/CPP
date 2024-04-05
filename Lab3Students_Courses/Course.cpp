#include <iostream>
#include <iomanip>
#include "Student.h"
#include "course.h"
#include <vector>

using namespace std;

Course::Course() {}

void Course::AddStudent(Student student) {
	roster.push_back(student);
}
int Course::CourseSize() {
	return roster.size();
}
void Course::DropStudent(string lastName) {
	for (int i = 0; i < roster.size(); i++){
		if (lastName == roster.at(i).GetLastName()) {
			roster.erase(roster.begin() + i);
		}
	}
}
Student Course::FindStudentHighestGpa() {
	double top = 0.0;
	string first;
	string last;

	for (int i = 0; i < roster.size(); i++) {
		if (top < roster.at(i).GetGPA()){
			top = roster.at(i).GetGPA();
			first = roster.at(i).GetFirstName();
			last = roster.at(i).GetLastName();
		}
	}
	return Student(first, last, top);
}
void Course::PrintRoster() {
	string first;
	string last;
	double grade;

	for (int i = 0; i < roster.size(); i++) {
		grade = roster.at(i).GetGPA();
		first = roster.at(i).GetFirstName();
		last = roster.at(i).GetLastName();
		cout << setw(7) << last << setw(7) << first << setw(7) << grade << endl;
	}
	cout << "Student: " << roster.size() << endl;
}

vector<Student> Course::GetDeansList(){
	double grad = 3.50;
	vector<Student> temp;

	for (int i = 0; i < roster.size(); i++){
		if (roster.at(i).GetGPA() >= grad) {
			temp.push_back(roster.at(i));
		}
	}
	return(temp);
}
