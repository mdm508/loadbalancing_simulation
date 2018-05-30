//Unit.hpp
#ifndef UNIT_HPP
#define UNIT_HPP

class Unit{
    private:
        int appointment;
        int load;
        Unit* prev;
        Unit* next;
    public:
        Unit(Unit* prev,Unit* next);
        Unit();
        //getters
        int getAppointment() const;
        int getLoad() const;
        Unit* getPrev() ;
        Unit* getNext();
        //setters
        void scheduleAppointment();
        void setLoad(int load);
        void setPrev(Unit* prev);
        void setNext(Unit* next);
};
#endif //UNIT_HPP