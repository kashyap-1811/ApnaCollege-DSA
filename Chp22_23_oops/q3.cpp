#include <iostream>
#include<string>
using namespace std;

class Person
{
    string name;
    int age;

    public:
    Person(string name, int age)
    {
        this->age=age;
        this->name=name;
    }

    void display()
    {
        cout<<"Name of the Student is: "<<name<<endl;
        cout<<"Age of the Student is: "<<age<<endl;
    }
};

class Student:public Person
{
    string id;

    public:
    Student(string name,int age,string id):Person(name,age)
    {
        this->id=id;
    }

    void display()
    {
        Person::display();
        cout<<"Id of the Student is: "<<id<<endl;
    }
};

int main()
{
    Student s1("Kashyap",18,"23CEUOG138");
    s1.display();
    return 0;
}