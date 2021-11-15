#ifndef HERO_H_
#define HERO_H_

#include "Defines.h"

#define MAX_HERO_NAME_SIZE 20
#define MAX_SPELLS 3

typedef struct Hero{
  void (*SpellCast[MAX_SPELLS])(struct Hero *hero, short passiveMultiplier);
  char name[MAX_HERO_NAME_SIZE];
  int maxMana;
  int currMana;
  int manaRegenRate;
}Hero;

void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana, int inputManaRegenRate);

void heroSpellsInit(Hero *hero, void (*basicSpellName)(Hero *hero, short passiveMultiplier),
                    void (*ultimateSpellName)(Hero *hero, short passiveMultiplier));

void regenerateMana(Hero *hero, short passiveMultiplier);

void createArchMage(Hero *hero);

void createDeathKnight(Hero *hero);

void createDrawRanger(Hero *hero);

#endif /* HERO_H_ */