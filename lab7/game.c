#include "game.h"

// the two print routines have already been written for you

void printPlayers(Players *list) {
	Players *ptr = list;
	printf("Printing the current list of players : \n");
	while (ptr != NULL) {
		printf("\tName: %s\n", ptr->name);
		ptr = ptr->next;
	}
	printf("End of player list\n");
	return;
}

void printEverything(Players *list) {
	Players *ptr = list;
	printf("Printing the current players and their possessions: \n");
	while (ptr != NULL) {
		printf("\tName: %s\n", ptr->name);
		Items *ptr2 = ptr->things;
		while (ptr2 != NULL) {
			printf("\t\t%d %s\n", ptr2->count, ptr2->name);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	printf("End of listing\n");
	return;
}

// You need to write the following routines

Players *add(Players *list, char *name) {
	Players *newPlayer = malloc(sizeof(Players));
	newPlayer->name = malloc(strlen(name)+1);
	strcpy(newPlayer->name, name);
	newPlayer->next=list;
	return newPlayer;
}

void addItem(Players *list, char *p, char *item, int num) {
	Players *ptr = list;

	//Finds which players list we need to be adding the item to.
	while (strcmp(p, ptr->name)!=0){
		ptr = ptr->next;
	}
	//Assigning ptr2 to the list nested in the original list.
	Items *ptr2 = ptr->things;


	for (ptr2 = ptr->things; ptr2 != NULL; ptr2 = ptr2->next){
		if (strcmp(ptr2->name, item)==0){
			ptr2->count += num;
			return;
		}
	}

	ptr2 = ptr->things;
	Items *newItem = malloc(sizeof(Items));
	newItem->name = malloc(strlen(item)+1);
	strcpy(newItem->name, item);
	newItem->count = num;
	newItem->next = ptr2;
	ptr->things = newItem;	
	return;
}

int countPlayers(Players *list) {
	Players *ptr = list;
	if (ptr->next == NULL) return 0;
	int count = 1;
	while(ptr->next != NULL){
		count++;
		ptr = ptr->next;
	}
	return count;
}

int countItems(Players *list, char *name) {
	Players *ptr = list;

	//Finds which players list we need to count.
	while (strcmp(name, ptr->name)!=0){
		ptr = ptr->next;
	}

	Items *ptr2 = ptr->things;
	int num = 0;
	while (ptr2 != NULL){
		num += ptr2->count;
		ptr2 = ptr2->next;
	}

	return num;
}

int numItems(Players *list, char *item) {
	Players *ptr = list;
	Items *ptr2 = ptr->things;
	int num = 0;
		for(ptr=list; ptr!=NULL; ptr = ptr->next){
			for(ptr2 = ptr->things; ptr2 != NULL; ptr2= ptr2->next){
				if(strcmp(ptr2->name, item)==0){
					num += ptr2->count;
				}
			}

		}

	return num;
}

Players *orderedAdd(Players *list, char *name) {
	
	//Creating the new player and assigning them a name.
	Players *newPlayer = malloc(sizeof(Players));
	newPlayer->name = malloc(strlen(name)+1);
	strcpy(newPlayer->name, name);

	Players *ptr = list;
	for(ptr=list; ptr!=NULL; ptr = ptr->next){
		//This word should be before the one we are trying to place.

		//This word should be after the one we are trying to place.
		if(strcmp(ptr->next->name, name)<0){
			printf("<0");
			newPlayer->next = ptr->next;
			ptr->next = newPlayer;
			return newPlayer;
		}
		//This word is the same word we are trying to place.
		if(strcmp(ptr->next->name, name)==0){
			printf("==0");
			newPlayer->next = ptr->next;
			ptr->next = newPlayer;
			return newPlayer;
		}
		//We reached the end of the list and none of the words should be before this word.
		if(ptr->next==NULL){
			printf("==NULL");
			ptr->next = newPlayer;
			newPlayer->next = NULL;
			return newPlayer;
		}

	}


	return newPlayer;
}

void orderedAddItem(Players *list, char *p, char *item, int num) {
	return;
}
	
void gives(Players *list, char *p1, char *p2, char *item) {
	return;
}

