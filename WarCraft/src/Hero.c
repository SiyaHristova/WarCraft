#include "BasicSpells.h"
#include "UltimateSpells.h"

/* Fills the hero's stats */
void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana, int inputManaRegenRate){
    strcpy(hero->name, inputName);
    hero->maxMana = inputMaxMana;
    hero->currMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
}

/* Fills the hero's spells */
void heroSpellsInit(Hero *hero, void (*basicSpellName)(Hero *hero, short passiveMultiplier),
                    void (*ultimateSpellName)(Hero *hero, short passiveMultiplier)){

    hero->SpellCast[CAST_BASIC_SPELL] = basicSpellName;
    hero->SpellCast[CAST_ULTIMATE_SPELL] = ultimateSpellName;
    hero->SpellCast[REGENERATE_MANA] = &regenerateMana;
}

/* Regenerates the mana of the hero */
void regenerateMana(Hero *hero, short passiveMultiplier){
    hero->currMana += hero->manaRegenRate;
    if(hero->currMana > hero->maxMana){
        hero->currMana = hero->maxMana;
    }
    if(passiveMultiplier){}
}

/* Creates the ArchMage hero */
void createArchMage(Hero *hero){
  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  int manaRegenModifier = 0;
  scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
  heroBaseInit(hero, name, maxMana, manaRegenModifier*baseManaRegenRate);
  heroSpellsInit(hero, &waterElementalCast, &massTeleportCast);
}

/* Creates the DeathKnight hero */
void createDeathKnight(Hero *hero){
  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  heroBaseInit(hero, name, maxMana, baseManaRegenRate);
  heroSpellsInit(hero, &deathCoilCast, &animateDeadCast);
}

/* Creates the DrawRanger hero */
void createDrawRanger(Hero *hero){
  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  heroBaseInit(hero, name, maxMana, baseManaRegenRate);
  heroSpellsInit(hero, &silenceCast, &charmCast);
}