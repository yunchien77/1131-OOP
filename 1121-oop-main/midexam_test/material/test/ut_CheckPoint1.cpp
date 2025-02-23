#include <gtest/gtest.h>

#include "AmarettoSour.h"
#include "CowboyShot.h"
#include "CraftBeer.h"
#include "Fireball.h"
#include "Goldschlager.h"
#include "Hefeweizen.h"
#include "IPA.h"
#include "Lager.h"
#include "Margarita.h"
#include "Martini.h"
#include "Mojito.h"
#include "Rum.h"
#include "Stout.h"
#include "Tequila.h"
#include "Wildfire.h"

TEST(CheckPoint1, TestAmarettoSourGetTypeShouldReturnCorrectType){
    AmarettoSour amarettoSour;

    ASSERT_EQ(amarettoSour.GetType(), "Cocktail");
}

TEST(CheckPoint1, TestCowboyShotGetTypeShouldReturnCorrectType){
    CowboyShot cowboyShot;

    ASSERT_EQ(cowboyShot.GetType(), "Shot");
}

TEST(CheckPoint1, TestCraftBeerGetTypeShouldReturnCorrectType){
    CraftBeer craftBeer;

    ASSERT_EQ(craftBeer.GetType(), "Beer");
}

TEST(CheckPoint1, TestFireballGetTypeShouldReturnCorrectType){
    Fireball fireball;

    ASSERT_EQ(fireball.GetType(), "Shot");
}

TEST(CheckPoint1, TestGoldschlagerGetTypeShouldReturnCorrectType){
    Goldschlager goldschlager;

    ASSERT_EQ(goldschlager.GetType(), "Shot");
}

TEST(CheckPoint1, TestHefeweizenGetTypeShouldReturnCorrectType){
    Hefeweizen hefeweizen;

    ASSERT_EQ(hefeweizen.GetType(), "Beer");
}

TEST(CheckPoint1, TestIPAGetTypeShouldReturnCorrectType){
    IPA ipa;

    ASSERT_EQ(ipa.GetType(), "Beer");
}

TEST(CheckPoint1, TestLagerGetTypeShouldReturnCorrectType){
    Lager lager;

    ASSERT_EQ(lager.GetType(), "Beer");
}

TEST(CheckPoint1, TestMargaritaGetTypeShouldReturnCorrectType){
    Margarita margarita;

    ASSERT_EQ(margarita.GetType(), "Cocktail");
}

TEST(CheckPoint1, TestMartiniGetTypeShouldReturnCorrectType){
    Martini martini;

    ASSERT_EQ(martini.GetType(), "Cocktail");
}

TEST(CheckPoint1, TestMojitoGetTypeShouldReturnCorrectType){
    Mojito mojito;

    ASSERT_EQ(mojito.GetType(), "Cocktail");
}

TEST(CheckPoint1, TestRumGetTypeShouldReturnCorrectType){
    Rum rum;

    ASSERT_EQ(rum.GetType(), "Shot");
}

TEST(CheckPoint1, TestStoutGetTypeShouldReturnCorrectType){
    Stout stout;

    ASSERT_EQ(stout.GetType(), "Beer");
}

TEST(CheckPoint1, TestTequilaGetTypeShouldReturnCorrectType){
    Tequila tequila;

    ASSERT_EQ(tequila.GetType(), "Shot");
}

TEST(CheckPoint1, TestWildfireGetTypeShouldReturnCorrectType){
    Wildfire wildfire;

    ASSERT_EQ(wildfire.GetType(), "Cocktail");
}
