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
	//Basic creation of a node and addition to the front of the list
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

	//If the item is already present then the number is just added to the existing count
	for (ptr2 = ptr->things; ptr2 != NULL; ptr2 = ptr2->next){
		if (strcmp(ptr2->name, item)==0){
			ptr2->count += num;
			return;
		}
	}

	//If the item is not present a new node is created and assigned as below.
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

	//Cycles through the player and adds all of their counts up
	//to produce a total number of items
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
	//A nested for loop to find how much of the item each player has
	//the first loop cycles through players and the second items
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

	//The list is empty
	if(list==NULL){
		list = newPlayer;
		newPlayer->next=NULL;
		return list;
	}

	//The very first name should be after this one.
	if(strcmp(name, list->name) < 0){
		newPlayer->next = list;

		return newPlayer;
	}

	Players *ptr = list;
	for(ptr=list; ptr!=NULL; ptr = ptr->next){
		
		//We reached the end of the list and none of the words should be before this word.
		if(ptr->next==NULL){
			ptr->next = newPlayer;
			newPlayer->next = NULL;
			return list;
		}
		//This word is the same word we are trying to place.
		if(strcmp(name, ptr->next->name) < 0){
			newPlayer->next = ptr->next;
			ptr->next = newPlayer;
			return list;
		}		

	}


	return newPlayer;
}

void orderedAddItem(Players *list, char *p, char *item, int num) {
	//Creating the new player and assigning them a name.
	Items *newItem = malloc(sizeof(Items));
	newItem->name = malloc(strlen(item)+1);
	strcpy(newItem->name, item);

	//Locate the player's list that we wish to add to.
	Players *ptr = list;
	while (strcmp(p, ptr->name)!=0){
		ptr = ptr->next;
	}

	//Find if the item is already present and if so just add to the count.
	Items *ptr2 = ptr->things;

	for (ptr2 = ptr->things; ptr2 != NULL; ptr2 = ptr2->next){
		if (strcmp(ptr2->name, item)==0){
			ptr2->count += num;
			return;
		}
	}
	
	ptr2 = ptr->things;
	//The list is empty
	if(ptr2==NULL){
		ptr->things = newItem;
		newItem->next=NULL;
		newItem->count=num;
		return;
	}

	//The very first name should be after this one.
	if(strcmp(item, ptr2->name) < 0){
		newItem->next = ptr2;
		newItem->count=num;
		return;
	}

	for(ptr2=ptr->things; ptr2!=NULL; ptr2 = ptr2->next){
		
		//We reached the end of the list and none of the words should be before this word.
		if(ptr2->next==NULL){
			ptr2->next = newItem;
			newItem->count=num;
			newItem->next = NULL;
			return;
		}
		//This word is the same word we are trying to place.
		if(strcmp(item, ptr2->next->name) < 0){
			newItem->next = ptr2->next;
			ptr2->next = newItem;
			newItem->count=num;
			return;
		}		

	}return;
}
	
void gives(Players *list, char *p1, char *p2, char *item) {

	//Identifies the giving player and assigns node to ptr1
	Players *ptr1 = list;
	while (strcmp(p1, ptr1->name)!=0){
		ptr1 = ptr1->next;
	}

	//Identifies the recieving player and assigns node to ptr2
	Players *ptr2 = list;
	while (strcmp(p2, ptr2->name)!=0){
		ptr2 = ptr2->next;
	}

	//Identifies the count of the object the player is giving away.
	Items *thing1 = ptr1->things;
	while (strcmp(thing1->name, item)!=0){
		thing1 = thing1->next;
	}
	int num = thing1->count;

	//Removes the node from the givers list.
	thing1 = ptr1->things;

	if (strcmp(item, thing1->name)==0){
		ptr1->things = thing1->next;
		free(thing1->name);
		free(thing1);
	}
	else{
		Items *ptr = ptr1->things;
		while (strcmp(item, ptr->next->name)!=0){
			ptr = ptr->next;
		}
		Items *pDel=ptr->next;
		ptr->next=ptr->next->next;
		free(pDel->name);
		free(pDel);
	}

	//Identifies whether the reciever is already in possesion of this item
	//and if they are increments the count rather than adding a new node.
	Items *thing2 = ptr2->things;
	for (thing2 = ptr2->things; thing2 != NULL; thing2 = thing2->next){
		if (strcmp(thing2->name, item)==0){
			thing2->count += num;
			return;
		}
	}

	//Add a new node if the item was not already possesed.
	thing2 = ptr2->things;
	Items *newItem = malloc(sizeof(Items));
	newItem->name = malloc(strlen(item)+1);
	strcpy(newItem->name, item);
	newItem->count = num;
	newItem->next = thing2;
	ptr2->things = newItem;
	return;
}

