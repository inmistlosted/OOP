
#ifndef LAB_N3_FUNCTIONS_H
#define LAB_N3_FUNCTIONS_H

#include <iostream>
#include <d:/libraries/Eigen/Dense>

using namespace Eigen;
using namespace std;

/**
 * multiplyes matrix on scalar
 *
 * @param m
 * @param s
 */
void Scalar_multiplication(MatrixXd m, double s);

/**
 * divides matrix on scalar
 *
 * @param m
 * @param s
 */
void Scalar_division(MatrixXd m, double s);

/**
 * multiplyes matrix on vector
 *
 * @param m
 * @param v
 */
void Vector_multiplication(MatrixXd m, VectorXd v);

/**
 * multiplyes matrix on itself
 *
 * @param m
 */
void Squared_Matrix(MatrixXd m);

/**
 * sums all elements of matrix
 *
 * @param m
 */
void Sum_elements(MatrixXd m);

/**
 * multiplyes all elements of matrix
 *
 * @param m
 */
void Product_elements(MatrixXd m);

/**
 * shows average value of elements of matrix
 *
 * @param m
 */
void Average(MatrixXd m);

/**
 * shows minimal element of matrix
 *
 * @param m
 */
void MinElement(MatrixXd m);

/**
 * shows maximal element of matrix
 *
 * @param m
 */
void MaxElement(MatrixXd m);

/**
 * sums two matrixes
 *
 * @param m
 * @param n
 */
void Sum_Matrix(MatrixXd m, MatrixXd n);

/**
 * divides two matrixes
 *
 * @param m
 * @param n
 */
void Subtraction_Matrix(MatrixXd m, MatrixXd n);

/**
 * multiplyes two matrixes
 *
 * @param m
 * @param n
 */
void Multiply_Matrix(MatrixXd m, MatrixXd n);

#endif //LAB_N3_FUNCTIONS_H
