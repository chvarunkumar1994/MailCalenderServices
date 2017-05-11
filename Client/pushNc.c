void pushNc()
{
	char g[3];
	int count;
	if(recv(sock, g, 3, 0) <=0)
		printf("\nDoesn't receive push");
	count = atoi(g);
	if(count > 0)
		printf("\n[%d] New Emails arrived!", count);
}
