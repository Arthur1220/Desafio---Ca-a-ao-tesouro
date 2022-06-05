#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerar_mapa(Localizacao);
void gerar_caminho();
int gerar_pontuacao(Localizacao);

struct Localizacao{
    //LOCALIZACAO DO TESOURO
    int X, Y;
    //LOCALIZACAO DO JOGADOR
    int locaX, locaY;
    //NUMERO DE MOVIMENTOS
    int mov;
    //TAMANHO DO MAPA
    int n, m;
}local;

int main(){
    //RECEBER O TAMANHO DO MAPA
    do{
        printf("Insira o numero de linhas: ");
        scanf("%d",&local.n);
        printf("Insira o numero de colunas: ");
        scanf("%d",&local.m);
    }while(local.n>100 && local.m>100);
    
    system("cls");

    gerar_mapa(local);
    gerar_caminho();
    gerar_pontuacao(local.n, local.m);

	return 0;
}

//GERAR O MAPA COM AS POSICOES DO JOGADOR E DO TESOURO
int gerar_mapa(Localizacao){
    int i, j;
    srand(time(NULL));

    //GERAR A POSICAO DO TESOURO
    do{
        local.X = rand() % (local.n);
        local.Y = rand() % (local.m);
    }while(local.X==(local.n/2) && local.Y==(local.m/2));
        
    printf("=-=-Bem-vindo a Caca ao tesouro-=-=\n\n");
    for(i=0;i<local.n;i++){
        for(j=0;j<local.m;j++){
            //LOCALIZACAO DO JOGADOR, QUE É NO "MEIO"
            if(i==(local.n/2) && j==(local.m/2)){
                printf("   @");
                local.locaX = i;
                local.locaY = j;
            }  
            else if(local.X==i & local.Y==j)
                printf("   $");
            else
                printf("   .");
        }
        printf("\n");
    }

    return 0;
}

//GERA O CAMINHO DO JOGADOR ATE O TESOURO
void gerar_caminho(){
    local.mov=0;
    
    printf("\n=-=-=-Caminho para o tesouro-=-=-=\n");
    do{
        if(local.locaX<local.X){
            local.locaX++;
            local.mov++;
            printf(" - Baixo");
        }
        if(local.locaX>local.X){
            local.locaX--;
            local.mov++;
            printf(" - Cima");
        }
        if(local.locaY<local.Y){
            local.locaY++;
            local.mov++;
            printf(" - Direita");
        }
        if(local.locaY>local.Y){
            local.locaY--;
            local.mov++;
            printf(" - Esquerda");
        }
    }while(local.locaX != local.X || local.locaY != local.Y);

    return 0;
}

//GERA A PONTUAÇÃO A PARTIR DOS MOVIMENTOS E TAMANHO DO MAPA
int gerar_pontuacao(Localizacao){
    float pontuacao;

    pontuacao = (local.n*local.m - local.mov) / 10.0;
    printf("\n\nPontuacao: %.1f\n", pontuacao);

    return 0;
}