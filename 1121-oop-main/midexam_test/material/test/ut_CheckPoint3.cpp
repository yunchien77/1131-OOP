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

TEST(CheckPoint3,
     TestAmarettoSourSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    AmarettoSour amarettoSour;

    amarettoSour.SetAlcoholContent(50);

    ASSERT_EQ(amarettoSour.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestAmarettoSourSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    AmarettoSour amarettoSour;

    ASSERT_THROW(amarettoSour.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestAmarettoSourGetQualityShouldReturnCorrectQuality) {
    AmarettoSour amarettoSour;

    ASSERT_EQ(amarettoSour.GetQuality(), 2500);
}

TEST(CheckPoint3,
     TestCowboyShotSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    CowboyShot cowboyShot;

    cowboyShot.SetAlcoholContent(50);

    ASSERT_EQ(cowboyShot.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestCowboyShotSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    CowboyShot cowboyShot;

    ASSERT_THROW(cowboyShot.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestCowboyShotGetQualityShouldReturnCorrectQuality) {
    CowboyShot cowboyShot;

    ASSERT_EQ(cowboyShot.GetQuality(), 2560);
}

TEST(CheckPoint3, TestCraftBeerGetQualityShouldReturnCorrectQuality) {
    CraftBeer craftBeer;

    ASSERT_EQ(craftBeer.GetQuality(), 1465);
}

TEST(CheckPoint3,
     TestFireballSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Fireball fireball;

    fireball.SetAlcoholContent(50);

    ASSERT_EQ(fireball.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestFireballSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Fireball fireball;

    ASSERT_THROW(fireball.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestFireballGetQualityShouldReturnCorrectQuality) {
    Fireball fireball;

    ASSERT_EQ(fireball.GetQuality(), 2810);
}

TEST(CheckPoint3,
     TestGoldschlagerSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Goldschlager goldschlager;

    goldschlager.SetAlcoholContent(50);

    ASSERT_EQ(goldschlager.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestGoldschlagerSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Goldschlager goldschlager;

    ASSERT_THROW(goldschlager.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestGoldschlagerGetQualityShouldReturnCorrectQuality) {
    Goldschlager goldschlager;

    ASSERT_EQ(goldschlager.GetQuality(), 1310);
}

TEST(CheckPoint3, TestHefeweizenGetQualityShouldReturnCorrectQuality) {
    Hefeweizen hefeweizen;

    ASSERT_EQ(hefeweizen.GetQuality(), 1465);
}

TEST(CheckPoint3, TestIPAGetQualityShouldReturnCorrectQuality) {
    IPA ipa;

    ASSERT_EQ(ipa.GetQuality(), 1965);
}

TEST(CheckPoint3, TestLagerGetQualityShouldReturnCorrectQuality) {
    Lager lager;

    ASSERT_EQ(lager.GetQuality(), 1215);
}

TEST(CheckPoint3,
     TestMargaritaSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Margarita margarita;

    margarita.SetAlcoholContent(50);

    ASSERT_EQ(margarita.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestMargaritaSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Margarita margarita;

    ASSERT_THROW(margarita.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestMargaritaGetQualityShouldReturnCorrectQuality) {
    Margarita margarita;

    ASSERT_EQ(margarita.GetQuality(), 2250);
}

TEST(CheckPoint3,
     TestMartiniSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Martini martini;

    martini.SetAlcoholContent(50);

    ASSERT_EQ(martini.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestMartiniSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Martini martini;

    ASSERT_THROW(martini.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestMartiniGetQualityShouldReturnCorrectQuality) {
    Martini martini;

    ASSERT_EQ(martini.GetQuality(), 2400);
}

TEST(CheckPoint3,
     TestMojitoSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Mojito mojito;

    mojito.SetAlcoholContent(50);

    ASSERT_EQ(mojito.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestMojitoSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Mojito mojito;

    ASSERT_THROW(mojito.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestMojitoGetQualityShouldReturnCorrectQuality) {
    Mojito mojito;

    ASSERT_EQ(mojito.GetQuality(), 2150);
}

TEST(CheckPoint3, TestRumSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Rum rum;

    rum.SetAlcoholContent(50);

    ASSERT_EQ(rum.GetAlcoholContent(), 50);
}

TEST(CheckPoint3, TestRumSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Rum rum;

    ASSERT_THROW(rum.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestRumGetQualityShouldReturnCorrectQuality) {
    Rum rum;

    ASSERT_EQ(rum.GetQuality(), 3810);
}

TEST(CheckPoint3, TestStoutGetQualityShouldReturnCorrectQuality) {
    Stout stout;

    ASSERT_EQ(stout.GetQuality(), 1715);
}

TEST(CheckPoint3,
     TestTequilaSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Tequila tequila;

    tequila.SetAlcoholContent(50);

    ASSERT_EQ(tequila.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestTequilaSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Tequila tequila;

    ASSERT_THROW(tequila.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestTequilaGetQualityShouldReturnCorrectQuality) {
    Tequila tequila;

    ASSERT_EQ(tequila.GetQuality(), 3310);
}

TEST(CheckPoint3,
     TestWildfireSetAlcoholWithValidValueShouldChangeAlcoholContent) {
    Wildfire wildfire;

    wildfire.SetAlcoholContent(50);

    ASSERT_EQ(wildfire.GetAlcoholContent(), 50);
}

TEST(CheckPoint3,
     TestWildfireSetAlcoholWithInvalidValueShouldThrowInvalidArgument) {
    Wildfire wildfire;

    ASSERT_THROW(wildfire.SetAlcoholContent(400), std::invalid_argument);
}

TEST(CheckPoint3, TestWildfireGetQualityShouldReturnCorrectQuality) {
    Wildfire wildfire;

    ASSERT_EQ(wildfire.GetQuality(), 2000);
}