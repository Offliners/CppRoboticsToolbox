#include<iostream>
#include<algorithm>
#include"ArgParser.h"

ArgParser::ArgParser(const std::string& name, const std::vector< std::vector<std::string> > &args)
{
    name_ = name;
    args_ = args;
}

void ArgParser::help() const
{
    std::cout << "\"" << name_ << "\""<< " command arguments usage :" << std::endl;
    for(auto p : this->args_)
        std::cout << "[" << p[0] << " | " << p[1] << "] --> " << p[3] << std::endl;
}

int ArgParser::optIndex(const std::string &opt) const
{
    auto index = std::find_if(args_.begin(), args_.end(), [&opt](const std::vector<std::string>& e){ return (e[0] == opt || e[1] == opt);} );
    
    if(index == args_.end())
        return -1;
    else
        return index - args_.begin();
}

int ArgParser::isArgValid(const std::vector<std::string> &args) const
{
    int flag = optIndex(args[0]);
    if((flag == -1) || (args.size() != std::atoi(args_[flag][2].c_str()) - 1))
        return -1;
    else
        return flag;
}

void ArgParser::errorMsg() const
{
    std::cout << "Error usage! Please use [-h] to check correct arguments" << std::endl;
};

ArgParser::~ArgParser()
{
    args_.clear();
}