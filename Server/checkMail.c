//#include "header.c"
//#include "retrieveInbox.c" //comment this later 

void checkMail()
{
	char user[30], sendBuffer[100*LENGTH] , countInChar[5], recvOption[5], att[2], validNum[5];
	int count, t, clientCount, actualIndex[100], recvOpt,reverse[100],i,j;
	count = 0;
	clientCount = 0;
	memset(user, 0, sizeof(user));
	strcpy(user, buffUsername);
	strcat(user, ".txt");

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
	//printf("\nIn Inbox service\n");
	retrieveInbox(user);
	
	while(strlen(inbox[count].userName) > 0 )
	{
	
		if( strcmp (inbox[count].read, "D") == 0 )
		{
			count++;
			continue;
		}
		
		actualIndex[clientCount++] = count++;
	//	printf("%d", actualIndex[clientCount - 1]);
		
	}
	//printf("\nNumber of emails - %d,", clientCount);
	if(clientCount == 0)
	{
		send(connfd, "!", 1, 0);
		return;
	}
	
	for(i=clientCount-1 , j=0; i >=0;i--,j++)
	{
		reverse[i] = actualIndex[j];
	}
	//printf("\ncalling view");
	viewMail(reverse, clientCount);
	//strcpy(user, "asdf");
	/*if(send(connfd, user, 4, 0) <= 0)
		printf("unable to send");*/

	/*if(send(connfd, user, 4, 0) <= 0)
		printf("unable to send");)*/

}
/*
int main()
{
	
	return 1;
}*/
