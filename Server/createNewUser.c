void createNewUser()
{
				//	printf("\n**********Creating A New Account********* \n"); 
                                 
					
                            do
								{
									j = -1;					
									memset(buffUsername, 0, 16);
									if( (n = recv (connfd, buffUsername, 16, 0)) < 0)
															perror("\nError in receiving");
													fflush(stdout); 
									tempUser.userName = (char*) malloc (100);
												strcpy(tempUser.userName, buffUsername);
									tempUser.userName[strlen(buffUsername)] = '\0';
								//	printf("Username is:  %s \n" ,buffUsername); 

									if(fetchUser(tempUser.userName) == NULL)
										j = 1;

									else if(j == -1)
										printf("\nThis is shit!");
									else
										j = 0;
									buf[0] = (char)j;
									buf[1] = '\0';
									send(connfd,buf,2,0);
									if ( buf[0] == '1');		
										{
											strcpy(buffcalusername,tempUser.userName);
											strcat(buffcalusername, "_c.txt");
										}
								}while(j != 1);



                            memset(buffPassword, 0, 16);
					
                            if( (n = recv (connfd, buffPassword, 16, 0)) < 0)
                                perror("\nError in receiving");
                            fflush(stdout); 
                            tempUser.password = buffPassword;
							//printf("Password is:  %s \n" ,buffPassword); 

							memset(buffFirstName, 0, 16);
					
                            if( (n = recv (connfd, buffFirstName, 16, 0)) < 0)
                                perror("\nError in receiving");
                            fflush(stdout); 
                            tempUser.firstName = buffFirstName;
							//printf("First name is:  %s \n" ,buffFirstName); 

                                    
                            memset(buffLastName, 0, 16);
					
                            if( (n = recv (connfd, buffLastName, 16, 0)) < 0)
                                perror("\nError in receiving");
                            fflush(stdout); 
                         	tempUser.lastName = buffLastName;	           
							//printf("Last Name is:  %s \n" ,buffLastName); 
                                    
							signUp(tempUser);
							selection();
}
