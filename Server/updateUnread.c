
//#include"header.c"


void* updateUnread()
{
	int i, read, len, count;
	char filename[LENGTH];
	FILE *fp;
//	line = (char*) malloc(LENGTH);

	strcpy(filename, buffUsername);
	strcat(filename, ".txt");
	while(1)
	{
		
		count = 0;
		memset(line, 0, sizeof(line));
		fp = fopen( filename, "r");
		//printf("%s", buffUsername);
		while ((read = getline( &line, &len, fp)) != -1) 
		{
			if(line[0] == 'U')
				count++;
			//printf("\n%s", line);
		}
	 	/* if(count > gCount || count > 0 )
		{
			notify = gCount - count ; 
		}  */
		gCount = count - lCount;
		sleep(1);/* 
		printf("\nlcount = %d", lCount);
		printf("\ngcount = %d", gCount); */
		fclose(fp);
		
	}
//	free(line);
	//return;
		
}
/*
int main()
{
	// buffUsername[20] = "user11.txt";
	updateUnread();
}
*/
