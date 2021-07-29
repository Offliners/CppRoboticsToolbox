#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include<string>
#include<vector>

class ArgParser
{
    public:
        ArgParser(const std::string&, const  std::vector< std::vector<std::string> >&);
        int optIndex(const std::string&) const;
        void help() const;
        void errorMsg() const;
        int isArgValid(const std::vector<std::string>&) const;
        ~ArgParser();

    private:
        std::string name_;
        std::vector< std::vector<std::string> > args_;
};

#endif