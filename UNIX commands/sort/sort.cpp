#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>


int main(int argc, char* argv[])
{
    std::list<std::string> lines;
    std::string line;
    bool flag = true;
    if (argc == 1)
    {
        while (getline(std::cin, line))
            lines.push_back(line);
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::ifstream ifs(argv[i]);
            if(!ifs)
            {
                std::cout << "sort: cannot read: " << argv[1] << ": No such file or directory\n";
                flag = false;
            }
            else
                while (getline(ifs, line))
                {
                    lines.push_back(line);
                }
        }
    }
    if(flag)
    {
        lines.sort();
        std::list<std::string>::iterator itr;
        for(itr=lines.begin();itr!=lines.end();++itr)
            std::cout << *itr << std::endl;
    }
    return EXIT_SUCCESS;
}