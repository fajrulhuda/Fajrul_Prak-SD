//Program untuk mengintroduksi konsep pointer
#include <stdio.h>
#include <conio.h>
int main(){
	int usia1=50;
	int usia2=18;
	
	int *ptr;
	ptr=&usia1;
	
	printf("Usia saya (usia1): %d\n", usia1);
	printf("Usia saya (*ptr)", *ptr);
	printf("(&usia1) %x (ptr) %x", &usia1, ptr);
	ptr=&usia2;
	
	printf("\nUsia Anda (*ptr): %d", *ptr);
	printf("\n(&usia2) %x (ptr) %x", &usia2, ptr);
	printf("\n(&ptr) %x", &ptr);
	getch();
}