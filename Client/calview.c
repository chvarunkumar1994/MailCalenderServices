void calview()
{
	char bufcal[LENGTH];
	printf("we are in calendar view");
	
	if( (z = recv (sock, bufcal, LENGTH, 0)) <= 0)
		perror("\nError in receiving");
    printf("\n%s", bufcal);
	calbuffstringlenght = strlen(bufcal);
	if (calbuffstringlenght == 0)	
		{
			printf("your calender is empty");
		}
		
	//printf("\n \n how much length is in the buffer: %d", calbuffstringlenght);
	memset(bufcal, 0, LENGTH);
}
