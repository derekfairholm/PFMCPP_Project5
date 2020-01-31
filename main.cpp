/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

 Destructors
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

/*
 copied UDT 1:
 */

struct House 
{
    House();
    ~House() { std::cout << "**** House deconstructor ****" << std::endl; }
    unsigned int numberOfBedrooms { 3 };
    unsigned int numberOfBathrooms { 2 };
    unsigned int totalSquareFootage;
    double currentMarketValueUsd;
    bool hasGarage;
    bool availableForRent;

    void numberBedsAndBaths() 
    { 
        std::cout << "This house has " << numberOfBedrooms << " bedrooms and " << numberOfBathrooms << " bathrooms." << std::endl;
    }
    double estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd );

    double projectedValue( int yearsFromCurrentDate, double annualGrowthPercantage )
    {
        double projectedValue = currentMarketValueUsd;
        for( int i = 0; i < yearsFromCurrentDate; i += 1 )
        {
            projectedValue += currentMarketValueUsd * annualGrowthPercantage;
        }
        std::cout << "In " << yearsFromCurrentDate << " years, the value of this home will have gone from $" << currentMarketValueUsd << " to $" << projectedValue << " assuming a " << (annualGrowthPercantage * 100) << " percent annual growth in value." << std::endl;
        return projectedValue;
    }

    void sellHouse() { std::cout << "Sold house for market value of: $" << currentMarketValueUsd << std::endl; }
};

House::House() :
totalSquareFootage(2000),
currentMarketValueUsd(250000.00)
{
    hasGarage = true;
    availableForRent = false;
}

double House::estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd )
{
    double principalLoanAmount = currentMarketValueUsd - downpaymentUsd;
    double monthlyInterestRate = interestRate / 12;
    double totalNumberOfPayments = term * 12;

    double estimate = (principalLoanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalNumberOfPayments));

    std::cout << "Estimated mortgage payment: $" << estimate << std::endl;

    return estimate;
}

/*
 copied UDT 2:
 */

struct Job
{
    double startingSalaryUsd { 70000 };
    bool canWorkRemotely = true;

    Job() {}
    ~Job() { std::cout << "**** Job deconstructor ****" << std::endl; }
    
    struct EmployeeBenefit
    {
        double monetaryValue;
        bool isActiveBenefit;

        EmployeeBenefit( double value ) :
        monetaryValue(value),
        isActiveBenefit(true)
        { }
    };

    double monetaryValueOfBenefits()
    {
        double value = 0;

        for( int i = 0; i < 3; i ++ )
        {
            value += employeeBenefits[i].monetaryValue;
        }
        std::cout << "Value of benefits is: $" << value << std::endl;
        return value;
    }

    void quitJob()
    {
        std::cout << "Congratulations! You quit your job that paid: $" << startingSalaryUsd << " per year!" << std::endl;
    }

    EmployeeBenefit employeeBenefits[3] = { EmployeeBenefit(2500), EmployeeBenefit(5000), EmployeeBenefit(1500) };
};

/*
 copied UDT 3:
 */

struct Circle
{
    double radius;
    double diameter;
    double centerX;
    double centerY;

    Circle( double r, double x, double y ) : 
    radius(r),
    centerX(x),
    centerY(y)
    { 
        diameter = radius * 2.0; 
    }
    ~Circle() { std::cout << "**** Circle deconstructor ****" << std::endl; } 

    double getCircumference();
    double getArea();

    void drawCircle()
    {
        std::cout << "Drawing new circle with radius: " << radius << std::endl;
        // A hypothetical function that would render a circle with a given radius.
    }

    void drawConcentricCircles( double startingRadius, double maxRadius, double numberOfCircles, double centerX_, double centerY_ )
    {
        double currentRadius = startingRadius;
        double increment = (maxRadius - startingRadius) / (numberOfCircles - 1.0);

        while ( currentRadius <= maxRadius + 0.0001 )
        {
            Circle c(currentRadius, centerX_, centerY_);
            c.drawCircle();
            currentRadius += increment;
        }
    }
};

double Circle::getCircumference()
{
    double circumference = M_PI * diameter;
    std::cout << "The diameter is: " << diameter << " and the circumference is: " << circumference << std::endl;
    return M_PI * diameter;
}

double Circle::getArea()
{
    double area = M_PI * (pow(radius, 2));
    std::cout << "Area is: " << area << std::endl;
    return M_PI * (pow(radius, 2));
}

/*
 new UDT 4:
 */

struct Person 
{
    House house;
    Job job;

    Person() {}
    ~Person() 
    {
        house.sellHouse();
        job.quitJob();
        std::cout << "**** Person deconstructor ****" << std::endl;
    }
};

/*
 new UDT 5:
 */

struct Shape 
{
    std::vector<Circle> circles
    {
        Circle(4,6,8), 
        Circle(2,3,7),
        Circle(6,8,2)
    };

    Shape() {}
    ~Shape() 
    {
        std::cout << "This shape contained " << circles.size() << " cirlces." << std::endl;
    }
};

// 

//////////////////////////

int main()
{
    //1
    std::cout << "-----------UTD: House---------------" << std::endl;
    House myHouse;
    //2
    std::cout << "-----------UTD: Job---------------" << std::endl;
    Job myJob;
    //3
    std::cout << "-----------UTD: Circle---------------" << std::endl;
    Circle myCircle(5, 10, 10);
    //4
    std::cout << "-----------UTD: Person---------------" << std::endl;
    Person myPerson;
    //5
    std::cout << "-----------UTD: Shape---------------" << std::endl;
    Shape myShape;
    std::cout << "good to go!" << std::endl;
}
