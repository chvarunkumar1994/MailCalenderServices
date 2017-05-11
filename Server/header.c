//header files   
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>	
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define LENGTH 5000 //Maximum length of buffer to transfer bet	ween servers and clients
#define SERV1_PORT 4000 //Port number to connect to the Mail Server
#define SERV2_PORT 6043//Port//Port number to connect to the Calender Server
#define LISTENQ 8 //Maximum number of clients that can interact with the server
#define LINESIZE 5000


int listenfd, connfd, ccount, scookie[5], choice, i, stopserver = 0;
char buf[LENGTH], *temp;
char meetingUsernames[10][20], buffMeetingUsernames[LENGTH];
socklen_t clilen;
struct sockaddr_in cliaddr, servaddr;
int n, pid, j, stopcase;
char buffUsername[16] , buffPassword[16], buffFirstName[16], buffLastName[16],  select2[2];
char buffSendUser[LENGTH] , buffSendBody[LENGTH], buffSendAttach[LENGTH] , buffSendSub[LENGTH] ,buff[LENGTH] , buff2[LENGTH] ,buf[LENGTH], buffTimeM[LENGTH], buffDateM[LENGTH];
time_t rawtime;
struct tm *t;
char *line, *line1;
int notify;
char buffAppointment[LENGTH], buffMeetingUsernames[LENGTH];
char startDate[11],endDate[11],startTime[6], endTime[6];
char calFileData[LENGTH];
int day[4], month[4], year[4], hours[4], mins[4],i, lCount; //this is
char buffcalusername[LENGTH];
//calander for modifying and deleting
char mcalbuff[2], dcalbuff[2];
char mcalbuf[LENGTH];
int z,k;
char seqnumret[3], t1[3];
int gCount;
struct appointment
{
  char startDate[11],startTime[6],endDate[11], endTime[6];
};
typedef struct appointment appointment;
appointment existingAppointment;
appointment requestedAppointment;
struct calAppointmentContent
{
	char flag[1];
	appointment existingAppointment;
	char meetingUsernames[10][16];
	char place[30];
	char desc[100];
};
typedef struct calAppointmentContent calAppContent;
calAppContent existingAppointmentContent;


struct calender
{
	char *flag;
	char *startDate;
	char *startTime;
	char *endDate;
	char *endTime;
	char *seqnum;
	char *meetingUsernames;
	char *place;
	char *desc;

};
typedef struct calender cal;
cal tempcal, cala[100];





struct emailInfo
{
	char *userName, *firstName, *lastName, *subject, *msgBody, *msgAttached, *fileName, *fileBody , *read, *era;
	int seqNo;
};
struct userCredentials
{
	char *firstName, *lastName, *password, *userName;
};

typedef struct userCredentials user;
user tempUser, *currentUser;

typedef struct emailInfo mail;
mail tempMail, inbox[100], mailInfo;
user rUser;
user *receipient1;
	

user* retrieveUser(char*);
void selection();

int signUp(user u);
int appointmentInvolvedUsers();
int appointmentAvailability();
void validateTime();
void validateDate();
int validateAppointment();
void calenderView();
cal* mcalenderView();
//void calappointment();
void deletionnew(int n, char c);
void deletions(char *fileName, int n, char* c);
void requestappointment();
void* updateUnread();
void filterInbox();
