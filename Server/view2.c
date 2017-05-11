//#include "header.c"

void viewMail(int* index, int count)
{
	printf("check");
	/*
	char user[30], sendBuffer[100*LENGTH] = "", countInChar[5], recvOption[5], att[2], validNum[5], rfOptions[5];
	int t, clientCount, actualIndex[100], recvOpt, indexTop = 0;
	mail f;
	//count = 0;
	//clientCount = 1;
	memset(user, 0, sizeof(user));
	strcpy(user, buffUsername);
	strcat(user, ".txt");
	//retrieveInbox(user);
	printf("count - %d\nIndexTop - ", count);
	memset(sendBuffer, 0, sizeof(sendBuffer));
	while(indexTop < count)
	{
		printf("%d", indexTop);
		sprintf(countInChar, "%d", indexTop + 1);
		strcat(sendBuffer, countInChar);
		strcat(sendBuffer, "\t");
		
		strcat(sendBuffer, inbox[index[indexTop]].read);
		strcat(sendBuffer, "\t");
		printf("%s", inbox[index[indexTop]].read);
		strcat(sendBuffer, inbox[index[indexTop]].userName);
		strcat(sendBuffer, "\t");
		printf("%s", inbox[index[indexTop]].userName);
		//strcat(sendBuffer, inboxindex[indexTop].firstName);
		//strcat(sendBuffer, "\t");
		
		//strcat(sendBuffer, inboxindex[indexTop].lastName);
		//strcat(sendBuffer, "\t");
		
		strcat(sendBuffer, inbox[index[indexTop]].subject);
		strcat(sendBuffer, "\t");
		printf("%s", inbox[index[indexTop]].subject);
		strcat(sendBuffer, inbox[index[indexTop]].era);
		strcat(sendBuffer, "\n");
		printf("%s", inbox[index[indexTop]].era);
		
		indexTop++;
		
	}
	sendBuffer[strlen(sendBuffer)] = '\0';
	printf("\n Sending buffer - %s, sendBuffer");
		if(send(connfd, sendBuffer, strlen(sendBuffer), 0) < 0)
		perror("Error in receiving user choice\n");
	fflush(stdout);

	memset(sendBuffer, 0 ,strlen(sendBuffer));

	//if(recv(connfd, recvOption, 5, 0) < 0)
	//	perror("Error in receiving user option\n");
	//fflush(stdout);

	recvOpt = (int)strtoul(recvOption, NULL,10);
	printf("received option in int - %d", recvOpt);
		
	recvOpt--;
	stpcpy(validNum,"Y");

	if(recvOpt > -1 && recvOpt < 100 && inbox[index[recvOpt]].userName != NULL)
	{
		printf("%s", inbox[index[recvOpt]].userName);
		//send that the number is valid
		send(connfd, validNum, strlen(validNum), 0);
		strcpy(sendBuffer, "\n");
		
		t = index[recvOpt];
		printf("Actual index %d, recv -%d", t, recvOpt);
		sprintf(countInChar, "%d", recvOpt);
		strcat(sendBuffer, countInChar);
		strcat(sendBuffer, "\n");
		
		strcat(sendBuffer, "USERNAME: ");
		strcat(sendBuffer, inbox[t].userName);
		strcat(sendBuffer, "\n");
		
		strcat(sendBuffer, "FIRST NAME ");
		strcat(sendBuffer, inbox[t].firstName);
		strcat(sendBuffer, "\n");
		
		strcat(sendBuffer, "LAST NAME: ");
		strcat(sendBuffer, inbox[t].lastName);
		strcat(sendBuffer, "\n");
		
		strcat(sendBuffer, "SUBJECT: ");
		strcat(sendBuffer, inbox[t].subject);
		strcat(sendBuffer, "\n");
		
		strcat(sendBuffer, "BODY: ");
		strcat(sendBuffer, inbox[t].msgBody);
		strcat(sendBuffer, "\n");
		
		//make that mail as read
		//printf("t = %d, recvOpt = %d", t, recvOpt);
		modifyInFile(user, t + 1, "R");
		
		//sending complete email now except attachment
		send(connfd, sendBuffer, strlen(sendBuffer), 0);
		printf("filename - %s.", inbox[t].fileName);
		if(inbox[t].fileName == NULL)
		{
			memset(att, 0, 2);
			fflush(stdin);
			strcpy(att, "N");
			send(connfd, att, 1, 0);
			printf("\nNo attachment\n");
			fflush(stdout);
		}
		else
		{
			printf("\nYes attachment\n");
			fflush(stdin);
			memset(att, 0 , 2);
			strcpy(att, "Y");
			send(connfd, att, 1, 0);
			fflush(stdout);
		}
			//user preference to save the rfOptionsachment
			memset(rfOptions, 0 , 2);
			recv(connfd, rfOptions, 1, 0);
			fflush(stdout);
			printf("att - %s, rfOptions - %s", att, rfOptions);
			//If user requests for rfOptionsachment
			if(att[0] == 'Y' && (rfOptions[0] == 'A' || rfOptions[0] == 'a'))
			{
				send(connfd, inbox[t].fileName, strlen(inbox[t].fileName), 0);
				send(connfd, inbox[t].fileBody, strlen(inbox[t].fileBody), 0);
			
			}
			else if(rfOptions[0] == 'R' || rfOptions[0] == 'r')
			{
				printf("\nReply email\n");
				fflush(stdin);
				reply(inbox[t].userName);
			}
			else if(rfOptions[0] == 'F' || rfOptions[0] == 'f')
			{
				f = inbox[t];
				strcpy(f.userName, buffUsername);
				fflush(stdout);
				//insert timestamp
				forward(f);
			}
			else if(rfOptions[0] == 'D' || rfOptions[0] == 'd')
			{
				modifyInFile(user, t + 1, "D");
			}
			
			
	}
	else
	{
		strcpy(validNum, "N");
		send(connfd, validNum, strlen(validNum), 0);
		return;
	}*/
} 