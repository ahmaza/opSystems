#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

char prompt[256] = "> ";
char delimiters[] = " \t\r\n";
extern char **environ;
pid_t pid;



int main() {
    // Stores the string typed into the command line.
    char command_line[MAX_COMMAND_LINE_LEN];
    char cmd_bak[MAX_COMMAND_LINE_LEN];
  
    // Stores the tokenized command line input.
    char *arguments[MAX_COMMAND_LINE_ARGS];
    int x;
    bool background;
    while (true) {
      
        do{ 
            // Print the shell prompt.
            printf("%s", prompt);
            fflush(stdout);
          
            if (getcwd(prompt, sizeof(prompt)) == NULL) 
            {
              perror("cwd error");
              exit(1);
            }
            else 
            {
              printf("%s", prompt);
              fflush(stdout);
            }

            // Read input from stdin and store it in command_line. If there's an
            // error, exit immediately. (If you want to learn more about this line,
            // you can Google "man fgets")
        
            if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
                fprintf(stderr, "fgets error");
                exit(0);
            }
 
        }while(command_line[0] == 0x0A);  // while just ENTER pressed

      
        // If the user input was EOF (ctrl+d), exit the shell.
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            return 0;
        }

        // TODO:
        // 
        
			  // 0. Modify the prompt to print the current working directory
			  
			
        // 1. Tokenize the command line input (split it on whitespace)

         arguments[0] = strtok(command_line, delimiters);
         x = 0;
         while (arguments[x] != NULL) 
         {
           x++;
           arguments[x] = strtok(NULL, delimiters);
         }
        // 2. Implement Built-In Commands
         if(strcmp(arguments[0], "c") == 0) 
         {
           chdir(arguments[1]);
         }
         else if (strcmp(arguments[0], "pwd") == 0)
         {
           printf("%s\n", prompt);
         }
         else if (strcmp(arguments[0], "echo") == 0) 
         {
           x = 1;
           while (arguments[x] != NULL) 
           {
             if (*arguments[x] == '$') 
             {
               printf("%s \n", getenv(arguments[x] + 1));
               
             }
             else 
             {
               printf("%s\n", arguments[x]);
             }
             x++;
           }
         }
          else if (strcmp(arguments[0], "exit") == 0) 
          {
            exit(0);
          }
          else if (strcmp(arguments[0], "env") == 0) 
          {
            printf("%s \n", getenv(arguments[1]));
            getenv("path");
          }
          else if (strcmp(arguments[0], "setenv") == 0) 
          {
            const char *s_arr[2];
            char *s = arguments[1];
            x = 0;
            s_arr[x] = strtok(s, "=");
            while (s_arr[x] != NULL) 
            {
              s_arr[++x] = strtok(NULL,"=");
            }
            setenv(s_arr[0], s_arr[1],1);
          }
           
         else 
          {
            if (strcmp(arguments[x - 1], "&") == 0) 
            {
              arguments[x - 1] = NULL;
              background = true;
            }
            //use pid to compare
            pid = fork();
            if (pid < 0) 
            {
              perror("failed");
              exit(0);
            }
            else if (pid == 0) 
            {
              execvp(arguments[0], arguments);
              printf("execvp failed\n");
              exit(0);
            }
            else 
            {
              if (background != true) 
              {
                wait(NULL);
              }
            }
          } 
        
      
        // Hints (put these into Google):
        // man fork
        // man execvp
        // man wait
        // man strtok
        // man environ
        // man signals
        
        // Extra Credit
        // man dup2
        // man open
        // man pipes
        return -1;
 }
  
  // This should never be reached.
   

void sig_handler(int sig_n) 
{
  printf("signal %d caught\n", sig_n);
  kill(pid, SIGKILL);
  } 
}