#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef list<int> vi;
typedef pair<int, vi> pis;

void simula(list<pis> &fila)
{
  int tempoTotal = 0;

  while (!fila.empty())
  {
    pis processo = fila.front();
    int instrucao = processo.second.front();

    if (instrucao == 0)
    {
      tempoTotal += 10;
      if (processo.second.size() > 1)
      {
        processo.second.pop_front();
        fila.erase(fila.begin());
        fila.push_front(make_pair(processo.first, processo.second));
      }
      else
      {
        fila.pop_front();
        cout << processo.first << " (" << tempoTotal << ")" << endl;
        continue;
      }
    }
    else if (instrucao == 1)
    {
      processo.second.erase(processo.second.begin());
      processo.second.push_front(0);

      fila.pop_front();
      fila.push_back(processo);
      continue;
    }
  }
}

int main()
{
  int qtd_processos;
  cin >> qtd_processos;

  list<pis> fila_execucao;

  vector<int> qtd_instrucoes_p_processo(qtd_processos);
  rep(i, 0, qtd_processos)
  {
    int qtd_instrucoes;
    cin >> qtd_instrucoes;

    qtd_instrucoes_p_processo[i] = qtd_instrucoes;
  };

  rep(i, 0, qtd_processos)
  {
    list<int> instrucoes;
    rep(j, 0, qtd_instrucoes_p_processo[i])
    {
      int instrucao;
      cin >> instrucao;

      instrucoes.push_back(instrucao);
    }
    fila_execucao.push_back(make_pair(i + 1, instrucoes));
  }

  simula(fila_execucao);

  return 0;
}