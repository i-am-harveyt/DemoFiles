#include<iostream>
using namespace std;

class Demo
{
private:
    string name;
    int age;
    int height;
public:
    Demo(string, int, int);
    void set_name(string);
    void set_age(int);
    void set_height(int);
    string get_name();
    int get_age();
    int get_height();
    void saySomething();
};

