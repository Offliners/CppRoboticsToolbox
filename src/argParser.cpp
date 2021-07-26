#include<iostream>
#include<algorithm>
#include"argParser.h"

ArgParser::ArgParser(std::string name, std::vector< std::pair<std::string, std::string> > args)
{
    name_ = name;
    args_ = args;
}

void ArgParser::help() const
{
    std::cout << name_ << " arguments information :" << std::endl;
    for(auto p : this->args_)
        std::cout << "[" << p.first << "] -- " << p.second << std::endl;
}

int ArgParser::optIndex(const std::string &opt) const
{
    auto index = std::find_if(args_.begin(), args_.end(), [&opt](const std::pair<std::string, std::string>& e){ return e.first == opt;} );
    
    if(index == args_.end())
        return -1;
    else
        return index - args_.begin();
}

ArgParser::~ArgParser()
{
    args_.clear();
}