/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
alarm_count = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5); //5 seconds sleep
  alarm_count = 1; //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 second
  while(1) 
  {
    alarm_count = 0;
    alarm(5)
    //busy wait for signal to be delivered
    while (!alarm_count) 
    {
      printf("It was correct");
    }
   return 0;
}
    
  
  return 0; //never reached
}