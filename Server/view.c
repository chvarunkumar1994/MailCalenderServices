//#include "header.c"

void viewMail(int* index, int count)
{
	char user[30], sendBuffer[100*LENGTH] = "", countInChar[5], recvOption[5], att[2], validNum[5], rfOptions[5], at[2], ex[3];
	int t, clientCount, actualIndex[100], recvOpt, i, indexTop = 0, a, x, deleteNo, t12;
	mail f;
	//count = 0;
	//clientCount = 1;
	if(count <= 0)
	{	
		send(connfd, "!", 1, 0);
		return;
	}	
	strcpy(user, buffUsername);
	strcat(user, ".txt");
//	retrieveInbox(user);
	while(indexTop < count)
	{
		
		sprintf(countInChar, "%d", indexTop + 1);
		strcat(sendBuffer, countInChar);
		strcat(sendBuffer, "\t");
		
		strcat(sendBuffer, inbox[index[indexTop]].read);
		strcat(sendBuffer, "\t");
		t = strlen(sendBuffer);
		i = 0;
		printf("%d", i);
		while(inbox[index[indexTop]].userName[i] != '\0')
		{
			sendBuffer[t++] = inbox[index[indexTop]].userName[i++];
			//strcat(sendBuffer, inbox[index[indexTop]].userName);
		}
		strcat(sendBuffer, "\t");
		
		//strcat(sendBuffer, inboxindex[indexTop].firstName);
		//strcat(sendBuffer, "\t");
		
		//strcat(sendBuffer, inboxindex[indexTop].lastName);
		//strcat(sendBuffer, "\t");
		
		strcat(sendBuffer, inbox[index[indexTop]].subject);
		strcat(sendBuffer, "\t\t\t");
		
		strcat(sendBuffer, inbox[index[indexTop]].era);
		strcat(sendBuffer, "\n");
		
		indexTop++;
		
	}
	
	//printf("\n Sending buffer - %s", sendBuffer);
	if(send(connfd, sendBuffer, strlen(sendBuffer), 0) <= 0)
		perror("Error in sending\n");
	fflush(stdin);

		//update unread messages that the user knows
		updatelCount();

	memset(recvOption , 0 , 5);
	if(recv(connfd,recvOption, 5, 0) <= 0)
		perror("Error in receiving user option\n");
	fflush(stdout);

	recvOpt = (int)strtoul(recvOption, NULL,10);
	//printf("received option in int - %d", recvOpt);
		
	recvOpt--;
	stpcpy(validNum,"Y");
	memset(sendBuffer, 0, sizeof(sendBuffer));
	if(recvOpt > -1 && recvOpt < 100 && inbox[index[recvOpt]].userName != NULL && recvOpt+1 <= count)
	{
		printf("%s", inbox[index[recvOpt]].userName);
		//send that the number is valid
		send(connfd, validNum, strlen(validNum), 0);
		strcpy(sendBuffer, "\n");
		
		t = index[recvOpt];
		printf("COunt - %d, Actual index %d, recv -%d", count, t, recvOpt);
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
		
		strcat(sendBuffer, "DATE AND TIME: ");
		strcat(sendBuffer, inbox[t].era);
		strcat(sendBuffer, "\n");
		
		strcat(sendBuffer, "BODY: ");
		strcat(sendBuffer, inbox[t].msgBody);
		strcat(sendBuffer, "\n");
		
		//make that mail as read
		printf("t = %d, recvOpt = %d", t, recvOpt);
		printf("\nWhile making READ %d", t + 1);		
		modifyInFile(user, t + 1, "R");
		deleteNo = t + 1;
		
		//memset(ex, 0, 3);
		x = strlen(sendBuffer);		
		sprintf(ex, "%d", x);		
		send(connfd, ex, 3, 0);
		
			

		//sending complete email now except attachment
		if((send(connfd, sendBuffer, x, 0)) < 0)
			printf("error in sending emailInfo");
		
		for(t12 = 0; t12 < 5; t12++)
		printf("\n\n*@@***filename -%s.", inbox[t12].fileName);
		t12 = index[recvOpt];
		if((inbox[t12].fileName[0] != '\0' && strlen(inbox[t12].fileName) > 3))
		{
			fflush(stdout);				
			memset(att, 0, 2);
			
			printf("\n@@%d %s %d",t12, inbox[t12].fileName, strlen(inbox[t12].fileName));
			
			
			//printf("%d", strlen(inbox[t].fileName));
			//strcpy(att, "N");
			att[0] = 'Y';
			if(send(connfd, att, 1, 0)<=0)
				printf("error in sending attachment flag");
			//printf("\nNo attachment\n");
			fflush(stdout);
		}
		else
		{
			//printf("\nYes attachment\n");
			fflush(stdout);
			memset(att, 0 , 2);
			//strcpy(att, "Y");
			att[0] = 'N';
			if(send(connfd, att, 1, 0)<=0)
				printf("\nerror in sending attachment flag");
			fflush(stdout);
		}
			//user preference to save the rfOptionsachment
			memset(rfOptions, 0 , 2);
			if((recv(connfd, rfOptions, 1, 0)<=0))
				printf("\nError in receiving attachment preference");
			fflush(stdout);
			//printf("att - %s, rfOptions - %s", att, rfOptions);





			//If user requests for rfOptionsachment
			if((att[0] == 'Y') && (rfOptions[0] == 'A' || rfOptions[0] == 'a'))
			{
				
				//puts(inbox[t].fileName);
				//printf("filename  - %s, filebody - %s", inbox[t12].fileName, inbox[t12].fileBody);
				a = strlen(inbox[t12].fileName);
				sprintf(at, "%d", a);
				//printf("^^^^^%d %s", a, at);
				send(connfd, at, 2, 0);
			
				
				if(send(connfd, inbox[t12].fileName, a, 0) <= 0)
					printf("\nError in sending filename");
				fflush(stdout);
				//printf("filebody -");
				puts(inbox[t12].fileBody);



				a = strlen(inbox[t12].fileBody);
				sprintf(at, "%d", a);
				send(connfd, at, 2, 0);
			
				if((send(connfd, inbox[t12].fileBody, strlen(inbox[t12].fileBody), 0)) <= 0)
					printf("\nError in sending filename");
				//printf("abc");
			//	return;
			
			}
			else if(rfOptions[0] == 'R' || rfOptions[0] == 'r')
			{
				//printf("\nReply email\n");
				fflush(stdin);
				reply(inbox[t12].userName);
			}
			else if(rfOptions[0] == 'F' || rfOptions[0] == 'f')
			{
				f = inbox[t12];
				strcpy(f.userName, buffUsername);
				fflush(stdout);
				//insert timestamp
				forward(f);
			}
			else if(rfOptions[0] == 'D' || rfOptions[0] == 'd')
			{
				//printf("\nWhile making READ %d", t12 + 1);			
				modifyInFile(user, deleteNo , "D");
				//printf("\nWhile making READ %d", t12+ 1);
			}
			else if(rfOptions[0] == 'S' || rfOptions[0] == 's')
			{
				filterInbox();
			}
			
			
	}
	else
	{
		strcpy(validNum, "N");
		send(connfd, validNum, strlen(validNum), 0);
		return;
	}
	
	//printf("\nterminating view");
} 
