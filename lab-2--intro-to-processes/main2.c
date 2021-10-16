#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int x;
     for(x = 0; x < 2; x++) 
     {
       pid = fork();
       if (pid == 0) 
          ChildProcess();
       else if(pid < 0)
          printf("Issue in fork");  
     }
    ParentProcess(); 
}

void  ChildProcess(int id)
{
     int   i;
     if (id == 0)
     {
       printf("Child %d", id);
     }
     else if (id == 1) 
     {
       printf("Child %d", id); 
     }
  printf("\n\n")
  sleep(8);
}

void  ParentProcess(void)
{
     int i,pid,stat;

     for (i = 0; i < 2; i++)
     {
       pid = wait(&stat);
       printf("*** Parent is done ***%d\n", pid);
     }
}