/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

alarm_count = 0;
alarm_number = 0;

time_t start, stop;

void alarmhandler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5); //5 seconds sleep
  alarm_count = 1; //exit after printing
  alarm_number++;
}

void intHandler(int signum)
{
  int t_time;
  stop_time = time(NULL); // stop time
  t_time= stop - start;
  
  printf("The elapsed time is %d", t_time);
  printf("The number of alarms are %d", alarm_number);

}



int main(int argc, char * argv[])
{
  signal(SIGALRM,alarmhandler); //register handler to handle SIGALRM
  signal(SIGINT,intHandler);
  start = time(NULL); //Schedule a SIGALRM for 5 second
  
  while(1) 
  {
    alarm_count = 0;
    alarm(5)
    //busy wait for signal to be delivered
    while (!alarm_count) 
    {
      printf("It was correct");
    }
}
 
  return 0; //never reached
}