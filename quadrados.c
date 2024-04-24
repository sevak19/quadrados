#include <stdio.h>

char escolha;
int numero;

//by sevak
//funcao apenas de leitura, com uma repeticao para escolhas invalidas.

void leitura(){
    printf("\n\nEscolha uma das opcoes acima: ");
        scanf(" %c", &escolha);
    while(escolha!='c'&&escolha!='b'&&escolha!='p'&&escolha!='s'&&escolha!='h'&&escolha!='v'&&escolha!='0'){
        printf("Escolha Invalida");
        printf("\nEscolha uma das opcoes acima: ");
            scanf(" %c", &escolha);
    }if(escolha!='0'){
    printf("Informe um numero inteiro: ");
        scanf(" %d", &numero);
    }
}

//funcao que printa todas as matrizes

void calculo(){
    
    //se a escolha da pessoa for C, ou seja, o quadrado inteiramente preenchido
    //é necessario apenas um simples for dentro de outro for para montar a matriz
    //sendo o 'j' resposavel por descer a linha, e o 'i' "caminha" sobre as colunas,
    //os dois comecando valendo 0, e acrescendo 1 a cada vez, ate o valor do NUMERO informado pelo usuario.
    
    if(escolha == 'c'){
        for(int j = 0;j<numero;j++){
            printf("\n\t");
            for(int i=0;i<numero;i++){
                printf("* ");
            }
        }
    }
    
    //ja se a escolha da pessoa for B, ou seja, apenas as bordas do quadrado
    //eu fiz primeiro o for com a variavel J, que novamente é resposavel pelas linhas
    
    else if(escolha == 'b'){
        for(int j = 0;j<numero;j++){
            if(j==0||j==numero-1){ //---> se a linha for a 0(primeira) ou a ultima
                if(j==0){ //---------------> se for a primeira linha
                    printf("\n\t"); //--------> descer uma linha e dar o espacamento (TAB)
                }
                for(int i=0;i<numero;i++){ //-------> ainda dentro da condicao de ser primeira ou a ultima linha
                    printf("* ");                    //printar o * ate o valor do NUMERO digitado pela pessoa, ou seja, preencher toda a borda
                }                                   //de cima e de baixo do quadrado
            }
            printf("\n\t"); //-----> desce uma linha e da o espacamento.
            if(j<numero-2){ //----------> se o J for menor que o numero-2, entrara no for responsavel pela coluna
                for(int i=0;i<2;i++){   //essa condicao e necessaria pois a primeira linha ja foi feita e a ultima
                    printf("* ");        //sera feita de maneira diferente(ali em cima)
                    for(int i=0;i<numero-2;i++){
                        printf("  ");        //primeiro for se repete duas vezes por linha apenas, ou seja, ele roda uma vez
                    }                       //e printa o * responsavel pela primeira coluna do lado esquerdo e depois dos espacos que preenchem
                }                           //o meio do quadrado serem printados pelo proximo for, ele é printado pela segunda vez, fechando o outro lado.
            }
        }
    }
    
    //se a escolha da pessoa for P, ou seja, as bordas e a diagonal principal
    //comeca a complicar. Comecei novamente com o for com a variavel J, que 
    //novamente é resposavel por descer as linhas
    
    else if(escolha == 'p'){
        for(int j = 0;j<numero;j++){ 
            if(j==0||j==numero-1){      //se a linha for a 0(primeira) ou a ultima
                if(j==0){                   //se for a primeira linha
                    printf("\n\t");         //descer uma linha e dar o espacamento (TAB)
                }
                for(int i=0;i<numero;i++){      //ainda dentro da condicao de ser primeira ou a ultima linha
                    printf("* ");                    //printar o * ate o valor do NUMERO digitado pela pessoa, ou seja, preencher toda a borda
                }                                   //de cima e de baixo do quadrado
            }
            printf("\n\t");     //desce uma linha e da o espacamento
            if(j<numero-2){                             //se o J for menor que o numero-2, entrara no for responsavel pela coluna, como ja explicado acima,
                    printf("* ");                        //porem dessa vez os * que formam os lados nao estao dentro de um loop, isso se deve
                    for(int i=0;i<numero-2;i++){        //a um conflito que encontrei, onde a diagonal acabava se repetindo junto com o lado
                        if(j==i){                       //isso nao ocorre no B pois os espacos sao indiferentes visualmente.
                            printf("* ");
                        }else{                  //a condicao J igual ao I, significa por exemplo que na linha 1, a diagonal principal passa obviamente
                            printf("  ");        //na coluna 1, ou seja, um * e printado, senao, um espaco, assim formando a diagonal principal.
                        }
                    }
                    printf("* ");    //novamente outro * printado para fechar o outro lado do quadrado
            }
        }
    }
    
    //se a escolha da pessoa for S, ou seja, as bordas e a diagonal secundaria
    //novamente o primeiro passo é o for com a variavel J, que 
    //novamente é resposavel por descer as linhas
    
    else if(escolha == 's'){
        for(int j = 0;j<numero;j++){
            if(j==0||j==numero-1){      //se a linha for a 0(primeira) ou a ultima
                if(j==0){                   //se for a primeira linha
                    printf("\n\t");         //descer uma linha e dar o espacamento (TAB)
                }
                for(int i=0;i<numero;i++){      //ainda dentro da condicao de ser primeira ou a ultima linha
                    printf("* ");                    //printar o * ate o valor do NUMERO digitado pela pessoa, ou seja, preencher toda a borda
                }                                   //de cima e de baixo do quadrado
            }
            printf("\n\t");     //desce uma linha e da o espacamento
            if(j<numero-2){                             //se o J for menor que o numero-2, entrara no for responsavel pela coluna, como ja explicado acima,
                    printf("* ");                        //porem dessa vez os * que formam os lados nao estao dentro de um loop, como ja explicado,
                    for(int i=0;i<numero-2;i++){        //isso se deve a um conflito que encontrei, onde a diagonal acabava se repetindo junto com o lado
                        if(i==(numero-3)-j){            //isso nao ocorre no B pois os espacos sao indiferentes visualmente.
                            printf("* ");
                        }else{              //a condicao i igual ao (numero-3)-j, significa exatamente o contrario da ultima condicao, deixando a diagonal
                            printf("  ");    //comecando da direita para a esquerda (SECUNDARIA).
                        }                   //caso a condicao seja falsa, é printado novamente o espaco, alinhando o quadrado e a diagonal.
                    }
                    printf("* ");    //novamente outro * printado para fechar o outro lado do quadrado  
            }
        }
    }
    
    //se a escolha da pessoa for H, ou seja, as bordas e a sua divisao horizontal
    //novamente o primeiro passo é o for com a variavel J, que 
    //novamente é resposavel por descer as linhas
    
    else if(escolha == 'h'){
        for(int j = 0;j<numero;j++){
            if(j==0||j==numero-1){      //se a linha for a 0(primeira) ou a ultima
                if(j==0){                   //se for a primeira linha
                    printf("\n\t");         //descer uma linha e dar o espacamento (TAB)
                }
                for(int i=0;i<numero;i++){      //ainda dentro da condicao de ser primeira ou a ultima linha
                    printf("* ");                    //printar o * ate o valor do NUMERO digitado pela pessoa, ou seja, preencher toda a borda
                }                                   //de cima e de baixo do quadrado
            }
            printf("\n\t");     //desce uma linha e da o espacamento
            if(j==(numero/2)-1){                //ja esta nova condicao tem como objetivo encontrar a 
                for(int i=0;i<numero;i++){      //coluna na qual seja o valor exato da metade do numero digitado
                    printf("* ");                //porem percebi que o programa estava arredondando erroniamente pois é uma divisao inteira
                }                               //para consertar adcionei -1 ao resultado, fazendo com que funcione normalmente
            }else if(j<numero-2){               //assim é printado uma linha completa na metade horizontal do quadrado.
                for(int i=0;i<2;i++){               //LOGO, se essa condicao nao for verdadeira, ou seja, nao for o meio do quadrado
                    printf("* ");                    //o primeiro for dentro do else if printa os lados e o outro os espacos em branco, igual na letra B.
                    for(int i=0;i<numero-2;i++){
                        printf("  ");
                    }
                }                               //como numeros pares nao tem um meio exato,
            }                                   //este codigo so funciona com numeros impares
        }                                       //ja que nao e possivel repartir uma linha ao meio
    }
    
    //se a escolha da pessoa for V, ou seja, as bordas e a sua divisao vertical
    //novamente o primeiro passo é o for com a variavel J, que 
    //novamente é resposavel por descer as linhas
    
    else if(escolha == 'v'){
        for(int j = 0;j<numero;j++){
            if(j==0||j==numero-1){      //se a linha for a 0(primeira) ou a ultima
                if(j==0){                   //se for a primeira linha
                    printf("\n\t");         //descer uma linha e dar o espacamento (TAB)
                }
                for(int j=0;j<numero;j++){      //ainda dentro da condicao de ser primeira ou a ultima linha
                    printf("* ");                    //printar o * ate o valor do NUMERO digitado pela pessoa, ou seja, preencher toda a borda
                }                                   //de cima e de baixo do quadrado
            }
            printf("\n\t");     //desce uma linha e da o espacamento
            if(j<numero-2){                         //novamente usei o loop para criar os lados do quadrado, porem printados um antes do for
                printf("* ");                        //que irei explicar agora e um depois
                    for(int i=0;i<numero-2;i++){        //esse for caminha sobre as colunas
                        if(i==(numero-2)/2){                //esta condicao é necessaria para encontrar o meio do quadrado
                            printf("* ");                    //novamente se nao for o meio do quadrado, é printado um espaco para preenchimento
                        }else{
                            printf("  ");
                        }
                    }
                printf("* ");    //outro lado do quadrado e printado
            }
        }                                   //como numeros pares nao tem um meio exato,
    }                                       //este codigo so funciona com numeros impares
}                                           //ja que nao e possivel repartir uma linha ao meio

//dentro da minha funcao MAIN apenas printei a TABELA, onde mostro ao usuario como funciona o programa
//e puxo as funcoes, criando tambem um loop onde tudo se repete ate o usuario digitar o numero 0,
//no qual deixo claro na tabela que ele e responsavel em encerrar o codigo.

int main(){
    printf("'0'- encerra o codigo\n'c'- imprime um quadrado totalmente preenchido\n'b'- imprime somente as bordas\n'p'- imprime suas bordas e a diagonal principal\n's'- imprime suas bordas e a diagonal secundaria\n'h'- imprime suas bordas e sua divisao horizontal(apenas numeros impares)\n'v'- imprime suas bordas e sua divisao vertical(apenas numeros impares)");
    leitura();
    while(escolha!='0'){
    calculo();
    leitura();
    }
    return 0;
}
