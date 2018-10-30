#include <stdio.h>
#include <iostream>
#include <assert.h>

enum naipes {NENHUM, OUROS, ESPADAS, COPAS, PAUS};
enum valores {ZERO, DOIS=1, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI, AS};

void testaMaior();
void testaTem1Par();
void testaTem2Pares(void);


typedef struct {
  naipes naipe;
  valores valor;
} carta;

carta jogador1[5];
carta jogador2[5];

carta escolheMaiorCartaJogador(carta *mao){

  carta maiorCarta;
  maiorCarta.naipe=PAUS;
  maiorCarta.valor=DOIS;
    
    for (int i=0; i<5; i++){
        if (mao[i].valor > maiorCarta.valor)
           maiorCarta = mao[i];
    }
    return maiorCarta;
}

carta tem1Par (carta *mao){
    carta par;
    par.naipe=NENHUM;
    par.valor=ZERO;
     
    for (int i=0; i<5; i++){
        for (int j=i+1;j<5; j++)
            if (mao[i].valor == mao[j].valor)
              return mao[i];
           
    }
    return par;
}    

carta tem2Pares (carta *mao){
    carta par1, par2;
    par1.naipe=NENHUM;
    par1.valor=ZERO;
    par2.naipe=NENHUM;
    par2.valor=ZERO;
    bool achou = false; 
     
    for (int i=0; i<5 && !achou; i++){
        for (int j=i+1;j<5; j++)
            if (mao[i].valor == mao[j].valor) {
                if (par1.valor == ZERO) {
                    
                    par1 = mao[i];
                }
                else {
                    
                    par2 = mao[i];
                    achou = true;
                }
              break;
            }
           
    }
    
    if (achou) {
        
        if (par1.valor > par2.valor)
           return par1;
    
    }

    return par2;
}    


carta temTrinca (carta *mao){
    
    carta trinca;
    
    return trinca;
}



int main()
{
    testaMaior();
    testaTem1Par();
    testaTem2Pares();
    
    return 0;
}

void testaMaior(void){

    carta jogador1[5];
    carta maiorCarta;
    
    jogador1[0].naipe = OUROS;
    jogador1[0].valor = QUATRO;

    jogador1[1].naipe = OUROS;
    jogador1[1].valor = OITO;
    
    jogador1[2].naipe = PAUS;
    jogador1[2].valor = REI;
    
    jogador1[3].naipe = OUROS;
    jogador1[3].valor = NOVE;
    
    jogador1[4].naipe = ESPADAS;
    jogador1[4].valor = AS;
    
    maiorCarta = escolheMaiorCartaJogador(jogador1);
    assert(maiorCarta.valor == AS);
    
}


void testaTem1Par(void){

    carta jogador1[5];
    carta par;
    
    jogador1[0].naipe = OUROS;
    jogador1[0].valor = QUATRO;

    jogador1[1].naipe = OUROS;
    jogador1[1].valor = OITO;
    
    jogador1[2].naipe = PAUS;
    jogador1[2].valor = REI;
    
    jogador1[3].naipe = OUROS;
    jogador1[3].valor = QUATRO;
    
    jogador1[4].naipe = ESPADAS;
    jogador1[4].valor = AS;
    
    par = tem1Par(jogador1);
    assert(par.valor != ZERO);    
}


void testaTem2Pares(void){

    carta jogador1[5];
    carta par;
    
    jogador1[0].naipe = OUROS;
    jogador1[0].valor = QUATRO;

    jogador1[1].naipe = OUROS;
    jogador1[1].valor = OITO;
    
    jogador1[2].naipe = PAUS;
    jogador1[2].valor = REI;
    
    jogador1[3].naipe = OUROS;
    jogador1[3].valor = QUATRO;
    
    jogador1[4].naipe = ESPADAS;
    jogador1[4].valor = OITO;
    
    par = tem2Pares(jogador1);
    assert(par.valor == OITO);    
}


void testaTemTrinca(void){

    carta jogador1[5];
    carta trinca;
    
    jogador1[0].naipe = OUROS;
    jogador1[0].valor = QUATRO;

    jogador1[1].naipe = OUROS;
    jogador1[1].valor = OITO;
    
    jogador1[2].naipe = PAUS;
    jogador1[2].valor = OITO;
    
    jogador1[3].naipe = OUROS;
    jogador1[3].valor = QUATRO;
    
    jogador1[4].naipe = ESPADAS;
    jogador1[4].valor = OITO;
    
    trinca = temTrinca(jogador1);
    assert(trinca.valor == OITO);    
}
/**

    
    jogador1[0].naipe = OUROS;
    jogador1[0].valor = QUATRO;

    jogador1[1].naipe = OUROS;
    jogador1[1].valor = OITO;
    
    jogador1[2].naipe = PAUS;
    jogador1[2].valor = REI;
    
    jogador1[3].naipe = OUROS;
    jogador1[3].valor = NOVE;
    
    jogador1[4].naipe = ESPADAS;
    jogador1[4].valor = AS;

    jogador2[0].naipe = COPAS;
    jogador2[0].valor = AS;

    jogador2[1].naipe = ESPADAS;
    jogador2[1].valor = CINCO;
    
    jogador2[2].naipe = PAUS;
    jogador2[2].valor = VALETE;
    
    jogador2[3].naipe = OUROS;
    jogador2[3].valor = DOIS;
    
    jogador2[4].naipe = OUROS;
    jogador2[4].valor = VALETE;



        std::cout << "Jogador 1 venceu" << std::endl;
        */
