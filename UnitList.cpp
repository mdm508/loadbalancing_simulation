//UnitList.cpp
#include "UnitList.hpp"
#include <iostream>

/*
todo: implement the UnitList clzs
todo: insert  
todo: constructor
todo: destructor
todo: transfer_load 
*/

//@: k is the number of units to initialize in the unit listF
//result: a circular unit list consisting of k units is initialized.
UnitList::UnitList(int k)
    : length(k) {
        ringHead = new Unit();
        initRing(k);
        //first unit starts as head of sched list 
        //however after insertions this may change
        schedHead = ringHead;
        schedHead->next = 0;
        schedHead->prev = 0;
        initSchedule();
    }


//@: k is number of units to initialize 
//result: a ring of k units is initialized
//result: the order never changes 
void UnitList::initRing(int k){
    Unit* temp1;
    Unit* temp2;
    temp1 = ringHead;
    for (int i = 0; i < length - 1; ++i){
        //init success of temp2
        temp2 = new Unit(temp1);
        temp1->successor = temp2;
        temp1 = temp2;
    }
    ringHead->predecessor = temp1;
    temp1->successor = ringHead;

}

//result: uses ring to create a schedule where elements with
//result: lower appointment times are earlier in the list
void UnitList::initSchedule(){
    Unit* temp = ringHead;
    do{
        insert(temp);
        temp = temp->successor;
    } while (temp != ringHead);

}

//@: unit is a unit pointer
//result: unit inserted in order with key=time
void UnitList::insert(Unit* unit){
    Unit* temp1 = schedHead;
    while (unit->getAppointment() < temp1->getAppointment() ){
        if (temp1->next == 0){
            break;
        }
        temp1 = temp1->next;
    }
    if (temp1->next == 0){
        temp1->next = unit;
        unit->prev= temp1;
        unit->next = 0;
    }
    else{
        //back up temp1 old previous value
        Unit* temp2 = temp1->prev;
        //make unit and temp1 point to eachother
        //unit becomes the new previous of temp1
        temp1->prev = unit;
        unit->next = temp1;
        unit->prev = temp2;
    }
}

    

//result: the unit pointed to by head is popped and returned. 
Unit UnitList::pop(){
    return Unit();
}

//result: this unit tries to balance its load with its
//result: predecessor and successor
void UnitList::tryToBalance(){

}


//result: prints the list according the annecsstor
void UnitList::printRing (){
    Unit* temp = ringHead;
    //print(ringHead->predecessor,2);
    for (int i = 0; i < length; ++i){
        print(temp,temp->getId());
        temp = temp->successor;
    }
}

void UnitList::printSchedule(){
    Unit* temp = schedHead;
    int i = 0;
    while (i < 10 && temp != 0){
        print(temp,temp->getId());
        std::cout << i << std::endl;
        temp = temp->next;
        ++i;
    }
}

//helper function
//@: l1,l2,l3 are the three loads to use in avg calc
//result: returns the average of the three loads
double averageLoad(int l1,int l2, int l3){
    return 4.0;
}

// Output related helpers
//result: print unit in format specified below
void print(Unit* unit, int id){
    std::cout << "Head: " <<  id << " Load: " << unit->getLoad() << " Appointment: " << unit->getAppointment() << std::endl;
}


//result: prints list according to the schedule
void printSchedule();
