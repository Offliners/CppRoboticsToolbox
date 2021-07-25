#include<iostream>
#include<iomanip>
#include"Manipulator.h"

Manipulator::Manipulator()
{
    this->links_.clear();
}

void Manipulator::addJoint(int n)
{
    std::cout << "Input DH Table (Craig)" << std::endl;
    title();
    for(int i = 0; i < n; ++i)
    {
        double alpha, a, d, theta;
        std::cout << std::setw(4) << std::setfill(' ') << i + 1 << " | ";
        std::cin >> alpha >> a >> d >> theta;
        std::cin.ignore();
        links_.push_back(new Link(i + 1, alpha, a, d, theta));
    }
}

void Manipulator::title()
{
    std::cout << "=========================================" << std::endl
              << "Index" 
              << std::setw(14) << std::setfill(' ') << "alpha(i-1)"
              << std::setw(10) << std::setfill(' ') << "a(i-1)"
              << std::setw(8) << std::setfill(' ') << "d(i)"
              << std::setw(12) << std::setfill(' ') << "theta(i)" << std::endl;
}

Manipulator::~Manipulator()
{
    for (auto p : this->links_)
		delete p;
	this->links_.clear();
}

void Manipulator::ShowDHTable()
{
    title();
    for (int i = 0; i < links_.size(); ++i)
    {
        std::cout << std::setw(4) << std::setfill(' ') << i + 1 << " | ";
        links_[i]->showInfo();
    }
}

void Manipulator::ShowTransformMatrix(int up, int down)
{
    if(up > down)
        std::cout << "Error! Upper index must be less than lower index!" << std::endl;
    else if(up + 1 == down)
        std::cout << *(links_[--down]) << std:: endl;
    else
    {
        Link temp = (*links_[up]);
        for(int i = up + 1; i < down; ++i)
            temp = temp * (*links_[i]);
        
        std::cout << temp << std::endl;
    }
}