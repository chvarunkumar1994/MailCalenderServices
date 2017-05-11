/*#include<stdio.h>
#include<stdlib.h>

#define LENGTH 500*/


void modifyInFile(char* filename, int n, char* c)
{
	int i = 1, j = 0;
	char s[LENGTH];
	char *line;
	size_t len = 0;
	ssize_t read;
	FILE *fp, *fwrite;
	fp = fopen(filename, "r");
	line = (char*) malloc (LENGTH);
	while( i != n )
	{
		read = getline( &line, &len, fp);
			j += read;
	//	printf("%d %s\n", j, line);
		i++;
	}
	fclose(fp);
	
	
	fwrite = fopen(filename, "r+");
	fseek(fwrite, j, SEEK_SET);
	fputs(c, fwrite);
	//printf("%d", n);
	//printf("in deletion");
	fclose(fwrite);
	
}

/*
int main()
{
	modifycharInFile("varun.txt", 5, "M");
}*/
