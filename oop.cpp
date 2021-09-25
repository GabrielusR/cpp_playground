#include <iostream>

using namespace std;

//it is a way of exposing a standardized
//and common functionalities interface
//for someone looking at the contract.

//the given example maybe is not the best one.

//class AbstractShape getArea() class Square
//getArea(){side*size} class Rectangle getArea()
//{side*side/2}. Would be a better example.

//works as an interface
class AbstractEmployee
{
public:
    //pure virtual function = abstract
    virtual void askForPromotion() = 0;

    virtual void work() = 0;
};

class Employee : public AbstractEmployee
{
private:

    //attributes
    string name;
    string company;
    int age;

public:

    //methods
    inline void setName( string name )
    {
        this->name = name;
    }
    inline string getName()
    {
        return this->name;
    }
    inline void setCompany( string company )
    {
        this->company = company;
    }
    inline string getCompany()
    {
        return this->company;
    }
    inline void setAge( int age )
    {
        this->age = age;
    }
    inline int getAge()
    {
        return this->age;
    }
    void introduceYourself()
    {
        cout << "Name - " << name << endl;
        cout << "Company - " << company << endl;
        cout << "Age - " << age << endl;
    }
    void askForPromotion()
    {
        if( this->age > 30 )
        {
            cout << this->name << " got promoted." << endl;
        }
        else
        {
            cout << "Sorry no promotion for you." << endl;
        }
    }
    //constructor
    //constructors make instatiation of objects succint.
    //And its a way of guaranteeing that we'll have well
    //initialized object members.
    Employee(string name, string company, int age)
    {
        this->name=name;
        this->company=company;
        this->age=age;
    }

    virtual ~Employee()
    {
        //virtual destructor is necessary, so
        //the compiler will solve by looking at the v table
        //that the base classes destructors should be called
        //for superclass pointers, pointing to base classe objects.
        cout << "Calling employee destructor.\n";
    }
};

class Developer : public Employee
{
private:
    string favProgLanguage;
public:
    inline string getFavProgLanguage()
    {
        return favProgLanguage;
    }
    void fixBug()
    {
        cout << getName() << " fixed bug using " << getFavProgLanguage() << endl;
    }
    virtual void work()
    {
        fixBug();
        cout << "and " << getName() << " is writing code." << endl;
    }
    Developer(string name, string company, int age, string favProgLanguage)
    : Employee(name, company, age)
    {
        this->favProgLanguage = favProgLanguage;
    }

    ~Developer()
    {
        cout << "Calling developer destructor.\n";
    }
};

class Teacher : public Employee
{
private:
    string subject;
public:
    inline string getSubject()
    {
        return subject;
    }
    void prepareLesson()
    {
        cout << getName() << " is preparing a lesson on " << getSubject() << endl;
    }
    virtual void work()
    {
        prepareLesson();
        cout << "and is teaching " << endl;
    }
	
	//explicit avoids implicit class conversion
    explicit Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        this->subject = subject;
    }

    ~Teacher()
    {
        cout << "Calling teacher destructor.\n";
    }

    static int s_num;
};

int Teacher::s_num = 1;

int main()
{
    //Developer dev1 = Developer("Gabriel", "Minds", 26, "C++");

    //Teacher t1 = Teacher("Emanuel", "Bouros", 21, "Marketing");

    Employee * e1 = new Developer("Gabriel", "Minds", 26, "C++");//&dev1;

    Employee * e2 = new Teacher("Emanuel", "Bouros", 21, "Marketing");//&t1;

    Teacher t1 = Teacher("Jessica", "Transfero", 26, "Telemarkting");

    Teacher t2 = Teacher("Regina", "Hitts", 56, "Cooker");

    cout << Teacher::s_num << endl;
	
	cout << t1.getName() << " " << t1.getCompany() << " " << t1.getAge() << " " << t1.getSubject() << endl;
	
	//this will produce compiling error since we have an explicit constructor
	t1 = {"Ana", "Homecare", 51, "Nursery"}; //this will make an implicit class conversion.
	
	cout << t1.getName() << " " << t1.getCompany() << " " << t1.getAge() << " " << t1.getSubject() << endl;

    e1->work();

    e2->work();

    delete e1;

    delete e2;

    e1 = nullptr;

    e2 = nullptr;
}
