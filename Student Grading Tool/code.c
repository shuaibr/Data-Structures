
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_REC 100
#define MAX_LINE 100

//define record structure
typedef struct {

	char name[100];
	float mark;

} record;

char letter_grade(float);
int data_import(record dataset[], char*);
void data_report(record dataset[], int, char*);

//---------------------------------------------------------
int main(int argc, char *args[]) {

	record dataset[MAX_REC];
	int record_count = 0;

	record_count = data_import(dataset, args[1]);
	data_report(dataset, record_count, args[2]);

	return 0;
}

//grade conversion from float to number
char letter_grade(float score) {
	if (score <= 100) {
		if (score >= 85) {
			return 'A';
		} else if (score >= 70) {
			return 'B';
		} else if (score >= 60) {
			return 'C';
		} else if (score >= 50) {
			return 'D';
		} else {
			return 'F';
		}
	}
}

int data_import(record dataset[], char *filename) {

	char line[MAX_LINE];
	char *result;
	char delimiters[] = ","; //for comma delimited lines
	int i = 0;

	//open input file
	FILE *fi;
	fi = fopen(filename, "r");

	if (fi == NULL) {
		printf("Error reading file");
		return 0;
	}

	//read line and copy ctring
	while (fgets(line, sizeof(line), fi) != NULL) {

		result = strtok(line, delimiters);
		strncpy(dataset[i].name, result, sizeof(dataset[i].name));
		result = strtok(NULL, delimiters);
		dataset[i].mark = atof(result);
		i++;
	}

	//file close
	fclose(fi);
	return i;
}

void data_report(record dataset[], int n, char *filename) {

	//initializations
	int i;
	int temp = 0;
	float sum;
	float mean;
	float stdev;

	//sum of the scores
	for (i = 0; i < n; i++) {
		sum += dataset[i].mark;
		temp++;
	}

	//mean calculation
	mean = sum / n;

	// use mean to compute the standard deviation
	for (i = 0; i < n; i++) {

		stdev = stdev + pow(dataset[i].mark - mean, 2);
	}

	//calculate standard deviation
	stdev = sqrt(stdev / n);

	//print on
	//screen use
	//format


	//output to file
	FILE *fo;
	fo = fopen(filename, "w");

	if (fo == NULL) {
		printf("Cannot open output file\n");
		exit(1);
	}

	fprintf(fo, "Letter Grade\n");
	printf("Letter Grade\n");

	//print student grades
	for (i = 0; i < n; i++) {

		fprintf(fo, "%-20s%3.1c\n", dataset[i].name,

				letter_grade(dataset[i].mark));

		printf("%-20s%3.1c\n", dataset[i].name, letter_grade(dataset[i].mark));
	}

	//print to console
	printf("\nSummary\n");
	printf("Record count:       %d\n", n);
	printf("Average:            %3.1f\n", mean);
	printf("Standard Deviation: %3.1f\n", stdev);

	//print to file
	fprintf(fo, "\nSummary\t\n");
	fprintf(fo, "Record count:       %d\n", n);
	fprintf(fo, "Average:            %3.1f\n", mean);
	fprintf(fo, "Standard Deviation: %3.1f\n", stdev);
	fclose(fo);
}
