//#include "headerc.c"


void existingUserc()
{
	//Receiving the text from the user for login 	 service							 
	printf("\n************************************Existing User Login************************************ \n");		
	stopcase = 0;
	while(stopcase == 0)
	{
							 
		memset(buff,0, LENGTH);
		printf("\nUsername:");
		scanf("%s",buffUsername);
		// n = strlen(buffUsername);
		//sleep(1);
		//puts(buffUsername);
		if( ( send( sock, buffUsername, 16, 0) < 0) )
			perror("\nError in sending");
		fflush(stdout);
		printf("Password:");
		scanf("%s",buffPassword);
		n = strlen(buffPassword);
		//sleep(1);
							  
		if( ( send( sock, buffPassword, 16, 0) < 0) )
			printf("\nError in sending");
		memset(buff,0, LENGTH);

		recv( sock, buff, 2, 0);
		//printf("***%c***",buff[0]);
		if( buff[0] == '0')
			printf("\nINVALID USERNAME");
		else if( buff[0]   == '2')
			printf("\nINVALID PASSWORD");
		

		else
		{
			stopcase = 1;
			printf("\nSuccesfully Logged In\n");
			strcpy(currentUsername, buffUsername);
			selection();

		}
	}
}
