/*
 * MatrixCalculator.c
 *
 *  Created on: Oct 28, 2017
 *  Author: Ivan Antunovic
 */

#include "MatrixCalculator.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

static int max(int, int);
static int loadMatrixWithRandNum(int**);
static int sumColumnElements(int** matrix_a, int columnIndex, int columnSize);

MatrixCalculator_t* new_MatrixCalculator(void)
{
	MatrixCalculator_t* matrixCalculator = NULL;

	matrixCalculator = (MatrixCalculator_t*) malloc ( sizeof( MatrixCalculator_t ) );
	if ( matrixCalculator == NULL )
	{
		return NULL;
	}

	matrixCalculator->calculate = MatrixCalculator_Calculate;

	srand(time(NULL));

	return matrixCalculator;
}

void delete_MatrixCalculator(MatrixCalculator_t* const matrixCalculatorObj)
{
	if ( matrixCalculatorObj != NULL )
	{
		free ( matrixCalculatorObj );
	}
}

int MatrixCalculator_Calculate(MatrixCalculator_t* matrixCalculator, int** matrix_a, int** matrix_b, int* outputMatrix)
{
	int *tempMatrix[MATRIX_MAX_SIZE];

	// Check input parameters
	if ( matrixCalculator == NULL ||
		 matrix_a == NULL || *matrix_a == NULL ||
		 matrix_b == NULL || *matrix_b == NULL ||
		 outputMatrix == NULL )
	{
		return -1;
	}


	for ( int i = 0; i < MATRIX_MAX_SIZE; ++i)
	{
		tempMatrix[i] = (int*) malloc (MATRIX_MAX_SIZE * sizeof(int) );
	}

	loadMatrixWithRandNum(matrix_a);
	loadMatrixWithRandNum(matrix_b);

	for ( int i = 0; i < MATRIX_MAX_SIZE; ++i )
	{
		for ( int j = 0; j < MATRIX_MAX_SIZE; ++j )
		{
			tempMatrix[i][j] = max ( matrix_a[i][j] , matrix_b[i][j] );
		}
	}

	for ( int column = 0; column < MATRIX_MAX_SIZE; ++column )
	{
		outputMatrix[column] = sumColumnElements(tempMatrix, column, MATRIX_MAX_SIZE);
	}

	// Deallocate 2-d array
	for ( int i = 0; i < MATRIX_MAX_SIZE; ++i )
	{
		free ( tempMatrix[i] );
	}


	return 0;
}

int loadMatrixWithRandNum(int** matrix)
{
	if ( matrix == NULL )
	{
		return -1;
	}

	if ( *matrix == NULL )
	{
		return -1;
	}

	for ( int i = 0; i < MATRIX_MAX_SIZE; ++i )
	{
		for ( int j = 0; j < MATRIX_MAX_SIZE; ++j )
		{
			matrix[i][j] = rand() % RANDOM_NUMBER_FACTOR;
		}

	}

	return 0;
}

int max(int numOne, int numTwo)
{
	if ( numOne > numTwo )
	{
		return numOne;
	}

	return numTwo;
}

int sumColumnElements(int** inputMatrix, int columnIndex, int columnSize)
{
	int columnSum = 0;

	if ( inputMatrix == NULL || *inputMatrix == NULL )
	{
		return -1;
	}

	if ( columnIndex > columnSize )
	{
		return -1;
	}


	for ( int row = 0; row < columnSize; ++row )
	{
		columnSum += inputMatrix[row][columnIndex];
	}

	return columnSum;
}








