// Copyright 2024 <Copyright Owner>
#include <gtest/gtest.h>
#include <string>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAITING_FOR_COIN);
}

TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.coin(1.0);
    a.off();
    EXPECT_EQ(a.getState(), OFF);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, InsertCoin) {
    Automata a;
    a.on();
    a.coin(2.5);
    EXPECT_EQ(a.getCash(), 2.5);
    EXPECT_EQ(a.getState(), WAITING_FOR_CHOICE);
}

TEST(AutomataTest, CheckValidChoice) {
    Automata a;
    a.on();
    a.coin(2.0);
    EXPECT_TRUE(a.check(1));
}

TEST(AutomataTest, CheckInvalidChoice) {
    Automata a;
    a.on();
    a.coin(1.0);
    EXPECT_FALSE(a.check(1));
}

TEST(AutomataTest, CheckOutOfRangeChoice) {
    Automata a;
    a.on();
    a.coin(2.0);
    EXPECT_FALSE(a.check(5));
    EXPECT_FALSE(a.check(-1));
}

TEST(AutomataTest, MakeChoice) {
    Automata a;
    a.on();
    a.coin(2.0);
    a.choice(1);
    EXPECT_EQ(a.getState(), COOKING);
}

TEST(AutomataTest, CookAndFinish) {
    Automata a;
    a.on();
    a.coin(2.0);
    a.choice(1);
    EXPECT_EQ(a.getState(), COOKING);
    a.cook();  // Добавляем явный вызов cook()
    EXPECT_EQ(a.getState(), FINISHED);
    a.finish();
    EXPECT_EQ(a.getState(), WAITING_FOR_COIN);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, CancelBeforeChoice) {
    Automata a;
    a.on();
    a.coin(2.0);
    a.cancel();
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_EQ(a.getState(), WAITING_FOR_COIN);
}

TEST(AutomataTest, GetMenu) {
    Automata a;
    std::string menu = a.getMenu();
    EXPECT_TRUE(menu.find("Tea") != std::string::npos);
    EXPECT_TRUE(menu.find("Coffee") != std::string::npos);
    EXPECT_TRUE(menu.find("Milk") != std::string::npos);
}

TEST(AutomataTest, CannotChooseWhenOff) {
    Automata a;
    a.choice(1);
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, CannotInsertNegativeCoin) {
    Automata a;
    a.on();
    a.coin(-1.0);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, MultipleCoins) {
    Automata a;
    a.on();
    a.coin(1.0);
    a.coin(0.5);
    EXPECT_EQ(a.getCash(), 1.5);
}
