#include "Theatre.h"

Theatre::Theatre()
{
    int cnt = 0;
    for(int i = 1; i < 11; ++i){
        for(int j = 1; j < 16; ++j){
                 tickets[cnt] = Ticket((11-i), j, 0.0, false);
                 ++cnt;}
    }
        
    for (int i = 0; i < 150; ++i) tickets[i].setPrice();
}

bool Theatre::sellTicket(Ticket t)
{
    for(int i = 0; i < 150; ++i)
            if(tickets[i].getRow() == t.getRow() && tickets[i].getSeat() == t.getSeat() && !tickets[i].isOccupied()){
                tickets[i].setOccupied(true);
                return tickets[i].isOccupied();
            } else return false;            
}

void Theatre::sortBySeat()              // bubble sort
{                                       // O(n²)
    Ticket temp;
    for (int n = numberOfTickets; n > 0; --n)
        for (int i = 0; i < n - 1; ++i){
            if(tickets[i].getSeat() + (tickets[i].getRow() * 15) > (tickets[i+1].getSeat() + tickets[i+1].getRow()*15)) 
            {
                temp = tickets[i];
                tickets[i] = tickets[i+1];
                tickets[i+1] = temp;               
            }    
    }
    
}
void Theatre::sortByPrice()             // selection sort
{                                       // O(n²)
    Ticket temp;
    int index;
    for (int i = 0; i < numberOfTickets -2; ++i) {
        temp = tickets[i];
        index = i;
        for(int j = i + 1; j < numberOfTickets - 1; ++j)
            if(tickets[j].getPrice() > temp.getPrice()){ temp = tickets[j]; index = j;}
        tickets[index] = tickets[i];
        tickets[i] = temp;
    }
}


void Ticket::setOccupied(bool occ)
{
    occupied = occ;
}

void Ticket::setPrice()
{
    if (seat == 0 || row == 0) return;
    if(seat < 9) price = 10.0 + 0.5 * (seat-1) + 1.0 * (10 - row);
    else price = 10.0 + 0.5 * (15 - seat) + 1.0 * (10 - row);
}

std::string Ticket::toString()
{
    std::ostringstream os;
    os << "row: " << row << " seat: " << seat << "\noccupied: " << occupied
            << "\nprice: "<<price<<"\n";
    return os.str();
}

