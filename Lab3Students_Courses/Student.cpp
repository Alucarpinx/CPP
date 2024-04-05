#include <iostream>
#include "Student.h"


using namespace std;

Student::Student()
{
	firstName = "null";
	lastName = "null";
	gpa = 0.0;
}

Student::Student(string first, string last, double grade)
{
	firstName = first;
	lastName = last;
	gpa = grade;
}

string Student::GetFirstName()
{
	return(firstName);
}

string Student::GetLastName()
{
	return(lastName);
}

double Student::GetGPA()
{
	return(gpa);
}