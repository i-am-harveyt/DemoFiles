#include<iostream>
using namespace std;

int main(){
    Student adam;
    adam.name = "Adam";
    adam.gender = '1';
    adam.year = 2;
    printf("%s, %d, %d, %d",adam.name, adam.gender, adam.year, adam.calculate(1,2));
    return 0;
}

class Student{
    public:
    string name;
    int year;
    char gender;
    int calculate(int,int);
};
int calculate(int a, int b){
    return a+b;
}