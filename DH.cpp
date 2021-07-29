#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"Manipulator.h"
#include"ArgParser.h"

using namespace std;

void errorMsg(); 
bool checkValid(const string&, int);

class DH_ArgParser : ArgParser
{
    public:
        DH_ArgParser(int argc, char **argv, const std::string& name, const std::vector< std::vector<std::string> > &arg) : ArgParser(name, arg)
        {
            if(argc > 1)
                all_args_.assign(argv + 1, argv + argc);
            else
            {
                this->errorMsg();
                std::exit(-1);
            }
        };

        ~DH_ArgParser()
        {
            all_args_.clear();
        };

        void readFileAndShowTF()
        {
            const string filename = all_args_[1];
            ifstream DH_file(filename);
            if(!DH_file)
            {
                cout << "\"" << filename << "\"" << "File can't be opened! Please check the path of the file!" << endl;
                return;
            }

            int cnt = 1;
            int alpha, a, d, theta;
            Manipulator m;
            while(DH_file >> alpha >> a >> d >> theta)
            {
                m.addOneJoint(cnt, alpha, a, d, theta);
                ++cnt;
            }
            m.ShowTransformMatrix(atoi(all_args_[2].c_str()), atoi(all_args_[3].c_str()));
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
                    this->readFileAndShowTF();
            }
        };

        private:
            std::vector< std::string > all_args_;
};

int main(int argc, char **argv)
{
    vector< vector<string> > opt
    {
        {"-h", "--help", "2", "Print help and exit"},
        {"-f", "--file", "5", "File path of DH table (Please use txt file to record the table)"}
    };

    string tool_name = argv[0];
    vector<string> all_args;
    DH_ArgParser arg(argc, argv, tool_name.erase(0, 2), opt);
    
    arg.argFunction();

    return 0;
}