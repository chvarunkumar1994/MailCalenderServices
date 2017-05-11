
void deletions(char *fileName, int n, char* c)
{
	int i = 1, j = 0, k,seqnum;
	char s[LENGTH], *seq, seq1[4];
	char *line;
	size_t len = 0;
	ssize_t read;
	FILE *fp, *fwrite;
	fp = fopen(fileName, "r");
	line = (char*) malloc (LENGTH);
	
	while( 1 )
	{
		
		read = getline( &line, &len, fp);
			j += read;
		seq = line+36;
		for(k=0; seq[k] !='|' ; k++)
		{
			seq1[k] = seq[k];
		 }
		seq1[k] = '\0';
		//printf("%s\n", seq1);
		seqnum = atoi(seq1);
		//printf("%d\n", seqnum);
		if(seqnum == n)
		{
			j -= read;
			break;
		}
	//	//printf("%d %s\n", j, line);
		i++;
	}
	fclose(fp);
	
	
	fwrite = fopen(fileName, "r+");
	fseek(fwrite, j, SEEK_SET);
	fputs(c, fwrite);
//	//printf("%d", i);
	fclose(fwrite);
	//return 0;
}


