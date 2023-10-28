#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, double> pii;
typedef vector<int> vi;

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