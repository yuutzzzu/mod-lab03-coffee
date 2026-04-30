// Copyright 2024 <Copyright Owner>
#include "Automata.h"
#include <iostream>

int main() {
    Automata a;

    std::cout << "=== Coffee Machine Demo ===" << std::endl;
    std::cout << "Turning on..." << std::endl;
    a.on();
    std::cout << "State: " << a.getState() << std::endl;

    std::cout << "\nMenu:" << std::endl;
    std::cout << a.getMenu();

    std::cout << "\nInserting $2.0..." << std::endl;
    a.coin(2.0);
    std::cout << "Cash: $" << a.getCash() << std::endl;
    std::cout << "State: " << a.getState() << std::endl;

    std::cout << "\nChoosing coffee (index 1)..." << std::endl;
    a.choice(1);

    std::cout << "\nFinishing..." << std::endl;
    a.finish();

    std::cout << "\nTurning off..." << std::endl;
    a.off();

    return 0;
}
