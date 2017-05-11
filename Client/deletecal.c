void deletecal()
{
	if( (z = recv (sock, bufcal, LENGTH, 0)) < 0)
		perror("\nError in receiving");
	printf("\n%s", bufcal);
	printf("\nSelect the apointment you want to delete: ");
	scanf("%s", dc);
	memset(dbuffcal,LENGTH,0);
	if( ( send( sock, dbuffcal, LENGTH, 0) < 0) )
		printf("\nError in sending delete appointment details");
}
