void deletionnew(int n, char c)
{
	int i = 1, j = 0,k,cn;
	char s[LENGTH];
	char *line;
	size_t len = 0;
	ssize_t read;
	char calUsernameToBeModified[22];
	char seq[3];
	int seqNum;
	FILE *fp, *fwrite;
	fp = fopen(buffcalusername, "r");
	line = (char*) malloc (LENGTH);
	//printf("Modifying the appointment in file : %s",buffcalusername);
	while( i != n+1 )
	{
		//printf("\n inside loop");
		read = getline( &line, &len, fp);
			j += read;
	//	//printf("%d %s\n", j, line);
		if(line[0] == 'A')
		   i++;
	}
	fclose(fp);
	j -= read;
	//printf("line: %s", line);
	fwrite = fopen(buffcalusername, "r+");
	fseek(fwrite, j, SEEK_SET);
	fputc(c, fwrite);
//	//printf("%d", i);
	fclose(fwrite);
	
	strncpy(seq,line+36,3);
	seqNum = atoi(seq);
	//printf("seq No: %d",seqNum);
	strcpy(buffMeetingUsernames,line+40);
	//printf("\nbuffMeetingUsernames: %s", buffMeetingUsernames);
	cn = appointmentInvolvedUsers(); 
	for(k = 1;k < cn ; k++)
	{
	//printf("\n%s",meetingUsernames[k]);
	strcpy(calUsernameToBeModified, meetingUsernames[k]);
	strcat(calUsernameToBeModified,"_c.txt");
	////printf("users whoes it need to be modified are : %s", calUsernameToBeModified);
	deletions(calUsernameToBeModified, seqNum, "M");
	}									
	
}

/*
int main()
{
	modifycharInFile("varun.txt", 5, "M");
}*/
