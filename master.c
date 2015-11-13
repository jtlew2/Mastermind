
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


int compare_ans(char* ans, char* user, char* compare);
void play_game(int pieces,int turns);
void rand_ans( char* ans, int pieces);
void settings(int * pieces, int * turns);





int main(int argc, char const *argv[])
{
	int a,pieces=6,turns=9;
	printf("Welcome to Mastermind!\n");
	printf("C represents correct, X represents wrong place\n");
	printf("O represents completely wrong.\n");
	printf("Default number of pieces: 6\n");
	printf("Default number of turn: 9\n");
	
	while (a!=69){
		printf("Input 0 to quit\n");
		printf("Input 1 to start a new game\n");
		printf("Input 2 to change settings\n");
		scanf("%d",&a);
		switch (a){

			case 0:
				printf("Thanks for playing!\n");
				printf("Press any key to exit:");
				getch();
				a=69;
				break;
				
			case 1:
				play_game(pieces,turns);
				break;	

			case 2:
				settings(&pieces,&turns);
				break;

			default:
				printf("Not a valid input.\n");
				break;


		}


	}
	return 0;

}


void play_game(int pieces, int turns)
{

	char ans[5];
	rand_ans(ans,pieces);
	char user[5];
	char compare[5];
	int a,i;
	printf("Input 4 letter sequence using a-%c:  ",('a'+pieces-1));
	for(a=0;a<turns;a++){

		scanf("%s",&user);
		i= compare_ans(ans,user,compare);
		printf("%s\n",compare);
		if (i==1){
			printf("You Win!\n\n\n");
			return;
		}
		printf("%d guesses left\n",(turns-1-a));
	}
	printf("You lose!\n\n\n");
	
	return;

}

void rand_ans(char * ans, int  pieces){

	int i;
	srand(time(NULL));
	for (i=0;i<4;i++){
		ans[i]= 'a' + (rand() % pieces); 
	}
	ans[i]='\0';
	return;
}



int compare_ans( char* ans, char* user, char* compare)
{
	int i,j,correct=0,half=0;
	char ans_temp[4];
	for(i=0;i<4;i++){
		ans_temp[i]=ans[i];
	}

	for(i=0;i<4;i++){

		if(ans_temp[i]==user[i]){
			correct++;
			ans_temp[i]='Q';
			user[i]='G';
		}
	}

	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(ans_temp[j]==user[i]){
				half++;
				ans_temp[j]='Q';
				user[i]='G';
			}
		}
	}

	for(i=0;i<correct;i++){
		compare[i]='C';

	}
	for(j=i;j<i+half;j++){
		compare[j]='X';
	}
	for(;j<4;j++){
		compare[j]='O';
	}

	compare[4]='\0';
	if (correct==4) return 1;
	else return 0;		

}


void settings(int * pieces, int * turns){

	int a=1;
	while(a){
		printf("Input desired number of pieces.\n");
		printf("4-8 pieces recommended: ");
		scanf("%d",pieces);
		if(*pieces<1 || *pieces>26){
			printf("Not a valid number.\n");
		}
		else a=0;
	}
	while(!a){
		printf("Input desired number of turns.\n");
		printf("7-12 turns is recommended: ");
		scanf("%d",turns);
		if (*turns<1){
			printf("Not a valid number. \n");

		}
		else a=1;
	}

	return;

}
