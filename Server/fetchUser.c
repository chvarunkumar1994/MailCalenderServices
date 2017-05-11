//include "header.c"
user* fetchUser(char *userName)
{
	
	FILE *fetchAuth;
	fetchAuth = fopen("login.txt","r");
	//printf("Inside fetch user - %s.", userName);
	if( fetchAuth != NULL )
	{
		char *line = NULL , file_char;
		size_t lineLength = 0;
		int temp, stop = 0, i;
	
		while( (temp = getline(&line, &lineLength, fetchAuth)) != -1)
		{
			//printf("\n%s %d", line, lineLength);
			for(i = 0; i < lineLength; i++)
			{
				if(line[i] == '|')
				{
					char *name = (char *) malloc(LINESIZE);
					memset(name, 0, LINESIZE);
					strncpy(name, line, i);
					name[i] = '\0';
				//	printf("\nCompared %s,%s.",name, userName);
					//printf("\n name is %s", name);	
					if(strcmp(name, userName) == 0)
					{					
						//sleep(2);
				//		printf("found user %s", name);
						fclose(fetchAuth);						
						return retrieveUser(line);
	
					}
					
						break;
					
				}
				
			}
			
			puts(line);
		}
		
		
	}
	fclose(fetchAuth);
	printf("\nuser not found");
	return NULL;
}


