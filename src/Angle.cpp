#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include"Angle.h"

Angle::Angle()
{
    alpha_ = 0.0;
    beta_ = 0.0;
    gamma_ = 0.0;
    method_ = "fixed";
    sequence_ = "xyz";
}

Angle::Angle(const std::string &method, const std::string &sequence, double alpha, double beta, double gamma)
{
    method_ = isValid(method, rotate_method_);
    sequence_ = isValid(sequence, rotate_sequence_);
    alpha_ = alpha;
    beta_ = beta;
    gamma_ = gamma;
}

std::string Angle::isValid(const std::string &key, const std::set<std::string> &map)
{
    std::string temp = key;
    std::transform(key.begin(), key.end(), temp.begin(), ::tolower);

    if(map.find(temp) != map.end())
        return temp;
    else
    {
        std::cout << "Can't find this method or the sequence!" << std::endl;
        std::exit(-1);
    }
}

void Angle::getInfo() const
{
    std::cout << "Rotation Method : " << method_ << std::endl;
    if(method_ == "fixed")
    {
        std::cout << std::fixed << std::setprecision(3) 
                  << "R" << sequence_ << "(gamma, beta, alpha) = (" << alpha_ << ", " << beta_ << ", " << gamma_ << ")" << std::endl; 
    }
    else if(method_ == "euler")
    {
        std::cout << std::fixed << std::setprecision(3) 
                  << "R" << sequence_ << "(alpha, beta, gamma) = (" << alpha_ << ", " << beta_ << ", " << gamma_ << ")" << std::endl;
    }
    else
        std::cout << "Error!" << std::endl;
}

Eigen::Matrix3d Angle::rotateX(double a) const
{
    Eigen::Matrix3d result = Eigen::Matrix3d::Zero();

    result << 1, 0   , 0,
              0, c(a), -s(a),
              0, s(a), c(a);
    
    return result;
}

Eigen::Matrix3d Angle::rotateY(double a) const
{
    Eigen::Matrix3d result = Eigen::Matrix3d::Zero();

    result << c(a) , 0, s(a),
              0    , 1, 0,
              -s(a), 0, c(a);
    
    return result;
}

Eigen::Matrix3d Angle::rotateZ(double a) const
{
    Eigen::Matrix3d result = Eigen::Matrix3d::Zero();

    result << c(a), -s(a), 0,
              s(a), c(a) , 0,
              0   , 0    , 1;
    
    return result;
}

Eigen::Matrix3d Angle::chooseRotAxis(char axis, double a) const
{
    switch(axis)
    {
        case 'x':
            return rotateX(a);
        case 'y':
            return rotateY(a);
        case 'z':
            return rotateZ(a);
        default:
            std::cout << "Error!" << std::endl;
            break;
    }
}

void Angle::showRotateMatrix() const
{
    Eigen::Matrix3d r = Eigen::Matrix3d::Identity();
    std::string temp = sequence_;
    double angles[3] = {alpha_, beta_, gamma_};

    if(method_ == "fixed")
    {
        std::reverse(angles, angles + 3);
        std::reverse(temp.begin(), temp.end());
    }   

    for(int i = 0; i < temp.length(); ++i)
        r *= chooseRotAxis(temp[i], angles[i]);

    std::cout << std::fixed << std::setprecision(3) << r << std::endl; 
}

double Angle::c(double angle) const
{
    return std::cos(angle * M_PI / 180);
}

double Angle::s(double angle) const
{
    return std::sin(angle * M_PI / 180);
}

Angle::~Angle()
{
    rotate_method_.clear();
    rotate_sequence_.clear();
}