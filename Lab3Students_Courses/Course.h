#pragma once
#include "Student.h"
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Course {
	private:
		vector <Student> roster;
	public: 
		Course();

		void AddStudent(Student);
		void DropStudent(string);
		int CourseSize();
		Student FindStudentHighestGpa();
		void PrintRoster();
		vector <Student> GetDeansList();
};

