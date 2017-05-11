

void selection()
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
	char seqnew[10], sqnum[3], countV[4];
	  
	  
	  
	//counting already notified emails
	lCount = 0;
	  
	//char cala[3];
	receipient = (user*) malloc (sizeof(user));
	flag[1] = '|';
 	pthread_t updation;
				
	pthread_create(&updation, NULL, updateUnread, NULL); 
	sleep(1);
		do
		{
			
			pushN();
			//printf("\nCHOOSE EITHER MAIL OR CALENDER SERVICE");
			//printf("\n1)Mail Service\n2)Calender Service\n3)Exit");
			//printf("\n\nUser Option:");
			memset(buf, 2, 0);
			//printf("\nbuf has this in it: %s", buf);			
			recv(connfd, buf, 2, 0);
			//printf("\nnew buf: %s", buf);
			memset(buf, 2, 0);
			//printf("\nnew buf: %s", buf);
			a = buf[0] - '0';
			
			//if()
			//	printf("\ngCount = %d", gCount);
			
			fflush(stdin);
			//printf("\n%d", a);
			switch(a)
			{	
				case 1: 
				{
					//printf("User is in mail service");
					do
					{
						pushN();
						
						if(recv(connfd, select2, 2, 0) < 0)
							perror("\nError in receiving selection");
						fflush(stdout);
						//updateUnread();
					
						//printf("\ninside mail - %s", select2);
						i = select2[0] - '0';
						
						
						//printf("%d", i);
						switch(i)
						{
							case 1:
								{
									//printf("Check Mail");
									
									checkMail();
									
									//printf("%d", i);
									break;
								}
							case 2:
								{
							
									sendMail();
									//printf("\nOut of send mail");
									break;
								}
							case 3:
							{
								/*  printf("Filter");
								filterInbox();
								break; 
							}
							case 4: */
							//{
								//printf("Change Service");
								break;
							}
						}
					}while(i < 3);
				}
				break;
			

				case 2:{
					//printf("User is in calender service");
					do
					{
						//printf("\n1)view calender\n2)request an appointment\n3)modify an appointment\n4)delete an appointment\n5)change service");
						//printf("\n\nUser Option:");
	//					scanf("%d",&s);
	//					buff[0] = (char)s;
						memset(select2, 2, 0);
						if(recv(connfd, select2, 2, 0) < 0)
							perror("\nError in receiving selection");
						fflush(stdout);
						
						//printf("%s", select2);
						i = select2[0] - '0';
						//printf("%d", i);
						switch(i)
						{
							case 1:
								{
									//printf("\nHere is your Calender");
									calenderView();
									break;
								}
							case 2:
								{
									requestappointment();
									break;
								}
						case 3:
						{
							////printf("Modify Calender Event");
							calenderView();
							memset(mcalbuff, 0, 2);
							if( (z = recv (connfd, mcalbuff, 2, 0)) < 0)
								perror("\nError in receiving");
							fflush(stdout); 
							mintcalbuff = atoi(mcalbuff);
							deletionnew(mintcalbuff, 'M' );
							////printf("\n in mintcalbuff is : %d", mintcalbuff);
							////printf("\nnow its the servers turn:%s", mcalbuff);
							requestappointment();
							break;
						
						}
						case 4:
						{
							//printf("Delete calender Event");
							calenderView();
							memset(dcalbuff,LENGTH,0);
							if(recv(connfd, dcalbuff, 2, 0) < 0)
								perror("\nError in receiving selection");
							fflush(stdout); 
							dintcalbuff = atoi(dcalbuff);
							deletionnew(dintcalbuff, 'D' );
							//printf("\n in mintcalbuff is : %d", dintcalbuff);
							//printf("\nnow its the servers turn:%s", mcalbuff);
							//printf("%s", dcalbuff);
							break;
						}
						case 5:
						{
							//printf("Change Service");
							break;
						}
					}
				}while(i < 5);
					break;
					}
				case 3:{
					//printf("exiting selection function\n");
					//send(sock, buf, 2, 0);
					 break;

					}
			}
		}while(a < 3);
		
	pthread_cancel(updation);
}
