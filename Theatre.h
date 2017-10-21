#ifndef THEATRE_H
#define THEATRE_H
#include <string>
#include <sstream>
#include <iostream>


class Ticket {
public:
    Ticket() : row{0}, seat{0}, price{0.0}, occupied{false} {}
    Ticket(int ro, int se, double pr = 0.0, bool occ = false) : row{ro}, seat{se}, price{pr}, occupied{occ} {}
    bool isOccupied() {return occupied;}
    std::string toString();
    
    void setRow(int);
    void setSeat(int);
    void setOccupied(bool);
    void setPrice();
    inline int getRow(){return row;}
    inline int getSeat(){return seat;}
    inline double getPrice() {return price;}
        
private:
    int row;
    int seat;
    double price;
    bool occupied;
};


class Theatre{
public:
    const static int numberOfTickets = 150;
    Theatre();
    bool sellTicket(Ticket);
    void sortByPrice();
    void sortBySeat();
    int numberOfSoldTickets();
    double totalRevenues();
    std::string soldTickets();
    std::string showSeats();
    

private:
    Ticket tickets[numberOfTickets];
};


#endif /* THEATRE_H */

