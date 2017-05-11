#include "headerc.c"
void selection()
{			
	char option[LENGTH], sub, fileRead;
	int attachTop, a, b, i, j;

	printf("\nYou are in mail/calender service");

	do
	{
		printf("\n1)Mail Service\n2)Calender Service\n3)Exit");
		printf("\n\nYour Option:");
		scanf("%s",buff);
		send(sock, buff, 2, 0);
		a = buff[0] - '0';
		printf("%d", a);
		
		switch(a)
		{	
			case 1: 
			{
				printf("\n******************You are in mail service******************");
				do
				{
					printf("\n1)Check Mail\n2)Send Mail\n3)Filter\n4)Change Service");
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
							break;
						}
						case 2:
						{
							sendMailc();
							break;	
						}
						
						case 3:
						{
							printf("Filter");
							break;
						
						}
						
						case 4:
						{
							printf("Change Service");
							break;
						}
						
					}
				}while(b < 4);
			break;
			}

			case 2:
			{
			}
			break;
			case 3:
			{
				close(sock);
				m = 3;
			}
			break;
		}
	}while(a < 3);
}
