/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
 
 2) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 1a) & 1b)
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //3)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //3)
        mf.memberFunc();
        return 0;
    }
}


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
    ~House() {}
    unsigned int numberOfBedrooms { 3 };
    unsigned int numberOfBathrooms { 2 };
    unsigned int totalSquareFootage;
    double currentMarketValueUsd;
    bool hasGarage;
    bool availableForRent;

    void numberBedsAndBaths() 
    { 
        std::cout << "This house has " << this->numberOfBedrooms << " bedrooms and " << this->numberOfBathrooms << " bathrooms." << std::endl;
    }

    double estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd );

    double projectedValue( int yearsFromCurrentDate, double annualGrowthPercantage )
    {
        double projectedValue = currentMarketValueUsd;
        for( int i = 0; i < yearsFromCurrentDate; i += 1 )
        {
            projectedValue += currentMarketValueUsd * annualGrowthPercantage;
        }
        std::cout << "In " << yearsFromCurrentDate << " years, the value of this home will have gone from $" << this->currentMarketValueUsd << " to $" << projectedValue << " assuming a " << (annualGrowthPercantage * 100) << " percent annual growth in value." << std::endl;
        return projectedValue;
    }

    void sellHouse() { std::cout << "Sold house for market value of: $" << this->currentMarketValueUsd << std::endl; }

    void printEstimatedMortgagePayment() { std::cout << "Estimated mortgage payment: $" << this->estimatedMortgagePayment( 0.042, 30, 20000 ) << std::endl; }
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
    ~Job() {}
    
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
        return value;
    }

    void printMonetaryValueOfBenefits() { std::cout << "Value of benefits is: $" << this->monetaryValueOfBenefits() << std::endl; }

    void quitJob()
    {
        std::cout << "Congratulations! You quit your job that paid: $" << this->startingSalaryUsd << " per year!" << std::endl;
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
    ~Circle() {} 

    double getCircumference();
    double getArea();

    void drawCircle()
    {
        std::cout << "Drawing new circle with radius: " << this->radius << std::endl;
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

    void printCircumference()
    {
        std::cout << "The diameter is: " << this->diameter << " and the circumference is: " << this->getCircumference() << std::endl;
    }

    void printArea() { std::cout << "Area is: " << this->getArea() << std::endl; }
};

double Circle::getCircumference() { return M_PI * this->diameter; }

double Circle::getArea() { return M_PI * (pow(radius, 2)); }

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
        this->house.sellHouse();
        this->job.quitJob();
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
        std::cout << "This shape contained " << this->circles.size() << " cirlces." << std::endl;
    }
};

// 

//////////////////////////

int main()
{
	Example::main();
    //1
    std::cout << "-----------UTD: House---------------" << std::endl;
    House myHouse;
    std::cout << "This house has " << myHouse.numberOfBedrooms << " bedrooms and " << myHouse.numberOfBathrooms << " bathrooms." << std::endl;
    myHouse.numberBedsAndBaths();
    std::cout << "Estimated mortgage payment: $" << myHouse.estimatedMortgagePayment( 0.042, 30, 20000 ) << std::endl;
    myHouse.printEstimatedMortgagePayment();
    //2
    std::cout << "-----------UTD: Job---------------" << std::endl;
    Job myJob;
    std::cout << "Value of benefits is: $" << myJob.monetaryValueOfBenefits() << std::endl;
    myJob.printMonetaryValueOfBenefits();
    //3
    std::cout << "-----------UTD: Circle---------------" << std::endl;
    Circle myCircle(5, 10, 10);
    std::cout << "The diameter is: " << myCircle.diameter << " and the circumference is: " << myCircle.getCircumference() << std::endl;
    myCircle.printCircumference();
    std::cout << "Area is: " << myCircle.getArea() << std::endl;
    myCircle.printArea();
    //4
    std::cout << "-----------UTD: Person---------------" << std::endl;
    Person myPerson;
    //5
    std::cout << "-----------UTD: Shape---------------" << std::endl;
    Shape myShape;
    std::cout << "good to go!" << std::endl;
    std::cout << "-----------UTD Deconstructors---------------" << std::endl;
}
