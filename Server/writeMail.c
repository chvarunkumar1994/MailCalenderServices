void writeMail(char* u, mail tempMail)
{
	//printf("helooooooo");
	FILE *userAuth;
	char n[100]="";
	//time(&rawtime);
	strcpy(n, u);
	strcat(n, ".txt");
	if ((userAuth = fopen(n,"a")) < 0)
		printf("\nDoes not open");
	//printf("\nuserAuthfile - %s.",n);
	fflush(stdout);
	if( userAuth != NULL )
	{
		//char *line = (char*)malloc(300), tempChar;
		size_t lineLength = 0;
		//printf("\nhiiiii");
		memset(line, 0, sizeof(line));
		//tempChar = tempMail.read;
		strcat(line, tempMail.read);
		strcat(line, "|");
		
		strcat(line, tempMail.userName);
			strcat(line, "|");
		
		strcat(line, tempMail.firstName);
		strcat(line, "|");
		
		strcat(line, tempMail.lastName);
		strcat(line, "|");
		/*
		t = localtime(&rawtime);
		memset(n, 0, 100);
		strftime(n,100,"%x - %I:%M%p", t);
		tempMail.era = (char*) malloc (100);
		strcpy(tempMail.era, n);
		strcat(line, n);
		*/
		strcat(line,tempMail.era);
		strcat(line, "|");
			
		
		strcat(line, tempMail.subject);
		strcat(line, "|");
		
		if(tempMail.msgBody != NULL)
			strcat(line, tempMail.msgBody);
		strcat(line, "|");
		
		if(tempMail.fileName != NULL)
			strcat(line, tempMail.fileName);
		//printf("\nfilename - %s.", tempMail.fileName);
		strcat(line, "|");
		
		if(tempMail.fileName != NULL && tempMail.fileBody!=NULL)
			strcat(line, tempMail.fileBody);
		strcat(line, "|\n");
		line[strlen(line)] = '\0';
		
		//printf("\n*************************appending to the fie***************\n");	
		puts(line);
		fputs(line, userAuth);
	//	free(line);

	}
	else
		printf("\nFILE DID NOT OPEN\n");
	fclose(userAuth);
	
	//printf("\nExiting from writeMail");
	return;
}

