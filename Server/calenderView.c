/*
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
*/
//typedef struct appointment appointment;

char mcalbuf[LENGTH] ;



void calenderView()
{
	
	FILE *fp;
	char *text;
	char c;
	int endIndex =0, calN = -1, end, tempIndex = 0, i;
	size_t len = 0;
	ssize_t flag;
	//printf("\nbuffcalusername:%s, %d", buffcalusername, strlen(buffcalusername));
	fp = fopen(buffcalusername,"rb");
	//printf("\n %s i am opening the file", fp);
	text = (char*) malloc (LENGTH);
	memset(text, 0, sizeof(text));
	printf("\n after the malloc");
	int count = 1;
	char ccount[4] = "\0";
	int ret;
	char bit[2] = "A";
	/*printf("\n after the variables");
	printf("\nbuffcalusername:%s", buffcalusername);
	printf("\nbuffcalusername:%s", buffcalusername);
	printf("\nbuffcalusername:%s", buffcalusername);
	printf("\nbuffcalusername:%s", buffcalusername);*/
	if( fp != NULL )
	{
		//printf("\n inside the loop");
		memset(text , 0 , LENGTH);
		while ((flag = getline( &text, &len, fp)) != -1) 
		{
			calN++;
			printf("\n%s", text);
			endIndex = 0;
			//end = strlen(temp);
			//printf("ends here");
			//cala[calN].flag = (char *) malloc (2);
			memset(cala[calN].flag,0,2);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].flag, text, endIndex);
			cala[calN].flag[endIndex] = '\0';
			////printf("%s", cala[calN].flag);
			
			ret = strcmp(cala[calN].flag, bit);
			//printf("%d", ret);
			////printf("%d", ret);
			if (ret == 0)
			{
			////printf("\nAppointment Number: %d",count);

			strcat(mcalbuf,"\nAppointment Number: ");
			sprintf(ccount, "%d" , count);
			//printf(ccount, "%d",count);			
			//itoa(count,ccount,10);
			//ccount = (char)count ;
			strcat(mcalbuf, ccount);

			tempIndex = ++endIndex;
			//cala[calN].startDate = (char *) malloc (LENGTH);
			memset(cala[calN].startDate,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].startDate, text+tempIndex, endIndex-tempIndex);
			cala[calN].startDate[endIndex] = '\0';

			strcat(mcalbuf,"\nStart date of appointment is: ");
			strcat(mcalbuf, cala[calN].startDate);
			
			//break;

			
			
			tempIndex = ++endIndex;
			//cala[calN].startTime = (char *) malloc (LENGTH);
			memset(cala[calN].startTime,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].startTime, text+tempIndex, endIndex-tempIndex);
			cala[calN].startTime[endIndex] = '\0';

			strcat(mcalbuf,"\nStart Time of appointment is: ");
			strcat(mcalbuf, cala[calN].startTime);

			tempIndex = ++endIndex;
			//cala[calN].endDate = (char *) malloc (LENGTH);
			memset(cala[calN].endDate,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].endDate, text+tempIndex, endIndex-tempIndex);
			cala[calN].endDate[endIndex] = '\0';
			////printf(,cala[calN].endDate);

			strcat(mcalbuf,"\nEnd date of appointment is: ");
			strcat(mcalbuf, cala[calN].endDate);

			
			tempIndex = ++endIndex;
			//cala[calN].endTime = (char *) malloc (LENGTH);
			memset(cala[calN].endTime,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].endTime, text+tempIndex, endIndex-tempIndex);
			cala[calN].endTime[endIndex] = '\0';
			//printf("\ncaltime%s",cala[calN].endTime);

			strcat(mcalbuf,"\nEnd time of appointment is: ");
			strcat(mcalbuf, cala[calN].endTime);

			
			tempIndex = ++endIndex;
			//cala[calN].seqnum = (char *) malloc (LENGTH);
			memset(cala[calN].seqnum,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].seqnum, text+tempIndex, endIndex-tempIndex);
			cala[calN].endTime[endIndex] = '\0';
			//printf(,cala[calN].seqnum);
			
			//strcat(mcalbuf,"\nsequence number: ");
			//strcat(mcalbuf, cala[calN].seqnum);
			
			tempIndex = ++endIndex;
			//cala[calN].meetingUsernames = (char *) malloc (LENGTH);
			memset(cala[calN].meetingUsernames,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].meetingUsernames, text+tempIndex, endIndex-tempIndex);
			cala[calN].meetingUsernames[endIndex] = '\0';
			////printf(,cala[calN].meetingUsernames);

			strcat(mcalbuf,"\nPeople meeting at this apointment is: ");
			strcat(mcalbuf, cala[calN].meetingUsernames);
			
			tempIndex = ++endIndex;
			//cala[calN].place = (char *) malloc (LENGTH);
			memset(cala[calN].place,0,LENGTH);
			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].place, text+tempIndex, endIndex-tempIndex);
			cala[calN].place[endIndex] = '\0';
			////printf(,cala[calN].place);
			
			strcat(mcalbuf,"\nPlace of meeting: ");
			strcat(mcalbuf, cala[calN].place);

			tempIndex = ++endIndex;
			//cala[calN].desc = (char *) malloc (LENGTH);
			memset(cala[calN].desc,0,LENGTH);

			while(text[endIndex]!= '|')
					endIndex++;
			strncpy(cala[calN].desc, text+tempIndex, endIndex-tempIndex);
			cala[calN].desc[endIndex] = '\0';
			////printf("\nPurpose of meeting: %s",cala[calN].desc);
			
			strcat(mcalbuf,"\nPurpose of meeting: ");
			strcat(mcalbuf, cala[calN].desc);
			strcat(mcalbuf, "\n");
			memset(text, 0, sizeof(text));
			
			//printf("%d",calN);
			}
			else 
					continue;
		count++;
		}
		
		
	}

	fclose(fp);
	//printf("\nmbufcal - %s", mcalbuf);
	if( ( send( connfd, mcalbuf, LENGTH, 0) <= 0) )
		printf("\nError in sending");
	memset(mcalbuf , 0 , sizeof(mcalbuf));
	////printf("%s", mcalbuf);
	//return cala;

}

/*
int main()
{
	char t[10] = "\0";
	
	checkcal("test.txt");
	
	////printf("\nData structure - \n%d,%s,%s,%s,%s,%s,%s,%s,%s.", strlen(t), cala[3].flag, cala[3].startDate, cala[3].startTime, cala[3].endDate, cala[3].endTime, cala[3].meetingUsernames, cala[3].place, cala[3].desc);
	return 1;
}
*/
