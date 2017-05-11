/*	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>
	#include<string.h>
	#define LINESIZE 1024
	#define LENGTH 1000
	struct emailInfo
{
	char *userName, *firstName, *lastName, *subject, *msgBody, *fileName, *fileBody , *read , *t;
	int seqNo;
};
struct userCredentials
{
	char *firstName, *lastName, *password, *userName;
};
 
	typedef struct userCredentials user;
	user tempUser;
	
	typedef struct emailInfo mail;
	mail tempMail, inbox[100];*/
//#include "header.c"

mail* checkMail(char* n)
{
	//printf("asdfasdfasdf");
	FILE *userAuth;
	char *line;
	//char n[]= "user1.txt";
	char c;
	int endIndex =0, mailN = -1, end, tempIndex = 0, i;
	size_t len = 0;
	ssize_t read;
	userAuth = fopen(n,"r");
	//printf("%d",userAuth);
	//temp = (char*) malloc (LENGTH);
	line = (char*) malloc (LENGTH);
	if( userAuth != NULL )
	{
		
		while ((read = getline( &line, &len, userAuth)) != -1) 
		{
			mailN++;
			printf("\n%s %d", line, len);
			endIndex = 0;
			//end = strlen(temp);
			
			inbox[mailN].read = (char *) malloc (2);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].read, line, endIndex);
			inbox[mailN].read[endIndex] = '\0';
			
			tempIndex = ++endIndex;
			inbox[mailN].userName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].userName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].userName[endIndex] = '\0';

			
			
			tempIndex = ++endIndex;
			inbox[mailN].firstName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].firstName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].firstName[endIndex] = '\0';
		
			tempIndex = ++endIndex;
			inbox[mailN].lastName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].lastName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].lastName[endIndex] = '\0';
			
			tempIndex = ++endIndex;
			inbox[mailN].subject = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].subject, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].subject[endIndex] = '\0';
			
			tempIndex = ++endIndex;
			inbox[mailN].msgBody = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].msgBody, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].msgBody[endIndex] = '\0';
			
			for(i = 0; i < endIndex-tempIndex; i++)
				if(inbox[mailN].msgBody[i] == (char)187)
					inbox[mailN].msgBody[i] = '\n';
			
			
			tempIndex = ++endIndex;
			inbox[mailN].fileName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].fileName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].fileName[endIndex] = '\0';
			
			tempIndex = ++endIndex;
			inbox[mailN].fileBody = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].fileBody, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].fileBody[endIndex] = '\0';
			
			for(i = 0; i < endIndex-tempIndex; i++)
				if(inbox[mailN].fileBody[i] == (char)187)
					inbox[mailN].fileBody[i] = '\n';
			
	//	printf("\n%d %s.", i, inbox[mailN].fileBody);
			
		}
		
		
	}
	else 
		return NULL;
	fclose(userAuth);
	
	return inbox;
}

/*
int main()
{
	char t[10] = "\0";
	
	checkMail("user1.txt");
	
	printf("\nData structure - \n%d,%s,%s,%s,%s,%s,%s,%s,%s.", strlen(t), inbox[3].read, inbox[3].userName, inbox[3].firstName, inbox[3].lastName, inbox[3].subject, inbox[3].msgBody, inbox[3].fileName, inbox[3].fileBody);
	return 1;
}*/