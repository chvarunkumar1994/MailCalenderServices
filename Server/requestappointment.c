void requestappointment()
{
	int m,s,a,i,j,k,cn, noOfUsers, endOfUsers,temp,availability=0;
	char validUser[100], select2[2],flag[2];
	user *receipient;
	FILE* filecalcal;
	char finalAppointmentDetails[LENGTH];
	char username[16];
	char appointmentDetailsPart[LENGTH], appointment2part[LENGTH], appointment1part[LENGTH];
	//calander for modifying and deleting
	char mcalbuff[2], dcalbuff[2];
	int mn;
	int mintcalbuff,dintcalbuff;
	int z = 0;
	int len;
	char seqnew[10], sqnum[3];
	//char cala[3];
	receipient = (user*) malloc (sizeof(user));
	flag[1] = '|';
	char buffresult[LENGTH];


	memset(buffAppointment, 0, LENGTH);
	//printf("hello i have done the memset: %s", buffAppointment);
	if( (recv (connfd, buffAppointment, LENGTH, 0)) < 0)
		perror("\nError in receiving username");
	//printf("appointment: %s", buffAppointment);
	strncpy(requestedAppointment.startDate, buffAppointment, 11);
	//printf("\n%s\n",requestedAppointment.startDate);
	strncpy(requestedAppointment.startTime, buffAppointment+11, 6);
	//printf("\n%s\n",requestedAppointment.startTime);
	strncpy(requestedAppointment.endDate, buffAppointment+17, 11);
	//printf("\n%s\n",requestedAppointment.endDate);
	strncpy(requestedAppointment.endTime, buffAppointment+28, 6);
	//printf("\n%s\n",requestedAppointment.endTime);
	strcpy(buffMeetingUsernames,buffAppointment+34);
	//printf("\nbuffMeetingUsernames: %s", buffMeetingUsernames);
	//printf("\n buffMeetingUsernames Again: %s", buffMeetingUsernames);
	//printf("appointment time: %s ",requestedAppointment.endTime);
	strncpy(appointment1part,buffAppointment, 33);
	strcpy(appointment2part,buffAppointment+33);
	memset(validUser, 0, 100);
	cn = appointmentInvolvedUsers(); 
	for(k = 0;k < cn ; k++)
	{
		//printf("\n%s",meetingUsernames[k]);
		strcpy(username, meetingUsernames[k]);
		//printf("\n%s \n%s", username, meetingUsernames[k]);
		// Added code from here
		receipient = fetchUser(meetingUsernames[k]);
		if(receipient == NULL)
		{
		//printf("User %s doesn't exist",username);
		//validUser[0] = '0';
		strcpy(validUser,"0");
		strcat(validUser, username); 
		break;
		}
		else
		strcpy(validUser,"1");
		availability = appointmentAvailability(meetingUsernames[k]);
		if( availability == 0)
		break;
	}
	//printf("\nvalidUser: %s",validUser);
	if((send(connfd, validUser, 100, 0)) < 0)
		printf("\nError in sending validUser");
	//printf("after sending validuser");
	//printf("\n availability: %d", availability);
	if(validUser[0] == '0')
	{
		//printf("Before return");
		return;
	}
	if(availability == 1)
	{
	//seqNum();
		fflush(stdout);
		fflush(stdin);
		//printf("i am going to go into the opening file");
		filecalcal = fopen ("logFile.txt" , "r+");
		fscanf (filecalcal, "%d", &z); 
		//printf (" this is the number: %d ", z);  
		fclose (filecalcal);
		z++;
		//printf("z value is: %d",z);
		sprintf(seqnew,"%d",z);
		len = strlen(seqnew);
		if(len == 3)
		{
		strcpy(sqnum,seqnew);
		}
		else if(len == 2)
		{
		strcpy(sqnum,"0");
		strcat(sqnum,seqnew);
		}
		else if(len == 1)
		{
		strcpy(sqnum,"00");
		strcat(sqnum,seqnew);
		}
		//printf("seqnum inside function: %s",sqnum);
		filecalcal = fopen ("logFile.txt" , "w");
		printf("%s.", sqnum);
		fputs(sqnum,filecalcal);
		fclose(filecalcal);
		strcpy(seqnumret, sqnum);
		//printf("\nseqnum : %s", seqnumret);
		memset(finalAppointmentDetails, 0, LENGTH);
		//printf("\ninitial finalAppointmentDetails: %s", finalAppointmentDetails);
		strcpy(appointmentDetailsPart, "|");
		strcat(appointmentDetailsPart,seqnumret);
		strcat(appointmentDetailsPart, appointment2part);	
		flag[0]='A';
		strcpy(finalAppointmentDetails,"A|");
		strcat(finalAppointmentDetails, appointment1part);
		strcat(finalAppointmentDetails,appointmentDetailsPart);
		strcat(finalAppointmentDetails,"\n");
		for(k = 0;k < cn ; k++)
		{
			//printf("\n%s",meetingUsernames[k]);
			strcpy(username, meetingUsernames[k]);
			strcat(username,"_c.txt");
			FILE *calfile = fopen(username,"a+");
			//printf("final appointment details are : %s",finalAppointmentDetails);
			fputs(finalAppointmentDetails, calfile);
			fclose(calfile);
		}
		strcpy(buffresult, "Your Appointment is conformed");
		
	}

	else
	{
		//printf(" \nRequested appintment is not available for user %s\n",meetingUsernames[k]);
		strcpy(buffresult, "Requested appintment is not available for user \n");
	}
		//printf("\nsending appointment confirmation details");
		if((send(connfd,buffresult , LENGTH , 0)) < 0)
			printf("\nError in sending validUser");
//printf("\nfinalAppointmentDetails: %s", finalAppointmentDetails);
		fflush(stdout);
}
