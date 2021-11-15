#include "BasicSpells.h"

/* Casts the WaterElemental spell */
void waterElementalCast(Hero *hero, short passiveMultiplier){
    if(hero->currMana >= ARCHMAGE_BASIC_SPELL_MANA_COST * passiveMultiplier){
        hero->currMana -= ARCHMAGE_BASIC_SPELL_MANA_COST * passiveMultiplier;
        printf("%s casted Water Elemental for %d mana\n", hero->name, ARCHMAGE_BASIC_SPELL_MANA_COST*passiveMultiplier);
    }
    else{
        printf("%s - not enough mana to cast Water Elemental\n", hero->name);
    }
}

/* Casts the DeathCoil spell */
void deathCoilCast(Hero *hero, short passiveMultiplier){
    if(hero->currMana >= DEATH_KNIGHT_BASIC_SPELL_MANA_COST * passiveMultiplier){
        hero->currMana -= DEATH_KNIGHT_BASIC_SPELL_MANA_COST * passiveMultiplier;
        printf("%s casted Death Coil for %d mana\n", hero->name, DEATH_KNIGHT_BASIC_SPELL_MANA_COST*passiveMultiplier);
    }
    else{
        printf("%s - not enough mana to cast Death Coil\n", hero->name);
    }
}

/* Casts the Silence spell */
void silenceCast(Hero *hero, short passiveMultiplier){
    if(hero->currMana >= DRAW_RANGER_BASIC_SPELL_MANA_COST * passiveMultiplier){
        hero->currMana -= DRAW_RANGER_BASIC_SPELL_MANA_COST * passiveMultiplier;
        printf("%s casted Silence for %d mana\n", hero->name, DRAW_RANGER_BASIC_SPELL_MANA_COST*passiveMultiplier);
        if(passiveMultiplier){
            silenceCast(hero, PASSIVE_SPELL);
        }
    }
    else{
        printf("%s - not enough mana to cast Silence\n", hero->name);
    }
}