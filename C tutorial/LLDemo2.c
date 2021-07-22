#include <stdio.h>
#include <stdlib.h>

//Car
struct car{
	int data, tag, isTail;
	struct car *next, *previous;
}

//Enter
Car *enter(int data, Car *previous, Car *tailTag, Car *headTag){
	Car *add = (Car*)malloc(sizeof(Car));
	add->data = data;
	add->previous = NULL;
	add->next = NULL;
	if(tailTag->next == headTag){
		add->tag = 0;
	}else{
		if ((tailTag->next)->tag == 0){
			add->tag = 0;
			add->previous = previous;
		}else{
			add->tag = 1;
			add->next = previous;
		}
	}
	return add;
}
//Leave
int leave(Car *tail, Car *headTag){
	Car* newTail;
	if(tail->tag == 0){
		newTail = tail->previous;
	}else{
		newTail = tail->next;
	}
	free(tail);
	return newTail;
}
//Migrate
//main
int main(void){
	int numberOfRails = 0, steps = 0;
	//default node
	//Car* defaultNode = (Car*)malloc(sizeof(Car));
	//Get the number of rails and the number of steps
	scanf("%d %d", &numberOfRails, &steps);
	Car* headTags[numberOfRails];
	Car* tailTags[numberOfRails];
	//initialize
	for (int i = 0; i < numberOfRails; ++i){
		*tailTags[i]->next = *headTags[i];
		*headTags[i]->next = *tailTags[i];
	}
	int input1 = 0, input2 = 0;
	char command[10] = {' '};
	while(steps > 0){
		scanf("%s", command);
		//Read the first letter of command, so I can get to know what input want me to do.
		switch(command[0]){
		//I'll write the detail later because I want to clarify the structure first.
			case 'E':
				//input1 is the number of rail, input2 is the data of the new node.
				scanf(" %d %d", &input1, &input2);
				//enter();
				//Connect tailTag;
				//If headTag == tailTag, connect headTag
				break;
			case 'L':
				//input1 is the number of rail, which is going to remove the 'tail'.
				scanf(" %d", &input1);
				//leave();
				//If return is NULL, connect headTag and tailTag;
				break;
			case 'M':
				//input1 is the rails that is going to clear all nodes, input2 is the receiver.
				scanf(" %d %d", &input1, &input2);
				//migrate();
				//Connect headTag to railTag;
				break;
		}
		steps -= 1;
	}
	//Link the tails to the next head, so I can use one loop to print them all.
	//I need to check that the next headTag's next is not railTag, then we can connect, which means
	//I need to find the rail that the headTag is not connect with railTag.
	
	Car* headOfAll = NULL;
	for(int i = 0; i< rail; i++){
		if (headTags[i]->next != tailTags[i]){
			headOfAll = headTags[i]->next;
		}
	}
	while (headOfAll != NULL){
		if (headOfAll->isTail == 0){
			printf("%d ", headOfAll->data);
		}else
			printf("%d\n", headOfAll->data);
		readyToDelete = headOfAll;
		if (headOfAll->tag == 0){
			headOfAll = headOfAll->next;
		}else{
			headOfAll = headOfAll->previous;
		}
		free(readyToDelete);
	}
}






































