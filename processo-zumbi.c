#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void func(int signal) {}

int main()
{
  signal(SIGUSR1, func);
  signal(SIGUSR2, func);

  pause();

  pid_t pid = fork(); // fork a child process

  if(pid == 0) exit(0); 

  pause(); 
  wait(NULL);
  pause();
  
  exit(0);
}