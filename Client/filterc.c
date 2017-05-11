void filterInboxc()
{
	int a;
	char searchBuffer[LENGTH], buff[2], validUser[2], buffFDate[LENGTH];
	
	int size;
	char tz[3];

	printf("\n1)By user name\n2)By subject line\n3)By date");
	printf("\n\nYour Option:");
	scanf("%s",buff);
	send(sock, buff, 2, 0);
	a = buff[0] - '0';
	printf("%d", a);
	
	switch(a)
	{	
		case 1: 
		{
			printf("\nSearch mails by username");
			memset(searchBuffer,0,LENGTH);
			printf("\nEnter Username:");
			scanf("%s",searchBuffer);
			if(send(sock, searchBuffer, strlen(searchBuffer), 0) < 0)
				perror("\nError in sending username");
			fflush(stdin);
			
			memset(validUser, 0, sizeof(validUser));
			fflush(stdin);
			
			if( ( recv(sock, validUser, 1, 0)) <= 0)
				printf("error in valid user");
			
			fflush(stdout);
			printf("validuser %s", validUser);
			
			if(validUser[0] == '0')
			{
				printf("\nInvalid User name");
				fflush(stdout);
				return;
			} 
			viewMailc();
		break;
		}

		case 2:
		{
			printf("\nText to search:");
			memset(searchBuffer,0,LENGTH);
			scanf("%s",searchBuffer);
			if(send(sock, searchBuffer, strlen(searchBuffer), 0) < 0)
				perror("\nError in sending username");
			fflush(stdin);
			viewMailc();
			
		}
		break;
		case 3:
		{
			//printf("\ndate to search DD/MM/YY:");
			memset(buffFDate,0,17);
			//scanf("%s",searchBuffer);
			ctime = 0;
			do
			{
			if(ctime > 0)
				printf("\nPlease enter a valid date!");
			ctime++;
			printf("\nEnter the date(MM/DD/YYYY)");
			scanf("%s",buffFDate);
        		}while(validateDate(buffFDate,0) == 0);
			
			size = strlen(buffFDate);
			sprintf(tz, "%d", size);

			send(sock, tz, 2, 0);
 			if( ( send( sock, buffFDate, size , 0) < 0) )
				printf("\nError in sending time");

			fflush(stdin);
			viewMailc();

		}
		break;
	}
}
