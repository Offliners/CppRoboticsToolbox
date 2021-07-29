#include<iostream>
#include<vector>
#include"Angle.h"
#include"ArgParser.h"

using namespace std;

class AC_ArgParser : ArgParser
{
    public:
        AC_ArgParser(int argc, char **argv, const std::string& name, const std::vector< std::vector<std::string> > &arg) : ArgParser(name, arg)
        {
                if(argc > 1)
                    all_args_.assign(argv + 1, argv + argc);
                else
                {
                    this->errorMsg();
                    std::exit(-1);
                }
        };

        ~AC_ArgParser()
        {
                all_args_.clear();
        };

        void argFunction()
        {
            int temp = this->isArgValid(all_args_);
            switch(temp)
            {
                case -1:
                    this->errorMsg();
                    break;
                case 0:
                    this->help();
                    break;
                case 1:
                {
                    if(all_args_[2] != "-s" && all_args_[2] != "--sequence")
                    {
                        this->errorMsg();
                        std::exit(-1);
                    }

                    shwoRT(all_args_[1], all_args_[3], std::atof(all_args_[4].c_str()), std::atof(all_args_[5].c_str()), std::atof(all_args_[6].c_str()));
                    break;
                }
                case 2:
                {
                    if(all_args_[2] != "-m" && all_args_[2] != "--method")
                    {
                        this->errorMsg();
                        std::exit(-1);
                    }

                    shwoRT(all_args_[3], all_args_[1], std::atof(all_args_[4].c_str()), std::atof(all_args_[5].c_str()), std::atof(all_args_[6].c_str()));
                    break;
                }
                default:
                    this->errorMsg();
                    break;
            }
        };

        void shwoRT(std::string method, std::string sequence, double a1, double a2, double a3)
        {
            Angle angle(method, sequence, a1, a2, a3);
            angle.showRotateMatrix();
        };

    private:
        std::vector< std::string > all_args_;
};

int main(int argc, char **argv)
{
    vector< vector<string> > opt
    {
        {"-h", "--help", "2", "Print help and exit"},
        {"-m", "--method", "8", "Input rotate method(euler or fixed, case insensitive)"},
        {"-s", "--sequence", "8", "The sequence of input angles(case insensitive)\n\
                      If rotation method is \"fixed\", the input sequence of angles is \"gamma->beta->alpha\"\n\
                      If rotation method is \"euler\", the input sequence of angles is \"alpha->beta->gamma\""}
    };

    string tool_name = argv[0];
    vector<string> all_args;
    AC_ArgParser arg(argc, argv, "AC", opt);
    
    arg.argFunction();

    return 0;
}