user* retrieveUser(char* line)
{
	char text[1024] = "\0";
	int endIndex = 0, temp = 0;
	//text = "";

	//rUser.userName = (char*) malloc(100);
	memset(rUser.userName, 0, sizeof(rUser));
	while(line[endIndex] != '|')
		endIndex++;
	strncpy(rUser.userName, line, endIndex);
	rUser.userName[endIndex] = '\0';

	temp = ++endIndex;
	while(line[endIndex] != '|')
		endIndex++;
	rUser.password = (char*) malloc(100);
	strncpy(rUser.password, line+temp, endIndex-temp);
	rUser.password[endIndex - temp] = '\0';
	//printf("inside retrieve user");
	temp = ++endIndex;
	while(line[endIndex] != '|')
		endIndex++;
	rUser.firstName = (char*) malloc(100);
	strncpy(rUser.firstName, line+temp, endIndex-temp);
	rUser.firstName[endIndex - temp] = '\0';
	
	temp = ++endIndex;
	while(line[endIndex] != '|')
		endIndex++;
	rUser.lastName = (char*) malloc(100);
	strncpy(rUser.lastName, line+temp, endIndex-temp);
	rUser.lastName[endIndex - temp] = '\0';

	//printf("\n%s %s %s %s", rUser.userName, rUser.password, rUser.firstName,rUser.lastName);
	return &rUser;
	//printf("\nout of retrieve user");
}

