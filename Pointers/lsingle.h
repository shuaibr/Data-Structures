/*
 * lsingle.h
 *
 *  Created on: Feb 8, 2017
 *      Author: Shuaib
 */

#ifndef LSINGLE_H_
#define LSINGLE_H_

#define MAX_LINE 40
#include <stdio.h>
#include <stdlib.h>

struct node {
	float score;
	struct node *next;
	char name[MAX_LINE];

};

char letter_grade(float);
int delete(struct node**, char*);
void insert(struct node**, char*, float);
void data_import(struct node**, char*);
void clean(struct node*);
void display(struct node*);
void data_report(struct node**, char*);

#endif /* LSINGLE_H_ */
