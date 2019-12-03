#include <iostream>
#include "myMatrix.h"
#include "myMatrix.cpp"
#include "../WordFrequencyLib/TextParser.h"
#include <memory>

using std::shared_ptr;

int main(int argc, char **argv) {
    if(argc!=2) {
        throw std::invalid_argument("No file entered in the program");
    }
    std::cout << "Testing creating 2 2x2 matrices of type int..." << std::endl;

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

    //Add mat1 and mat2
    std::cout << "Testing addition between mat1 and mat2..." << std::endl;
    myMatrix<int> mat1_mat2 = mat_int1 + mat_int2;
    mat1_mat2.printMatrix();
    std::cout << "Testing creating 1 3x3 matrices of type double..." << std::endl;

    //2x2 matrix of doubles
    std::vector<std::vector<double>> double_dat{{2.0, 1.344, 3.1789},
                                                {.67, 8.29,  10.0000}};
    myMatrix<double> mat_double = myMatrix<double>(2, 3, double_dat);
    mat_double.printMatrix();

    std::cout << "Testing adding mat2 to itself i.e. mat_int2+=mat_int2..." << std::endl;
    //Add mat2 to itself
    mat_int2 += mat_int2;
    mat_int2.printMatrix();
    std::cout << "Testing dot product between mat1 and mat2..." << std::endl;
    myMatrix<int> multiplied_mat = mat_int1 * mat_int2;
    multiplied_mat.printMatrix();

    std::cout << "Testing creating 2 3x3 matrices of type double..." << std::endl;

    //Test a 3x3 double matrix
    std::vector<std::vector<double>> ThreeByThree_One{{1.0, 2.5, 3.3},
                                                      {4,   2.1, 5.22},
                                                      {.7,  .8,  3.5}};
    std::vector<std::vector<double>> ThreeByThree_Two{{.7,  .8,  3.5},
                                                      {4,   2.1, 5.22},
                                                      {1.0, 2.5, 3.3}};

    myMatrix<double> TbT_one = myMatrix(3, 3, ThreeByThree_One);
    myMatrix<double> TbT_two = myMatrix(3, 3, ThreeByThree_Two);
    std::cout << "Testing multiplication between  2 2x2 matrices of type double..." << std::endl;
    myMatrix<double> TbT_res = TbT_one * TbT_two;
    TbT_res.printMatrix();

    std::cout << "Testing multiplication between 1 matrix and a scalar value of 2" << std::endl;
    // 2x2 matrix of ints
    std::vector<std::vector<int>> scalar_mult{{1, 2},
                                            {4, 2}};
    myMatrix<int> mat_scalar_mult = myMatrix<int>(2, 2, scalar_mult);
    mat_scalar_mult.printMatrix();
    myMatrix<int> scalar_result = mat_scalar_mult * 2;
    scalar_result.printMatrix();
    std::cout
            << "Testing non-member \"-\" functionality, result should be a 2x2 matrix of zeros\nas the multiplied_mat - multiplied_mat = 0"
            << std::endl;
    myMatrix<int> zero_mat = multiplied_mat - multiplied_mat;
    zero_mat.printMatrix();


    return 0;
}