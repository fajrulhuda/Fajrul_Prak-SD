#include<stdio.h>
#include<stdlib.h>

typedef struct employee_st {
    char name[40];
    int id;
} Employee;

int main() {
    int myInt;
    Employee john;
    
    printf("Size of int is %zu\n", sizeof(myInt));
    printf("Size of Employee is %zu\n", sizeof(Employee));
    printf("Size of john is %zu\n", sizeof(john));
    printf("Size of char is %zu\n", sizeof(char));
    printf("Size of short is %zu\n", sizeof(short));
    printf("Size of int is %zu\n", sizeof(int));
    printf("Size of long is %zu\n", sizeof(long));
    printf("Size of float is %zu\n", sizeof(float));
    printf("Size of double is %zu\n", sizeof(double));

    return 0;
}
