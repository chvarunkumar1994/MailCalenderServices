
//#include"header.c"


void updatelCount()
{
	int i, read, len, count;
	char filename[100];
	FILE *fp;
	//line = (char*) malloc(LENGTH);
	memset(filename, 0, sizeof(filename));
	strcpy(filename, buffUsername);
	strcat(filename, ".txt");
	//printf("%s", filename);
	//line1 = (char*)malloc(sizeof(line1));
	//while(1)
	{
		//sleep(1);
		count = 0;
		memset(line1, 0, sizeof(line1));
		fp = fopen(filename, "r");
		
		while ((read = getline( &line1, &len, fp)) != -1) 
		{
			if(line1[0] == 'U')
				count++;
			//printf("inside");
			//printf("%s", line1);
			//memset(line, 0, sizeof(line));
		}
		lCount = count;
		//sleep(1);
		//printf("\nLLLLcount = %d", count);
		fclose(fp);
	}
	
	return;
		
}

