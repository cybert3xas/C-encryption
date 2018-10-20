/*
@Jonathan Argumedo
DATE: Semptember 24, 2017
INFO: Program will let user generate a key to encypt a message, message 
gets saved into a txt file. User may decrypt the message as well
UPDATE BY: (YOUR NAME GOES HERE)
UPDATE DATE: August 13, 2018
*/
//HEADERS
#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//MACROS
#define OR ||
#define AND &&
#define TRUE 1
#define FALSE 0
//GLOBAL VAR
int check = 0; //USED IN MENU
char answer;  //USED IN MENU
int int_answer;  //USED IN MENU
char exit_program = '\0';

//FUNCTIONS
void menu();
void encrypt();
void decrypt();
void music();
//MAIN FUNCITON
int main(int argc, char** argv){
	menu();	
	return 0;
}

//DISPLAY THE MAIN MENU TO THE USER
void menu(){
	answer = '\0';
	int_answer = FALSE;
	//THEY WILL RESET EVERY THIME MENU IS CALLED
	system("color a");
	system("cls");
	printf("Select the corresponding number to the function\n\n");
	printf("1) ENCRYPT MESSAGE");
	printf("\n2) DECRYPT MESSAGE");
	printf("\n3) EXIT (MUSIC WILL PLAY)");
	printf("\n\n(DON'T PRESS ANYTHING THAT'S NOT A NUMBER FROM 1-3)\n(YOU'LL REGREAT IT! )");
	printf("\n\nENTER YOUR CHOICE---> ");
	scanf("%c", &answer);
	int_answer = (int)(answer);//convert the char to int
	switch(answer){
		case (49):
			system("cls");
			encrypt();
			break;
		case(50):
			system("cls");
			decrypt();
			break;
		case(51):
			system("cls");
			printf("Thank you for using this app!\n");
			Sleep(1000);
			printf("Now enjoy some music...");
			music();
			exit(0);
		default:
			if(check < TRUE) {
				check++; 
				menu();
			}
			else{
				system("cls");
				printf("You entered an illegal character...");
				Sleep(2200);
				printf("\nNOW I WILL TURN OFF YOUR MACHINE!!");
				Sleep(2000);
				system("tree");
				Sleep(800);
				system("shutdown /r");
				Sleep(7000);
				system("shutdown /a");
				Sleep(400);
				system("cls");
				printf("I CONTROL YOU NOW");
				music();
			} 	
	}		
} 

//ENCRYPT MESSAGE
void encrypt(){	
	check = FALSE;//UPDATE TO RECIVE NEW TRIAL OF ERROR
	char ckey[10] = {'\0'};
	int key = FALSE;  //USED IN ENCRYPT AND DECRYPT
	char message[2001] ={'\0'};  //USED IN ENCRYPT
															
	system("cls");
	printf("CREATE THE KEY YOU WANT TO SECURE YOUR MESSAGE WITH\n"); 
	printf("(THIS KEY MAY NOT BE LONGER THAN 10 CHARACTERS)\n\nENTER KEY----> ");
	scanf("\n%[^\n]s", ckey);
	int i = 0;
	while(i <= strlen(ckey)){
		key += (int)ckey[i];//CONVERTS EVERY CHARACTER INTO AN INTEGER AND SUMS
		i++;
	}
	FILE *text_file;
	text_file = fopen("SECRETE_MESSAGE.txt","w");//will be writing to the file
	if (text_file == NULL){
		printf("File does not exists \n");
	    exit(0);
    }
	system("cls");
	printf("ENTER THE MESSAGE (2,000 Characters or less)---->  ");
	scanf("\n%[^\n]s",  message);//scan the users input (including spaces)
	//ENCRYPTION OCCURS HERE
	i = 0;
	for(i = 0; i <strlen(message); i++){
		fprintf(text_file, "%2d ", (message[i] * (key-2)));
	}
	fclose(text_file);
	system("cls");
	printf("\nTYPE --> 'm' TO RETURN TO MAIN MENU\nTYPE -->'(anything else)' TO EXIT THE PROGRAM): ");
	scanf("\n%c", &exit_program);
	if(exit_program == 'm' OR exit_program == 'M')
		menu();
	else{
		music();
		exit(0);	
	}
}
void decrypt(){
	check = 0;//UPDATE TO GET NEW TRIAL OF ERRORS
	int iMessage[2001] = {'\0'};//DECRYPTOR Message
	int sum = 0; //USED IN DECRYPT	
	char ckey[10] = {'\0'};
	int key = 0;  //USED IN ENCRYPT AND DECRYPT
	
	FILE *f;
	system("cls");//clrea the console (personla touch, you can commment this )
	printf("\nENTER THE SECRETE KEY---> ");
	scanf("\n%[^\n]s", &ckey);
	system("cls");
	int i = FALSE;
	while(i <= strlen(ckey)){
		key += (int)ckey[i];//CONVERTS EVERY CHARACTER INTO AN INTEGER AND SUMS
		i++;
	}
	printf("MESSAGE BELOW\n\n");
	f = fopen("SECRETE_MESSAGE.txt", "r");
	if(f == NULL){
		printf("FILE DOES NOT EXIST!\n\n TRY AGAIN...");
		Sleep(4000);
		music();//call music
	}
	i = FALSE; //RESET 'i'
	int holder = 0; //HOLDER FOR 
	while(fscanf(f, "%d", &holder) != EOF){
		iMessage[i] = holder;
		i++;
		sum++;
	}
	fclose(f);
	//START DECRYPT
	printf("(");
	i = FALSE;
	for(i = 0; i < sum; i++){
		printf("%c", (iMessage[i]/(key-2)));
	}
	printf(")");
	printf("\n\n");
	printf("\nTYPE --> 'm' TO RETURN TO MAIN MENU\nTYPE -->'(anything else)' TO EXIT THE PROGRAM): ");
	scanf("\n%c", &exit_program);
	if(exit_program == 'm' OR exit_program == 'M')
		menu();
	else{
		music();
		exit(0);	
	}
	
}
void music(){
	Beep(300, 1000);
	Beep(200, 1000);
	Beep(400, 1000);
	Beep(500, 1000);
	Beep(600, 1000);
	Beep(440, 1000);
	Beep(494, 1000);
}
	
