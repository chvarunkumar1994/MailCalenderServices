void selection()
{			
	char option[LENGTH], sub, fileRead, buffUC[4];
	int attachTop, a, b, i, j;
	char validUser[2], at,cus[20],desc[100],meetingPlace[30];
	char n[100];
	int z;
	char notExistingUser[100];		
	printf("\nYou are in mail/calender service");

  //calender variables:
	char mbufcal[LENGTH];

	do
	{
		printf("\n1)Mail Service\n2)Calender Service\n3)Exit");
		pushNc();
		printf("\n\nYour Option:");
		scanf("%s",buff);
		send(sock, buff, 2, 0);
		a = buff[0] - '0';
		printf("%d", a);
		
		
		switch(a)
		{	
			case 1: 
			{
				printf("You are in mail service");
				do
				{
					/* recv(sock, buffUC, 4, 0);
					notify = atoi(buffUC);
					 */
					printf("\n1)Inbox\n2)Compose an Email\n3)Change Service");
					pushNc();
					if(notify > 0)
					{
						printf("\nYou have unread message(s). Please check!");
						notify = 0;
					}
					printf("\n\nYour Option:");
					scanf("%s",option);
					puts(option);
					//buff[0] = (char)s;
					if(send(sock, option, 2, 0) < 0 )
						perror("\nError in sending");
					
					
					
					b = option[0] - '0';
					switch(b)
					{
						case 1:
						{
							printf("Check Mail");
							checkMail();
							//updatelCount();
							break;
						}
						case 2:
						{
							sendMailc();
							break;	
						}
						
						case 3:
						{
							/* printf("Filter");
							filterInboxc();
							break;
						
						}
						
						case 4:
						{
							printf("Change Service");*/
							break; 
						}
						
					}
					
					
				}while(b < 3);
			break;
			}

			case 2:
			{
						printf("You are in Calender Service");
						do
						{
							
							printf("\n1)View Calender\n2)Request an appointment\n3)modify an appointment\n4)Delete an appointment\n5)Change Service");
							if(notify > 0)
							{
								printf("\nYou have unread message(s). Please check!");
								notify = 0;
							}
							printf("\n\nYour Option:");
							scanf("%s",option);
							//puts(option);
							//buff[0] = (char)s;
							if(send(sock, option, 2, 0) < 0 )
								perror("\nError in sending");
							
							b = option[0] - '0';
							switch(b)
							{
								case 1:
								{
									//strcpy(n,currentUsername);
									//calcheck(ucal);
									/*
									printf("we are in calendar view");
									if( (z = recv (sock, bufcal, LENGTH, 0)) < 0)
                                						perror("\nError in receiving");
									printf("\n%s", bufcal);
									*/
									calview();
									//memset(bufcal, 0, LENGTH);
                            						break;
								}
								case 2:
								{
									printf("New Appointment creation");
									//newAppointment();
									/*
									// Create appointment//
									int appointmentValid = 0, appointmentAvailable = 0;
									memset(buffAppointment,0, LENGTH);
									
									printf("\nEnter usernames involved in meeting (seperate users using ',')\n");											
									scanf("\n%s",meetingUsernames);
									strcpy(buffMeetingUsernames, meetingUsernames); 
									printf("\nbuffMeetingUsernames: %s",buffMeetingUsernames);
									/*if( ( send( sock, buffMeetingUsernames, strlen(buffMeetingUsernames), 0) < 0) )
										printf("\nError in sending appointment details");
									
								
					
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
									if( (z = recv (sock, validUser, 100, 0)) < 0)
										perror("\nError in receiving user's existence");
									if(validUser[0] == '0')
									{
									strcpy(notExistingUser, validUser +1);
									printf("\nAppointment cancelled as user %s doesn't exist, Please try again...",notExistingUser);
									}
									*/
								modifycallrequest();
								break;	
								}
								
								case 3:
								{
									
									printf("\n******************Modify an appointment******************");
									modify();
									printf("\nPlease enter the new appointment:");
									modifycallrequest();
														
									
									break;
									
						
								}
								
								case 4:
								{
											
										printf("\n******************Delete an appointment******************");
										if( (z = recv (sock, bufcal, LENGTH, 0)) < 0)
                                							perror("\nError in receiving");
										printf("\n%s", bufcal);
										//memset(bufcal, 0, LENGTH);
										memset(mbuffcal,0,2);
										//printf("modify an appointment");
										printf("\nPlease select an appointment number: ");
										scanf("%s", dbuffcal);
										if( ( send( sock, dbuffcal, 2, 0) < 0) )
										printf("\nError in sending");
										//printf("modify in client side: %s", dbuffcal);
										
									break;
								}
								case 5:								
								{
									printf("\n******************Change Service******************");
									break;
								}
							}
						}while(b < 5);
			}
			break;
			case 3:
			{
				//close(sock);
				m = 3;
			}
			break;
		}
	}while(a < 3);
//close(sock);
}
