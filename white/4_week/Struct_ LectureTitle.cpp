//
// Created by alfa on 12.05.2020.
//
#include <iostream>
#include <string>
using namespace std;
struct Specialization
{
	string value;
	explicit Specialization(string new_value)
	{
		value = new_value;
	}
};

struct Course
{
	string value;
	explicit Course(string new_value)
	{
		value = new_value;
	}
};

struct Week
{
	string value;
	explicit Week(string new_value)
	{
		value = new_value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle( Specialization new_specialization, Course new_course, Week new_week)
	{
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
};



void PrintLectureTitle(const LectureTitle& LectureTitle)
{
	cout << LectureTitle.specialization << '\n' << LectureTitle.course << '\n' << LectureTitle.week;
}

//int main()
//{
////WORK
//	LectureTitle title(
//			Specialization("C++"),
//			Course("White belt"),
//			Week("4th")
//	);
////
////	LectureTitle title(
////			Specialization("C++"),
////			Week("4th"),
////			Course("White belt")
////	);
////
////
//	PrintLectureTitle(title);
//	return 0;
//}