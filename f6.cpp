/*
* Filename: f6.cpp
* Project: Focused Assignment 6
* By: Jongeon Lee
* Date: Mar 17, 2023
* Description: Write a program to give you practice at using pointer variables to modify parameters.
*/


#include <stdio.h>

#define kNumArray 7
#define kCalAverage 4.0
#define kFillValue 40.0

int getDouble(double *pNumber);
void calculateStats(double d1, double d2, double d3, double d4, double *pAverage, double *pSum);
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage);
void fillArray(double values[], int numArray, double fillValue);

int main()
{
	double data1 = 0.0;
	double data2 = 0.0;
	double data3 = 0.0;
	double data4 = 0.0;
	
	printf("Enter a floating point number: ");
	if (getDouble(&data1) != 1)
	{
		return 0;
	}
	printf("Enter another floating point number: ");
	if (getDouble(&data2) != 1)
	{
		return 0;
	}
	printf("Enter another floating point number: ");
	if (getDouble(&data3) != 1)
	{
		return 0;
	}
	printf("Enter another floating point number: ");
	if (getDouble(&data4) != 1)
	{
		return 0;
	}

	double average = 0.0;
	double sum = 0.0;

 	calculateStats(data1, data2, data3, data4, &average, &sum);
	printf("The average and sum of the variables: %lf  %lf \n", average, sum);

	double array[kNumArray] = { 0 };
	double sumArray = 0.0;
	double aveArray = 0.0;

	for (int i = 0; i < kNumArray; i++)
	{
		printf("Enter a number: ");
		if (getDouble(&array[i]) != 1)
		{
			return 0;
		}
	}
	
	calculateArrayStats(array, kNumArray, &sumArray, &aveArray);
	printf("The average and sum of the array elements: %lf  %lf \n", aveArray, sumArray);

	fillArray(array, kNumArray, kFillValue);
	for (int i = 0; i < kNumArray; i++)
	{
		if ( i < kNumArray-1)
		{
			printf("%lf, ", array[i]);
		}
		else
		{
			printf("%lf", array[i]);
		}
	}
	return 0;
}



/*
* Function: getDouble(double *pNumber)
* Description: This function gets a floating-point number from the user.
*              If the user enters a valid floating-point number, the value is 
*	   		   put into the variable pointed to by the parameter and 1 is returned. 
*			   If the user-entered value is not valid, 0 is returned.
* Parameters: double *pNumber: pointer to a variable that is filled in by the user input, if valid.
* Returns: int: 1 if the user entered a valid floatingpoint number, 0 otherwise
*/
#pragma warning(disable: 4996) 
int getDouble(double *pNumber)
{
	char record[121] = { 0 };
	double value = 0.0;
	int valid = 0;
	fgets(record, 121, stdin);
	if (sscanf(record, "%lf", &value) != 1)
	{
		valid = 0;
	}
	else
	{
		*pNumber = value;
		valid = 1;
	}
	return valid;
}



/*
* Function: calculateStats(double d1, double d2, double d3, double d4, double *pAverage, double *pSum)
* Description: This function takes four floating-point numbers passed as doubles and 
*             calculates the average and sum of the numbers. Once calculated, the average
*			  gets put into the variable pointed to by the pAverage parameter and the sum 
*			  gets put into the variable pointed to by the pSum parameter.
* Parameters: double d1, d2, d3, d4: four floating-point numbers.
*             double *pAverage: pointer to a variable that is filled in by this function
*                               with the average of d1, d2,d3, and d4.
*             double *pSum: pointer to a variable that is filled in by this function with
*                            the sum of d1, d2, d3, and d4.
* Returns: none.
*/
void calculateStats(double d1, double d2, double d3, double d4, double *pAverage, double *pSum)
{
	*pSum = d1 + d2 + d3 + d4;
	*pAverage = *pSum / kCalAverage;
}



/*
* Function: calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage)
* Description: This function takes an array of floating-point (double) numbers, given 
*              the number of elements in the array as a parameter, and calculates the average and
*			   sum of the numbers. Once calculated, the average gets put into the variable pointed
*			   to by the pAverage parameter and the sum gets put into the variable pointed to by the pSum parameter.
* Parameters:  double values[]: floating-point numbers.
*              int numArray: number of array elements.
*              double *pSum: pointer to a variable that is filled in by this function
* 		                     with the sum of all elements in the array.
*              double *pAverage: pointer to a variable that is filled in by this function
*			                     with the average of all elements in the array.
* Returns: none.
*/
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage)
{
	*pSum = 0.0;
	for (int i=0; i<numArray; i++)
	{
		*pSum += values[i];
	}
	*pAverage = *pSum / numArray;
}



/*
* Function: fillArray(double values[], int numArray, double fillValue)
* Description: This function takes an array of floating-point (double) numbers,
*              given the number of elements in the array as a parameter, and puts
*			   the fillValue into each element of the array.
* Parameters:  double values[]: floating-point numbers
*              int numArray: number of array elements
*              double fillValue: value to put into array elements
* Returns: none.
*/
void fillArray(double values[], int numArray, double fillValue)
{
	for (int i = 0; i < numArray; i++)
	{
		values[i] = fillValue;
	}
}