#ifndef _ANGLE_H_
#define _ANGLE_H_

#include<string>
#include<set>
#include<Eigen/Core>

class Angle
{
    public:
        Angle();
        Angle(const std::string&, const std::string&, double, double, double);
        std::string isValid(const std::string&, const std::set<std::string>&);
        void getInfo() const;
        void showRotateMatrix() const;
        Eigen::Matrix3d rotateX(double) const;
        Eigen::Matrix3d rotateY(double) const;
        Eigen::Matrix3d rotateZ(double) const;
        Eigen::Matrix3d chooseRotAxis(char, double) const;
        double c(double) const;
        double s(double) const;
        ~Angle();

    private:
        double alpha_ = 0.0;
        double beta_ = 0.0;
        double gamma_ = 0.0;
        std::string method_;
        std::set<std::string> rotate_method_ = {"fixed", "euler"};
        std::string sequence_;
        std::set<std::string> rotate_sequence_ = {"xyz", "xzy", "yxz", "yzx", "zxy", "zyx", "xyx", "xzx", "yxy", "yzy", "zxz", "zyz"};
};

#endif