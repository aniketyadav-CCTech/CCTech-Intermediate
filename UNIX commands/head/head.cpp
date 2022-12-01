#include <fstream>
#include <iostream>
#include <list>

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        char c;
        while (true)
        {
            c = getchar();
            if (c == EOF)
                break;
            putchar(c);
        }
    }
    else
    {
        std::list<std::string>lines;
        std::string line;
        int counter=1;
        for(int i = 1; i < argc; i++)
        {
            if(argc > 2)
            {
                std::cout << "==> " << argv[i] << " <=="<<std::endl;
                counter = 1;
            }
            std::ifstream ifs(argv[i]);
            while(getline(ifs,line))
            {
                std::cout<<line<<std::endl;
                if(counter==10)
                {
                    std::cout << std::endl;
                    break;
                }
                counter++;
            }
        }
    }
    return EXIT_SUCCESS;
}