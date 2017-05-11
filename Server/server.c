#include "header.c"
#include "pushN.c"
#include "updatelCount.c"
#include "updateUnread.c"
#include "fetchUser.c"
#include "writeMail.c"
#include "forward.c"
#include "sendMail.c"
#include "reply.c"

#include "retrieveUser.c"
#include "signUp.c"
#include "deletion.c"
#include "retrieveInbox.c"
#include "view.c"

#include "filter.c"
#include "checkMail.c"
#include "selectionServices.c"
#include "existingUser.c"
#include "createNewUser.c"
#include "appointmentAvailability.c"
#include "appointmentInvolvedUsers.c"
#include "validateAppointment.c"
#include "calenderView.c"
#include "calappointment.c"
#include "deletionnew.c"
#include "deletions.c"
#include "mcalview.c"
#include "requestappointment.c"


void* services();
void ed();

int main()
{
    pthread_t MailCalendar;
    line = (char*) malloc (LENGTH);
	 //new
    //creation of socket
    listenfd = socket (AF_INET, SOCK_STREAM, 0);
    printf("\nWelcome to THE 3 Server!");
    
    //creating socket address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV2_PORT);

    printf("\nServers running.. waiting for connections");
    bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
   

    //Listening to the socket for client connections
    listen(listenfd, LISTENQ);
    //Creating the services of the server
    pthread_create ( &MailCalendar, NULL, services, NULL);
   //  pthread_create ( &Cryptography, NULL, ed, NULL);
    
				
	//Allowing the services to be implemented
    sleep(1000);
    
    return 0;
}


//Implementation of services
void* services()
{

    
    //Indefinitely implementing the services requested by the clients
    for(; ;)
    {
        //Condition to stop the server
		int i,pid2;
        stopserver = 0;
      
        clilen = sizeof(cliaddr);
        
       
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
       
        
        if( (pid = fork()) < 0)
            perror("\nError in fork");
        
        else
        {
            if(pid != 0)
            {
                printf("\nClient terminated abruptly!");
				//kill(pid, SIGKILL);
                close(connfd);
                continue;
            }
            else
            {
                
				line1 = (char*) malloc (LENGTH);
				
    
				
				for( i = 0; i < 100; i++)
					{
						inbox[i].read = (char*) malloc (2);
						inbox[i].userName = (char*) malloc (LENGTH);
						inbox[i].firstName = (char*) malloc (LENGTH);
						inbox[i].lastName = (char*) malloc (LENGTH);
						inbox[i].subject = (char*) malloc (LENGTH);
						inbox[i].msgBody = (char*) malloc (LENGTH);
						inbox[i].fileName = (char*) malloc (LENGTH);
						inbox[i].fileBody = (char*) malloc (LENGTH);
						inbox[i].era  = (char*) malloc (LENGTH);
						cala[i].flag = (char *) malloc (2);
						cala[i].startDate = (char *) malloc (LENGTH);
						cala[i].startTime = (char *) malloc (LENGTH);
						cala[i].endDate = (char *) malloc (LENGTH);
						cala[i].endTime = (char *) malloc (LENGTH);
						cala[i].seqnum = (char *) malloc (LENGTH);
						cala[i].meetingUsernames = (char *) malloc (LENGTH);
						cala[i].place = (char *) malloc (LENGTH);
						cala[i].desc = (char *) malloc (LENGTH);
					}
                    
						mailInfo.read = (char*) malloc (2);
						mailInfo.userName = (char*) malloc (LENGTH);
						mailInfo.firstName = (char*) malloc (LENGTH);
						mailInfo.lastName = (char*) malloc (LENGTH);
						mailInfo.subject = (char*) malloc (LENGTH);
						mailInfo.msgBody = (char*) malloc (LENGTH);
						mailInfo.fileName = (char*) malloc (LENGTH);
						mailInfo.fileBody = (char*) malloc (LENGTH);
						mailInfo.era  = (char*) malloc (LENGTH);
						receipient1 = (user*) malloc (sizeof(user));
						
                while(stopserver == 0)
                {
                    memset(buf, 0, LENGTH);
                    for( i = 0; i < 100; i++)
					{
						memset(inbox[i].read, 0, 2);
						memset(inbox[i].userName, 0, LENGTH);
						memset(inbox[i].firstName, 0, LENGTH);
						memset(inbox[i].lastName, 0, LENGTH);
						memset(inbox[i].subject, 0, LENGTH);
						memset(inbox[i].msgBody, 0, LENGTH);
						memset(inbox[i].fileName, 0, LENGTH);
						memset(inbox[i].fileBody, 0, LENGTH);
						memset(inbox[i].era, 0, LENGTH);
					}
                    //fflush(stdout);
                    printf("\nbuff is %c",buf[0]);
						rUser.userName = (char*) malloc(100);
		    if(recv(connfd, buf, 2, 0) < 0)
                    {
                         printf("\nTerminating a connection");
                         close(connfd);
                         stopserver = 1;
                         break;
                    }
					
					
		    printf("\nnew buff is %c",buf[0]);
                    switch(buf[0])
                    {
                        case '1':
						{ 
								existingUser();
								break;
						}          //send(connfd,buf,n,0);
                                    
                        case '2':
						{   
								createNewUser();
								break;
						}
                        
                        
                        case '3':
                        {   
							printf("\nTerminating a connection");
							pid2 = getpid();
							if(strcmp(buffUsername, "admin") == 0)
								kill(pid, SIGKILL);
							else
								kill(pid2, SIGKILL);
							//close(connfd);
							stopserver = 1;
							break;
                        }
						//break;
                          
                    }
                }
			printf("\nSocket has been closed!!!");
			close(connfd);
            }
        }      
    }
}






