#ifndef _LINK_H_
#define _LINK_H_

#include<Eigen/Core>

class Link
{
    friend std::ostream& operator << (std::ostream&, const Link&);

    public:
        Link();
        Link(int index, double alpha, double a, double d, double theta);
        double c(double);
        double s(double);
        void zeroSign();
        void showInfo() const;
        int getIndex() const;
        Link operator * (const Link&);
        ~Link();

    private:
        int up_ = 0;
        int down_ = 0;
        double alpha_ = 0;
        double a_ = 0;
        double d_ = 0;
        double theta_ = 0;
        Eigen::Matrix<double, 4, 4> joint_;
};

#endif