/*
 * MatrixCalculator.h
 *
 *  Created on: Oct 28, 2017
 *      Author: root
 */

#ifndef SRC_MATRIXCALCULATOR_H_
#define SRC_MATRIXCALCULATOR_H_

#define MATRIX_MAX_SIZE 5
#define RANDOM_NUMBER_FACTOR 10

typedef struct MatrixCalculator MatrixCalculator_t;

// declaration of pointers to functions
typedef int (*funcPtrCalculate_t)(MatrixCalculator_t*, int**, int**, int*);


typedef struct MatrixCalculator
{
	funcPtrCalculate_t calculate;

} MatrixCalculator_t;

MatrixCalculator_t* new_MatrixCalculator(void);
void delete_MatrixCalculator(MatrixCalculator_t* const matrixCalculatorObj);
int MatrixCalculator_Calculate(MatrixCalculator_t* matrixCalculator, int** matrix_a, int** matrix_b, int* outputMatrix);



#endif /* SRC_MATRIXCALCULATOR_H_ */
