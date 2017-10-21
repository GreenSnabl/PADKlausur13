#include "Theatre.h"

int main() {
    
    Theatre t;
    for(int i = 0; i < 150; ++i)
    std::cout << t.tickets[i].toString() << "\n";
    
    t.sortByPrice();
    for(int i = 0; i < 150; ++i)
    std::cout << t.tickets[i].toString() << "\n";
    
    t.sortBySeat();
    for(int i = 0; i < 150; ++i)
    std::cout << t.tickets[i].toString() << "\n";
    

    return 0;
}

