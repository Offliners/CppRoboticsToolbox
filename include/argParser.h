#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include<string>
#include<vector>

class ArgParser
{
    public:
        ArgParser(std::string, std::vector< std::pair<std::string, std::string> >);
        int optIndex(const std::string&) const;
        void help() const;
        ~ArgParser();

    private:
        std::string name_;
        std::vector< std::pair<std::string, std::string> > args_;
};

#endif