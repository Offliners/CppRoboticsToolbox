#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"Manipulator.h"
#include"argParser.h"

using namespace std;

void errorMsg(); 
bool checkValid(const string&, int);

int main(int argc, char **argv)
{
    vector< pair<string, string> > opt =
    {
        {"-h", "Print help and exit"},
        {"-f", "File path of DH table (Please use txt file to record the table)"}
    };

    string tool_name = argv[0];
    vector<string> all_args;
    ArgParser arg("DH", opt);
    
    if(argc > 1 && arg.optIndex(string(argv[1])) != -1)
    {
        all_args.assign(argv + 1, argv + argc);
        
        if(all_args[0] == "-h")
        {
            if(argc != 2)
                errorMsg();
            else
                arg.help();
        }
        else if(all_args[0] == "-f")
        {
            if(argc != 5)
                errorMsg();
            else
            {
                const string filename = all_args[1];
                ifstream DH_file(filename);
                if(!DH_file)
                {
                    cout << "\"" << filename << "\"" << "File can't be opened! Please check the path of the file!" << endl;
                    return 0;
                }

                int cnt = 1;
                int alpha, a, d, theta;
                Manipulator m;
                while(DH_file >> alpha >> a >> d >> theta)
                {
                    m.addOneJoint(cnt, alpha, a, d, theta);
                    ++cnt;
                }
                
                if(checkValid(all_args[2], cnt) && checkValid(all_args[3], cnt))
                    m.ShowTransformMatrix(atoi(all_args[2].c_str()), atoi(all_args[3].c_str()));
                else
                    errorMsg();
            }
        }
        else
            errorMsg();
    }
    else
        errorMsg();

    return 0;
}

void errorMsg()
{
    cout << "Error usage! Please use [-h] to check correct arguments" << endl;
}

bool checkValid(const string& str, int maxNum)
{
    for (char const &c : str)
        if (isdigit(c) == 0) 
            return false;
    
    if(atoi(str.c_str()) > maxNum)
        return false;

    return true;
}