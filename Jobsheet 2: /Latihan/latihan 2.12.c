#include <stdio.h>

struct complex{
	int imag;
	float real;
};

struct number {
	struct complex comp;
	int integers;
}num1, num2;

//Buatlah nested struct sampai dengan 5 tingkat
struct level5 {
    int data;
};

struct level4 {
    struct level5 l5;
};

struct level3 {
    struct level4 l4;
};

struct level2 {
    struct level3 l3;
};

struct level1 {
    struct level2 l2;
};

int main() {
    // Create an instance of the nested struct
    struct level1 nested_struct;

    // Assigning values
    nested_struct.l2.l3.l4.l5.data = 10;

    // Accessing values
    printf("Data: %d\n", nested_struct.l2.l3.l4.l5.data);

    return 0;
}