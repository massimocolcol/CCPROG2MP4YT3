#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SELECTED_IDOLS 3

typedef struct GameState
{
	int selectedIdols[SELECTED_IDOLS];
	int DoneDungeons[SELECTED_IDOLS]; //if 0 not yet done, 1 if done
	int gold;
	int hp;
}
//SavedGame if 1 a saved game exist, 0 if none
char MainMenu(int SavedGame)
{
	char choice;
	
	printf("\n****************************************\n");
	printf("*         Yohane The Parhelion!        *\n");
	printf("*      The Siren in the Mirror World!  *\n");
	printf("\n****************************************\n");
	

	
	if(SavedGame == 1)
		printf("[C]ontinue\n");
	else 
		printf(" [N]ew Game\n");
	
	printf("[V]iew Achievements\n");
	printf("[Q]uit\n");
	printf("\n Enter: ");
	scanf(" %c", &choice);
	
	return choice;	
}

void saveGame(GameState *state)
{
	FILE *file = fopen("saveFile.dat","wb");
	
	if(file !=NULL)
	{
		fwrite(state, sizeof(GameState), 1, file);
		fclose(file);
		printf("Game Saved! \n");
	}
	else
		printf("Error Saving the game :( \n");
}

int loadGame(GameState *state)
{
	int load = -1;
	FILE *file = fopen("saveFile.dat","rb");
	
	if(file !=NULL)
	{
		fread(state, sizeof(GameState), 1, file);
		fclose(file);
		load = 1;
	}
	else
		load = 0;
	
	return load;
}

