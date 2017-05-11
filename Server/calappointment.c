void calappointment()
{
  int m,s,a,i,j,k,cn, noOfUsers, endOfUsers,temp,availability=0;
  char validUser[2], select2[2],flag[2];
  user *receipient;
  char finalAppointmentDetails[LENGTH];
  char username[16];


					//Request for an appointment by inserting following fields

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
									//printf("appointment time: %s ",requestedAppointment.endTime);
										
									flag[0]='A';
									strcpy(finalAppointmentDetails,"A|");
									strcat(finalAppointmentDetails,buffAppointment);
									cn = appointmentInvolvedUsers(); 
									for(k = 0;k < cn ; k++)
									{
									//printf("\n%s",meetingUsernames[k]);
									strcpy(username, meetingUsernames[k]);
									availability = appointmentAvailability(meetingUsernames[k]);
									if( availability == 0)
										break;

									}
								
								   	strcat(finalAppointmentDetails,"\n"); 

									if(availability == 1)
									{
									for(k = 0;k < cn ; k++)
									{
									//printf("\n%s",meetingUsernames[k]);
									strcpy(username, meetingUsernames[k]);
									strcat(username,"_c.txt");  // create a file by a name of user
									
									FILE *calfile = fopen(username,"ab");
									//printf("inside the if loop we are : %s",finalAppointmentDetails);
									fputs(finalAppointmentDetails, calfile);
								
										
									fclose(calfile);
									
									}
									}
									else
									{
									//printf(" \nRequested appintment is not available for user %s\n",meetingUsernames[k]);
									}

									//printf("\nfinalAppointmentDetails: %s", finalAppointmentDetails);

									fflush(stdout);
}
