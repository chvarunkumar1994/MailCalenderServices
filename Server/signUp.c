
int signUp(user u)
{
	char rawUserDetails[LINESIZE] = "\0";
	int check;
	char *calenderFile = (char*) malloc (100);
	char *mailFile = (char*) malloc (100);
	char dummy[100] = "F|MM/DD/YY|HH:MM|MM/DD/YY|HH:MM|seq|place|Description|\n";

	{
		FILE *authFile = fopen("login.txt","a");
		
		strcat(rawUserDetails,u.userName);
		strcat(rawUserDetails,"|");
		
		strcat(rawUserDetails,u.password);
		strcat(rawUserDetails,"|");
		
		strcat(rawUserDetails,u.firstName);
		strcat(rawUserDetails,"|");
		
		strcat(rawUserDetails,u.lastName);
		strcat(rawUserDetails,"|\n");
		
		fputs(rawUserDetails, authFile);

	    fclose(authFile);
		strcpy(mailFile,u.userName);
		strcpy(calenderFile,u.userName);
    
		strcat(mailFile,".txt");
		strcat(calenderFile,"_c.txt");
    
		authFile = fopen( mailFile, "w");
		//fputs("D|a|a|a|a|a||\n", authFile);
		fclose(authFile);
		authFile = fopen( calenderFile, "w");
		fputs(dummy, authFile);
		fclose(authFile);
		
		
	}
	
	//else
	//	return 0;
	
	return 1;
}
