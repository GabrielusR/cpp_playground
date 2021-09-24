#ifndef CLASS_H
#define CLASS_H

class StudentRecord final
{
public:

    //methods
    StudentRecord();

    void setScore( int score );

    inline int getScore() const { return score; }

    static bool isValidScore( int score );

    //attributes
    const char * name;
    int id;
    StudentRecord * next;

private:

    int score;
};

class ClassRoster
{
public:

    //methods
    ClassRoster();

    ClassRoster( const ClassRoster & original );

    ~ClassRoster();

    void addStudent( const char * name, int score );

    void removeStudent( int id );

    void showStudent( int id );

    double showClassAverage();

    ClassRoster & operator=( const ClassRoster & rhs );

    StudentRecord * classRepresentative() const;

private:

    typedef bool (ClassRoster::*classRepPolicy)( const StudentRecord & r1, const StudentRecord & r2 );

    classRepPolicy currentRepPolicy; //class representative policy

    inline void setClassRepPolicy( classRepPolicy policy ){ currentRepPolicy = policy; }

    bool highestGrade( const StudentRecord & r1, const StudentRecord & r2 );
    bool veteranStudent( const StudentRecord & r1, const StudentRecord & r2 );
    bool alphabeticalOrder( const StudentRecord & r1, const StudentRecord & r2 );

    //methods
    const char * studentGrade( int score );

    StudentRecord * copiedStudents( const StudentRecord * original );

    void deleteStudents( StudentRecord * & students );

    //attributes
    StudentRecord * students;
};

#endif // CLASS_H
