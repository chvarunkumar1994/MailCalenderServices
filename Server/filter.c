void filterInbox()
{
	char buffer[LENGTH],searchBuffer[LENGTH];
	char sub[LENGTH];
	FILE *userAuth;
	char *line,ch, validUser[2];
	int num_match[LENGTH], a, count,i,j,reverse[100];
	user *check;
	size_t len = 0;
	ssize_t read;
	int size;
	char tz[3];
	memset(buffer, 0, LENGTH);
	strcpy(buffer, buffUsername);
	strcat(buffer, ".txt");
	retrieveInbox(buffer);
	recv(connfd, buff, 2, 0);
	//printf("%s", buff);
	a = buff[0] - '0';
	//printf("%d", a);
	count = 0;
	
	switch(a)
	{
		case 1:
		{
			memset(searchBuffer, 0, LENGTH);
			if(recv(connfd, searchBuffer, LENGTH, 0) < 0)
				perror("\nError in receiving username");
			
			fflush(stdout);
			check = fetchUser(searchBuffer);
	
	
			memset(validUser, 0, sizeof(validUser));
			if(check == NULL)
				validUser[0] = '0';
			else
				validUser[0] = '1';
			
			send(connfd, validUser, 1, 0);
			
			if(validUser[0] == '0')
				return;
			
			//printf("\nUsername:%s", searchBuffer);
			
			
			
			for(j=0;j < 100 && (inbox[j].userName != NULL);j++)
			{
					if(inbox[j].read[0] == 'D')
						continue;
					if(strcmp(inbox[j].userName,searchBuffer)==0)
					{
						num_match[count++] = j;
						//printf("%d", num_match[count-1]);
					}
				
			}
			for(i=count-1 , j=0; i >=0;i--,j++)
			{
				reverse[i] = num_match[j];
			}
			viewMail(reverse, count); 
			break;


		}
		
		case 2:
		{	
			
			//printf("\nInside subject");
			memset(searchBuffer,0,LENGTH);
			if(recv(connfd, searchBuffer, LENGTH, 0) < 0)
				perror("\nError in sending username");
			fflush(stdout);
			
			//printf("\ntext to search:%s", searchBuffer);
			
			for(j=0;j< 100 && (inbox[j].userName != NULL);j++)
			{
					
					if(inbox[j].read[0] == 'D')
						continue;
					if(strstr(inbox[j].subject,searchBuffer)!=NULL)
					{
						//printf("HELOOOO");
						num_match[count++]=j;
					}
				
			}
			for(i=count-1 , j=0; i >=0;i--,j++)
			{
				reverse[i] = num_match[j];
			}
			viewMail(reverse, count); 
			
			break;
		}	
		case 3:
		{
			//printf("emails filtered by date:");
			
			memset(tz, 0, 3);
			recv(connfd, tz, 2, 0);
			size = atoi(tz);


			memset(searchBuffer,0,LENGTH);
			if(recv(connfd, searchBuffer, size, 0) < 0)
				perror("\nError in sending username");
			fflush(stdout);
			
			//printf("\ntext to search:%s", searchBuffer);
			
			for(j=0;j< 100 && (inbox[j].userName != NULL);j++)
			{
					
					if(inbox[j].read[0] == 'D')
						continue;
					if(strstr(inbox[j].era,searchBuffer)!=NULL)
					{
						//printf("HELOOOO");
						num_match[count++]=j;
					}
				
			}for(i=count-1 , j=0; i >=0;i--,j++)
			{
				reverse[i] = num_match[j];
			}
			viewMail(reverse, count);  
			
			break;
		}
		

	}
	
	
}
