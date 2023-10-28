#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, double> pii;
typedef vector<int> vi;

int main()
{
  int N;            // number of processes
  double Q;            // quantum in ms
  pii processes[N]; // {pid, burst time in seconds}

  // input
  cin >> N >> Q;
  rep(i, 0, N)
  {
    int pid;
    double burst;
    cin >> pid >> burst;
    processes[i] = {pid, burst};
  }

  // round robin
  int time = 0;
  queue<pii> q;
  rep(i, 0, N) q.push(processes[i]);

  while (!q.empty())
  {
    pii p = q.front();
    q.pop();
    int pid = p.first;
    double burst = p.second; // remaining burst time

    double quantumInSeconds = Q / 1000.0;  

    if (burst > quantumInSeconds)
    {
      time += static_cast<int>(Q);
      burst -= quantumInSeconds;
      q.push({pid, burst});

      continue;
    }
    time += static_cast<int>(round(burst * 1000.0));
    cout << pid << " "
         << "(" << time << ")" << endl;
  }

  return 0;
}