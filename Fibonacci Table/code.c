#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// the following two lines are for Eclipse console un-buffered output
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n, i, total, next = 1, prev = 0, a = 1;

	printf("Enter a value between 1 and 40 \n");
	scanf("%d", &n);

	printf("a1q2 %d\n", n);

	if (n < 1 || n > 40) {
		printf("Please enter a value in the Range!");

	} else {
		for (i = 1; i < n + 1; i++) {

			if (i <= 1) {
				total = i;

			} else {

				total = prev + next;
				prev = next;
				next = total;

			}

			printf("\t%12d", total);
			a++;
			if (a == 5) {
				printf("\n");
				a = 1;
			}
		}
	}
	printf("\nGoodbye\n");
	return 0;
}
