void modify()
{
	int a;
	char mbufcal[LENGTH];
	if( (z = recv (sock, mbufcal, LENGTH, 0)) < 0)
		perror("\nError in receiving");
	//printf("\n%s", mbufcal);
	memset(bufcal, 0, LENGTH);
	a = strlen(mbufcal);
	//printf("%d", a);
	//printf("%d",calbuffstringlenght);
	memset(mbuffcal,0,2);
	printf("\nPlease select an appointment number: ");
	scanf("%s", mbuffcal);
	if( ( send( sock, mbuffcal, 2, 0) < 0) )
		printf("\nError in sending");
	//printf("modify in client side: %s", mbuffcal);
}
