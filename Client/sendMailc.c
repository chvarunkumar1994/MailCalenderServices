//#include "headerc.c"

void sendMailc()
{
	char validUser[2], at[3];
	FILE *attach;
	size_t len = 0;
	ssize_t read;
	int a;
	printf("******************Send Mail******************");
	// Send Service//
	memset(bufftotaltime, 0 , sizeof(bufftotaltime));
	
	memset(buffTimeM, 0, 5);
	memset(buffSendUser, 0, sizeof(buffSendUser));
	printf("\nUsername:\n");
	//memset(buffSendUser, 0, sizeof(buffSendUser));
	scanf("%s",buffSendUser);
	//printf("\n%s", buffSendUser);

	if( ( send( sock, buffSendUser, strlen(buffSendUser), 0) <= 0) )
	{
		fflush(stdin);
		printf("\nError in sending username");
	}
	
	memset(validUser, 0, sizeof(validUser));
	//fflush(stdin);
	
	if( (a = recv(sock, validUser, 1, 0)) <= 0)
		printf("error in valid user");
	
	fflush(stdout);
	//printf("%d,validuser %s",a, validUser);
	
	if(validUser[0] == '0')
	{
		printf("\nInvalid User name");
		//fflush(stdout);
		return;
	} 
	
	printf("\nSubject:\n");

	getchar();
	memset(buffSendSub, 0, sizeof(buffSendSub));
	subTop = 0;
	do{
		buffSendSub[subTop++] = 
		getchar();
	
	}while(buffSendSub[subTop - 1] != '\n');
	buffSendSub[subTop - 1] = '\0';
	
	//scanf("%[^\n]", buffSendSub);
	//printf("\n******%s", buffSendSub);
	if( ( send( sock, buffSendSub, strlen(buffSendSub), 0) < 0) )
		printf("\nError in sending subject");
	//fflush(stdin);
	//sleep(1);

	printf("\nMessage Content:\n");
	//scanf("%s",buffSendBody);
	
	getchar();
	memset(buffSendBody, 0, sizeof(buffSendBody));
	subTop = 0;
	do{
		buffSendBody[subTop++] = getchar();
		if(buffSendBody[subTop - 1] == '\n')
					buffSendBody[subTop - 1] = (char)187;
	}while(buffSendBody[subTop - 1] != EOF);
	buffSendBody[subTop - 1] = '\0';
	
	//printf("\n%d %d %s.", strlen(buffSendBody), subTop, buffSendBody);
			
	
	if( ( send( sock, buffSendBody, strlen(buffSendBody) , 0) < 0) )
		printf("\nError in sending message content");
//	fflush(stdin);
	//printf("Enter the date(MM/DD/YYYY");
	//scanf("%s",maildt.EDate);
	ctime = 0;
	do
	{
	memset(buffDateM, 0, sizeof(buffDateM));	
	if(ctime > 0)
		printf("\nPlease enter a valid date!\n");
	ctime++;
	printf("\nEnter the date(MM/DD/YYYY):\n");
	scanf("%s",buffDateM);
        }while(validateDate(buffDateM,0) == 0);
	//printf("mail date is %s", buffDateM);
	//if( ( send( sock, buffDateM, 11 , 0) < 0) )
	//	printf("\nError in sending date");
	
	memset(bufftotaltime, 0 , 17);
	strcpy(bufftotaltime, buffDateM);
	strcat(bufftotaltime, "-");
	ctime = 0;
	getchar();
	do
        {
	memset(buffTimeM, 0, sizeof(buffTimeM));
	if(ctime > 0)
		printf("\nPlease enter a valid date!\n");
	ctime++;
        printf("\nEnter the time(HH:MM):\n");
        scanf("%s",buffTimeM);
	
	}while(validateTime(buffTimeM,0) == 0);
	//printf("mail time is %s", buffTimeM);
	strcat(bufftotaltime,  buffTimeM);
	
	if( ( send( sock, bufftotaltime, 17 , 0) < 0) )
		printf("\nError in sending time");
	
	
	//printf("Enter the time(HH:MM)");
	//scanf("%s",maildt.ETime);
	printf("\nDo you want to attach a file Y/N?:");
	scanf("%s", at);
	
	//send
	
	if(at[0] == 'Y' || at[0] == 'y')
	{
		memset( buffSendAttach, 0, LENGTH);
		printf("\nEnter file name:");
		scanf("%s",buffSendAttach);
		
		//attach = NULL;		
		
		//attachTop = 0;
		struct stat buffer;
		memset( buffSendAData, 0, LENGTH);
		//memset( buff, 0, LENGTH);
		if(!stat(buffSendAttach, &buffer))
		{
			attach = fopen(buffSendAttach, "r");
			memset(temp, 0, sizeof(temp));
			while ((read = getline( &temp, &len, attach)) != -1) 
			{
				temp[strcspn(temp, "\n")] = (char)187;
				temp[strcspn(temp, "\n") + 1] = '\0';
				strcat(buffSendAData, temp);
				memset(temp, 0, sizeof(temp));
			}
			//buffSendAData[strlen(buffSendAData)] = '\0';
			fflush(stdout);
			//printf("\nfilename - %s,\ndata - %s.!\n", buffSendAttach, buffSendAData);
			fclose(attach);
		}
		else
		{
			printf("\nAttachment does not exist!");
			at[0] = 'N';
		}
		
	}
	else
		at[0] = 'N';
	
	send(sock, at, 1, 0);
	
	if( at[0] == 'Y' || at[0] == 'y')
	{
		
		a = strlen(buffSendAttach);
		memset(at, 0, 3);
		sprintf(at, "%d", a);
		send(sock, at, 3, 0);

		//printf("\nSending filename - %s", buffSendAttach);
		if( ( send( sock, buffSendAttach, strlen(buffSendAttach), 0) <= 0) )
			printf("\nError in sending attachment!");
		
		a = strlen(buffSendAData);
		
		sprintf(at, "%d", a);
		send(sock, at, 3, 0);


		//printf("\nSending filebody - %s", buffSendAData);
		if ( (send( sock, buffSendAData, strlen(buffSendAData), 0) <= 0) )
			printf("\nError in sending attachment content!");
	}
	
	printf("\nSent Successfully!");
}
