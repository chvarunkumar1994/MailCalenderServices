void reply(char* un)
{	//store receipient's username else where
	int m,s,a,i;
	char validUser[2], at[3], rName[100], data[LENGTH];
	
	//mail mailInfo;
	//printf("\nReply Mail Service Selected\n");
	
	receipient1 = NULL;
	receipient1 = fetchUser(un);
	if(receipient1 == NULL)
		printf("\nnot working");
	
	//printf("\nbefore memset");

	//memset(mailInfo.read, 0, 2);
	//memset(mailInfo.userName, 0, sizeof(mailInfo.userName));
	//memset(mailInfo.firstName, 0, sizeof(mailInfo.firstName));
	//memset(mailInfo.lastName, 0, sizeof(mailInfo.lastName));
	//memset(mailInfo.subject, 0, sizeof(mailInfo.subject));
	//memset(mailInfo.msgBody, 0, sizeof(mailInfo.msgBody));
	//memset(mailInfo.fileName, 0, sizeof(mailInfo.fileName));
	//memset(mailInfo.fileBody, 0, sizeof(mailInfo.fileBody));
	//memset(mailInfo.era, 0, sizeof(mailInfo.era));
	//printf("\nafter memset");
	
	//mailInfo.userName = (char*) malloc (LENGTH);
	strcpy(mailInfo.userName,receipient1->userName);
							
	//mailInfo.firstName = (char*) malloc (LENGTH);
	strcpy(mailInfo.firstName,receipient1->firstName);

	//mailInfo.lastName = (char*) malloc (LENGTH);
	strcpy(mailInfo.lastName,receipient1->lastName);
	
	
	//mailInfo.subject = (char*) malloc (LENGTH);

	//memset(mailInfo.subject, 0, LENGTH);
	
	if( (a = recv (connfd, mailInfo.subject, LENGTH, 0)) < 0)
		perror("\nError in receiving subject of mail");
	fflush(stdout);	

	//printf("\nSubject:%s",mailInfo.subject);
	
	//mailInfo.msgBody = (char*) malloc (LINESIZE);
	//memset(mailInfo.msgBody, 0, LENGTH);
	memset(data, 0, LENGTH);
	
	if( ( recv (connfd, data, LENGTH, 0)) < 0)
		perror("\nError in receiving body");
	fflush(stdout);
	//sleep(1);
	
	strcpy(mailInfo.msgBody, data);
	//printf("\nMessage Content:%s.",mailInfo.msgBody);
	
	memset(buffTimeM, 0, 17);
	if( ( recv (connfd, buffTimeM, 17, 0)) < 0)
		perror("\nError in receiving time");
	//printf("bufftotatime has %s", buffTimeM);
	strcpy(mailInfo.era, buffTimeM);
//	strcpy(receipient1->userName, un);
	
	
	//mailInfo.userName = (char*)malloc(LENGTH);
	memset(mailInfo.userName, 0, sizeof(mailInfo.userName));
	strcpy(mailInfo.userName, buffUsername);
	

//	sleep(1);
	
	if(recv(connfd, at, 1, 0) < 0)
		perror("error in attachment boolean");
	fflush(stdout);
	//printf("at - %c",at[0]);

	if( at[0] == 'Y' || at[0] == 'y')
	{
	//	mailInfo.fileName = (char*) malloc (LENGTH);
		
	/* 	if( (recv (connfd, mailInfo.fileName , LENGTH, 0)) < 0)
			perror("\nError in receiving filename");
		fflush(stdout); */
		
	//	mailInfo.fileBody = (char*) malloc (LENGTH);
		/* if((a = recv (connfd, mailInfo.fileBody , LENGTH, 0)) < 0)
			perror("\nError in receiving file content");
		fflush(stdout);
		

		printf("\n%s %s File attached", mailInfo.fileName, mailInfo.fileBody);
		 */
		recv(connfd, at, 3, 0);
		a = atoi(at);
		
		
		memset(data, 0, sizeof(data));
		if( a = (recv (connfd, data , a , 0)) <= 0)
			printf("\nError in receiving filename, a = %d", a);
		//fflush(stdout);
		strcpy(mailInfo.fileName, data);
		//printf("\nfilename - %s.", mailInfo.fileName);
		
		//mailInfo.fileBody = (char*) malloc (LENGTH);
		memset(data, 0, sizeof(data));
		if( (a = recv (connfd, data , LENGTH , 0)) <= 0)
			printf("\nError in receiving filebody, a = %d", a);
	//	fflush(stdout);
		strcpy(mailInfo.fileBody, data);
		//printf("\nfilebody - %s.", mailInfo.fileBody);
	}
	else
	{
		//printf("\nNo attachment");
		mailInfo.fileName = NULL;
		mailInfo.fileBody = NULL;
	}
	
	
//	mailInfo.read = (char*)malloc(2);
//	mailInfo.read = "U";
	strcpy(mailInfo.read, "U");
	writeMail(un, mailInfo);
	//printf("\nreceived Successfully");
}
