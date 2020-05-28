#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {

	int x = atoi(args[1]);
	int n = argc - 2;
	int a[n];
	int i = 0; //index

	for (i = 0; i < n; i++) {
		a[i] = atoi(args[i + 2]);
		// printf("i: %d  val: %d\n", i, atoi(args[i + 2]));
	}

	printf("The value of the polynomial when x = %d is %d\n", x,
			evaluate_polynomial(a, n, x));
	return 0;
}

//Horner's algorithm to evaluate polynomial
int evaluate_polynomial(int a[], int n, int x) {
	int value = a[0];
	int i;

	for (i = 1; i<n; i++)
		value = value * x + a[i];

	return value;
}
