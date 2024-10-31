#include "raylib/src/raylib.h"
#include "player.h"
#include "colisoes.h"
#include "animacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void phaseOne(Jogador *players, int *cenaAtual, Cenas *cena, Sound sound){
    
    if (*cenaAtual == 5){ //tranca da porta
        //if (players->key[0] == false && (players->posX >= 480 && players->posX <= 615) && (players->posY >= 620 && players->posY <= 650)){
        //    // imprimir "a porta está trancada, embaixo do vaso blah blah blah" na tela
        //}
        /*else*/ 
        if ((*players).key[0] == true && (players->posX >= 480 && players->posX <= 615) && (players->posY >= 620 && players->posY <= 650)){
            players->itens[0] = false;
        }    
    }
    
    if (*cenaAtual == 6 && (players->posX >= 550 && players->posX <= 600) && (players->posY >= 810 && players->posY <= 900) /* && players->key[0] == false*/ && IsKeyPressed(KEY_E)){
        players->itens[0] = true; // animação baseada nisso
        players->key[0] = true;
        PlaySound(sound);
    }    
}

void phaseTwo(Jogador *player, int *cenaAtual, Cenas *cena, Sound sound, int* pato){
    //.1 pegar maca na cozinha
    int proximoMaca = 0;
    if(player->posX >= 380 && player->posX <= 400){
        if(player->posY >= 550) proximoMaca = 1;   //nao precisava
        else proximoMaca = 0;
    }
    else if(player->posY >= 550 && player->posY <= 630){
        if(player->posX<=400) proximoMaca = 1;    //fazer isso, mas ok
        else proximoMaca = 0;
    }
    
    if(*cenaAtual == 8){ //dentro da cozinha 
        if(player->key[1] == false && proximoMaca == 1 && IsKeyDown(KEY_E)){ // proximo ao cesto de maças
            player->itens[1] = true;// animaçao de mostrar a maça
            player->key[1] = true;
            PlaySound(sound);
        }    
    } 
    
    //2. alimentar o pato
    if(*cenaAtual == 9){
        if(player->key[1] == true && (player->posY <= 640 && player->posY >= 400) && (player->posX < 1600 && player->posX > 1300) && IsKeyDown(KEY_E)){
            if(player->itens[1] == true)PlaySound(sound);
            (*pato) = 1;
            player->itens[1] = false;
            //player->posX = 1725;
            //player-> posY = 535;
        }
    }
}

void phaseThree(Jogador *player, int *cenaAtual, Cenas *cena, Sound sound, int *frame1, int *frame2){
    static bool aux1 = true, aux2, aux3;
    if(*cenaAtual == 9){
 //.1 abrir cortina
        /*if(player->posy = ___ && (player->posX>= __ && player->posX<= ___) && IsKeyDown(KEY_E) && aux1 == false){
            //desenhar cortina aberta
            aux1 = true;
        }*/
 //.2 espelho 01
        if((player->posX>= 850 && player->posX <= 1250 && player->posY >= 600 && player->posY <= 1100) && IsKeyPressed(KEY_E)){
            static int giroEspelho1 = 3; //frame inicial
            giroEspelho1++;
            if(giroEspelho1%4==0){ //correta
                aux2 = true;
                giroEspelho1 = 0;
                (*frame1) = 0;
                PlaySound(sound);
            }           
            else if(giroEspelho1%4==1){
                aux2 = false;
                (*frame1) = 1;
            }
            else if(giroEspelho1%4==2){
                aux2 = false;
                (*frame1) = 2;
            }
            else if(giroEspelho1%4==3){
                aux2 = false;
                (*frame1) = 3;
            }
        }    
 //.3 espelho 02
        if((player->posX >= 30 && player->posX <=270 && player->posY<=1100 && player->posY>= 600) && IsKeyPressed(KEY_E)){
            static int giroEspelho2 = 0;
            giroEspelho2++;
            if(giroEspelho2%4==0){
                aux3 = false;
                giroEspelho2 = 0;
                (*frame2) = 0;
            }           
            else if(giroEspelho2%4==1){
                aux3 = false;
                (*frame2) = 1;
            }
            else if(giroEspelho2%4==2){//correta
                aux3 = true;
                (*frame2) = 2;
                PlaySound(sound);
            }
            else if(giroEspelho2%4==3){
                aux3 = false;
                (*frame2) = 3;
            }
        } 
 //.4 abrir gaveta
    static int flagGav = 0;
        if(aux2 == true && aux3 == true && flagGav == 0){
            //abrir gaveta
            //PlaySound(sound);
            player->key[2] = true;
        }
//.4 pegar item da gaveta
        if(player->key[2]==true && player->posX >= 60 && player->posX <=300 && player->posY<=500 && player->posY>= 400 && IsKeyPressed(KEY_E)){
            player->itens[2] = true; 
            flagGav = 1;
            PlaySound(sound);
        }
    }
    //printf("%d %d %d %d\n", aux1, aux2, aux3, player->key[2]);
}   
