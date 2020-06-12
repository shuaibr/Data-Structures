/*
 ============================================================================
 Name        : reey6640_a05q2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lsingle.h"

int main(int argc, char *args[]) {

	struct node *start = NULL;
	data_import(&start, args[1]);

	printf("Before: \n\n");
	data_report(&start, args[2]);

	insert(&start, "Moore", 92);
	delete(&start, "Wang");

	printf("After: \n");
	data_report(&start, args[2]);
	clean(start);
	return 0;
}
