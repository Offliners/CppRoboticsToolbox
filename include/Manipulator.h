#ifndef _MANIPULATOR_H_
#define _MANIPULATOR_H_

#include<vector>
#include"Link.h"

class Manipulator
{
    public:
        Manipulator();
        void addJoint(int n);
        void title();
        ~Manipulator();
        void ShowDHTable();
        void addOneJoint(int, double, double, double, double);
        void ShowTransformMatrix(int, int);
    private:
        std::vector<Link*> links_;
};

#endif