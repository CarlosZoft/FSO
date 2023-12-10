#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, string> pis;
typedef vector<int> vi;

void simulacao(queue<pis> &fila)
{
  int tempoTotal = 0;

  while (!fila.empty())
  {
    bool foiInterrompido = false;
    pis processo = fila.front();
    fila.pop();

    // for (int i = 0; processo.second.size(); i++)
    // {
    //   char instrucao = processo.second[i];
    //   if (instrucao == '0')
    //   {
    //     tempoTotal += 10;
    //     foiInterrompido = false;
    //   }
    //   else if (instrucao == '1')
    //   {
    //     processo.second += '0';
    //     fila.push(processo);
    //     foiInterrompido = true;
    //     break;
    //   }
    // }
    for (char instrucao : processo.second)
    {
      string sub = processo.second.substr(1);
      // cout << processo.first << " -> Atual " << processo.second << " Sub: " << sub << endl;
      if (instrucao == '0')
      {
        tempoTotal += 10;
        foiInterrompido = false;
      }
      else if (instrucao == '1')
      {
        processo.second = '0' + sub;
        fila.push(processo);
        foiInterrompido = true;
        break;
      }
    }
    if (!foiInterrompido)
      cout << processo.first << " (" << tempoTotal << ")" << endl;
  }
}

void simulacao2(queue<pis> &fila)
{
  int tempoTotal = 0;

  while (!fila.empty())
  {
    bool foiInterrompido = false;
    pis processo = fila.front();
    char instrucao = processo.second[0];

    cout << processo.first << " -> " << processo.second << endl;

    if (instrucao == '0')
    {
      tempoTotal += 10;
      foiInterrompido = false;
      processo.second.erase(0, 1);
    }
    else if (instrucao == '1')
    {
      processo.second[0] = '0';
      foiInterrompido = true;
      fila.pop();
    }

    if (processo.second.size() <= 0)
      fila.pop();

    if (foiInterrompido and processo.second.size() > 0)
      fila.push(processo);
    else
      cout << processo.first << " (" << tempoTotal << ")" << endl;
  }
}

void simulacao3(queue<pis> &fila)
{
  int tempoTotal = 0;

  while (!fila.empty())
  {
    pis processo = fila.front();
    char instrucao = processo.second[0];

    cout << processo.first << " -> " << processo.second << endl;

    if (instrucao == '0')
    {
      tempoTotal += 10;
      processo.second.erase(0, 1);
    }
    else if (instrucao == '1')
    {
      processo.second[0] = '0';
      fila.pop();
      fila.push(processo);
      continue;
    }
    if (processo.second.size() <= 0)
      fila.pop();
  }
}

int main()
{
  int qtd_processos;
  cin >> qtd_processos;

  queue<pis> fila_execucao;

  vector<int> qtd_instrucoes_p_processo(qtd_processos);
  rep(i, 0, qtd_processos)
  {
    int qtd_instrucoes;
    cin >> qtd_instrucoes;

    qtd_instrucoes_p_processo[i] = qtd_instrucoes;
  };

  rep(i, 0, qtd_processos)
  {
    string instrucao_completa = "";
    rep(j, 0, qtd_instrucoes_p_processo[i])
    {
      char instrucao;
      cin >> instrucao;
      instrucao_completa += instrucao;
    }
    fila_execucao.push(make_pair(i + 1, instrucao_completa));
  }

  simulacao3(fila_execucao);

  // rep(i, 0, qtd_processos)
  // {
  //   cout << "Processo " << fila_execucao.front().first << ": " << fila_execucao.front().second << endl;
  //   fila_execucao.pop();
  // }

  // simulacao(fila_execucao);

  return 0;
}