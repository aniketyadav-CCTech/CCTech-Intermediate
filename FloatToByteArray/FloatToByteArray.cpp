// Convert a float number (32 bits) into 4 bytes and vice versa.

#include <iostream>
// #include <bitset>

using namespace std;

union my_float{
    unsigned char buffer[4];
    float fl;
};

int main(int argc,char* argv[])
{
    // using bitset
    // float d=stof(argv[1]);
    // char* temp = reinterpret_cast<char*>(&d);
    // for(int i=0;i<4;i++)
    //     cout << bitset<8>(temp[i]).to_ulong() << " ";
    // cout << endl;

    union my_float temp;
    if(argc==2)
    {
        temp.fl = stof(argv[1]);
        for(unsigned char ch:temp.buffer)
        cout<< (int)ch << " ";
        cout << endl;
    }
    else if(argc==5)
    {
        temp.buffer[0]=(unsigned char)(stoi(argv[1]));
        temp.buffer[1]=(unsigned char)(stoi(argv[2]));
        temp.buffer[2]=(unsigned char)(stoi(argv[3]));
        temp.buffer[3]=(unsigned char)(stoi(argv[4]));
        cout << temp.fl<< endl;
    }
    return EXIT_SUCCESS;
}