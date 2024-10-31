#include "colisoes.h"
#include <stdlib.h>

Cenas* criarCenas(int numCenas){

    Cenas* cenas = (Cenas*) malloc (numCenas * sizeof(Cenas));

    int i;
    for(i=0;i<numCenas;i++){
        (cenas)[i].codigoCena = i;
    }

    //-----------------------INÍCIO DA DECLARAÇÃO DAS PORTAS-----------------------------------------

    (cenas)[0].qtdPortas = 0;
    (cenas)[1].qtdPortas = 1;
    (cenas)[2].qtdPortas = 2;
    (cenas)[3].qtdPortas = 2;
    (cenas)[4].qtdPortas = 2;
    (cenas)[5].qtdPortas = 3;
    (cenas)[6].qtdPortas = 1;
    (cenas)[7].qtdPortas = 5;
    (cenas)[8].qtdPortas = 1;
    (cenas)[9].qtdPortas = 1;
    (cenas)[10].qtdPortas = 1; 
    (cenas)[11].qtdPortas = 1;
    (cenas)[12].qtdPortas = 3;
    (cenas)[13].qtdPortas = 3;
    (cenas)[14].qtdPortas = 3;
    (cenas)[15].qtdPortas = 3;
    (cenas)[16].qtdPortas = 3;
    (cenas)[17].qtdPortas = 3;
    (cenas)[18].qtdPortas = 2;
    (cenas)[19].qtdPortas = 2;
    (cenas)[20].qtdPortas = 2;
    (cenas)[21].qtdPortas = 0;
    (cenas)[22].qtdPortas = 0;

    Porta portas1[1] = {
        {{1900, 535, 60, 190}, 1, 2, 1, 60.0, 690.0}
    };

    Porta portas2[2] = {
        {{0, 625, 20, 180}, 2, 1, 1, 1795.0, 610.0},
        {{295, 1100, 255, 20}, 2, 3, 1, 878.0, 602.0}
    };

    Porta portas3[2] = {
        {{803, 567, 150, 17}, 3, 2, 1, 415.0, 960.0},
        {{0, 0, 10, 1080}, 3, 4, 1, 1800.0, 520.0}
    };

    Porta portas4[2] = {
        {{1910, 0, 20, 1080}, 4, 3, 1, 120.0, 520.0},
        {{0, 0, 10, 1080}, 4, 5, 1, 1800.0, 520.0}
    };

    Porta portas5[3] = {
        {{1910, 0, 20, 1080}, 5, 4, 1, 120.0, 520.0},
        {{0, 0, 10, 1080}, 5, 6, 1, 1800.0, 520.0},
        {{465, 620, 140, 25}, 5, 7, 0, 1470, 950.0}
    };

    Porta portas6[1] = {
        {{1910, 0, 10, 1080}, 6, 5, 1, 20.0, 520.0}
    };

    Porta portas7[5] = {
        {{1450, 220, 255, 5}, 7, 9, 1, 1685.0, 965.0},
        {{0, 0, 10, 1080}, 7, 8, 1, 1800.0, 520.0},
        {{1910, 530, 10, 245}, 7, 10, 1, 10.0, 500.0},
        {{1375, 1050, 270, 10}, 7, 5, 1, 470, 686.0},
        {{435, 390, 250, 20}, 7, 12, 0, 917.0, 990.0}
    };
 
    Porta portas8[1] = {
        {{1900, 0, 20, 1080}, 8, 7, 1, 10.0, 520.0}
    };

    Porta portas9[1] = {
        {{1585, 1050, 240, 10}, 9, 7, 1, 1555.0, 235.0}
    };

    Porta portas10[1] = {
        {{0, 0, 10, 1080}, 10, 7, 1, 1795.0, 605.0}
    };

    Porta portas11[1] = {
        {{830, 1000, 175, 20}, 11, 7, 1, 515.0, 410.0}
    };

    Porta portas12[3] = {
        {{830, 1070, 175, 10}, 12, 12, 1, 385.0, 280.0},
        {{315, 220, 235, 15}, 12, 13, 1, 917.0, 990.0},
        {{1335, 220, 240, 15}, 12, 20, 1, 917.0, 990.0}
    };

    Porta portas13[3] = {
        {{830, 1070, 175, 10}, 13, 19, 1, 385.0, 280.0},
        {{315, 220, 235, 15}, 13, 14, 1, 917.0, 990.0},
        {{1335, 220, 240, 15}, 13, 12, 1, 917.0, 990.0}
    };

    Porta portas14[3] = {
        {{830, 1070, 175, 10}, 14, 19, 1, 385.0, 280.0},
        {{315, 220, 235, 15}, 14, 20, 1, 917.0, 990.0},
        {{1335, 220, 240, 15}, 14, 15, 1, 917.0, 990.0}
    };

    Porta portas15[3] = {
        {{830, 1070, 175, 10}, 15, 16, 1, 385.0, 280.0},
        { {315, 220, 235, 15}, 15, 20, 1, 917.0, 990.0},
        {{1335, 220, 240, 15}, 15, 19, 1, 917.0, 990.0}
    };

    Porta portas16[3] = {
        {{830, 1070, 175, 10}, 16, 20, 1, 385.0, 280.0},
        {{315, 220, 235, 15}, 16, 17, 1, 917.0, 990.0},
        {{1335, 220, 240, 15}, 16, 14, 1, 917.0, 990.0}
    };

    Porta portas17[3] = {
        {{830, 1070, 175, 10}, 17, 19, 1, 385.0, 280.0},
        {{315, 220, 235, 15}, 17, 18, 1, 917.0, 990.0},
        {{1335, 220, 240, 15}, 17, 13, 1, 917.0, 990.0}
    };

    Porta portas18[2] = {
        {{830, 1070, 175, 10}, 18, 12, 1, 385.0, 280.0},
        {{850, 220, 240, 15}, 18, 21, 1, 917.0, 900.0}
    };

    Porta portas19[2] = {
        {{830, 1070, 175, 10}, 19, 12, 1, 385.0, 280.0},
        {{850, 220, 240, 15}, 19, 20, 1, 917.0, 990.0}
    };

    Porta portas20[2] = {
        {{830, 1070, 175, 10}, 20, 12, 1, 385.0, 280.0},
        {{1335, 220, 240, 15}, 20, 19, 1, 917.0, 990.0}
    };


    (cenas)[1].portas = (Porta *) calloc((cenas)[1].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[1].qtdPortas;i++){
        ((cenas)[1].portas)[i] = portas1[i];
    }

    (cenas)[2].portas = (Porta *) calloc((cenas)[2].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[2].qtdPortas;i++){
        ((cenas)[2].portas)[i] = portas2[i];
    }

    
    (cenas)[3].portas = (Porta *) calloc((cenas)[3].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[3].qtdPortas;i++){
        ((cenas)[3].portas)[i] = portas3[i];
    }


    (cenas)[4].portas = (Porta *) calloc((cenas)[4].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[4].qtdPortas;i++){
        ((cenas)[4].portas)[i] = portas4[i];
    }

    (cenas)[5].portas = (Porta *) calloc((cenas)[5].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[5].qtdPortas;i++){
        ((cenas)[5].portas)[i] = portas5[i];
    }
    (cenas)[6].portas = (Porta *) calloc((cenas)[6].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[6].qtdPortas;i++){
        ((cenas)[6].portas)[i] = portas6[i];
    }


    (cenas)[7].portas = (Porta *) calloc((cenas)[7].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[7].qtdPortas;i++){
        ((cenas)[7].portas)[i] = portas7[i];
    }

    (cenas)[8].portas = (Porta *) calloc((cenas)[8].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[8].qtdPortas;i++){
        ((cenas)[8].portas)[i] = portas8[i];
    }

   
    (cenas)[9].portas = (Porta *) calloc((cenas)[9].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[9].qtdPortas;i++){
        ((cenas)[9].portas)[i] = portas9[i];
    }

   
    (cenas)[10].portas = (Porta *) calloc((cenas)[10].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[10].qtdPortas;i++){
        ((cenas)[10].portas)[i] = portas10[i];
    }

    
    (cenas)[11].portas = (Porta *) calloc((cenas)[11].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[11].qtdPortas;i++){
        ((cenas)[11].portas)[i] = portas11[i];
    }
    
    
    //Portas do último Puzzle
    //Ordem até então Vermelho - Branco - Azul - Verde - Preto - Laranja - Violeta - Amarelo - Rosa
    //As portas da direita pulam o próximo quarto e vão para o seguinte
    //As da esquerda seguem a ordem
    //As portas de baixo voltam 1 quarto na sequência
    
    
    (cenas)[12].portas = (Porta *) calloc((cenas)[12].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[12].qtdPortas;i++){
        ((cenas)[12].portas)[i] = portas12[i];
    }

    
    (cenas)[13].portas = (Porta *) calloc((cenas)[13].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[13].qtdPortas;i++){
        ((cenas)[13].portas)[i] = portas13[i];
    }

   
    (cenas)[14].portas = (Porta *) calloc((cenas)[14].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[14].qtdPortas;i++){
        ((cenas)[14].portas)[i] = portas14[i];
    }

    
    (cenas)[15].portas = (Porta *) calloc((cenas)[15].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[15].qtdPortas;i++){
        ((cenas)[15].portas)[i] = portas15[i];
    }


    (cenas)[16].portas = (Porta *) calloc((cenas)[16].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[16].qtdPortas;i++){
        ((cenas)[16].portas)[i] = portas16[i];
    }


    (cenas)[17].portas = (Porta *) calloc((cenas)[17].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[17].qtdPortas;i++){
        ((cenas)[17].portas)[i] = portas17[i];
    }

  
    (cenas)[18].portas = (Porta *) calloc((cenas)[18].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[18].qtdPortas;i++){
        ((cenas)[18].portas)[i] = portas18[i];
    }


    (cenas)[19].portas = (Porta *) calloc((cenas)[19].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[19].qtdPortas;i++){
        ((cenas)[19].portas)[i] = portas19[i];
    }

   
    (cenas)[20].portas = (Porta *) calloc((cenas)[20].qtdPortas, sizeof(Porta));
    for(i=0;i<(cenas)[20].qtdPortas;i++){
        ((cenas)[20].portas)[i] = portas20[i];
    }
    

    //Vou adicionar amanhã junto com a origem e destino dos negócios:
    //Coordenadas das salas coloridas com duas portas = 315 220 235 15     1335 220 240 15
    //Coordenadas das salas coloridas com só uma porta = 850 220 240 15
    //Coordenadas da entrada das salas coloridas = 830 1070 175 10
    //-----------------------FIM DA DECLARAÇÃO DAS PORTAS-----------------------------------------------

    //-----------------------INÍCIO DA DECLARAÇÃO DOS OBSTÁCULOS-----------------------------------------
    (cenas)[0].qtdObstaculos = 0;
    (cenas)[1].qtdObstaculos = 3;
    (cenas)[2].qtdObstaculos = 3;
    (cenas)[3].qtdObstaculos = 5;
    (cenas)[4].qtdObstaculos = 0;
    (cenas)[5].qtdObstaculos = 3;
    (cenas)[6].qtdObstaculos = 6;
    (cenas)[7].qtdObstaculos = 4;
    (cenas)[8].qtdObstaculos = 6;
    (cenas)[9].qtdObstaculos = 7;
    (cenas)[10].qtdObstaculos = 3;
    (cenas)[11].qtdObstaculos = 5;
    (cenas)[12].qtdObstaculos = 0;
    (cenas)[13].qtdObstaculos = 0;
    (cenas)[14].qtdObstaculos = 0;
    (cenas)[15].qtdObstaculos = 0;
    (cenas)[16].qtdObstaculos = 0;
    (cenas)[17].qtdObstaculos = 0;
    (cenas)[18].qtdObstaculos = 0;
    (cenas)[19].qtdObstaculos = 0;
    (cenas)[20].qtdObstaculos = 0;
    (cenas)[21].qtdObstaculos = 0;
    (cenas)[22].qtdObstaculos = 0;

    Rectangle obstaculos1[3]= {{160, 220, 370, 505}, 
                               {710, 220, 220, 155}, 
                               {1545, 220, 255, 105}
                              };
           Rectangle obstaculos2[3] = {{1150, 295, 180, 170}, 
                                {1665, 295, 176, 170},
                                {1365, 265, 260, 185}
                               };  
           Rectangle obstaculos3[5] = {{1350, 220, 370, 275}, 
                                {1720, 220, 130, 220},
                                {985, 220, 365, 450},
                                {618, 220, 182, 450},
                                {618, 220, 732, 345}
                               };      
              Rectangle obstaculos5[3] = {{20, 220, 115, 80}, 
                                {135, 220, 840, 420},
                                {975, 220, 320, 315},
                               };   

    Rectangle obstaculos6[6] = {{440, 535, 145, 145}, 
                               {870, 535, 138, 145},
                               {425, 800, 138, 145},
                               {855, 810, 138, 140},
                               {0, 0, 120, 1080},
                               {0, 0, 1920, 360}
                              };
         Rectangle obstaculos7[4] = {{250, 730, 255, 450}, 
                               {435, 220, 250, 170},
                               {760, 220, 550, 185},
                               {760, 740, 255, 220}
                              };    

        
    Rectangle obstaculos8[6] = {{490, 220, 1430, 265}, 
                               {80, 220, 335, 265},
                               {0, 705, 385, 375},
                               {895, 710, 385, 370},
                               {705, 735, 175, 345},
                               {1313, 730, 172, 145}
                              };    
           Rectangle obstaculos9[7] = {{1295, 220, 130, 225}, 
                               {1295, 665, 130, 415},
                               {440, 220, 365, 475},
                               {75, 220, 250, 220},
                               {915, 220, 400, 95},
                               {1000, 700, 125, 270},
                               {130, 700, 125, 270},
                              };    
            Rectangle obstaculos10[3] ={{290, 220, 765, 140}, 
                                {340, 360, 670, 160},
                                {1535, 220, 175, 210}
                               };  
             
    Rectangle obstaculos11[5]={{145, 220, 385, 55}, 
                               {320, 220, 130, 270},
                               {1030, 220, 365, 250},
                               {1355, 220, 310, 65},
                               {1520, 220, 125, 280}
                              };  

    (cenas)[1].obstaculos = (Rectangle *) calloc((cenas)[1].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[1].qtdObstaculos; i++){
        ((cenas)[1].obstaculos)[i] = obstaculos1[i];
    }


    (cenas)[2].obstaculos = (Rectangle *) calloc((cenas)[2].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[2].qtdObstaculos; i++){
        ((cenas)[2].obstaculos)[i] = obstaculos2[i];
    }

  
    (cenas)[3].obstaculos = (Rectangle *) calloc((cenas)[3].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[3].qtdObstaculos; i++){
        ((cenas)[3].obstaculos)[i] = obstaculos3[i];
    }

  
    (cenas)[5].obstaculos = (Rectangle *) calloc((cenas)[5].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[5].qtdObstaculos; i++){
        ((cenas)[5].obstaculos)[i] = obstaculos5[i];
    }

    (cenas)[6].obstaculos = (Rectangle *) calloc((cenas)[6].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[6].qtdObstaculos; i++){
        ((cenas)[6].obstaculos)[i] = obstaculos6[i];
    }


    (cenas)[7].obstaculos = (Rectangle *) calloc((cenas)[7].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[7].qtdObstaculos; i++){
        ((cenas)[7].obstaculos)[i] = obstaculos7[i];
    }

    (cenas)[8].obstaculos = (Rectangle *) calloc((cenas)[8].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[8].qtdObstaculos; i++){
        ((cenas)[8].obstaculos)[i] = obstaculos8[i];
    }


    (cenas)[9].obstaculos = (Rectangle *) calloc((cenas)[9].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[9].qtdObstaculos; i++){
        ((cenas)[9].obstaculos)[i] = obstaculos9[i];
    }


    (cenas)[10].obstaculos = (Rectangle *) calloc((cenas)[10].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[10].qtdObstaculos; i++){
        ((cenas)[10].obstaculos)[i] = obstaculos10[i];
    }

    (cenas)[11].obstaculos = (Rectangle *) calloc((cenas)[11].qtdObstaculos, sizeof(Rectangle));
    for(i=0; i<(cenas)[11].qtdObstaculos; i++){
        ((cenas)[11].obstaculos)[i] = obstaculos11[i];
    }

    //-----------------------FINAL DA DECLARAÇÃO DOS OBSTÁCULOS-----------------------------------------

    return cenas;

}

int colisaoMapa(Rectangle player, Cenas cena){

    if(cena.qtdObstaculos==0) {
        return 0;
    }

    for(int i=0;i<cena.qtdObstaculos;i++){
        if(CheckCollisionRecs(player, cena.obstaculos[i])) {
            return 1;
        }
    }

    return 0;
}


int trocarCena(Rectangle player, float *x, float *y, Cenas cena, int *cenaAtual){

    for(int i=0;i<cena.qtdPortas;i++){
        if(CheckCollisionRecs(player, (cena.portas[i]).area)==1){

            if((cena.portas[i]).check==1) {

                *cenaAtual = (cena.portas[i]).destino;
                *x = (cena.portas[i]).destinoX;
                *y = (cena.portas[i]).destinoY;

                return 1;
            }
        }
    }

    return 0;
}


void freeCenas(Cenas* cenas,int numCenas){

    int i;
    for(i=0;i<numCenas;i++){
        free(cenas[i].obstaculos);
        free(cenas[i].portas);
    }
    free(cenas);

}
