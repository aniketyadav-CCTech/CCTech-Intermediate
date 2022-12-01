#include <deque>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::string line;
        std::deque<std::string> lines;
        int counter=1;
        while (std::cin >> line)
        {   
            lines.push_back(line);
            if(counter>10)
            lines.pop_front();
            counter++;
        }
        std::cout<< std::endl;
        for (int i = 0; i < lines.size(); i++)
            std::cout<<lines.at(i)<<std::endl;
        
	}
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::ifstream ifs(argv[i]);
            std::string line;
            std::deque<std::string> lines;
            int counter=1;
            while (getline(ifs,line))
            {   
                lines.push_back(line);
                if(counter>10)
                lines.pop_front();
                counter++;
            }
            if(argc > 2)
            std::cout<< "==> " << argv[i] << " <==" << std::endl;
            for (int i = 0; i < lines.size(); i++)
                std::cout<<lines.at(i)<<std::endl;
        }
    }
    return EXIT_SUCCESS;
}