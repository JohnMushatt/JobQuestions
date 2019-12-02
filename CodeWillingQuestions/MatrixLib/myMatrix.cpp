//
// Created by johnm on 11/29/2019.
//

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "myMatrix.h"

/**
* Constructor for
* @tparam T Data type to create a m x n matrix of
* @param rows # of rows
* @param col # of columns
* @param data Data to store in the matrix
*             Data must be m x n or rows x col
*/
template<class T>
myMatrix<T>::myMatrix(const unsigned int rows, const unsigned int col, vector<vector<T>> data) {
    //If # of rows * # of cols of data are not compatible
    if (data.size() * data.at(0).size() != rows * col) {
        throw std::invalid_argument("Dimensions of data do not work with the rows and columns provided");
    }
    if (checkRows(rows, col, data)) {
        throw std::invalid_argument("Dimensions of data and rows or columns are invalid");
    }
    this->rows = rows;
    this->columns = col;
    this->size = rows * col;
    this->data.resize(rows);
    for (size_t i = 0; i < this->data.size(); i++) {

        this->data.at(i).resize(col);
    }
    for (size_t i = 0; i < data.size(); i++) {

        for (size_t j = 0; j < data.at(i).size(); j++) {

            this->data.at(i).at(j) = data.at(i).at(j);
        }
    }
}

/**
 * Print the matrix stored in data
 * @tparam T Type of data stored in data
 */
template<class T>
void myMatrix<T>::printMatrix() {
    std::cout << std::endl;
    for (size_t i = 0; i < this->data.size(); i++) {
        std::stringstream current_row;
        for (size_t j = 0; j < this->data.at(i).size(); j++) {
            current_row << data.at(i).at(j) << "\t";

        }
        std::cout << current_row.str() << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Multiply 2 matrices together
 * @tparam T Type of data
 * @param other_matrix Other matrix to multiple a.k.a right hand sside
 * @return A new matrix containing the dot product of the 2 matrices
 */
template<class T>
myMatrix<T> myMatrix<T>::operator*(myMatrix<T> &other_matrix) const {
    //First check to make sure THIS matrix and other_matrix are equal dimension
    if (this->columns != other_matrix.rows) {
        throw std::invalid_argument("# of columns on left hand side does not equal # of rows on the right hand side");
    }
    //Create temporary 2d matrix
    vector<vector<T>> data(this->rows, vector<T>(other_matrix.columns));

    for (size_t i = 0; i < this->data.size(); i++) {
        for (size_t j = 0; j < this->data.at(i).size(); j++) {

            for (size_t row = 0; row < other_matrix.data.size(); row++) {
                T this_element = this->data.at(i).at(row);
                T other_element = other_matrix.data.at(row).at(j);
                T product = this_element * other_element;
                data.at(i).at(j) += product;
            }
        }


    }
    myMatrix<T> newMat = myMatrix<T>(this->rows, this->columns, data);
    return newMat;
}
/**
 * Scalar version of matrix multiplication
 * @tparam T Data type of matrix
 * @param scalar Value to multiply matrix by
 * @return A new matrix containg the product of the matrix and scalar
 */
template<class T>
myMatrix<T> myMatrix<T>::operator*(T scalar) const {
    vector<vector<T>> data(this->rows, vector<T>(this->columns));

    for (size_t i = 0; i < this->data.size(); i++) {
        for (size_t j = 0; j < this->data.at(i).size(); j++) {

            data.at(i).at(j) = this->data.at(i).at(j) * scalar;
        }


    }
    myMatrix<T> newMat = myMatrix<T>(this->rows, this->columns, data);
    return newMat;
}

/**
 * Vector value version of the member function overload +
 * @tparam T Class type of vector value to add to the matrix
 * @param val Vector value to add to the matrix
 * @return matrix that has been modified by val
 */
template<class T>
myMatrix<T> myMatrix<T>::operator+(myMatrix<T> &other_matrix) const {
    //First check to make sure THIS matrix and other_matrix are equal dimension
    if (this->rows != other_matrix.rows && this->columns != other_matrix.columns) {
        throw std::invalid_argument("Right hand matrix does not have the same dimensions as left hand matrix");
    }
    //Create temporary 2d matrix
    vector<vector<T>> data(other_matrix.rows, vector<T>(columns));

    for (size_t i = 0; i < this->data.size(); i++) {
        for (size_t j = 0; j < this->data.at(i).size(); j++) {
            data.at(i).at(j) = this->data.at(i).at(j) + other_matrix.data.at(i).at(j);
        }
    }
    myMatrix<T> newMat = myMatrix<T>(this->rows, this->columns, data);
    return newMat;
}
/**
 * The += operator overload
 * @tparam T Type of data in matrix
 * @param other_matrix Reference to matrix to add to itself
 */
template<class T>
void myMatrix<T>::operator+=(myMatrix<T> &other_matrix) {
    //First check to make sure THIS matrix and other_matrix are equal dimension
    if (this->rows != other_matrix.rows && this->columns != other_matrix.columns) {
        throw std::invalid_argument("Right hand matrix does not have the same dimensions as left hand matrix");
    }
    for (size_t i = 0; i < this->data.size(); i++) {
        for (size_t j = 0; j < this->data.at(i).size(); j++) {
            this->data.at(i).at(j) = this->data.at(i).at(j) + other_matrix.data.at(i).at(j);
        }
    }
}
/**
 * The - operator
 * @tparam T Type of data stored in matrix
 * @param lhs Left hand side matrix
 * @param rhs Right hand side matrix
 * @return A new matrix with the difference between lhs and rhs
 */
template<class T>
myMatrix<T> operator-(myMatrix<T> &lhs, myMatrix<T> &rhs) {
    if (lhs.rows != rhs.rows || lhs.columns != rhs.columns) {
        throw std::invalid_argument("Right hand side or left hand side are invalid matrices");
    } else {
        vector<vector<T>> data(lhs.rows, vector<T>(lhs.columns));

        for (unsigned int i = 0; i < lhs.rows; i++) {
            for (unsigned int j = 0; j < lhs.columns; j++) {

                data.at(i).at(j) = lhs.data.at(i).at(j) - rhs.data.at(i).at(j);
            }
        }

        myMatrix<T> new_mat = myMatrix<T>(lhs.rows, lhs.columns, data);
        return new_mat;
    }
}
