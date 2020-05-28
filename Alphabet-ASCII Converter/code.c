#include <stdio.h>

int main(void) {

	// the following two lines are for Eclipse console un-buffered output
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char c = 0;

	do {
		printf("Please enter a character\n");
		c = getchar();

		do {
			if (getchar() == '\n')
				break;

		} while (1);

		if (c >= 'a' && c <= 'z') {
			printf("%c %d %c\n", c, c, c - 32);

		}
		else if (c >= 'A' && c <= 'Z') {
			printf("%c %d %c\n", c, c, c + 32);
		}

	} while (c != '*');

	printf("Good bye\n");
	return 0;
}
