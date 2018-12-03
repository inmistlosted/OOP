#include <iostream>
#include <d:/libraries/Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

int main() {
    int n1, m1, n2, m2, operation, quantity, vec_width, ques;
    double p[100][100], v[100];
    double scalar;
    bool q = false;

    cout << "MATRIX CALCULATOR" << endl;

    cout << "Choose: Operations for one matrix( 1 ) | Operations for two matrixes( 2 ): ";
    cin >> quantity;

    if(quantity == 1)
    {
        cout << "Enter matrix " << endl << "Enter height:";
        cin >> m1;
        cout << endl << "Enter width: ";
        cin >> n1;
        if(n1 < 2 || m1 < 2)
        {
            cout << "ERROR!  Width or height can't be < 2! " << endl;
            return 0;
        }

        MatrixXd matrix1(m1,n1);
        cout << "Enter value of matrix: ";


        /** fills the matrix */
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                cin >> p[i][j];
                matrix1(i, j) = p[i][j];
            }
        }

        cout << "Matrix:" << endl << matrix1 << endl << endl;

        /** operations with one matrix */
        while (!q) {
            cout << "Matrix:" << endl << matrix1 << endl << endl;
            cout << "Choose operation(1 - Scalar multiplication, 2 - Scalar division, 3 - Transposition(matrix^T)" << endl;
            cout << "                 4 - Conjugation, 5 - Vector multiplication, 6 - Squared matrix" << endl;
            cout << "                 7 - Sum of all elements, 8 - Product of all elements, 9 - Average value of all elements" << endl;
            cout << "                 10 - Determinant of matrix, 11 - Minimal element, 12 - Maximal element" << endl;
            cin >> operation;
            if (operation == 1) {
                cout << "Enter Scalar: ";
                cin >> scalar;
                cout << "SCALAR MULTIPLICATION" << endl;
                cout << "Result-Matrix: " << endl << matrix1 * scalar << endl;
            } else if (operation == 2) {
                cout << "Enter Scalar: ";
                cin >> scalar;
                cout << "SCALAR DIVISION" << endl;
                cout << "Result-Matrix: " << endl << matrix1 / scalar << endl;
            } else if (operation == 3) {
                cout << "TRANSPOSITION" << endl;
                cout << "Result-Matrix: " << endl << matrix1.transpose() << endl;
                }
            else if (operation == 4) {
                cout << "CONJUGATION" << endl;
                cout << "Result-Matrix: " << endl << matrix1.conjugate() << endl;
            }
            else if (operation == 5) {
                cout << "Enter width of Vector: ";
                cin >> vec_width;
                cout << endl;
                VectorXd vector1;
                    for (int j = 0; j < vec_width; j++) {
                        cin >> v[j];
                        vector1(j) = v[j];
                    }
                cout << "VECTOR MULTIPLICATION" << endl;
                cout << "Result-Matrix: " << endl << matrix1 * vector1 << endl;
            }
            else if (operation == 6) {
                cout << "SQUARED MATRIX" << endl;
                cout << "Result-Matrix: " << endl << matrix1 * matrix1 << endl;
            }
            else if (operation == 7) {
                cout << "SUM OF ALL ELEMENTS" << endl;
                cout << "Sum of all elements = " << matrix1.sum() << endl;
            }
            else if (operation == 8) {
                cout << "PRODUCT OF ALL ELEMENTS" << endl;
                cout << "Product of all elements = " << matrix1.prod() << endl;
            }
            else if (operation == 9) {
                cout << "AVERAGE VALUE OF ALL ELEMENTS" << endl;
                cout << "Average value of all elements = " << matrix1.mean() << endl;
            }
            else if (operation == 10) {
                cout << "DETERMINANT" << endl;
                cout << "Determinant of matrix = " << matrix1.determinant() << endl;
            }
            else if (operation == 11) {
                cout << "MINIMAL ELEMENT" << endl;
                ptrdiff_t i,j;
                double min1 = matrix1.minCoeff(&i,&j);
                cout << "Minimal element = " << min1 << "it's position (" << i << ", " << j << ")" << endl;
            }
            else if (operation == 12) {
                cout << "MAXIMAL ELEMENT" << endl;
                ptrdiff_t i,j;
                double max1 = matrix1.maxCoeff(&i,&j);
                cout << "Maximal element = " << max1 << "it's position (" << i << ", " << j << ")" << endl;
            }
            cout << "Do you want to choose other operation? (1 - yes, 2 - no)";
            cin >> ques;
            if(ques == 2)
            {
                q = true;
            }

        }
    }else if(quantity == 2) {
        cout << "Enter first matrix: " << endl << "Enter height:";
        cin >> m1;
        cout << endl << "Enter width: ";
        cin >> n1;
        if(n1 < 2 || m1 < 2)
        {
            cout << "ERROR!  Width or height can't be < 2! " << endl;
            return 0;
        }
        MatrixXd matrix1(m1, n1);
        cout << "Enter value of matrix: ";

        /** fills the matrix */
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                cin >> p[i][j];
                matrix1(i, j) = p[i][j];
            }

        }

        cout << "Matrix #1:" << endl << matrix1 << endl << endl;

        cout << "Enter second matrix: " << endl << "Enter height: ";
        cin >> m2;
        cout << endl << "Enter width: ";
        cin >> n2;
        if(n1 < 2 || m1 < 2)
        {
            cout << "ERROR!  Width or height can't be < 2! " << endl;
            return 0;
        }
        MatrixXd matrix2(m2, n2);
        cout << "Enter value of matrix: ";

        /** fills the matrix */
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                cin >> p[i][j];
                matrix2(i, j) = p[i][j];
            }

        }

        cout << "Matrix #2:" << endl << matrix2 << endl << endl;

        /** operations with two matrixes */
        while (!q) {
            cout << "Matrix #1:" << endl << matrix1 << endl << endl;
            cout << "Matrix #2:" << endl << matrix2 << endl << endl;
            cout << "Choose operation(1 - sum, 2 - subtraction, 3 - multiplication): ";
            cin >> operation;
            if (operation == 1) {
                if (n1 != n2 || m1 != m2) {
                    cout << "ERROR! Matrixes have to be the same size to be able to SUM" << endl;
                } else {
                    cout << "SUM" << endl;
                    cout << "Result-Matrix: " << endl << matrix1 + matrix2 << endl;
                }
            } else if (operation == 2) {
                if (n1 != n2 || m1 != m2) {
                    cout << "ERROR! Matrixes have to be the same size to be able to SUBTRACT" << endl;
                } else {
                    cout << "SUBTRACTION" << endl;
                    cout << "Result-Matrix: " << endl << matrix1 - matrix2 << endl;
                }
            } else if (operation == 3) {
                if (n1 == m2) {
                    cout << "MULTIPLICATION" << endl;
                    cout << "Result-Matrix: " << endl << matrix1 * matrix2 << endl;
                } else {
                    cout << "ERROR! Matrixes have to be the same size to be able to MULTIPLY" << endl;
                }
            }
            cout << "Do you want to choose other operation? (1 - yes, 2 - no)";
            cin >> ques;
            if(ques == 2)
            {
                q = true;
            }
        }
    }
    return 0;
}