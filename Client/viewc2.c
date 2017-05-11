//#include "header.c"

void viewMailc()
{
	//printf("Asdfasdf");
	int count, no;
	char recvBuffer[100*LENGTH], num[5], att[5], filename[30];
	FILE *attach;
	
	memset(recvBuffer, 0, 100*LENGTH);
	
	if( (no = recv(sock, recvBuffer, 100*LENGTH, 0)) <= 0)
		perror("\nError in receiving inbox\n");
	fflush(stdout);
	puts(recvBuffer);
	//printf("\nreceived - %d", no);
	fflush(stdin);
	
	printf("\nChoose the email number to open:");
	scanf("%s", num);
		
	//send email number to display
	if(send(sock, num, strlen(num), 0) < 0)
		perror("error in sending email number\n");
	fflush(stdout);
	//check if sent number is valid
	memset(num, 0, 5);
	if(recv(sock, num, 5, 0) < 0)
		perror("error in receiving email validation\n");
	fflush(stdout);
	//printf("\nreceived num - %s", num);
	
	//depending on validity of email no
	if(num[0] == 'Y')
	{
		//receiving that particular email
		memset(recvBuffer, 0, 100*LENGTH);
		recv(sock, recvBuffer, 100*LENGTH, 0);
		fflush(stdout);
		printf("%s", recvBuffer);
		
		//check if there is an attachment
		memset(num, 0, 5);
		recv(sock, num, 5, 0);
		fflush(stdout);
		printf("\n****Choose one of the following options****\n");
		if(num[0] == 'Y')
		{
			printf("\nA - To save the attachment.");
		}
		printf("\nR - Reply to this email.");
		printf("\nF - Forward this email.");
		printf("\nD - Delete this email.");
		printf("\nOption:");
		memset(att, 0, 5);
		scanf("%s", att);
		
		send(sock, att, 2, 0);
			
		//If the user wants to save the attachment
			if(num[0] == 'Y' && (att[0] == 'A' || att[0] == 'a'))
			{
				printf("\nReceiving filename and body...");
				recv(sock, filename, 30, 0 );
				fflush(stdout);
				
				memset(recvBuffer, 0, 100*LENGTH);
				recv(sock, recvBuffer, 100*LENGTH, 0);
				fflush(stdout);
				
				attach = fopen(filename, "w");
				fputs(recvBuffer, attach);
				fclose(attach);
				fflush(stdout);
				fflush(stdin);
				printf("\n!Attachment saved!\n");
				
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
				printf("\nEmail has been deleted!!");
			//	delete();
			}
			else
				printf("This is shit");

		
	}
	else
	{
		printf("\nInvalid number");
		return;
	}

}
