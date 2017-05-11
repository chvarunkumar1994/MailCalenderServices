void existingUser()
{
	printf("\n*********Existing UserLogin********* \n");
	stopcase = 0;
	
	while(stopcase == 0)
	{
		//printf("\nHere 1");
		memset(buffUsername, 0, 16);
		//printf("\nHere 2");
		if( (n = recv (connfd, buffUsername, 16, 0)) < 0)
			perror("\nError in receiving");
		fflush(stdout); 
					
		//printf("Username is:  %s \n" ,buffUsername); 

					
		memset(buffPassword, 0, 16);
		if( (n = recv (connfd, buffPassword, 16, 0)) < 0)
			perror("\nError in receiving");
		fflush(stdout); 
					
		//printf("\nPassword is:  %s \n" ,buffPassword); 
		user *tempUser = NULL;
		tempUser = fetchUser (buffUsername);
		memset(buf, 0, strlen(buf));
		if( tempUser == NULL)
		{
		//	printf("\nINVALID USERNAME");
			buf[0] = '0';
			send(connfd, buf, 2, 0);
		}	
		else if( (strcmp(tempUser->password, buffPassword) != 0) )
		{
		//	printf("\n%s INVALID PASSWORD", tempUser->password);
			buf[0] = '2';
		//	printf("\n\n***%s***\n\n", tempUser->password);
			send(connfd, buf, 2, 0);
		}
		else 
		{
		//	printf("\n\n***%s***\n\n", tempUser->password);
		//	printf("\nSUCCESSFUL LOGIN");
			buf[0] = '1';
			stopcase = 1;
			send(connfd, buf, 2, 0);
			strcpy(buffcalusername,buffUsername);
			strcat(buffcalusername, "_c.txt");
			selection();
		}
		buf[1] = '\0';
		
		
	}			  
										   
}
