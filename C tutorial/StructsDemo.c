#include<stdio.h>
#include<stdlib.h>

int main(){
    struct Student student1;
    student1.age = 22;
    strcpy(student1.name, "Harvey");
    strcpy(student1.major, "Sociology");
    
}

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};
