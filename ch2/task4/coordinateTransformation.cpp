#include<Eigen/Core>
#include<Eigen/Geometry>
#include<iostream>
using namespace std;

int main(int argv, char** argc)
{
    //初始化四元数
    Eigen::Quaterniond q_W2R(0.55, 0.3, 0.2, 0.2);	//这种方式初始化，实部在前
    Eigen::Quaterniond q_R2B(0.99, 0, 0, 0.01);
    Eigen::Quaterniond q_B2L(0.3, 0.5, 0, 20.1);
    Eigen::Quaterniond q_B2C(0.8, 0.2, 0.1, 0.1);

    //四元数归一化
    q_W2R.normalize();
    q_R2B.normalize();
    q_B2L.normalize();
    q_B2C.normalize();

    //初始化平移向量
    Eigen::Vector3d t_W2R(0.1, 0.2, 0.3);
    Eigen::Vector3d t_R2B(0.05, 0, 0.5);
    Eigen::Vector3d t_B2L(0.4, 0, 0.5);
    Eigen::Vector3d t_B2C(0.5, 0.1, 0.5);

    //相机坐标系下该点坐标
    Eigen::Vector3d p_C(0.3, 0.2,1.2);

    //四元数转化为旋转矩阵
    Eigen::Matrix3d R_W2R = q_W2R.matrix();
    Eigen::Matrix3d R_R2B = q_R2B.matrix();
    Eigen::Matrix3d R_B2L = q_B2L.matrix();
    Eigen::Matrix3d R_B2C = q_B2C.matrix();

    //计算激光坐标系下该点位置 C -> B -> L
    Eigen::Vector3d p_B = R_B2C*p_C + t_B2C;
    Eigen::Vector3d p_L = R_B2L.transpose()*p_B - R_B2L.transpose()*t_B2L;		//激光坐标系下该点位置

    //计算世界坐标系下该点位置 B -> R -> W
    Eigen::Vector3d p_R = R_R2B*p_B + t_R2B;
    Eigen::Vector3d p_W = R_W2R*p_R + t_W2R;		//世界坐标系下该点位置


    std::cout << "激光坐标系下该点位置:" << p_L.transpose() << std::endl;
    std::cout << "世界坐标系下该点位置" << p_W.transpose() << std::endl;

    return 0;
}

