// Copyright 2024 <Copyright Owner>
#include "Automata.h"
#include <sstream>
#include <string>

Automata::Automata() {
    cash = 0;
    state = OFF;

    menu = { "Tea", "Coffee", "Milk" };
    prices = { 1.5, 2.0, 1.0 };
}

void Automata::on() {
    if (state == OFF) {
        state = WAITING_FOR_COIN;
    }
}

void Automata::off() {
    state = OFF;
    cash = 0;
}

void Automata::coin(double amount) {
    if (amount > 0 && (state == WAITING_FOR_COIN ||
                       state == WAITING_FOR_CHOICE)) {
        cash += amount;
        if (state == WAITING_FOR_COIN) {
            state = WAITING_FOR_CHOICE;
        }
    }
}

std::string Automata::getMenu() {
    std::stringstream out;

    for (int i = 0; i < static_cast<int>(menu.size()); i++) {
        out << i << ": " << menu[i]
            << " - " << prices[i] << "\n";
    }

    return out.str();
}

STATES Automata::getState() {
    return state;
}

double Automata::getCash() {
    return cash;
}

bool Automata::check(int index) {
    if (index < 0 || index >= static_cast<int>(prices.size())) {
        return false;
    }
    return cash >= prices[index];
}

void Automata::choice(int index) {
    if (state != WAITING_FOR_CHOICE) return;

    if (check(index)) {
        state = COOKING;
        cook();
    }
}

void Automata::cook() {
    if (state == COOKING) {
        state = FINISHED;
    }
}

void Automata::finish() {
    if (state == FINISHED) {
        cash = 0;
        state = WAITING_FOR_COIN;
    }
}

void Automata::cancel() {
    if (state == WAITING_FOR_COIN || state == WAITING_FOR_CHOICE) {
        cash = 0;
        state = WAITING_FOR_COIN;
    }
}
