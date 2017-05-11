

void createNewUserc()
{
	int i = 0;	
	printf("******************Creating A New Account******************\n");
	printf("*Required fields\n");	
	do
	{
		if( i > 0)
			printf("\nUsername already exists");
		i++;		
		memset(buff,0, LENGTH);
		memset(buffUsername,0,16);
		printf("\n*Username:");
		scanf("%s",buffUsername);
		n = strlen(buffUsername);
		//sleep(1);
			
		if( ( send( sock, buffUsername, 16, 0) < 0) )
			printf("\nError in sending");
		recv(sock, buff, 2, 0);
		j = (int)buff[0];
		//printf("\n%c %d",buff[0], j);
		if (buff[0] == 1)
		{//		printf("%s", buffUsername);
			strcpy(currentUsername,buffUsername);
		}
		memset(buffUsername,0,16);
	}while(j != 1);
	
	memset(buffPassword,0,16);
	printf("*Password:");
	scanf("%s",buffPassword);
	n = strlen(buffPassword);
	//sleep(1);

			
	if( ( send( sock, buffPassword, 16, 0) < 0) )
		printf("\nError in sending");

	memset(buffFirstName,0,16);
	printf("*First Name:");
	scanf("%s",buffFirstName);
	n = strlen(buffFirstName);
			//sleep(1);
			
	if( ( send( sock, buffFirstName, 16, 0) < 0) )
		printf("\nError in sending");


	memset(buffLastName,0,16);
	printf("*Last Name:");
	scanf("%s",buffLastName);
	n = strlen(buffLastName);
	//sleep(1);
	
	if( ( send( sock, buffLastName, 16, 0) < 0) )
		printf("\nError in sending");                                              
	//next();  
	printf("\nSuccesfully Signed up\n");
	//printf("buffUsername has: %s", buffUsername);
	
	//printf("currentUsername has: %s", currentUsername);
	selection();        
}
