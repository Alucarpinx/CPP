#pragma once
#include <string>
#include <iomanip>
using namespace std;

class Student
{
	private:
		string firstName;
		string lastName;
		double gpa;

	public:
		Student();
		Student(string, string, double);
		string GetFirstName();
		string GetLastName();
		double GetGPA();
};
