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

void retrieveInbox(char* n)
{
	////printf("asdfasdfasdf");
	FILE *userAuth;
	char *line;
	//char n[]= "user1.txt";
	char c;
	int endIndex =0, mailN = -1, end, tempIndex = 0, i = 0;
	size_t len = 0;
	int read;
	userAuth = fopen(n,"r");
	////printf("%d",userAuth);
	//temp = (char*) malloc (LENGTH
	//printf("\n!!inside retrieve inbox");
	line = (char*) malloc (LENGTH);	
	memset(line, 0, sizeof(LENGTH));
	if( userAuth != NULL )
	{
		
		while ((read = getline( &line, &len, userAuth)) != -1) 
		{
			mailN++;
			//printf("inside while");
			//printf("\n%s %d\n", line, len);
			endIndex = 0;
			//end = strlen(temp);
			
			//inbox[mailN].read = (char *) malloc (2);
			memset(inbox[mailN].read, 0, sizeof(inbox[mailN].read));
			while(line[endIndex]!= '|')
					endIndex++;
			if( tempIndex != endIndex)
				strncpy(inbox[mailN].read, line, endIndex);
				printf("%d", endIndex);
			inbox[mailN].read[endIndex] = '\0';
			puts(inbox[mailN].read);
			tempIndex = ++endIndex;
			
			i = 0;
			memset(inbox[mailN].userName,0, sizeof(inbox[mailN].userName));
			//inbox[mailN].userName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
			{
			//		inbox[mailN].userName[i++] = line[endIndex];
					endIndex++;
					
			}
			if( tempIndex != endIndex)
				strncpy(inbox[mailN].userName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].userName[endIndex] = '\0';
			//printf("%d", endIndex);
			puts(inbox[mailN].userName);
			//printf("%s",inbox[mailN].userName);
			
			tempIndex = ++endIndex;
			memset(inbox[mailN].firstName,0, sizeof(inbox[mailN].firstName));
			//inbox[mailN].firstName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].firstName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].firstName[endIndex] = '\0';
			//printf("%d", endIndex);
			puts(inbox[mailN].firstName);
			tempIndex = ++endIndex;
			memset(inbox[mailN].lastName,0, sizeof(inbox[mailN].lastName));
			//inbox[mailN].lastName = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			if( tempIndex != endIndex)
				strncpy(inbox[mailN].lastName, line+tempIndex, endIndex-tempIndex);
			inbox[mailN].lastName[endIndex] = '\0';
			//printf("%d", endIndex);
			puts(inbox[mailN].lastName);
			
			
			tempIndex = ++endIndex;
			//inbox[mailN].era = (char *) malloc (LENGTH);
			memset(inbox[mailN].era,0, sizeof(inbox[mailN].era));
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(inbox[mailN].era, line+tempIndex, endIndex-tempIndex);
			//printf("%d", endIndex);
			inbox[mailN].era[endIndex] = '\0';
			puts(inbox[mailN].era);
			tempIndex = ++endIndex;
			
			memset(inbox[mailN].subject, 0, LENGTH);
			//inbox[mailN].subject = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			if( tempIndex != endIndex)
				strncpy(inbox[mailN].subject, line+tempIndex, endIndex-tempIndex);
			//printf("%d", endIndex);
			inbox[mailN].subject[endIndex] = '\0';
			puts(inbox[mailN].subject);
			tempIndex = ++endIndex;
			memset(inbox[mailN].msgBody,0, sizeof(inbox[mailN].msgBody));
			//inbox[mailN].msgBody = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			if( tempIndex != endIndex)
				strncpy(inbox[mailN].msgBody, line+tempIndex, endIndex-tempIndex);
			//printf("%d", endIndex);
			inbox[mailN].msgBody[endIndex] = '\0';
			puts(inbox[mailN].msgBody);
			
			for(i = 0; i < endIndex-tempIndex; i++)
				if(inbox[mailN].msgBody[i] == (char)187)
					inbox[mailN].msgBody[i] = '\n';
			
			
			tempIndex = ++endIndex;
			
			while(line[endIndex]!= '|')
			{
					endIndex++;
					printf("\n!!!!%d %d ", tempIndex, endIndex);
			}
			if( tempIndex != endIndex)
			{
				memset(inbox[mailN].fileName,0, sizeof(inbox[mailN].fileName));
				//inbox[mailN].fileName = (char *) malloc (LENGTH);
				printf("\nfileEndindex - %d", endIndex);
			
				strncpy(inbox[mailN].fileName, line+tempIndex, endIndex-tempIndex);
				inbox[mailN].fileName[endIndex] = '\0';
			}
			else
				inbox[mailN].fileName[0] = '\0';
			//printf("\n!!!!filename");
			
			puts(inbox[mailN].fileName);
			//if(strlen(inbox[mailN].fileName) < 4)
				//inbox[mailN].fileName = NULL;
			
			tempIndex = ++endIndex;
			memset(inbox[mailN].fileBody,0, sizeof(inbox[mailN].fileBody));
			//inbox[mailN].fileBody = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			if( tempIndex != endIndex)
				strncpy(inbox[mailN].fileBody, line+tempIndex, endIndex-tempIndex);
			//printf("%d", endIndex);
			inbox[mailN].fileBody[endIndex] = '\0';
			puts(inbox[mailN].fileBody);
			for(i = 0; i < endIndex-tempIndex; i++)
				if(inbox[mailN].fileBody[i] == (char)187)
					inbox[mailN].fileBody[i] = '\n';
			
			memset(line, 0, sizeof(LENGTH));
			//printf("%d inside while", mailN);
	//	//printf("\n%d %s.", i, inbox[mailN].fileBody);
			
		}	
			//printf("%d Out of while", mailN);
		
	}
	else 
	{
		//printf("unsuccesful retrieve inbox");
		fclose(userAuth);
		//printf("\n!!!!filename");
			
		//	puts(inbox[mailN].fileName);
		return;
	}
	if(mailN == -1)
		inbox[0].userName[0] = '\0';
	//printf("%d Out of retrieve inbox", mailN);
	fclose(userAuth);
	
	return;
}

/*
int main()
{
	char t[10] = "\0";
	
	checkMail("user1.txt");
	
	//printf("\nData structure - \n%d,%s,%s,%s,%s,%s,%s,%s,%s.", strlen(t), inbox[0].read, inbox[0].userName, inbox[0].firstName, inbox[0].lastName, inbox[0].subject, inbox[0].msgBody, inbox[0].fileName, inbox[0].fileBody);
	
		//printf("\nData structure - \n%d,%s,%s,%s,%s,%s,%s,%s,%s.", strlen(t), inbox[1].read, inbox[1].userName, inbox[1].firstName, inbox[1].lastName, inbox[1].subject, inbox[1].msgBody, inbox[1].fileName, inbox[1].fileBody);
	
	return 1;
}*/
