#include "Theatre.h"

Theatre::Theatre()
{
    for(int i = 1; i < 16; ++i)
        for(int j = 1; j < 11; ++j)
        {
            tickets[i*(11-j) - 1] = Ticket(11-j,i, 0.0, false);
        }
    for (int i = 0; i < 150; ++i) tickets[i].setPrice();
}

/*void Theatre::sellTicket(Ticket t)
{
    

}*/



void Ticket::setPrice()
{
    if (seat == 0 || row == 0) return;
    price = 10.0 + 0.5 * (seat-1) + 1.0 * (row - 1) ;
}

std::string Ticket::toString()
{
    std::ostringstream os;
    os << "row: " << row << " seat: " << seat << "\noccupied: " << occupied
            << "\nprice: "<<price<<"\n";
    return os.str();
}