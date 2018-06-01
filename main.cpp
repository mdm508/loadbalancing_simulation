//main.cpp
/*
todo: write the mainloop
*/



#include "UnitList.hpp"
#include "Write.hpp"
#include <iostream>
using namespace std;


int main(){
    UnitList list = UnitList(4);
    list.printRing();
    cout << endl << endl;
    list.printSchedule();
    return 0;

}