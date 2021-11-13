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
          ChildProcess(x);
       else if(pid > 0)
          ParentProcess();
       else
          printf("Issue in fork");  
     }
}

void  ChildProcess(int id)
{
     int i;
    
    printf("Child Pid: %d is going to sleep!\n",getpid());
    
    srand(getpid());
    i = rand() % 11;
    sleep(i + 1);
    
    printf("Child Pid: %d is awake!\n\nWhere is my Parent: %d\n",getpid(),getpid());
    
    exit(0);
}

void  ParentProcess(void)
{
     int x,pid,stat;

     for (x = 0; x < 2; x++)
     {
       printf("Child: %d x: %d\n",pid,i)
       pid = wait(&stat);
       printf("*** Child is done ***%d\n", pid);
     }
}