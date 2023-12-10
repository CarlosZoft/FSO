#include <iostream>
#include <vector>

using namespace std;

class Processo
{
public:
  int id;
  vector<int> instrucoes;
  string estado; // Estados possíveis: pronto, bloqueado
  int tempo_executado;

  Processo(int _id, const vector<int> &_instrucoes) : id(_id), instrucoes(_instrucoes), estado("pronto"), tempo_executado(0) {}
};

void escalonador_fcfs(vector<Processo> &processos)
{
  vector<Processo> fila = processos;
  int tempo_total = 0;

  while (!fila.empty())
  {
    Processo processo_atual = fila[0];
    fila.erase(fila.begin());

    cout << "Executando processo " << processo_atual.id << endl;

    for (int instrucao : processo_atual.instrucoes)
    {
      if (instrucao == 0)
      {
        // Instrução não bloqueante
        tempo_total += 10;
        processo_atual.tempo_executado += 10;
      }
      else if (instrucao == 1)
      {
        // Instrução bloqueante
        processo_atual.estado = "bloqueado";
        processo_atual.instrucoes.insert(processo_atual.instrucoes.begin(), 0);
        fila.push_back(processo_atual);
        break;
      }
    }

    if (processo_atual.estado != "bloqueado")
    {
      cout << "Processo " << processo_atual.id << " concluído. Tempo total de execução: " << processo_atual.tempo_executado << " ms" << endl;
    }
  }
}

int main()
{
  vector<Processo> processos = {
      Processo(1, {1}),
      Processo(2, {1, 1}),
      Processo(3, {1, 1, 1})};

  escalonador_fcfs(processos);

  return 0;
}
