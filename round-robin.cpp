#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
  int N;            // number of processes
  int Q;            // quantum in ms
  pii processes[N]; // {pid, burst time in seconds}

  // input
  cin >> N >> Q;
  rep(i, 0, N)
  {
    int pid;
    int burst;
    cin >> pid >> burst;
    processes[i] = {pid, burst * 1000};
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
    int burst = p.second; // remaining burst time

    if (burst > Q)
    {
      time += Q;
      burst -= Q;
      q.push({pid, burst});

      continue;
    }
    time += burst;
    cout << pid << " "
         << "(" << time << ")" << endl;
  }

  return 0;
}