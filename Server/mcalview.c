#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LENGTH 5000

//typedef struct appointment appointment;

char mmcalbuf[LENGTH] ;



cal* mcalenderView()
{
	
	FILE *userAuth;
	char *line;
	char c;
	int endIndex =0, calN = -1, end, tempIndex = 0, i;
	size_t len = 0;
	ssize_t flag;
	userAuth = fopen(buffcalusername,"r");
	line = (char*) malloc (LENGTH);
	int count = 1;
	char ccount[4];
	int ret;
	char bit[2] = "A";

	if( userAuth != NULL )
	{
		//memset(mcalbuf , 0 , LENGTH);
		while ((flag = getline( &line, &len, userAuth)) != -1) 
		{
			calN++;
			////printf("\n%s", line);
			endIndex = 0;
			//end = strlen(temp);
			
			cala[calN].flag = (char *) malloc (2);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].flag, line, endIndex);
			cala[calN].flag[endIndex] = '\0';
			////printf("%s", cala[calN].flag);
			
			ret = strcmp(cala[calN].flag, bit);
			////printf("%d", ret);
			////printf("%d", ret);
			if (ret == 0)
			{
			////printf("\nAppointment Number: %d",count);

			strcat(mcalbuf,"\nAppointment Number: ");
			//printf(ccount, "%d",count);			
			//itoa(count,ccount,10);
			//ccount = (char)count ;
			strcat(mcalbuf, ccount);

			tempIndex = ++endIndex;
			cala[calN].startDate = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].startDate, line+tempIndex, endIndex-tempIndex);
			cala[calN].startDate[endIndex] = '\0';

			strcat(mcalbuf,"\nStart date of appointment is: ");
			strcat(mcalbuf, cala[calN].startDate);
			
			//break;

			
			
			tempIndex = ++endIndex;
			cala[calN].startTime = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].startTime, line+tempIndex, endIndex-tempIndex);
			cala[calN].startTime[endIndex] = '\0';

			strcat(mcalbuf,"\nStart Time of appointment is: ");
			strcat(mcalbuf, cala[calN].startTime);

			tempIndex = ++endIndex;
			cala[calN].endDate = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].endDate, line+tempIndex, endIndex-tempIndex);
			cala[calN].endDate[endIndex] = '\0';
			////printf(,cala[calN].endDate);

			strcat(mcalbuf,"\nEnd date of appointment is: ");
			strcat(mcalbuf, cala[calN].endDate);

			
			tempIndex = ++endIndex;
			cala[calN].endTime = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].endTime, line+tempIndex, endIndex-tempIndex);
			cala[calN].endTime[endIndex] = '\0';
			////printf(,cala[calN].endTime);

			strcat(mcalbuf,"\nEnd time of appointment is: ");
			strcat(mcalbuf, cala[calN].endTime);

			
			tempIndex = ++endIndex;
			cala[calN].seqnum = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].seqnum, line+tempIndex, endIndex-tempIndex);
			cala[calN].endTime[endIndex] = '\0';
			////printf(,cala[calN].seqnum);
			
			//strcat(mcalbuf,"\nsequence number: ");
			//strcat(mcalbuf, cala[calN].seqnum);
			
			tempIndex = ++endIndex;
			cala[calN].meetingUsernames = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].meetingUsernames, line+tempIndex, endIndex-tempIndex);
			cala[calN].meetingUsernames[endIndex] = '\0';
			////printf(,cala[calN].meetingUsernames);

			strcat(mcalbuf,"\nPeople meeting at this apointment is: ");
			strcat(mcalbuf, cala[calN].meetingUsernames);
			
			tempIndex = ++endIndex;
			cala[calN].place = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].place, line+tempIndex, endIndex-tempIndex);
			cala[calN].place[endIndex] = '\0';
			////printf(,cala[calN].place);
			
			strcat(mcalbuf,"\nPlace of meeting: ");
			strcat(mcalbuf, cala[calN].place);

			tempIndex = ++endIndex;
			cala[calN].desc = (char *) malloc (LENGTH);
			while(line[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].desc, line+tempIndex, endIndex-tempIndex);
			cala[calN].desc[endIndex] = '\0';
			////printf("\nPurpose of meeting: %s",cala[calN].desc);
			
			strcat(mcalbuf,"\nPurpose of meeting: ");
			strcat(mcalbuf, cala[calN].desc);
			strcat(mcalbuf, "\n");
			
			}
			else 
					continue;
		count++;
		}
		
		
	}
	else 
		return NULL;
	fclose(userAuth);
	if( ( send( connfd, mcalbuf, LENGTH, 0) < 0) )
		//printf("\nError in sending");
	memset(mcalbuf , 0 , LENGTH);
	////printf("%s", mcalbuf);
	return cala;

}
