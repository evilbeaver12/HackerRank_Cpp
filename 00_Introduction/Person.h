#include <string>

static int student_id = 1;
static int prof_id = 1;

class Person
{
protected:
    std::string name;
    int age;
public:
    virtual void getdata()
    {
        std::cin >> name >> age;
    }

    virtual void putdata()
    {
        std::cout << name << " " << age << std::endl;
    }
};

class Professor : public Person
{
    int publications;
    int cur_id;

public:
    Professor()
    {
        cur_id = prof_id;
        prof_id++;
    }

    void getdata()
    {
        std::cin >> name >> age >> publications;
    }

    void putdata()
    {
        std::cout << name << " " << age << " " << publications << " " << cur_id << std::endl;
    }
};

class Student : public Person
{
    int marks[6];
    int cur_id;

public:
    Student()
    {
        cur_id = student_id;
        student_id++;
    }

    void getdata()
    {
        std::cin >> name >> age;
        for (int i = 0; i < 6; i++)
        {
            std::cin >> marks[i];
        }
    }

    void putdata()
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += marks[i];
        }
        std::cout << name << " " << age << " " << sum << " " << cur_id << std::endl;
    }
};