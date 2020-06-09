#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_LEN 80

//variable used
void lower(char *);
void trim(char*);
void swap(char *a, char *b);

struct word {
	char word[MAX_LEN];
	int freq;
};


int main(int argc, char *args[]) {
	setbuf(stdout, NULL);

	FILE *inputf;
	FILE *outputf;

	char line[MAX_LEN];
	char *result;

	//initialize counts
	int line_c = 0, word_c = 0, new_word_c = 0;
	struct word wordloc[MAX_WORDS];

	char delimiters[] = "!:;,.-_ \n\r\t";

	//open input file
	inputf = fopen(args[1], "r");

	//input file error
	if (inputf == NULL) {

		printf("Cannot open input file\n");
		return 0;
	}

	outputf = fopen(args[2], "w");

	//output file error
	if (outputf == NULL) {

		printf("Cannot open output file\n");
		return 0;
	}

	//read line
	while (fgets(line, MAX_LEN, inputf) != NULL) {

		lower(line);
		trim(line);
		line_c++;
		result = strtok(line, delimiters);


		while (result != NULL) {
			//word count increment
			word_c++;
			int x = 0;
			for (x = 0; x < new_word_c; x++) {

				if ((strcmp(result, wordloc[x].word)) == 0) {
					break;

				}
			}

			if (x < new_word_c) {
				wordloc[x].freq++;

			} else {

				strcpy(wordloc[x].word, result);
				new_word_c++;
				wordloc[x].freq++;

			}

			result = strtok(NULL, delimiters);
		}

	}

	int t = 0;

	//Print line and word counts to console and file
	printf("Line count:            %d\n", line_c);
	printf("Word count:            %d\n", word_c);
	printf("Frequency: \n");
	fprintf(outputf, "Line count:            %d\n", line_c);
	fprintf(outputf, "Word count:            %d\n", word_c);
	fprintf(outputf, "Frequency: ");

	//Print frequencies to console and file
	while (t < new_word_c) {
		fprintf(outputf, "%-15s frequency: %-3d\n", wordloc[t].word,
				wordloc[t].freq);
		printf("%-15s   %-3d\n", wordloc[t].word, wordloc[t].freq);
		t++;

	}
	fclose(inputf);
	fclose(outputf);
	return 0;

}

//Change capital to lower case
void lower(char c[]) {
	int i = 0;
	while (*(c + i) != '\0') {
		if (*(c + i) >= 'A' && *(c + i) <= 'Z') {
			*(c + i) = *(c + i) + 32;
		}
		i++;
	}
}


void trim(char c[]) {
	char *a = c, *b = c, *end = (c + strlen(c) - 1);
	while (*b != '\0') {
		while (*b == ' ') {
			b += 1;
		}
		while ((*b != ' ') && (*b != '\0')) {
			swap(a, b);
			a++;
			b++;

		}
		a++;
	}
	while (*end == ' ' || *end == '\t' || *end == '\n') {
		end -= 1;
	}
	*(end + 1) = '\0';
}

void swap(char *first, char *second) {
	char hold;
	hold = *first;
	*first = *second;
	*second = hold;
}
