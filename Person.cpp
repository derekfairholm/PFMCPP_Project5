#include "Person.h"

Person::Person() { }
Person::~Person() 
{
    this->house.sellHouse();
    this->job.quitJob();
}
