void pushN()
{
	char g[3];
	sleep(1);
	sprintf(g, "%d", gCount);
	//printf("\n%s %d", g, gCount );
	send(connfd, g, 3, 0);
}
