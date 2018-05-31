//Unit.cpp

#include "Unit.hpp"
#include <random>

// Random Number Generators
std::random_device rdT; //used as a seed for time_dis
std::random_device rdL; //used as seed for load_dis

std::mt19937 genT(rdT()); //Standard mersenne_twister_engine seeded with rdT()
std::mt19937 genL(rdL()); 

std::uniform_int_distribution<int> time_dis(100, 1000);
std::uniform_int_distribution<int> load_dis(10,1000);


Unit::Unit(Unit* prev,Unit* next)
: prev(prev), next(next) 
{
    //initialze load to a random number in
    //the interval [10,1000]
    this->load = load_dis(genL);
    scheduleAppointment();
}

Unit::Unit()
{
    this->prev = 0;
    this->next = 0; 
    this->load = load_dis(genL);
}


Unit::Unit(Unit prev, next)
: prev(prev), next(next)
{
    this->load = load_dis(genL);
    scheduleAppointment();
}


//getters
int Unit::getAppointment() const {
    return this->appointment;
}

int Unit::getLoad() const {
    return this->load;
}

//setters
void Unit::scheduleAppointment(){
    //use time_dis to transform the randomly generated number
    //to one in interval [100,1000]
    this->appointment = time_dis(genT); 
}

void Unit::setLoad(int load){
    this->load = load;
}


/*
?: do we need this
void Unit::setPrev(Unit* prev){
}
void Unit::setNext(Unit* next){
}
*/