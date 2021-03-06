#include <iostream>
#include "StudentAfterSecondSession.h"

StudentAfterSecondSession::StudentAfterSecondSession (const StudentAfterFirstSession &student, const int *nsecond_session)
        : StudentAfterFirstSession(student) {
    marks2 = new int [5];
    for (int i = 0; i < 5; ++i) {
        marks2[i] = nsecond_session[i];
    }
}

StudentAfterSecondSession::StudentAfterSecondSession (const StudentAfterSecondSession &d) : StudentAfterFirstSession(d) {
    marks2 = new int [5];
    for (int i = 0; i < 5; ++i) {
        marks2[i] = d.marks2[i];
    }
}

int* StudentAfterSecondSession::GetSecondSession() {
    return marks2;
}

int* StudentAfterSecondSession::setmarks2(const int *valueSecondSession) {
    marks2 = new int [5];
    for (int i = 0; i < 5; ++i) {
        marks2[i] = valueSecondSession[i];
    }
    return marks2;
}

std::ostream& operator << (std::ostream& out, StudentAfterSecondSession &d) {
    out << "Name: " << d.name << "\tGroup: " << d.group << "\tCourse: " << d.course << "\tId: "
        << d.GetIdentificator() << "\tRecordBook: " << d.GetRecordBookNumber();
    std::cout << std::endl;
    out << "Marks after first session: ";
    for (int i = 0; i < 4; ++i) {
        out << d.marks1[i] << " ";
    }
    std::cout << std::endl;
    out << "Marks after second session: ";
    for (int i = 0; i < 5; ++i) {
        out << d.marks2[i] << " ";
    }
    std::cout << std::endl;
    return out;
}

double StudentAfterSecondSession::AverageMark() {
    double average_mark = 0;
    for (int i = 0; i < 4; ++i) {
        average_mark += marks1[i];
    }
    for (int i = 0; i < 5; ++i) {
        average_mark += marks2[i];
    }
    average_mark = (double) average_mark / 9;
    std::cout << "The average mark after 2 session is: " << average_mark << std::endl;
    return average_mark;
}

int StudentAfterSecondSession::GetSession() {
    return 2;
}