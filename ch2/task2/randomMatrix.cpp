#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Cholesky>
using namespace std;

int main(int argv, char** argc)
{
    //初始化矩阵
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A = Eigen::MatrixXd::Random(100,100);
    Eigen::Matrix<double, Eigen::Dynamic, 1>b = Eigen::MatrixXd::Random(100,1);

    //保证A是正定对称矩阵，这样cholesky才有效
    A = A.transpose()*A;

    //QR分解的结果
    Eigen::Matrix<double, Eigen::Dynamic, 1> x_QR = A.colPivHouseholderQr().solve(b);

    //分解的结果
    Eigen::Matrix<double, Eigen::Dynamic, 1> x_Cholesky = A.ldlt().solve(b);;

    std::cout << "QR result: " << x_QR.transpose() << std::endl;
    std::cout << "Cholesky result: " << x_Cholesky.transpose() << std::endl;

    return 0;
}


