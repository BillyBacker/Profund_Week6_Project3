#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int* A, int* B) {
	int B0 = *A;
	int B1 = *B;
	*A = B1;
	*B = B0;
}

void bubbleSort(int* In) {
	int Buffer[4] = {*In, *In + 1, *In + 2, *In + 3};
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 3; j++) {
			if (In[j] > In[j + 1]) {
				swap(&In[j], &In[j + 1]);
			}
		}
	}
};

int main() {
	int In[4], ans, i = 0, j = 3;
	printf("Enter 4 numbers : ");
	scanf("%d %d %d %d", &In[0], &In[1], &In[2], &In[3]);
	bubbleSort(In);
	printf("Enter number that you want to find : ");
	scanf("%d", &ans);
	while (true) {
		if (i == 3 || j == 0 || i == j) {
			printf("No any pairs of numbers in %d %d %d and %d can added together to get %d", In[0], In[1], In[2], In[3], ans);
			break;
		}
		else if (In[i] + In[j] == ans && !(i == 3 || j == 0 || i == j)) {
			printf("The numbers %d and %d can added up to get %d", In[i], In[j], ans);
			break;
		}
		if (In[i] + In[j] < ans) {
			i++;
		}
		else if (In[i] + In[j] > ans) {
			j--;
		}
	}
	return 0;
}