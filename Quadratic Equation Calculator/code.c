#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

double a;
double b;
double c;

double hold1;
double rootpos;
double rootneg;

int main(void) {

	// the following two lines are for Eclipse console un-buffered output
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter The Coefficient a: ");
	scanf("%lf", &a);

	printf("Enter The Coefficient b: ");
	scanf("%lf", &b);

	printf("Enter The Coefficient c: ");
	scanf("%lf", &c);

	if (a == 0) {

		printf("Invalid quadratic equation!\n");

	} else {
		hold1 = (pow(b, 2)) - (4 * (a * c));
		rootpos = ((-1 * b) + (pow(hold1, 0.5))) / (2 * a);
		rootneg = ((-1 * b) - (pow(hold1, 0.5))) / (2 * a);

	}
	if (hold1 < 0) {
		printf("The equation has complex roots\n");
		printf("%.0f.0000 + %.0f.000\n", rootpos, rootpos);
		printf("%.0f.0000 - %.0f.000", rootneg, rootneg);

	} else if (rootpos == rootneg) {
		printf("The equation has two equal roots: %.4f", rootpos);

	} else {
		printf("THe equation has distinct real roots: %.4f and %.4f", rootpos,
				rootneg);
	}

}

