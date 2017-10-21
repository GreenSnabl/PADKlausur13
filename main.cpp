#include "Theatre.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main() {
    
    std::srand(time(0));
    
    Theatre t;
    std::cout << t.showSeats();
    
    int seat, row;
    while (t.numberOfSoldTickets() < 50)
    {
        seat = std::rand() % 15 + 1;
        row = std::rand() % 10 + 1;
        Ticket tick(row, seat);
        tick.setPrice();
        //std::cout << "ticket row: " << tick.getRow() << " ticket seat: " << tick.getSeat() << " ticket price: " << tick.getPrice() << "\n";
    
        if (!t.sellTicket(tick)) std::cout << "Ihre Auswahl ist leider schon besetzt.\n\n";      
    }
    
    std::cout << t.showSeats();
    t.sortByPrice();
    std::cout << t.soldTickets();
    t.sortBySeat();
    std::cout << t.soldTickets();
    std::cout << t.showSeats();

    return 0;
}

