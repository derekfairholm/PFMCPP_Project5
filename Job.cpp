#include "Job.h"

Job::Job() :
    startingSalaryUsd(70000),
    canWorkRemotely(true)
{ 
    employeeBenefits = { EmployeeBenefit(2500), EmployeeBenefit(5000), EmployeeBenefit(1500) };
}

Job::~Job() { }

Job::EmployeeBenefit::EmployeeBenefit(double value) :
    monetaryValue(value),
    isActiveBenefit(true)
{ }

double Job::monetaryValueOfBenefits()
{
    double value = 0;

    for(unsigned long i = 0; i < employeeBenefits.size(); ++i)
    {
        value += employeeBenefits[i].monetaryValue; // recieving a warning here: "implicit conversion changes signedness: 'int' to 'std::vector::size_type' (aka 'unsigned long')" not sure how to handle it.
    }
    return value;
}

void Job::printMonetaryValueOfBenefits() 
{ 
    std::cout << "Value of benefits is: $" << this->monetaryValueOfBenefits() << std::endl; 
}

void Job::quitJob()
{
    std::cout << "Congratulations! You quit your job that paid: $" << this->startingSalaryUsd << " per year!" << std::endl;
}
