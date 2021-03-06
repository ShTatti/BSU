#include "Student.h"

class StudentAfterFirstSession : public Student {
protected:
    int *marks1;
public:
    StudentAfterFirstSession (const Student &, const int *nfirst_session);
    StudentAfterFirstSession (const StudentAfterFirstSession &);
    int *setmarks1(const int *valueFirstSession);
    friend std::ostream& operator << (std::ostream& out, StudentAfterFirstSession&);
    double AverageMark() override;
    int *GetMarks1();
    int GetSession() override;
};