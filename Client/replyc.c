//#include "headerc.c"

void replyc()
{
	char validUser[2], at[3], data[LENGTH], data1[LENGTH], buffSendSub[LENGTH], buffSendBody[LENGTH];
	int a;
	FILE *attach;
	size_t len = 0;
	ssize_t read;
	memset(bufftotaltime, 0 , sizeof(bufftotaltime));
	memset(buffDateM, 0, 11);
	memset(buffTimeM, 0, 5);
	printf("\n******************Reply Mail******************");
	subTop = 0;
	//fflush(stdin);
	
	printf("\nSubject:");
	getchar();
	
	memset(buffSendSub, 0, sizeof(buffSendSub));
	do{
		buffSendSub[subTop++] = 
		getchar();
	
	}while(buffSendSub[subTop - 1] != '\n');
	buffSendSub[subTop - 1] = '\0';
	
	//printf("\n%s\n", buffSendSub);
	if( ( send( sock, buffSendSub, strlen(buffSendSub), 0) < 0) )
		printf("\nError in sending subject");
	
	
	printf("\nMessage Content:");
	//scanf("%s",buffSendBody);
	
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
	//fflush(stdin);
	//printf("\nBody is %s", buffSendBody);
	ctime = 0;
	do
	{
	memset(buffDateM, 0, sizeof(buffDateM));	
	if(ctime > 0)
		printf("\nPlease enter a valid date!");
	ctime++;	
	printf("\nEnter the date(MM/DD/YYYY):");
	scanf("%s",buffDateM);
        }while(validateDate(buffDateM,0) == 0);
	//printf("mail date is %s", buffDateM);
	//if( ( send( sock, buffDateM, 11 , 0) < 0) )
	//	printf("\nError in sending date");
	strcpy(bufftotaltime, buffDateM);
	strcat(bufftotaltime, "-");
	
	ctime = 0;
	do
        {
	if(ctime > 0)
		printf("\nPlease enter a valid date!");
	ctime++;
        printf("\nEnter the time(HH:MM):");
        scanf("%s",buffTimeM);
	}while(validateTime(buffTimeM,0) == 0);
	//printf("mail time is %s", buffTimeM);
	strcat(bufftotaltime,  buffTimeM);
	
	if( ( send( sock, bufftotaltime, 17 , 0) < 0) )
		printf("\nError in sending time");
	
	printf("\nDo you want to attach a file Y/N?:");
	scanf("%s", at);
	
	//send

	if(at[0] == 'Y' || at[0] == 'y')
	{
		
		struct stat buffer1;
		
		memset( data, 0, LENGTH);
		printf("\nEnter file name:");
		scanf("%s",data);
		
		
		//attachTop = 0;
		
		
		//memset( buff, 0, LENGTH);
		if(!stat(data, &buffer1))
		{
			attach = fopen(data, "r");
			memset(temp, 0, sizeof(temp));
			memset( data1, 0, LENGTH);
			while ((read = getline( &temp, &len, attach)) != -1) 
			{
				temp[strcspn(temp, "\n")] = (char)187;
				temp[strcspn(temp, "\n") + 1] = '\0';
				strcat(data1, temp);
				memset(temp, 0, sizeof(temp));
			}
			fflush(stdout);
			//printf("\nattach - %s\n%s\n", data, data1);
			fclose(attach);
			//free(temp);
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
	fflush(stdin);
	
	if( at[0] == 'Y' || at[0] == 'y')
	{
		
		a = strlen(data);
		
		sprintf(at, "%d", a);
		send(sock, at, 3, 0);
		
		if( ( send( sock, data, a, 0) <= 0) )
			printf("\nError in sending attachment");
		fflush(stdin);
		if ( (send( sock, data1, strlen(data1), 0) <= 0) )
			printf("\nError in sending attachment content");
	}
	
	printf("\nSent Successfully!");
}
