//Program to add two distances (feet-in)
#include <stdio.h>

struct Distance {
	int feet;
	float inch;
} dist1, dist2, sum;

int main(){
	printf("1st distance\n");
	printf("Enter feet: ");
	scanf("%d", &dist1.feet);
	printf("Enter inch: ");
	scanf("%f", &dist1.inch);
	printf("2nd Distance\n");
	printf("Enter feet: ");
	scanf("%d", &dist2.feet);
	printf("Enter inch: ");
	scanf("%f", &dist2.inch);
	//adding feet
	sum.feet=dist1.feet+dist2.feet;
	sum.inch=dist1.inch+dist2.inch;
	
	while(sum.inch >= 12){
		++sum.feet;
		sum.inch=sum.inch-12;
	}
	printf("Sum of distance = %d %.1f\n", sum.feet, sum.inch);
	return 0;
}