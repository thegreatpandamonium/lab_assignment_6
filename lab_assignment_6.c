#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	// Terminating Condition
	if (high < low ){
		return -1;
	}
	
	// Find midpoint
	int med = (low+high)/2;

	// Check if midpoint equals value
	if(numbers[med] == value){
		return med;
	}

	// Else check if value is greater than midpoint
	else if(numbers[med]>value){
		return search(numbers, low, med-1,value); // calling search again but now the upper limit is midpoint-1
	}

	else{
		return search(numbers, med+1, high, value); // calling seach again but now the lower limit is midpoint+1
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}