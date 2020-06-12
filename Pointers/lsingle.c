/*
 * lsingle.c
 *
 *  Created on: Feb 8, 2017
 *      Author: Shuaib
 */


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // uncomment for Sleep(ms)
#include "lsingle.h"
#include <math.h>

#define MAX_LINE 100
char comma[] = ",\0";


char letter_grade(float score) {

	if (score >= 85 && score <= 100) {
		return 'A';
	} else if (score >= 70 && score < 85) {
		return 'B';
	} else if (score >= 60 && score < 70) {
		return 'C';
	} else if (score >= 50 && score < 60) {
		return 'D';
	}
	return 'F';
}

int delete(struct node **start, char *name) {

	struct node *current = *start;
	struct node *prev = NULL;

	while (current != NULL && strcmp(current->name, name) != 0) {

		prev = current;
		current = current->next;

	}

	if (current == NULL)
		return 0;

	else {
		if (prev == NULL)
			*start = current->next;
		else
			prev->next = current->next;

		free(current);
		return 1;
	}
}
void insert(struct node **start, char *name, float score) {

	struct node *current = *start;
	struct node *prev = NULL;

	while (current != NULL && strcmp(current->name, name) < 0) {

		prev = current;
		current = current->next;
	}

	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	strcpy(newNode->name, name);

	newNode->score = score;
	newNode->next = current;

	if (prev == NULL)
		*start = newNode;
	else
		prev->next = newNode;
}

void data_import(struct node **start, char *infilename) {

	char line[MAX_LINE];
	char delimiters[] = ",";
	FILE *fi;

	fi = fopen(infilename, "r");

	while (fgets(line, MAX_LINE, fi) != NULL) {

		char *name = strtok(line, delimiters);
		float mark = atof(strtok(NULL, delimiters));
		insert(start, name, mark);
	}

	fclose(fi);
}

void clean(struct node *start) {

	struct node* temp;

	while (start != NULL) {
		temp = start;
		start = start->next;
		free(temp);

	}
}

void display(struct node *start) {

	while (start != NULL) {

		printf("%s %.1f\n", start->name, start->score);
		start = start->next;

	}
}

void data_report(struct node **start, char *output_f) {

	float total = 0, stdev = 0, mean;
	int n = 0;
	FILE *fo;
	struct node *current;

	current = *start;
	while (current != NULL) {
		n += 1;
		total += current->score;
		current = current->next;
	}
	mean = total / n;

	current = *start;
	while (current != NULL) {
		float d = current->score - mean;
		stdev += d * d;
		current = current->next;
	}
	stdev = sqrt(stdev / n);

	fo = fopen(output_f, "w");

	printf("Letter Grade\n");
	fprintf(fo, "Letter Grade\n");

	current = *start;
	while (current != NULL) {
		char ltr = letter_grade(current->score);
		printf("%-20s %4c\n", current->name, ltr);
		fprintf(fo, "%-20s %4c\n", current->name, ltr);
		current = current->next;
	}
	printf("\n");
	fprintf(fo, "\n");

	printf("Summary\n");
	fprintf(fo, "Summary\n");

	printf("%-20s %4d\n", "Record count", n);
	fprintf(fo, "%-20s %4d\n", "Record count", n);

	printf("%-20s %3.1f\n", "Average", mean);
	fprintf(fo, "%-20s %3.1f\n", "Average", mean);

	printf("%-20s %3.1f\n", "Standard deviation", stdev);
	fprintf(fo, "%-20s %3.1f\n", "Standard deviation", stdev);
	fclose(fo);
}
