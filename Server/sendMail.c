void sendMail()
{
	int m,s,a,i;
	char validUser[2], at[3], count;
	user *receipient;
	char array[10][LENGTH];
	char *token;
	char user[LENGTH], data[LENGTH];
	//mail mailInfo;
	receipient = malloc (sizeof(user));
	
	//printf("Send Mail Service Selected");
		// Send Service//
	memset(buffSendUser, 0, sizeof(buffSendUser));	
	memset(user, 0, sizeof(user));
	
	if( (recv(connfd, user, LENGTH, 0)) < 0)
		perror("\nError in receiving username");
	fflush(stdout);
	
	count = 0;
	token = strtok(user, ",");
	while(token!= NULL)
	{
		printf("\n %s ",token);
		strcpy(array[count++], token);
		token = strtok(NULL,",");
	}
	memset(validUser, 0, sizeof(validUser));
	validUser[0] = '1';
	for(i = 0; i < count; i++)
	{
	//	printf("\narray[%d] = %s" , i , array[i]);
		receipient = fetchUser(array[i]);
		if(receipient == NULL)
		{
				validUser[0] = '0';
				break;
		}
	}
	
	//printf("Username: %s", buffSendUser);
	
	//receipient = NULL;
	
	
	//printf("\nOutside fetchUser");
	//printf("FetchedUsername: %s", receipient->userName);
	
	//else
		//validUser[0] = '1';
	
	if(send(connfd, validUser, 1, 0) <= 0)
		perror("error in sending validUser flag");
	fflush(stdout);
	
	if(validUser[0] == '0')
		return;

	//mailInfo.subject = (char*) malloc (LENGTH);
	memset(data, 0, sizeof(data));
	if( (a = recv (connfd, data, sizeof(data), 0)) < 0)
		perror("\nError in receiving subject of mail");
	fflush(stdout);
	strcpy(mailInfo.subject, data);
	//sleep(1);
	//printf("\nSubject:%s",data);
	//mailInfo.msgBody = (char*) malloc (LENGTH);
	memset(data, 0, sizeof(data));
	if( ( recv (connfd, data, LENGTH, 0)) < 0)
		perror("\nError in receiving body");
	fflush(stdout);
	
	
	strcpy(mailInfo.msgBody, data);
	//sleep(1);
	//printf("\nMessage Content:%s",mailInfo.msgBody);
	/*
	memset(buffDateM, 0, 11);
	if( ( recv (connfd, buffDateM, 11, 0)) < 0)
		perror("\nError in receiving date");
	printf("Buffdate has %s", buffDateM);
	*/
	memset(buffTimeM, 0, 17);
	if( ( recv (connfd, buffTimeM, 17, 0)) < 0)
		perror("\nError in receiving time");
	//printf("bufftotatime has %s", buffTimeM);
	strcpy(mailInfo.era, buffTimeM);
	sleep(1);

	if(recv(connfd, at, 1, 0) < 0)
		perror("error in attachment boolean");
	fflush(stdout);
	//printf("attach bool -%c.",at[0]);
	sleep(1);

	if( at[0] == 'Y' || at[0] == 'y')
	{
	
		recv(connfd, at, 3, 0);
		a = atoi(at);
		

		//mailInfo.fileName = (char*) malloc (LENGTH);
		memset(data, 0, a);
		if( (recv (connfd, data , a , 0)) < 0)
			perror("\nError in receiving filename");
		fflush(stdout);
		
		data[a] = '\0';
		//memset(mailInfo.fileName, 0, sizeof(mailInfo.fileName)); //newly added
		strcpy(mailInfo.fileName, data);
		//printf("\nfilename - %s %s.", data, mailInfo.fileName);
			

		recv(connfd, at, 3, 0);
		a = atoi(at);
		

		//mailInfo.fileBody = (char*) malloc (LENGTH);
		memset(data, 0, a);
		if( (recv (connfd, data , a , 0)) < 0)
			perror("\nError in receiving filename");
		fflush(stdout);
		//memset(mailInfo.fileBody, 0, sizeof(mailInfo.fileBody)); //newly added
		strcpy(mailInfo.fileBody, data);
	
		//printf("\nfilebody - %s.", mailInfo.fileBody);
		

		//printf("\n%s File attached", mailInfo.fileBody);
	}
	else
	{
		//printf("\nNo attachment");
		//mailInfo.fileName = (char*) malloc (LENGTH);
	//	mailInfo.fileBody = (char*) malloc (LENGTH);
		mailInfo.fileName = NULL;
		mailInfo.fileBody = NULL;
	}
	receipient = fetchUser(buffUsername);
//	mailInfo.userName = (char*) malloc (LENGTH);
	memset(mailInfo.userName, 0, sizeof(LENGTH));
	//printf("\n\n*******");
	puts(buffUsername);
	strcpy(mailInfo.userName,receipient->userName);
							
//	mailInfo.firstName = (char*) malloc (LENGTH);
	memset(mailInfo.firstName, 0, sizeof(LENGTH));
	strcpy(mailInfo.firstName,receipient->firstName);

//	mailInfo.lastName = (char*) malloc (LENGTH);
	memset(mailInfo.lastName, 0, sizeof(LENGTH));
	strcpy(mailInfo.lastName,receipient->lastName);
	
//	mailInfo.read = (char*)malloc(4);
	mailInfo.read = "U";
	//printf("\nCalling write mail from send mail");
	//receipient = fetchUser(buffSendUser);
	for( i = 0; i < count; i++)
		writeMail( array[i], mailInfo);
	//printf("\nreceived Successfully");
	
/* 	free(mailInfo.userName);
	free(mailInfo.firstName);
	free(mailInfo.lastName);
	free(mailInfo.read);
	free(mailInfo.fileName);
	free(mailInfo.fileBody);
	free(mailInfo.msgBody);
	free(mailInfo.subject); */
	
	
}
