#include <iostream>
using namespace std;

//recebe, do usuário, a coordenada de linha no tipo char e retorna o seu respectivo índice, dentro da matriz
int LinhaEscolha(char linhaLetra)
{
  if(linhaLetra == 'A')
    return 0;
  if(linhaLetra == 'B')
    return 1;
  if(linhaLetra == 'C')
    return 2;
}

int main() 
{
  char escolha[3][3], linhaLetra;
  int coluna, linhaNum, colunaNum, numJogadas = 1;
  bool vitoriaJ1 = false, vitoriaJ2 = false, empate = false;

  //seta todos as posições com um caracter vazio
  for(int l = 0; l < 5; l++)
  {
    for(int c = 0; c < 3; c++)
    {
      escolha[l][c] = ' ';
    }
  }

  //arma a "tabela" do jogo
  cout << endl << "\t" << 1 << "\t" << 2 << "\t" << 3 << endl << endl;
  for(int l = 0; l < 5; l++)
  {
    if(l == 0)
      cout << "A\t";
    if(l == 1)
      cout << "\t---------";
    if(l == 2)
      cout << "B\t";
    if(l == 3)
      cout << "\t---------";
    if(l == 4)
      cout << "C\t";

    for(int c = 0; c < 3; c++)
    {
      if(l == 0 || l == 2 || l == 4)
      {
        cout << escolha[l][c];

        if(c == 0 || c == 1)
          cout << " | ";
      }
    }
    cout << endl;
  }

  //interação com os usuários
  while(!vitoriaJ1 && !vitoriaJ2 && !empate)
  {
    if(numJogadas % 2 != 0)
      cout << "\nJogador 'X', em qual coordenada será a jogada??\n";
    else
      cout << "\nJogador 'O', em qual coordenada será a jogada??\n";

    cin >> linhaLetra >> coluna;

    linhaNum = LinhaEscolha(linhaLetra);
    colunaNum = coluna - 1;

    if(numJogadas % 2 != 0)
      escolha[linhaNum][colunaNum] = 'X';
    else
      escolha[linhaNum][colunaNum] = 'O';

    //monta a tabela novamente
    cout << endl << "\t" << 1 << "\t" << 2 << "\t" << 3 << endl << endl;
    for(int l = 0; l < 5; l++)
    {
      if(l == 0)
        cout << "A\t";
      if(l == 1)
        cout << "\t---------";
      if(l == 2)
        cout << "B\t";
      if(l == 3)
        cout << "\t---------";
      if(l == 4)
        cout << "C\t";

      for(int c = 0; c < 3; c++)
      {
        if(l == 0 || l == 2 || l == 4)
        {
          if(l == 0)
            cout << escolha[0][c];
          if(l == 2)
            cout << escolha[1][c];
          if(l == 4)
            cout << escolha[2][c];
          if(c == 0 || c == 1)
            cout << " | ";
        }
      }
      cout << endl;
    }

    //verifica se houve um vencedor
    if(escolha[0][0] == 'X' && escolha[0][1] == 'X' && escolha[0][2] == 'X')
      vitoriaJ1 = true;
    if(escolha[1][0] == 'X' && escolha[1][1] == 'X' && escolha[1][2] == 'X')
      vitoriaJ1 = true;
    if(escolha[2][0] == 'X' && escolha[2][1] == 'X' && escolha[2][2] == 'X')
      vitoriaJ1 = true;
    if(escolha[0][0] == 'X' && escolha[1][0] == 'X' && escolha[2][0] == 'X')
      vitoriaJ1 = true;
    if(escolha[0][1] == 'X' && escolha[1][1] == 'X' && escolha[2][1] == 'X')
      vitoriaJ1 = true;
    if(escolha[0][2] == 'X' && escolha[1][2] == 'X' && escolha[2][2] == 'X')
      vitoriaJ1 = true;
    if(escolha[0][0] == 'X' && escolha[1][1] == 'X' && escolha[2][2] == 'X')
      vitoriaJ1 = true;
    if(escolha[2][0] == 'X' && escolha[1][1] == 'X' && escolha[0][2] == 'X')
      vitoriaJ1 = true;

    if(escolha[0][0] == 'O' && escolha[0][1] == 'O' && escolha[0][2] == 'O')
      vitoriaJ2 = true;
    if(escolha[1][0] == 'O' && escolha[1][1] == 'O' && escolha[1][2] == 'O')
      vitoriaJ2 = true;
    if(escolha[2][0] == 'O' && escolha[2][1] == 'O' && escolha[2][2] == 'O')
      vitoriaJ2 = true;
    if(escolha[0][0] == 'O' && escolha[1][0] == 'O' && escolha[2][0] == 'O')
      vitoriaJ2 = true;
    if(escolha[0][1] == 'O' && escolha[1][1] == 'O' && escolha[2][1] == 'O')
      vitoriaJ2 = true;
    if(escolha[0][2] == 'O' && escolha[1][2] == 'O' && escolha[2][2] == 'O')
      vitoriaJ2 = true;
    if(escolha[0][0] == 'O' && escolha[1][1] == 'O' && escolha[2][2] == 'O')
      vitoriaJ2 = true;
    if(escolha[2][0] == 'O' && escolha[1][1] == 'O' && escolha[0][2] == 'O')
      vitoriaJ2 = true;

    else if(numJogadas == 9 && !vitoriaJ1 && !vitoriaJ2)
      empate = true;

    numJogadas++;
  }

  //mostra a mensagem correta de acordo com o resultado
  if(vitoriaJ1 == true)
    cout << "\nParabéns Jogador 'X', você foi o vencedor!!\n";
  if(vitoriaJ2 == true)
    cout << "\nParabéns Jogador 'O', você foi o vencedor!!\n";
  if(empate == true)
    cout << "\nInfelizmente ninguém foi o vencedor. O jogo Terminou em empate!!\n";

  return 0;
}
