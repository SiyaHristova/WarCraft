#include "UltimateSpells.h"

/* Casts the MassTeleport spell */
void massTeleportCast(Hero *hero, short passiveMultiplier){
    if(hero->currMana >= ARCHMAGE_ULTIMATE_SPELL_MANA_COST * passiveMultiplier){
        hero->currMana -= ARCHMAGE_ULTIMATE_SPELL_MANA_COST * passiveMultiplier;
        printf("%s casted Mass Teleport for %d mana\n", hero->name, ARCHMAGE_ULTIMATE_SPELL_MANA_COST*passiveMultiplier);
        hero->SpellCast[REGENERATE_MANA](hero, PASSIVE_SPELL);
    }
    else{
        printf("%s - not enough mana to cast Mass Teleport\n", hero->name);
    }
}

/* Casts the AnimateDead spell */
void animateDeadCast(Hero *hero, short passiveMultiplier){
    if(hero->currMana >= DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST * passiveMultiplier){
        hero->currMana -= DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST * passiveMultiplier;
        printf("%s casted Animate Dead for %d mana\n", hero->name, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST*passiveMultiplier);
        hero->SpellCast[CAST_BASIC_SPELL](hero, PASSIVE_SPELL);
    }
    else{
        printf("%s - not enough mana to cast Animate Dead\n", hero->name);
    }

}

/* Casts the Charm spell */
void charmCast(Hero *hero, short passiveMultiplier){
    if(hero->currMana >= DRAW_RANGER_ULTIMATE_SPELL_MANA_COST * passiveMultiplier){
        hero->currMana -= DRAW_RANGER_ULTIMATE_SPELL_MANA_COST * passiveMultiplier;
        printf("%s casted Charm for %d mana\n", hero->name, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST*passiveMultiplier);
    }
    else{
        printf("%s - not enough mana to cast Charm\n", hero->name);
    }

}
