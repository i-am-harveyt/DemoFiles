# Pointers Note

## Working with pointers
\* Computers Memory -> RAM
The basic constitution of memory is 1 byte memory. The momory address have a incresing relation. 

Datatypes and how much memory they'll use(to store the value):
+ int - 4 bytes
+ char - 1 byte
+ float - 4 bytes

---

\* Pointers: variables that store address of another variable.
Basic Forms(for those point to an int variable): 
	int a;(a variable)
	int *p;(make a pointer variable *p that points to a integer)
	p = &a;(p gets the address of variavble a, and therefore, *p gets the value of a, which means *p == a)

The difference between p and *p is that, p is the address and *p is the value at the address.

## Pointer types, pointer arithmetic, void pointers
The pointers can only point to those variables that match their type.
We can also modify the variable via modify the pointer variable, which called dereferencing.

Why strong types(so we need to use specific type of variable to store specific type of data)? Why not some generic type?
The reason that we use pointers is that, we use deferendies to modify the values conveniently(so that, we don't need to modify the original variable).

When you're using typecasting, you should pay attention to the memory that the variable use, for example, if the int variable have a value of 1025, if you typecast this varable to char, the value becomes 1.

## Pointers to Pointers in C/C++

The memory that pointers use is as large as the type that the memory claimed(pointed to).
\* If the pointer points another pointer, we use \*\*

## Pointers as function auguments - call by reference
When using methods and calling variables, users have to notice that the variable may be local variable, therefore the method (except main method) modify the argument do not modify the local variable in main method.

Application's memory is divided into: 
+ Heap: Heap is fixed, decided when the app start. 
+ Stack: Store the stack frame of the functions, also stored their local variables. Also decided when app start.
+ Static/Global:Global variable can be accessed and modify in entire app. Global variable is also fixed and decided when app start.
+ Code: Text.
*main function is a calling function, another function is called function.




## Pointers and arrays

## Arrays as function arguments

## Character arrays and pointers - part1

## Character arrays and pointers - part2

## Pointers and 2D arrays

## Pointers and dynamic memory - stack v.s. heap

## Dynamic memory allocation in C - malloc calloc realloc free

## Pointers as function returns in C/C++

## Function Pointers in C/C++

## Function pointers and callbacks

## Memory Leak in C/C++


