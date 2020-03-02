#pragma once

#include "LeakedObjectDetector.h"

struct House 
{
    House();
    ~House();

    // Memeber functions

    void numberBedsAndBaths();
    double estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd );
    double projectedValue( int yearsFromCurrentDate, double annualGrowthPercantage );
    void sellHouse();
    void printEstimatedMortgagePayment();

    // Memeber Variables

    unsigned int numberOfBedrooms;
    unsigned int numberOfBathrooms;
    unsigned int totalSquareFootage;
    double currentMarketValueUsd;
    bool hasGarage;
    bool availableForRent;

    JUCE_LEAK_DETECTOR(House)
};
