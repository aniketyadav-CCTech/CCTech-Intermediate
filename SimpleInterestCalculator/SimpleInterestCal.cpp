// Using C++ classes implement a Simple Interest Calculator
#include <iostream>
#include <cassert>

class SICalculator
{
public:
    SICalculator(const double& principleAmount, const double& rate,const double& duration);
    double calculateSimpleInterest();
private:
    double m_Principle;
    double m_Rate;
    double m_SimpleInterest;
    double m_Duration;
};
SICalculator::SICalculator(const double& principleAmount = 0, const double& rate = 0,const double& duration = 0):
    m_Principle(principleAmount),m_Rate(rate),m_Duration(duration)
{
    if(m_Principle < 0 || m_Rate < 0 || m_Duration < 0) 
    {
        std::cerr << "Input can't be a negative value\n";
        exit(EINVAL);
    }
}
double SICalculator::calculateSimpleInterest()
{
    m_SimpleInterest = (m_Principle * m_Rate * m_Duration)/100;
    return m_SimpleInterest;
}

int main(int argc, char* argv[])
{
    // double principleAmount, rate, duration;
    // std::cout << "Enter the principle amount (\u20B9) : " ;
    //     std::cin >> principleAmount;
    //     std::cout << "Enter rate of interest (%) : ";
    //     std::cin >> rate;
    //     std::cout << "Enter duration (yrs) : ";
    //     std::cin >> duration;
    // SICalculator si(principleAmount, rate, duration);
    // std::cout << "The Simple interest for the amount " << principleAmount << " for " 
    //         << rate << " years @ " << duration << " % is: " << si.calculateSimpleInterest() << std::endl;
    assert(SICalculator(20000,10,1.5).calculateSimpleInterest()==3000);
    assert(SICalculator(20000,10,1).calculateSimpleInterest()==2000);
    std::cout << "All Tests Passed" << std::endl;
}