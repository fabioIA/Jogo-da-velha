#include <bits/stdc++.h>

using namespace std;

vector<vector <char>> tabuleiro;

int verifica()
{
    int count = 0;

    for(auto line : tabuleiro)
    {
        for(auto column : line)
        {
            if(isdigit(column)) 
                count++;
        }
    }
    
    if(count == 0)
        return 2;
    
    for(auto el : tabuleiro)
    {
        if(el[0] == el[1] and el[0] == el[2])
            return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        if(tabuleiro[0][i] == tabuleiro[1][i] and tabuleiro[0][i] == tabuleiro[2][i])
            return 1;
    }

    if(tabuleiro[0][0] == tabuleiro[1][1] and tabuleiro[0][0] == tabuleiro[2][2])
        return true;
    else if(tabuleiro[0][2] == tabuleiro[1][1] and tabuleiro[0][2] == tabuleiro[2][0])
        return 1;

    return 0;
}

void printTabuleiro()
{
    cout<<endl;
    for(int i = 0; i < tabuleiro.size(); i++)
    {
        for(int j = 0; j < tabuleiro.size(); j++)
        {
            cout<<" "<<tabuleiro[i][j]<<" ";
            if(j != 2)
                cout<<"|";
        }
        if(i != 2)
            cout<<endl<<"-----------";

        cout<<endl;
    }
}

void jogada(int number, int jog)
{
    int x, y;

    if(number < 4)
    {
        y = 0;
        x = number - 1;
    }
    else if(number < 7)
    {
        y = 1;
        x = number - 4;
    }
    else
    {
        y = 2;
        x = number - 7;
    }

    if(jog == 1 and isdigit(tabuleiro[y][x]))
        tabuleiro[y][x] = 'X';
    else if(isdigit(tabuleiro[y][x]))
        tabuleiro[y][x] = 'O';
}

int main()
{
    int jog;
    char reiniciar = 'S';

    while(reiniciar == 'S')
    {
        tabuleiro = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        printTabuleiro();

        while(verifica() == 0)
        {
            cout<<endl<<"Jogador 1 (X), escolha uma posição: ";
            cin>>jog;

            jogada(jog, 1);
            jog = 1;

            printTabuleiro();

            if(verifica() != 0)
                break;

            cout<<endl<<"Jogador 2 (O), escolha uma posição: ";
            cin>>jog;

            jogada(jog, 0);
            jog = 2;

            printTabuleiro();
        }

        if(verifica() == 2)
            cout<<endl<<"Empate! Nenhum jogador venceu."<<endl;
        else
            cout<<endl<<"Parabéns! Jogador "<<jog<<" venceu!"<<endl;

        cout<<endl<<"Deseja reiniciar o jogo? (S/N) ";
        cin>>reiniciar;
    }
}
