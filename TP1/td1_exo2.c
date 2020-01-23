#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/unistd.h>



int main(void)
{
	/* code */
	int val=0;
	pid_t pid;
	switch (pid=fork()){
		case -1:
			perror("creation failed");
			exit(1);
		case 0:
			/*flis*/
			val=getpid();
			printf("\n fils: pid(%d) , son pere: pid(%d) \n",getpid(), getppid());
			printf("valeur ( et adresse) de val dans flis: %d (%p) \n",val ,&val);
			puts("fin du fils");
			exit(0);
		default:	
			/*pere*/
			while(waitpid(0,0,0)<0);
			printf("\n pere: pid(%d) , son pere: pid(%d)\n", getpid(),getppid());
			printf("valeur (et adresse) du val dans pére: %d (%p) \n",val, &val );
	}
	return 0;
}