#include<iostream>
using namespace std;

class Student1{
    public:
        void set_name(string name);
        void set_year(int year);
        void set_gender(char gender);
        string get_name();
        int get_year();
        char get_gender();
        void SaySomething();
    private:
        string name;
        int year;
        char gender;
};

void Student1::set_name(string name){
    this->name = name;
}

void Student1::set_year(int year){
    this->year = year;
}

void Student1::set_gender(char gender){
    this->gender = gender;
}

string Student1::get_name(){
    return name;
}

int Student1::get_year(){
    return year;
}

char Student1::get_gender(){
    return gender;
}

void Student1::SaySomething(){
    string name = get_name();
    printf("Hello, my name is %s", name.c_str());
}

int main(){
    Student1 adam;
    adam.set_name("Adam");
    adam.set_year(2);
    adam.set_gender('1');
    adam.SaySomething();
    return 0;
}