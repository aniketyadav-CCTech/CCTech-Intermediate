// Check if the given number is a Prime number. Follow the TDD approach.

#include <iostream>
#include <cassert>

bool isPrime(int Candidate_Int)
{
    if(Candidate_Int <= 1) return false;
    for(int i=2;i<=Candidate_Int/2;i++)
        if(Candidate_Int%i==0)
            return false;
    return true;
}

int main(int argc, char* argv[])
{
    assert(isPrime(-1)==false);
    assert(isPrime(1)==false);
    assert(isPrime(2)==true);
    assert(isPrime(4)==false);
    assert(isPrime(5)==true);
    return EXIT_SUCCESS;
}

