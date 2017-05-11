void forward()
{
	char validUser[2], at, uname[LENGTH], siz[2];
	FILE *attach;
	size_t len = 0;
	ssize_t read;
	int tS;
	printf("******************Forward mail************************************");
	// Send Service//
	
	printf("\nUsername:");
	fflush(stdout);
	memset(uname, 0, LENGTH);
	scanf("%s", uname);
	printf("\n%s", uname);
	memset(siz, 0, 2);
	tS = strlen(uname);
	sprintf(siz, "%d", tS);
	send(sock, siz, 2, 0);
	if( ( send( sock, uname, tS, 0) < 0) )
		printf("\nError in sending username");
	fflush(stdin);
	
	recv(sock, validUser, 1, 0);
	if(validUser[0] == '0')
	{
		printf("\nInvalid User name");
		return;
	} 

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
	memset(bufftotaltime, 0 , 17);
	strcpy(bufftotaltime, buffDateM);
	strcat(bufftotaltime, "-");
	ctime = 0;
	do
        {
	memset(buffTimeM, 0, sizeof(buffTimeM));
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
}
