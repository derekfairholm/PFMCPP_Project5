#pragma once

#include <vector>
#include "LeakedObjectDetector.h"

struct Job
{
    Job();
    ~Job();
    
    struct EmployeeBenefit
    {
        double monetaryValue;
        bool isActiveBenefit;

        EmployeeBenefit(double value);
    };

    // Member Functions

    double monetaryValueOfBenefits();
    void printMonetaryValueOfBenefits();
    void quitJob();

    // Member Variables

    double startingSalaryUsd;
    bool canWorkRemotely;
    std::vector<EmployeeBenefit> employeeBenefits;

    JUCE_LEAK_DETECTOR(Job)
};
