// Assignment: Implement UNIX commands cat, sort, heads and tails in C++ 

#include <iostream>
#include <fstream>

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
        for (int i = 1; i < argc; i++)
        {
            FILE *file;
            if (file = fopen(argv[i], "r"))
            {
                char c;
                while (1)
                {
                    c = getc(file);
                    if (c == EOF)
                        break;
                    std::cout << c;
                }
                fclose(file);
            }
            else
            {
                std::cout << "cat: " << argv[1] << ": No such file or directory";
            }
        }
    }
    return EXIT_SUCCESS;
}