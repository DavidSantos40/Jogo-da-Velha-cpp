#include <iostream>
#include <cstdlib>
using namespace std;

char verificarVencedor(char tabuleiro[3][3]) { //ia gerou
    
    
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0]; 
        }
    }

    
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
            return tabuleiro[0][j]; 
        }
    }

    
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }

    
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    
    return ' '; 
} 



void tabuleiroDesenhado(char tabuleiro [3][3]){

    cout << endl;

        // linhas
        for (int i = 0; i < 3; i++) 
        {
            // colunas 
            for (int j = 0; j < 3; j++) 
            {
                
                cout << " " << tabuleiro[i][j] << " "; 
                
                if (j < 2)
                {
                    cout << "|"; // Adiciona "|" ENTRE as colunas
                }
            }
            
            //pula proxima linha
            cout << endl; 

           
            if (i < 2)
            {
                cout << "---+---+---" << endl; 
            }
        }
}

void pausar(string mensagem){
    cout << mensagem << endl;
    cout << "Pressione enter para tentar novamente..." << endl;
    getchar();
    getchar();
}


char jogar(char tabuleiro[3][3], int posicao, int jogadorAtual){ 

    int linha = (posicao -1) /3; 
    int coluna = ( posicao -1) %3; 
    
    if (tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] !='O')
    {
        tabuleiro[linha][coluna] = jogadorAtual;
        return 0; 
    } else {
        return 1;
    }
}








int main(){

    char tabuleiro[3][3] = {
        {'1','2','3'}, //linha 0
        {'4','5','6'}, //linha 1
        {'7','8','9'} // linha 2
                         
    };

    int jogada = 0;
    int posicaoJogador = 0;
    bool vitoria = false;
   while (jogada < 9)
    {
        tabuleiroDesenhado(tabuleiro);

        printf("jogador %c, escolha a posicao de 1 a 9: ",(jogada %2 == 0) ? 'X' : 'O');
        cin >> posicaoJogador;

        if (posicaoJogador<1 || posicaoJogador>9)
        {
            pausar("Digite um valor entre 1 a 9");
            continue;
        }

        char jogadorAtual = (jogada % 2 == 0) ? 'X' : 'O';
        if (jogar(tabuleiro,posicaoJogador,jogadorAtual))
        {    
            pausar("posicao ja escolhida");
            continue;
        }
        
        char vencedor = verificarVencedor(tabuleiro);
        if (vencedor != ' ') { 
            tabuleiroDesenhado(tabuleiro); 
            cout << endl << "!!! FIM DE JOGO !!!" << endl;
            printf("O jogador %c venceu!\n", vencedor);
            
            vitoria = true; 
            break;          // Sai do loop 'while' imediatamente 
        } //funcao q pedi para ia gerar

        jogada++;
    }
    
    cout <<"Fim do jogo!"<< endl;

    return 0;
}
