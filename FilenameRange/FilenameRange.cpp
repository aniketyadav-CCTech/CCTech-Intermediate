// Assignment Name: Filename Range

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <fstream>

std::string removePath(const std::string& file_path)    // remove file path i.e. directory
{
    size_t pos = file_path.find_last_of("/\\");
    return file_path.substr(pos+1);
}

std::string removeExtension(const std::string& file_name)   // remove extension from filename
{
    size_t pos = file_name.find_last_of('.');
    return file_name.substr(0,pos);
}

std::string removeSeparators(std::string file_name) // removing separatoes e.g, _ - .
{
    char chars[] = {'_','-','.'};
    for(int i = 0; i < sizeof(chars); ++i)
    {
    auto t = remove(file_name.begin(),file_name.end(),chars[i]);
    file_name.erase(t,file_name.end());
    }
    return file_name;
}

std::string removeWords(std::string file_name)  // exclude words
{
    std::string skipWords[] = {"tests","test","Tests","Test","spec","Spec","steps","step"};
    for(std::string skipWord : skipWords)
    {
        size_t pos = file_name.find(skipWord,0);
        if(pos != std::string::npos)
            file_name.erase(pos,skipWord.length());
    }
    return file_name;
}

std::string getIndex(const std::string& file_path, const std::string& file_name)    // get selected index
{
    int indexArray[2];
    size_t pos = file_path.find(file_name,0);
    indexArray[0]=pos;
    indexArray[1]=pos+file_name.length();
    return std::to_string(indexArray[0]) + " " + std::to_string(indexArray[1]);
}

std::string functCall(std::string file_path)   // caller function 
{
    std::string str = removeWords(removeSeparators(removeExtension(removePath(file_path))));
    return getIndex(file_path,str);
}

void test() // asserts for test cases
{
    assert(functCall("src/Hiker_spec.re")=="4 9");
    assert(functCall("test/hiker_test.exs")=="5 10");
    assert(functCall("wibble/test/hiker_spec.rb")=="12 17");
    assert(functCall("hiker_steps.rb")=="0 5");
    assert(functCall("hiker_spec.rb")=="0 5");
    assert(functCall("test_hiker.rb")=="5 10");
    assert(functCall("test_hiker.py")=="5 10");
    assert(functCall("test_hiker.sh")=="5 10");
    assert(functCall("tests_hiker.sh")=="6 11");
    assert(functCall("test_hiker.coffee")=="5 10");
    assert(functCall("hiker_spec.coffee")=="0 5");
    assert(functCall("hikerTest.chpl")=="0 5");
    assert(functCall("hiker.tests.c")=="0 5");
    assert(functCall("hiker_tests.c")=="0 5");
    assert(functCall("hiker_test.c")=="0 5");
    assert(functCall("hiker_Test.c")=="0 5");
    assert(functCall("HikerTests.cpp")=="0 5");
    assert(functCall("hikerTests.cpp")=="0 5");
    assert(functCall("HikerTest.cs")=="0 5");
    assert(functCall("HikerTest.java")=="0 5");
    assert(functCall("DiamondTest.kt")=="0 7");
    assert(functCall("HikerTest.php")=="0 5");
    assert(functCall("hikerTest.js")=="0 5");
    assert(functCall("hiker-test.js")=="0 5");
    assert(functCall("hiker-spec.js")=="0 5");
    assert(functCall("hiker.test.js")=="0 5");
    assert(functCall("hiker.tests.ts")=="0 5");
    assert(functCall("hiker_tests.erl")=="0 5");
    assert(functCall("hiker_test.clj")=="0 5");
    assert(functCall("fizzBuzz_test.d")=="0 8");
    assert(functCall("hiker_test.go")=="0 5");
    assert(functCall("hiker.tests.R")=="0 5");
    assert(functCall("hikertests.swift")=="0 5");
    assert(functCall("HikerSpec.groovy")=="0 5");
    assert(functCall("hikerSpec.feature")=="0 5");
    assert(functCall("hiker.feature")=="0 5");
    assert(functCall("hiker.fun")=="0 5");
    assert(functCall("hiker.t")=="0 5");
    assert(functCall("hiker.plt")=="0 5");
    assert(functCall("hiker")=="0 5");
    std::cout << "All test Cases Passed" << std::endl;
}

int main(int argc, char* argv[])
{    
    test();
    return EXIT_SUCCESS;
}
