#include "headerc.c"
#include "pushNc.c"
#include "replyc.c"
#include "forwardc.c"
#include "viewc.c"
#include "filterc.c"
#include "sendMailc.c"
#include "checkMailc.c"
#include "selectionServicesc.c"
#include "existingUserc.c"
#include "createNewUserc.c"
#include "validateAppointment.c"
#include "validateDate.c"
#include "validateTime.c"
//#include "deletecal.c"
//#include "modify.c"
//#include "newAppointment.c"
#include "calview.c"
#include "modify.c"
#include "modifycallrequest.c"


int main( int argc, char *argv[])
{
  
	int pid;
    //Structure to connect to the server
   temp = (char*)malloc(LENGTH);
			
    if( argc != 2 )
    {
        printf("\nExecution requires the hostname of server\n");
        exit(0);
    }
    
	sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket failed");
        exit(1);
    }
                                     
    server.sin_family = AF_INET;
                                    
    //Checking if the hostname exists
    hp = gethostbyname(argv[1]);
	if(hp == 0)
	{
		perror("gethost by name failed");
		exit(1);
	}
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
									
	server.sin_port = htons(SERV2_PORT);
	printf("\nWaiting for connection from server\n");
	//sleep(1);
                                    
	//Connecting to the socket of the mail server
	if(connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
	{
		perror("\nconnect failed");
		close(sock);
		exit(1);
	}
	else
		printf("\nConnected to server");
	c = 1;

	//Requesting for mail services based on the user request
	while(c < 3)
	{
		printf("\n ***WELCOME TO MAIL/CALENDER SERVICE*** \n");
		printf("\n ***Choose any one of the options below***\n");
		printf("\n1)Existing User Login\n2)Create a new account\n3)Exit mail/calender service");
		printf("\n\nYour Option:");
		scanf("%s", buff);

		//buff[0] = (char)c;
		send(sock, buff, 2, 0);

		switch(buff[0])
		{
			case '1': 
			{   
				existingUserc();
				break;

			}
			
			//validating username and password
					
			case '2': 
			{  

				createNewUserc();
				break;
			}
			
			case '3':
			{    
				//Terminating the connection between a client and the mail server
				printf("\nExit services\n");
				close(sock);
				exit(1);
				c = 3;
				break;

			}
		}
	}   
}




