#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef list<int> vi;
typedef pair<int, vi> pis;

int main()
{

  ll qtd_quadros_ram;
  cin >> qtd_quadros_ram;

  ll qtd_referencia_pag_processo;
  cin >> qtd_referencia_pag_processo;

  list<ll> paginas_ram;

  ll countFault = 0;
  rep(i, 0, qtd_referencia_pag_processo)
  {
    ll page;
    cin >> page;

    auto it = find(paginas_ram.begin(), paginas_ram.end(), page);

    if (it != paginas_ram.end())
    {
      continue;
    }

    else if (paginas_ram.size() < qtd_quadros_ram)
    {
      paginas_ram.push_front(page);
      countFault++;
    }
    else
    {
      paginas_ram.pop_back();
      paginas_ram.push_front(page);
      countFault++;
    }
  }

  cout << countFault << endl;
  return 0;
}