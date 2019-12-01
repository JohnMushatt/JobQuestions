#include <iostream>
#include "MatrixLib/myMatrix.h"
#include "MatrixLib/myMatrix.cpp"
#include <memory>

using std::shared_ptr;

int main() {

    // 2x2 matrix of ints
    std::vector<std::vector<int>> data_int1{{1, 2},
                                            {4, 2}};
    myMatrix<int> mat_int1 = myMatrix<int>(2, 2, data_int1);
    mat_int1.printMatrix();
    std::vector<std::vector<int>> data_int2{{1, 2},
                                            {4, 2}};
    //2x2 matrix of ints
    myMatrix<int> mat_int2 = myMatrix<int>(2, 2, data_int2);
    mat_int2.printMatrix();


    //2x2 matrix of doubles
    std::vector<std::vector<double>> double_dat{{2.0, 1.344, 3.1789},
                                                {.67, 8.29,  10.0000}};
    myMatrix<double> mat_double = myMatrix<double>(2, 3, double_dat);
    mat_double.printMatrix();

    //Add mat1 and mat2
    myMatrix<int> mat1_mat2 = mat_int1 + mat_int2;
    mat1_mat2.printMatrix();

    //Add mat2 to itself
    mat_int2 += mat_int2;
    mat_int2.printMatrix();
    std::cout<<"Testing dot product"<<std::endl;
    myMatrix<int> multiplied_mat = mat_int1 * mat_int2;
    multiplied_mat.printMatrix();

    //Test a 3x3 double matrix
    std::vector<std::vector<double>> ThreeByThree_One{{1.0, 2.5, 3.3},
                                                      {4,   2.1, 5.22},
                                                      {.7,  .8,  3.5}};
    std::vector<std::vector<double>> ThreeByThree_Two{{.7,  .8,  3.5},
                                                      {4,   2.1, 5.22},
                                                      {1.0, 2.5, 3.3}};

    myMatrix<double> TbT_one = myMatrix(3,3,ThreeByThree_One);
    myMatrix<double> TbT_two = myMatrix(3,3,ThreeByThree_Two);

    myMatrix<double> TbT_res = TbT_one * TbT_two;
    TbT_res.printMatrix();
    return 0;
}