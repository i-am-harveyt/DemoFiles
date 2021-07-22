# Pointers Note

[TOC]

## Working with pointers

\* Computers Memory  -> RAM
The basic constitution of memory is 1 byte memory. The momory address have a incresing relation. 

Datatypes and how much memory they'll use(to store the value):
+ int - 4 bytes
+ char - 1 byte
+ float - 4 bytes
---
\* Pointers: variables that store address of another variable.
Basic Forms(for those point to an int variable): 
	int a; (a variable)
	int *p;(make a pointer variable *p that points to a integer)
	p = &a;(p gets the address of variable a, and therefore, *p gets the value of a, which means *p == a)

The difference between p and \*p is that, p is the address and \*p is the value at the address.

## Pointer types, pointer arithmetic, void pointers
The pointers can only point to those variables that match their type.
We can also modify the variable via modify the pointer variable, which called dereferencing.

Why strong types(so we need to use specific type of variable to store specific type of data)? Why not some generic type?
The reason that we use pointers is that, we use deferencing to modify the values(which means, we don't need to modify the original variable, which is very convenient, we'll talk about this later).

When you're using typecasting, you should pay attention to the memory that the variable use, for example, if the int variable have a value of 1025, if you typecast this varable to char, the value becomes 1.

Pointers can be use to plus and minus with integer and minus with a pointer, but two pointers cannot be used to plus each other.

## Pointers to Pointers in C/C++

The memory that pointers use is as large as the type that the variable claimed(pointed to).
\* If the pointer points another pointer, we use \*\*

## Pointers as function arguments - call by reference
When using methods and calling variables, users have to notice that the variable may be local variable, therefore the method (except main method) modify the argument do not modify the local variable in main method.

Application's memory is divided into: 
+ Heap: Heap is fixed, decided when the app start. And it is Free store.
+ Stack: Store the stack frame of the functions, also stored their local variables. Also decided when app start.
+ Static/Global:Global variable can be accessed and modify in entire app. Global variable is also fixed and decided when app start.
+ Code: Text.
\*main function is a calling function, another function is called function.

Here's the example for how we can we use pointers when writing a program:
We sometimes write code in this way:

```c
#include<stdio.h>
void Increment(int a)
{
    a = +1;
}
int main()
{
    int a;
    a = 10;
    Increment(a);
    printf("a = %d",a);//and the output will be 10
```

Since we know that the a in Increment method and the a in main method are not the same one, so we write this sometimes: 

```c
#include<stdio.h>
int Increment(int a)
{
    a = a + 1;
}
int main()
{
    int a = 10;
    a = Increment(a);
    printf("a = %d", a);//and therefore the result will be 11;
}
```

By using Pointers, we can write this app in a clear way:

```c
#include<stdio.h>
void Increment(int *p) //using *p as reference, we can now edit the int a.
{
    *p = (*p) + 1;
}
int main()
{
    int a;
    a = 10;
    Increment(&a);//because the calling argument is &a, the called argument is the a that we set in the main function
    printf("a = %d", a);//and the output is 11 now.
}
```

## Pointers and arrays
The address of the data in arrays are continuous.
Therefore, the way we write code in the previous section can also use in the situation when we write methods calling array and the item in arrays.
Thing that we should keep in mind, if the object using more than one byte, this address of the object is the first one.
That means, if the first byte that the address in type int use has the address 200, the array[1] has the address 204, and you can call it by calling \*(A+1).

## Arrays as function arguments
When array is a function argument, the compiler doesn't duplicate a brand-new array for the calling function, what the compiler does is copy the address of the array, so the size of the array will change into the size of the pointer instead of the array.
\* Since the array is called by the reference, so we can modify the array by using the calling function.

## Character arrays and pointers - part1
\* Strings: a group of characters.
+ How we store strings? The 'large enough ' array to store a string is larger than the number of characters in string +1. 
\*Rule: string in C need an extra byte to store a null character '\0' (if you want to store it in an array). 
+ Arrays and pointers are different ;types that are used in similar manner.
\* We can use the pointer with same type of the array it points to to edit the array.
+ Arrays are always passed to function by reference.

## Character arrays and pointers - part2
In this section, the lecturer explained the example in detail, if you want to take a look of it, please refer to the original video.

