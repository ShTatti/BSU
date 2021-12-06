#include <string>

class Student {
private:
    int identificator;
    int recordbook_number;
    static int count_id;
    static int count_rec;
protected:
    char *name;
    int course;
    int group;
public:
    Student (char *name1, int ncourse, int ngroup);
    Student (const Student &);
    char *GetName();
    int GetCourse();
    int GetGroup();
    int GetIdentificator();
    int GetRecordBookNumber();
    virtual int GetSession();
    void SetName(char *valueName);
    void SetCourse(int course);
    void SetGroup(int group);
    friend std::ostream& operator << (std::ostream& out, Student&);
    virtual double AverageMark();
};