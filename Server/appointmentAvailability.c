int appointmentAvailability(char *username)
{
  int appointmentAvailable=1;
  char uname[16];
  FILE *calFile;
  strcpy(uname,username);
  strcat(uname,"_c.txt");
  calFile = fopen(uname,"r+");
  if( calFile != NULL )
    {
      char *line = NULL , file_char;
      size_t lineLength = 0;
      int temp, stop = 0, i, count = 0;
      
      while( (temp = getline(&line, &lineLength, calFile)) != -1)
	{
	/*
	if (strlen(getline < 3) && count == 0 )
	{
		//printf("\n\nAppointment available\n");
	     	appointmentAvailable = 1;
		break;
	}
	count++;
	*/	

	// Check for the appointment availability
	if(line[0] == 'A')
	{
	  //printf("\n%s %d", line, lineLength);
	  //printf("line: ");
	  for(i = 0; i < lineLength; i++)
	    {
		//printf("%c",line[i]);
	    }
		    strncpy(existingAppointment.startDate, line+2, 11);
		    //printf("\n%s\n",existingAppointment.startDate);
		    strncpy(existingAppointment.startTime, line+13, 6);
		    //printf("\n%s\n",existingAppointment.startTime);
		    strncpy(existingAppointment.endDate, line+19, 11);
		    //printf("\n%s\n",existingAppointment.endDate);
		    strncpy(existingAppointment.endTime, line+30, 6);
		    //printf("\n%s\n",existingAppointment.endTime);
		    validateDate(existingAppointment.startDate,0);
		    validateDate(existingAppointment.endDate,1);
		    validateDate(requestedAppointment.startDate,2);
		    validateDate(requestedAppointment.endDate,3);
		    validateTime(existingAppointment.startTime,0);
		    validateTime(existingAppointment.endTime,1);
		    validateTime(requestedAppointment.startTime,2);
		    validateTime(requestedAppointment.endTime,3);


	  	    if(validateAppointment(1,2) == 1 || validateAppointment(3,0) == 1 )
	   	    {
	          	//printf("\n\nAppointment available\n");
	     		appointmentAvailable = 1;
	   	    }
	  	    else
		   {
	                //printf("\n\nAppointment Not available, try another appointment...\n");
			appointmentAvailable = 0;	 		
			break;

	           }
	  //puts(line);
	}
      }
      fclose(calFile);
      if(appointmentAvailable == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
    }
  
  
}