## Pointers and multi-dimensional arrays
**Important**
\*(A+i) is same as  A\[i]; (A+i) is same as &A\[i]
```c++
int A[3] //it means that in array A, there are three data stored in type 'int'.
int B[2][3] //it means that in array B, there are two arrays each contains three int data.
```
The things below refers to a same thing:
B\[i]\[j] = \*(B\[i]+j) = \*(\*(B+i)+j)
The most important thing in this section is that, the sense  of using pointers to present the element in multi-dimensional arrays.

## Pointers and dynamic memory - stack v.s. heap
The memory can divided into four segments:
+ Heap: Free store.
+ Stack: Methods and their arguments are store in this segment.
+ Static/Global: global variables, you must know what I mean.
+ Code\(text\).

The memory use is dynamic when an application executing. After the application finished, data in memory will clear.
However, if the app exhaust the memory \(beyond the limit\), ''stackoverflow'' will occur.
Heap is called dynamic memory. 

To use dynamic memory in C, we need the malloc calloc realloc and free function.
On the other hand, in C++, we need new and delete.

In C:
  If we want to allocate and reserve the space on Heap, we need malloc function.And the address of the data stored on Heap, will store in Stack.
  If the data is no longer necessary\(so we don't need to keep it\), we can use free function to remove it from Heap.

In C++:
  If we want to store the data in Heap, we use \"new\".
  If we want to remove a data from Heap, we use \"delete\".

## Dynamic memory allocation in C - malloc calloc realloc free

Allocate block of memory:
+ malloc\(most frequently used\): 
  datatype \*var = \(datatype\*\)malloc\(numbersOfElements\*sizeof\(datatype)),
  malloc give the first address of the byte of the block.
+ calloc:
  datatype\*var = \(datatype\*\)calloc\(numberOfElements, sizeof(\datatype\)\)

The difference between malloc and calloc is that, malloc leaves the memory uninitialized but malloc initialize the memory to read as 0.[stackoverflow](https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc)
+ realoc(change the size of memory):
  datatype\*var = \(datatype\*\)realloc\(exsisted data\(or NULL\),numbersOfElements\*sizeof\(datatype\)\)

Deallocate block of memory:
+ free:
  free(starting address);
  The free function can remove the dynamic memory. 

## Pointers as function returns in C
```c
#include<stdio.h>
#include<stdlib.h>
int Add(int a, int b){
    int c = a+b;
    return c;
}
int main(){
    int a = 2, b = 4;
    printf("Address of a in main = %d\n", &a);
    int c = Add(&a, &b);
    printf("Sum = %d\n", c);
```
If we write code like the stuff above, there might be a problem...

We can, of course, use pointer s as calling arguments. However, when it comes to calling the return item many times, use the pointers that return from another function, it might be a problem.
The reason is that, data in Stack change consistantly and the unnecessary data may be cleared instantly, so the value at the address you pointed to might be cleared or overwritten after your return.
However, we can still use pointers as arguments and return item as far as we store it in global variable or in Heap. \(by using malloc function\)

## Function Pointers in C
Pointers ,as far as we know, can store the address of data\(point to data\), however, it can point to functions too.
What would be the address of a function?
The code, that we written, is also a part of memory, so the function we write, without a doubt, has their own address.
When creating the function pointer, must be attention toward the argument and the return argument that the function you want to point to have, the type and number of arguments should be the same.

## Function pointers and callbacks
The function pointers and callbacks example:
```c++
#include<stdio.h>
void A(){
    printf("Hello");
}
void B(void (*ptr)()){ //function pointer as argument
    ptr(); //call-back function that "ptr" points to
}
int main(){
    void (*p)() = A;
    B(p); //So, A is callback function
}
```

## Memory Leak in C
This section, we're going to discuss the situation of improper use of dynamic memory\(Heap\).
If we store data in Heap, the RAM consuming increase during the application executing.
\* In C or C++, the garbage(unnecessary data) in Heap won't clean automatically, but in Java will.
On the other hand, we don't need to worry about this is we store data in Stack because the data in stack will deallocate automatically.
Therefore, remember the use of free function, or the consumption of dynamic memory will keep rising.
