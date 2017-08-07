



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
   	int i,j;
	printf("--Start of Lab 2 program--\n");
	int cUID = getuid();
	int cGID = getgid();
	printf("UID: %d\n", cUID);
	printf("GID: %d\n", cGID);
  	pid_t pid = fork();

            if (pid < 0)
            {
                perror("Fork failed");
            }
            if (pid == 0)
            {
                for (i = 1; i < argc; i++)
                {
			int chUID = getuid();
			int chGID = getgid();
			
			if (chUID == cUID)
			{
				printf("Filename:%s",argv[i]);
				printf("You have owner permissions:%s \n");
			}
			if (chGID == cGID)
			{
				printf("Filename:%s", argv[i]);
				printf("You have general permissions: %s\n");
			} else {
				printf("Owner is ouside the user group\n");
				}
	

                }
		exit(0);
	    }
            if (pid > 0)
            {
                wait(NULL);
                system("ps -H");
            }
}

