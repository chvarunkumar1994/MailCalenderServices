//#include "headerc.c"


void next2()
{

	printf("new next");
}
void next()

{
	int z;
	//printf("now i am in next part");
	printf("select from 1)Send mail 2)Reply 3)Forward 4)Quit");
	scanf(" %d" , &z);
	 
			switch(z)
			{
				case 1: {
						printf(" send mail section");
						next2();
						break;
					}
				case 2: {
						printf("reply");
						break;
					}
				case 3: { 
						printf("forward");
						break;	
					}
				case 4:{
						z=4;
						break;
					}
			break;	
			}
		
}
