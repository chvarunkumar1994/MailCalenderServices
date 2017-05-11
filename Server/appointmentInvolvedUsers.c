int appointmentInvolvedUsers( )
{
	int i,j=0,temp = 0, endOfUsers = 0, noOfUsers = 0;								
		    for(i=0;i<10;i++)
		      {
			while(buffMeetingUsernames[j] != ',') 
			  {
			    j++;
			    if(buffMeetingUsernames[j] == '|' )
			      {
				endOfUsers = 1;
				break;		
			      }
			  }
			
			strncpy(meetingUsernames[i], buffMeetingUsernames+temp, j-temp);
			meetingUsernames[i][j-temp+1] ='\0';
			//printf("\n%s.-",meetingUsernames[i]);
			if(endOfUsers == 1)
			  {
			    break;
			  }
			j++;	
			temp = j;
			
		      }
		    noOfUsers = i+1;
		return noOfUsers;

}
