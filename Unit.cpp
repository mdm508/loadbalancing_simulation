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

//initialize static member
int Unit::classId = 0;

Unit::Unit(Unit* predecessor)
: predecessor(predecessor), successor(0)
{

    this->id = ++ Unit::classId;
    this->load = load_dis(genL);
    scheduleAppointment();
}

Unit::Unit()
: predecessor(0), successor(0)
{
    this->id = ++ Unit::classId;
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

int Unit::getId() const{
    return this->id;
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


