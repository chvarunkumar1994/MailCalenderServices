//#include "header.c"

void viewMailc()
{
	//printf("Asdfasdf");
	int count, no, a, x;
	char recvBuffer[100*LENGTH], num[5], att[5], filename[30], at[3], ex[3];
	FILE *attach;
	
	memset(recvBuffer, 0, 100*LENGTH);
	
	if( (no = recv(sock, recvBuffer, 100*LENGTH, 0)) <= 0)
		perror("\nError in receiving inbox\n");
	
	fflush(stdout);
	if(recvBuffer[0] == '!')
	{
		printf("\nEMPTY");
		return;
	}
	printf("\n**********************Inbox*********************\n");
	puts(recvBuffer);
	//printf("\nreceived - %d", no);
	fflush(stdin);
	memset(num, 0, 5);
	printf("\nChoose the email number to open:");
	scanf("%s", num);
	puts(num);
	//send email number to display
	if(send(sock, num, strlen(num), 0) <= 0)
		perror("error in sending email number\n");
	fflush(stdin);
	
	//check if sent number is valid
	memset(num, 0, 5);
	if(recv(sock, num, 5, 0) <= 0)
		perror("error in receiving email validation\n");
	fflush(stdout);
	//printf("\nreceived num - %s", num);
	
	//depending on validity of email no
	if(num[0] == 'Y')
	{
		memset(ex, 0, 3);
		recv(sock, ex, 3, 0);
		x = atoi(ex);


		//receiving that particular email
		memset(recvBuffer, 0, sizeof(recvBuffer));
		recv(sock, recvBuffer, x, 0);
		fflush(stdout);
		//printf("%s", recvBuffer);
		
		//check if there is an attachment
		memset(num, 0, 5);
		recv(sock, num, 5, 0);

		//printf("\n*****aattachment %s",num);
		fflush(stdout);
		printf("\n****Choose one of the following options****\n");
		if(num[0] == 'Y')
		{
			printf("\nA - To save the attachment.");
		}
		printf("\nR - Reply to this email.");
		printf("\nF - Forward this email.");
		printf("\nD - Delete this email.");
		printf("\nS - Sort emails.");
		printf("\nQ - Quit");
		printf("\nOption:");
		memset(att, 0, 5);
		scanf("%s", att);
		
	
		if(send(sock, att, 1, 0)<=0)
			printf("\nError in sending user attachment preference");
		fflush(stdin);
		
		//If the user wants to save the attachment
			if(num[0] == 'Y' && (att[0] == 'A' || att[0] == 'a'))
			{
				memset(at, 0, 2);				
				recv(sock, at, 2, 0);
				at[3] = '\0';
				a = atoi(at);
				//printf("%s, %d", at, a);
				printf("\nReceiving filename and body...");
				memset(filename, 0, sizeof(filename));
				if(recv(sock, filename, a, 0 )<=0)
					printf("unable to receive filename");
				fflush(stdout);
				printf("\nFilename\n%s", filename);
				

				memset(at, 0, 2);
				recv(sock, at, 2, 0);
				a = atoi(at);
				//printf("%d", a);

				memset(recvBuffer, 0, LENGTH);
				if((recv(sock, recvBuffer, LENGTH, 0))<=0)
					printf("\nunable to receive file body");
				fflush(stdout);
				printf("\nFilebody\n%s", recvBuffer);
				
				if((attach = fopen(filename, "w"))<=0)
					printf("\nfile not created");
				fputs(recvBuffer, attach);
				fclose(attach);
				printf("\nAttachment saved!\n");
				return;
				
			}
			else if(att[0] == 'R' || att[0] == 'r')
			{
				
				replyc();
			}
			else if(att[0] == 'F' || att[0] == 'f')
			{
				fflush(stdout);
				forward();
			}
			else if(att[0] == 'D' || att[0] == 'd')
			{
				printf("\nEmail has been deleted!");
				
			}
			else if(att[0] == 'S' || att[0] == 's')
			{
				//printf("Filter");
				filterInboxc();
			}
			else
			{
				return;
			}

		
	}
	else
	{
		printf("\nInvalid number!");
		return;
	}

}
