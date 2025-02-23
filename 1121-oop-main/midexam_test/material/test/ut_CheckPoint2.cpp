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

TEST(CheckPoint2,
     TestAmarettoSourGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    AmarettoSour amarettoSour;

    ASSERT_EQ(amarettoSour.GetAlcoholContent(), 30);
}

TEST(CheckPoint2, TestAmarettoSourGetToppingShouldReturnCorrectTopping) {
    AmarettoSour amarettoSour;

    ASSERT_EQ(amarettoSour.GetTopping(),
              std::vector<std::string>{"OrangePiece"});
}

TEST(CheckPoint2, TestAmarettoSourGetPriceShouldReturn500) {
    AmarettoSour amarettoSour;

    ASSERT_EQ(amarettoSour.GetPrice(), 500);
}

TEST(CheckPoint2,
     TestCowboyShotGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    CowboyShot cowboyShot;

    ASSERT_EQ(cowboyShot.GetAlcoholContent(), 30);
}

TEST(CheckPoint2, TestCowboyShotGetPriceShouldReturnCorrectPrice) {
    CowboyShot cowboyShot;

    ASSERT_EQ(cowboyShot.GetPrice(), 600);
}

TEST(CheckPoint2,
     TestCraftBeerGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    CraftBeer craftBeer;

    ASSERT_EQ(craftBeer.GetAlcoholContent(), 5);
}

TEST(CheckPoint2, TestCraftBeerGetPriceShouldReturnCorrectPrice) {
    CraftBeer craftBeer;

    ASSERT_EQ(craftBeer.GetPrice(), 400);
}

TEST(CheckPoint2,
     TestFireballGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Fireball fireball;

    ASSERT_EQ(fireball.GetAlcoholContent(), 20);
}

TEST(CheckPoint2, TestFireballGetPriceShouldReturnCorrectPrice) {
    Fireball fireball;

    ASSERT_EQ(fireball.GetPrice(), 800);
}

TEST(CheckPoint2,
     TestGoldschlagerGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Goldschlager goldschlager;

    ASSERT_EQ(goldschlager.GetAlcoholContent(), 20);
}

TEST(CheckPoint2, TestGoldschlagerGetPriceShouldReturnCorrectPrice) {
    Goldschlager goldschlager;

    ASSERT_EQ(goldschlager.GetPrice(), 200);
}

TEST(CheckPoint2,
     TestHefeweizenGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Hefeweizen hefeweizen;

    ASSERT_EQ(hefeweizen.GetAlcoholContent(), 5);
}

TEST(CheckPoint2, TestHefeweizenGetPriceShouldReturnCorrectPrice) {
    Hefeweizen hefeweizen;

    ASSERT_EQ(hefeweizen.GetPrice(), 400);
}

TEST(CheckPoint2, TestIPAGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    IPA ipa;

    ASSERT_EQ(ipa.GetAlcoholContent(), 5);
}

TEST(CheckPoint2, TestIPAGetPriceShouldReturnCorrectPrice) {
    IPA ipa;

    ASSERT_EQ(ipa.GetPrice(), 600);
}

TEST(CheckPoint2, TestLagerGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Lager lager;

    ASSERT_EQ(lager.GetAlcoholContent(), 5);
}

TEST(CheckPoint2, TestLagerGetPriceShouldReturnCorrectPrice) {
    Lager lager;

    ASSERT_EQ(lager.GetPrice(), 300);
}

TEST(CheckPoint2,
     TestMargaritaiGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Margarita margarita;

    ASSERT_EQ(margarita.GetAlcoholContent(), 30);
}

TEST(CheckPoint2, TestMargaritaGetToppingShouldReturnCorrectTopping) {
    Margarita margarita;

    ASSERT_EQ(margarita.GetTopping(), std::vector<std::string>{"Lemon"});
}

TEST(CheckPoint2, TestMargaritaGetPriceShouldReturn400) {
    Margarita margarita;

    ASSERT_EQ(margarita.GetPrice(), 400);
}

TEST(CheckPoint2,
     TestMartiniGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Martini martini;

    ASSERT_EQ(martini.GetAlcoholContent(), 30);
}

TEST(CheckPoint2, TestMartiniGetToppingShouldReturnEmptyVector) {
    Martini martini;

    ASSERT_EQ(martini.GetTopping(), std::vector<std::string>());
}

TEST(CheckPoint2, TestMartiniGetPriceShouldReturn500) {
    Martini martini;

    ASSERT_EQ(martini.GetPrice(), 500);
}

TEST(CheckPoint2,
     TestMojitoGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Mojito mojito;

    ASSERT_EQ(mojito.GetAlcoholContent(), 30);
}

TEST(CheckPoint2, TestMojitoGetToppingShouldReturnEmptyVector) {
    Mojito mojito;

    ASSERT_EQ(mojito.GetTopping(), std::vector<std::string>());
}

TEST(CheckPoint2, TestMojitoGetPriceShouldReturn400) {
    Mojito mojito;

    ASSERT_EQ(mojito.GetPrice(), 400);
}

TEST(CheckPoint2, TestRumGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Rum rum;

    ASSERT_EQ(rum.GetAlcoholContent(), 60);
}

TEST(CheckPoint2, TestRumGetPriceShouldReturnCorrectPrice) {
    Rum rum;

    ASSERT_EQ(rum.GetPrice(), 800);
}

TEST(CheckPoint2, TestStoutGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Stout stout;

    ASSERT_EQ(stout.GetAlcoholContent(), 5);
}

TEST(CheckPoint2, TestStoutGetPriceShouldReturnCorrectPrice) {
    Stout stout;

    ASSERT_EQ(stout.GetPrice(), 500);
}

TEST(CheckPoint2,
     TestTequilaGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Tequila tequila;

    ASSERT_EQ(tequila.GetAlcoholContent(), 40);
}

TEST(CheckPoint2, TestTequilaGetPriceShouldReturn300) {
    Tequila tequila;

    ASSERT_EQ(tequila.GetPrice(), 800);
}

TEST(CheckPoint2,
     TestWildfireGetAlcoholContentShouldReturnCorrectAlcoholContent) {
    Wildfire wildfire;

    ASSERT_EQ(wildfire.GetAlcoholContent(), 30);
}

TEST(CheckPoint2, TestWildfireGetToppingShouldReturnCorrectTopping) {
    Wildfire wildfire;

    ASSERT_EQ(wildfire.GetTopping(),
              (std::vector<std::string>{"CinnamonWhiskey", "AppleJuice"}));
}

TEST(CheckPoint2, TestWildfireGetPriceShouldReturn300) {
    Wildfire wildfire;

    ASSERT_EQ(wildfire.GetPrice(), 300);
}