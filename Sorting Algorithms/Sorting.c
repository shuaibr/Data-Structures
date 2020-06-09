#include <stdio.h>

void print_array(int *a, int n);
void array_copy(int *, int *, int);
void selection_sort(int *, int);
void quick_sort(int *, int, int);
void swap(int*, int*);

int main(int argc, char *args[]) {
	int n = argc - 1; // number of elements in array to sort
	int a[n]; // original array
	int b[n]; // copy array to sort
	int i = 0;

	//Fill array to sort with from parameters
	for (i = 0; i < n; i++) {
		a[i] = atoi(args[i + 1]);
	}

	printf("Array: ");
	print_array(a, n);
	printf("\n");

	array_copy(a, b, n);
	//sort b

	return 0;
}

void print_array(int *a, int n) {
	int j = 0;
	for (j = 0; j < n; ++j) {
		if (j % 10 == 0)
			printf("\n");
		printf("%d ", *(a + j));
	}
}

void array_copy(int *a, int *b, int n) {
	int i = 0;
	for (i = 0; i < n + 1; i++) {
		*b[i] = *a[i];
	}
}

void selection_sort(int *list, int n) {
// implementation
}

// this is optional, in case of need in selection sort
int find_min(int *list, int fill, int n) {
// implementation
}

void quick_sort(int *list, int m, int n) {
// implementation
}

void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;



}
