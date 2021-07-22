#include"Twelveheading.h"
#include<iostream>
using namespace std;

int main(void){
    Demo adam("Adam",50,175);
    printf("%s\n", adam.get_name().c_str());
    printf("%d\n", adam.get_age());
    printf("%d\n", adam.get_height());
    adam.saySomething();
    return 0;
}
Demo::Demo(string name, int age, int height)
{
    set_name(name);
    set_age(age);
    set_height(height);
};

void Demo::set_name(string name){
    this->name = name;
}

void Demo::set_age(int age){
    this->age = age;
}

void Demo::set_height(int height){
    this->height = height;
}

string Demo::get_name(){
    return name;
}

int Demo::get_age(){
    return age;
}

int Demo::get_height(){
    return height;
}

void Demo::saySomething(){
    printf("%s, %d, %d",get_name().c_str(), get_age(), get_height());
}