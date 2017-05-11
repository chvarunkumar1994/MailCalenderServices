void forward(mail f)
{//store receipient's username else where
	int i = -1, len, tS;
	char validUser[2], uname[LENGTH] = "", count;
	user *receipient;
	char array[10][LENGTH], siz[2];
	char *token;
	char user[LENGTH];
	receipient = malloc (sizeof(user));
	
	//printf("\n***Forward Selected**\n");
		// Send Service//
	
	fflush(stdin);
	
	//sleep(1);
	//recv(connfd, uname, LENGTH, 0);
	//memset(uname, 0, LENGTH);
	memset(siz, 0, 2);
	recv(connfd, siz, 2, 0);
	tS = atoi(siz);
	if( (i = recv (connfd, user, tS, 0)) < 0)
		perror("\nError in receiving username");
	
	count = 0;
	token = strtok(user, ",");
	while(token!= NULL)
	{
		//printf("\n %s ",token);
		strcpy(array[count++], token);
		token = strtok(NULL,",");
	}
	//printf("i=%d", i);
	
//	printf("Username:%s.", user);
	
	/* receipient = fetchUser(uname);
	if(receipient == NULL)
		validUser[0] = '0';
	else
		validUser[0] = '1'; */
	
	memset(validUser, 0, sizeof(validUser));
	validUser[0] = '1';
	for(i = 0; i < count; i++)
	{
		//printf("\narray[%d] = %s" , i , array[i]);
		receipient = fetchUser(array[i]);
		if(receipient == NULL)
		{
				validUser[0] = '0';
				break;
		}
	}
	 
	send(connfd, validUser, 1, 0);
	
	if(validUser[0] == '0')
		return;
	len = strlen(f.msgBody);
	


	memset(buffTimeM, 0, 17);
	if( ( recv (connfd, buffTimeM, 17, 0)) < 0)
		perror("\nError in receiving time");
	//printf("bufftotatime has %s", buffTimeM);
	strcpy(f.era, buffTimeM);


	for(i = 0; i < len; i++)
	{
		if(f.msgBody[i] == '\n')
			f.msgBody[i] = (char)187;
	}
	
	for(i = 0; i < len; i++)
	{
		if(f.fileBody[i] == '\n')
			f.fileBody[i] = (char)187;
	}
	f.read[0] = 'U';
	for( i = 0; i < count; i++)
	writeMail( array[i], f);
	//writeMail(uname, f);
}
