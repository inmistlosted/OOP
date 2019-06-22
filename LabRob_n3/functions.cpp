
#include "functions.h"

//multiplyes matrix on scalar
void Scalar_multiplication(MatrixXd m, double s)
{
    cout << "SCALAR MULTIPLICATION" << endl;
    cout << "Result-Matrix: " << endl << m * s << endl;
}

//divides matrix on scalar
void Scalar_division(MatrixXd m, double s)
{
    cout << "SCALAR DIVISION" << endl;
    cout << "Result-Matrix: " << endl << m / s << endl;
}

//multiplyes matrix on vector
void Vector_multiplication(MatrixXd m, VectorXd v)
{
    cout << endl << "VECTOR MULTIPLICATION" << endl;
    cout << "Result-Matrix: " << endl << m * v << endl;
}

//multiplyes matrix on itself
void Squared_Matrix(MatrixXd m)
{
    cout << "SQUARED MATRIX" << endl;
    cout << "Result-Matrix: " << endl << m * m << endl;
}

//sums all elements of matrix
void Sum_elements(MatrixXd m)
{
    cout << "SUM OF ALL ELEMENTS" << endl;
    cout << "Sum of all elements = " << m.sum() << endl;
}

//multiplyes all elements of matrix
void Product_elements(MatrixXd m)
{
    cout << "PRODUCT OF ALL ELEMENTS" << endl;
    cout << "Product of all elements = " << m.prod() << endl;
}

//shows average value of elements of matrix
void Average(MatrixXd m)
{
    cout << "AVERAGE VALUE OF ALL ELEMENTS" << endl;
    cout << "Average value of all elements = " << m.mean() << endl;
}

//shows minimal element of matrix
void MinElement(MatrixXd m)
{
    cout << "MINIMAL ELEMENT" << endl;
    ptrdiff_t i,j;
    double min1 = m.minCoeff(&i,&j);
    cout << "Minimal element = " << min1 << "  " << "it's position (" << i << ", " << j << ")" << endl;
}

//shows maximal element of matrix
void MaxElement(MatrixXd m)
{
    cout << "MAXIMAL ELEMENT" << endl;
    ptrdiff_t i,j;
    double max1 = m.maxCoeff(&i,&j);
    cout << "Maximal element = " << max1 << "  " << "it's position (" << i << ", " << j << ")" << endl;
}

//sums two matrixes
void Sum_Matrix(MatrixXd m, MatrixXd n)
{
    cout << "SUM" << endl;
    cout << "Result-Matrix: " << endl << m + n << endl;
}

//divides two matrixes
void Subtraction_Matrix(MatrixXd m, MatrixXd n)
{
    cout << "SUBTRACTION" << endl;
    cout << "Result-Matrix: " << endl << m - n << endl;
}

//multiplyes two matrixes
void Multiply_Matrix(MatrixXd m, MatrixXd n)
{
    cout << "MULTIPLICATION" << endl;
    cout << "Result-Matrix: " << endl << m * n << endl;
}