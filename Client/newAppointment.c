void newAppointment()
{
	char option[LENGTH], sub, fileRead;
	int attachTop, a, b, i, j;
	char validUser[2], at,cus[20],desc[100],meetingPlace[30];
	char n[100];		
	printf("\nYou are in mail/calender service");
	int appointmentValid = 0, appointmentAvailable = 0;
									memset(buffAppointment,0, LENGTH);
									
									printf("\nEnter usernames involved in meeting (seperate users using ',')\n");											
									scanf("\n%s",meetingUsernames);
									strcpy(buffMeetingUsernames, meetingUsernames); 
									printf("\nbuffMeetingUsernames: %s",buffMeetingUsernames);
									/*if( ( send( sock, buffMeetingUsernames, strlen(buffMeetingUsernames), 0) < 0) )
										printf("\nError in sending appointment details");

*/
					
									do
									  {
									    do
									      {
										printf("\nEnter meeting start date(MM/DD/YYYY): ");
										scanf("%s",appointment.startDate);
									      }while(validateDate(appointment.startDate,0) == 0);
									    appointment.startDate[10] = '|';
									    do
									      {
										printf("\nEnter meeting start time(HH:MM): ");
										scanf("%s",appointment.startTime);
									      }while(validateTime(appointment.startTime,0) == 0);
									    appointment.startTime[5] = '|';
									    do
									      {
										printf("\nEnter meeting end date(MM/DD/YYYY): ");
										scanf("%s",appointment.endDate);
									      }while(validateDate(appointment.endDate,1) == 0);
									    appointment.endDate[10] = '|';
									    do
									      {
										printf("\nEnter meeting end time(HH:MM): ");
										scanf("%s",appointment.endTime);
									      }while(validateTime(appointment.endTime,1) == 0);
									    appointment.endTime[5] = '|';
									    if(validateAppointment(0,1) == 1)
									      {
										printf("\n\n Valid appointment\n");
										appointmentValid = 1;
									      }
									    else
									      {
										printf("\n\n Invalid appointment, try again...\n");
									      }
									  }while(appointmentValid == 0);
									printf("\nEnter place of the event\n");											
									scanf("\n%s",meetingPlace);
									strcat(meetingPlace,"|");
									printf("\nEnter description for the event\n");											
									scanf("\n%s",desc);
									strcat(desc,"|");
									strcat(buffAppointment,appointment.startDate);
									strcpy(cus,currentUsername);
									printf("current username %s", currentUsername);
									strcat(cus,",");
									strcat(buffAppointment,cus);
									strcat(buffAppointment,meetingUsernames);
									strcat(buffAppointment,"|");
									strcat(buffAppointment,meetingPlace);
									strcat(buffAppointment,desc);	
																		
									
									printf("bufAppoinment: %s",buffAppointment);
									if( ( send( sock, buffAppointment, strlen(buffAppointment), 0) < 0) )
										printf("\nError in sending appointment details");
									printf("\nappointment sent");
}
