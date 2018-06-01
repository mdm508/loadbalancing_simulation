//UnitList.hpp

/*
TODO
todo: implement the UnitList clzss
todo: insert  
todo: constructor
todo: destructor
todo: pop
todo: transfer_load 
*/

#ifndef UNITLIST_HPP
#define UNITLIST_HPP
#include "Unit.hpp"

class UnitList{
    private:
        int length;

    public:
        Unit* schedHead;
        Unit* ringHead; 
        //@: k is the number of units to initialize in the unit listF
        //result: a circular unit list consisting of k units is initialized.
        UnitList(int k);

        //@: k is number of units to initialize 
        //result: a ring of k units is initialized
        //result: this order never changes 
        void initRing(int k);

        //result: uses ring to create a schedule where elements with
        //result: lower appointment times are earlier in the list
        void initSchedule();

        //@: unit is a unit pointer
        //result: unit inserted in order with key=time
        void insert(Unit* unit);

        //result: the unit pointed to by head is popped and returned. 
        Unit pop();


        //result: head unit tries to balance its load with its
        //result: predecessor and successor. Its popped
        //result: then reinserted into list with new schedule
        void tryToBalance();

        //Outputrelated

        //result: prints a representation of the ring 
        void printRing ();
        
        //result: print current schedule 
        void printSchedule();

};

//helper function
//@: l1,l2,l3 are the three loads to use in avg calc
//result: returns the average of the three loads
double averageLoad(int l1,int l2, int l3);

//result: prints the list according the annecsstor
void printRing (Unit* unitHead, int k);

//result: prints list according to the schedule
void printSchedule();

// Output related helpers
//result: print unit in format specified below
void print(Unit* unit, int id);





#endif //UNITLIST_HPP