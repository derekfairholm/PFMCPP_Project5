#include "House.h"
#include <cmath>

House::House() :
    numberOfBedrooms(3),
    numberOfBathrooms(2),
    totalSquareFootage(2000),
    currentMarketValueUsd(250000.00),
    hasGarage(true),
    availableForRent(false)
{ }

House::~House() { }

void House::numberBedsAndBaths() 
{ 
    std::cout << "This house has " << this->numberOfBedrooms << " bedrooms and " << this->numberOfBathrooms << " bathrooms." << std::endl;
}

double House::estimatedMortgagePayment(double interestRate, double term, double downpaymentUsd)
{
    double principalLoanAmount = currentMarketValueUsd - downpaymentUsd;
    double monthlyInterestRate = interestRate / 12;
    double totalNumberOfPayments = term * 12;
    double estimate = (principalLoanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalNumberOfPayments));

    return estimate;
}

double House::projectedValue(int yearsFromCurrentDate, double annualGrowthPercantage)
{
    double projectedValue = currentMarketValueUsd;
    for(int i = 0; i < yearsFromCurrentDate; i += 1)
    {
        projectedValue += currentMarketValueUsd * annualGrowthPercantage;
    }
    std::cout << "In " << yearsFromCurrentDate << " years, the value of this home will have gone from $" << this->currentMarketValueUsd << " to $" << projectedValue << " assuming a " << (annualGrowthPercantage * 100) << " percent annual growth in value." << std::endl;
    return projectedValue;
}

void House::sellHouse() 
{ 
    std::cout << "Sold house for market value of: $" << this->currentMarketValueUsd << std::endl; 
}

void House::printEstimatedMortgagePayment() 
{ 
    std::cout << "Estimated mortgage payment: $" << this->estimatedMortgagePayment( 0.042, 30, 20000 ) << std::endl; 
} 
