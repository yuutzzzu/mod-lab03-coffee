// Copyright 2024 <Copyright Owner>
#pragma once
#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>

enum STATES {
    OFF,
    WAITING_FOR_COIN,
    WAITING_FOR_CHOICE,
    COOKING,
    FINISHED
};

class Automata {
private:
    double cash;
    std::vector<std::string> menu;
    std::vector<double> prices;
    STATES state;

public:
    Automata();

    void on();
    void off();

    void coin(double amount);

    std::string getMenu();
    STATES getState();

    void choice(int index);
    bool check(int index);

    void cook();
    void finish();

    void cancel();

    double getCash();
};

#endif  // AUTOMATA_H
