#include "BasicSpells.h"
#include "UltimateSpells.h"

#define MAX_HEROES 3

void spellsCasting(int commandsArr[], int commandsCount, Hero heroes[]);

int main() {
  Hero heroes[MAX_HEROES];

  createArchMage(&heroes[ARCHMAGE]);
  createDeathKnight(&heroes[DEATH_KNIGHT]);
  createDrawRanger(&heroes[DRAW_RANGER]);
  
  int commandsCount = 0;
  
  scanf("%d", &commandsCount);
  int *commands = malloc(sizeof(int) * commandsCount);

  spellsCasting(commands, commandsCount, heroes);
  
  free(commands);
  return EXIT_SUCCESS;
}

/* Represents the spell casting */
void spellsCasting(int commands[], int commandsCount, Hero heroes[]){
  int currAction = 0;

  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
    commands[i] = currAction;
  }

  for (int i = 0; i < commandsCount; i++) {
    for(int j = 0; j < MAX_HEROES; j++){
          heroes[j].SpellCast[commands[i]](&heroes[j], REGULAR_SPELL);
    }
  }
}