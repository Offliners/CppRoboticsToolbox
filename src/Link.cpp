#include<iostream>
#include<cmath>
#include<iomanip>
#include"Link.h"

Link::Link() {}

Link::Link(int index, double alpha, double a, double d, double theta)
{
    up_ = index - 1;
    down_ = index;
    alpha_ = alpha;
    a_ = a;
    d_ = d;
    theta_ = theta;

    joint_ << c(theta)         , -s(theta)          , 0        , a,
              s(theta)*c(alpha), c(theta)*c(alpha)  , -s(alpha), -s(alpha)*d,
              s(theta)*s(alpha), c(theta)*s(alpha)  , c(alpha) , c(alpha)*d,
              0                , 0                  , 0        , 1;

    zeroSign();
}

double Link::c(double angle)
{
    return std::cos(angle * M_PI / 180);
}
        
double Link::s(double angle)
{
    return std::sin(angle * M_PI / 180);
}

void Link::zeroSign()
{
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j)
            if(std::fabs(joint_(i, j)) < 1e-3)
                joint_(i, j) = 0.0;
}

void Link::showInfo() const
{
    std::cout << std::setw(12) << std::setfill(' ') << alpha_
              << std::setw(10) << std::setfill(' ') << a_
              << std::setw(8) << std::setfill(' ') << d_
              << std::setw(12) << std::setfill(' ') << theta_ << std::endl;
}

int Link::getIndex() const
{
    return down_;
}

std::ostream& operator << (std::ostream &os, const Link& link)
{
    os << "Transform Matrix " << link.down_ << "->" << link.up_ << " : " << std::endl;
    os << std::fixed << std::setprecision(3) << link.joint_ << std::endl;
    return os;
}

Link Link::operator * (const Link &T)
{
    Link temp;
    if(T.down_ < this->down_)
    {
        temp.joint_ = T.joint_ * this->joint_;
        temp.up_ = T.up_;
        temp.down_ = this->down_;
    }
    else if(T.down_ > this->down_)
    {
        temp.joint_ = this->joint_ * T.joint_ ;
        temp.up_ = this->up_;
        temp.down_ = T.down_;
    }
    else
        std::cout << "Error" << std::endl;

    return temp;
}

Link::~Link() {};