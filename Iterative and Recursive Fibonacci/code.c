#include <stdio.h>
#include <stdlib.h>

int ifib(int);
int rfib(int);

// Main to call fib function and output iterative and recursive results
int main(int argc, char *args[]) {

	int n = atoi(args[1]);
	printf("Fibonacci = Iterative Algorithm\n");
	printf("ifib(%d) = %d\n", n, ifib(n));

	printf("Fibonacci = Recursive Algorithm\n");
	printf("rfib(%d) = %d\n", n, rfib(n));

	printf("Done\n");
	return 0;
}

// The iterative algorithm
int ifib(int n) {

	if (n <= 0) {
		return 0;

	} else if (n <= 2) {
		return 1;

	} else {
		int a = 1; // first Fibonacci value
		int b = 1; // second Fibonacci value
		int index = 0; // index

		for (index = 1; index < n / 2; index++) {
			a += b;
			b += a;
		}
		if (n % 2 == 0) {
			// return Fibonacci value
			return b;
		} else {
			// update and return second Fib value
			return a + b;

		}
	}
}

//The recursive algorithm
int rfib(int n) {

	// setting the base case
	if (n <= 0) {
		return 0;

	} else if (n <= 2) {
		return 1;

		//Run general case where the current value is the sum of 2 previous values
	} else {

		return rfib(n - 1) + rfib(n - 2);
	}
}
