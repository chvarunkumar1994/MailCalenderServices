//header files
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

//Maximum length of buffer that the client can send or receive
#define LENGTH 5000

//Port number used for connecting to the mail server
#define SERV1_PORT 5000

//Port number used for connecting to the calender server
#define SERV2_PORT 6043

int m,s, subTop, ctime;
int sock, c, count, n, j;	
int notify; //changed here
struct sockaddr_in server;
struct hostent *hp; 
char w[3];
char buffSendUser[LENGTH] , buffSendBody[LENGTH], buffSendAttach[LENGTH] , buffSendAData[LENGTH], buffSendSub[LENGTH] ,buff[LENGTH] ,buf[LENGTH], *temp;	
char *temp,buffAppointment[LENGTH], buffMeetingUsernames[LENGTH], buffDateM[LENGTH], buffTimeM[LENGTH], bufftotaltime[LENGTH];
//char meetingUsernames[10][16];
char startDate[11],endDate[11],startTime[6], endTime[6];
char calFileData[LENGTH];
char *temp, buffAppointment[LENGTH],buffMeetingUsernames[LENGTH];
char meetingUsernames[100] ;
char currentUsername[16] ,buffUsername[16];
char bufcal[LENGTH];
//calander variables for modify and delete
char mbuffcal[2], dbuffcal[2];
char mc, dc;
char calbuf[LENGTH], t1[3];
//char mcalbuf[LENGTH];
int z;
int calbuffstringlenght, k;


struct appointment
{
	char startDate[11],startTime[6],endDate[11], endTime[6];
};
struct maildt
{
	char EDate[11],ETime[6];
};
typedef struct appointment current_appointment;
current_appointment appointment;
typedef struct maildt dateandtime;
dateandtime maildt;
char prevStartDate[11],prevEndDate[11],prevStartTime[6], prevEndTime[6];
int day[2], month[2], year[2], hours[2], mins[2],i;



//inside main
char buffUsername[16] , buffPassword[16], buffFirstName[16], buffLastName[16];
int stopcase, service = 1;
    
int validateDate();
int validateTime();
int validateAppointment();
char calcheck();
//void newAppointment();
//void modify();
//void deletecal();
void calview();
//void modifycal();
void modify();
void modifycallrequest();
void filterInboxc();
