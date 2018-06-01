//Unit.hpp
#ifndef UNIT_HPP
#define UNIT_HPP

class Unit{
    private:
        int appointment;
        int load;
        int id;
    public:
        static int classId;
        // maintains ordering of schedule
        Unit* prev;
        Unit* next;
        // will be needed by UnitList
        // maintains neigbors
        Unit* predecessor;
        Unit* successor;

        Unit(Unit* predecessor);
        Unit();
        //getters
        int getAppointment() const;
        int getLoad() const;
        Unit* getPrev() ;
        Unit* getNext();
        int getId() const;
        //setters
        void scheduleAppointment();
        void setLoad(int load);

    

};


#endif //UNIT_HPP