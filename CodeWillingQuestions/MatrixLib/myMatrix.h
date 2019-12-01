//
// Created by johnm on 11/29/2019.
//

#ifndef CODEWILLINGQUESTIONS_MYMATRIX_H
#define CODEWILLINGQUESTIONS_MYMATRIX_H

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <vector>

using std::vector;

#include <exception>

using std::exception;

template<class T>
class myMatrix {
public:

    myMatrix(const unsigned int rows, const unsigned int col, const vector<vector<T>> data);

    myMatrix();

    void printMatrix();
    myMatrix<T> operator+(myMatrix<T> other_matrix) const;
    void operator+=(myMatrix<T> other_mat);
    myMatrix<T> operator*(myMatrix<T> other_matrix) const;
private:
    unsigned int size;
    unsigned int columns;
    unsigned int rows;
    vector<vector<T>> data;

    static bool checkRows(const unsigned int rows, const unsigned int columns, const vector<vector<T>> data) {
        unsigned int row_count = 0;
        unsigned int col_count =0;
        for(size_t i = 0; i < data.size();i++) {
            row_count++;
            for(size_t j = 0; j < data.at(i).size();j++) {
                col_count++;
            }
        }
        //If the rows or columns of data are bigger than what was specified
        if(row_count > rows || col_count > columns) {
            return false;
        }
            //If the rows or columns of data are smaller than what was specified
        else if(row_count< rows || col_count < columns) {
            return false;
        }
        else {
            return true;
        }
    }
};

#endif //CODEWILLINGQUESTIONS_MYMATRIX_H
