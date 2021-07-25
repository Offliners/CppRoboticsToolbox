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
        void ShowTransformMatrix(int, int);
    private:
        std::vector<Link*> links_;
};

#endif