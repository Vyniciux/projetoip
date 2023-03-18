#include "raylib.h"
#include <stdlib.h>
#include "textures.h"
const int NumTexture = 64;
const int NumTexture2D = 11;
const int NumTexture2DI = 5;

Texture2D* InitiTex2DI(){

    Texture2D chave = LoadTexture("assets/itens/iten007.png");
    Texture2D maca = LoadTexture("assets/itens/iten005.png");
    Texture2D livro = LoadTexture("assets/itens/iten0010.png");
    Texture2D baldeVazio = LoadTexture("assets/itens/iten008.png");
    Texture2D baldeCheio = LoadTexture("assets/itens/iten009.png");

    Texture2D texturaarray[5] = {
            
                chave,//0
                maca,//1
                livro,//2
                baldeVazio,//3
                baldeCheio//4
    };


    Texture2D* texturas = (Texture2D*) malloc(NumTexture2DI*sizeof(Texture2D));

    for(int i=0; i<NumTexture2DI; i++){

        texturas[i]=texturaarray[i];

    }

    return(texturas);





}

Texture2D* InitiTex2D(){


    Texture2D BotaoStart = LoadTexture("assets/Menu/botaojogar.png");//0
    Texture2D BotaoSobre= LoadTexture("assets/Menu/botaosobre.png");//1
    Texture2D BotaoInst = LoadTexture ("assets/Menu/botaoinst.png");//3
    Texture2D BotaoFechar = LoadTexture("assets/Menu/botaoclose.png");//4
    Texture2D Titulo = LoadTexture("assets/Menu/title.png");//5
    Texture2D Lupa = LoadTexture("assets/Menu/lupa.png");//6

    Texture2D Player =  LoadTexture("assets/personagemov.png");//7
    Texture2D vizin = LoadTexture("assets/vizin.png");//8
    Texture2D Pato =  LoadTexture("assets/pato.png");//9
    Texture2D fogo =  LoadTexture("assets/img00133.png");//10
    Texture2D espelho = LoadTexture("assets/img00128.png");//11

    Texture2D chave = LoadTexture("assets/itens/iten007.png");
    Texture2D maca = LoadTexture("assets/itens/iten005.png");
    Texture2D livro = LoadTexture("assets/itens/iten0010.png");
    Texture2D baldeVazio = LoadTexture("assets/itens/iten008.png");
    Texture2D baldeCheio = LoadTexture("assets/itens/iten009.png");

    Texture2D texturaarray[11] = {
            
                BotaoStart,//0
                BotaoSobre,//1
                BotaoInst,//2
                BotaoFechar,//3
                Titulo,//4
                Lupa,//5
                Player,//6
                vizin,//7
                Pato,//8
                fogo,//9
                espelho//10
    };


    Texture2D* texturas = (Texture2D*) malloc(NumTexture2D*sizeof(Texture2D));

    for(int i=0; i<NumTexture2D; i++){

        texturas[i]=texturaarray[i];

    }

    return(texturas);





}

Texture* InitTex(){


    Texture mn1 = LoadTexture("assets/Menu/menu001.png"); 
    Texture mn2 = LoadTexture("assets/Menu/menub001.png");
    Texture mn3 = LoadTexture("assets/Menu/menu003.png");
    Texture mn4 = LoadTexture("assets/Menu/menu004.png");
    Texture mn5 = LoadTexture("assets/Menu/menu005.png");
    Texture mn6 = LoadTexture("assets/Menu/menu006.png");

  
    Texture fundo = LoadTexture("assets/img005.png");
    Texture fundo1 = LoadTexture("assets/img0051.png");
    Texture sala = LoadTexture("assets/img006.png");
    Texture sala1 = LoadTexture("assets/img0061.png");
    Texture fora = LoadTexture("assets/img008.png");
    Texture fora1 = LoadTexture("assets/img0081.png");
    Texture fora2 = LoadTexture("assets/img009.png");
    Texture fora3 = LoadTexture("assets/img0011.png");
    Texture fora4 = LoadTexture("assets/img00111.png");
    Texture casavizin = LoadTexture("assets/img0010.png");
    Texture casavizin1 = LoadTexture("assets/img00101.png");
    Texture casavizin2 = LoadTexture("assets/img00102.png");
    Texture salav = LoadTexture("assets/img0013.png");
    Texture cozinhav = LoadTexture("assets/img0014.png");
    Texture cozinhav1 = LoadTexture("assets/img00141.png");
    Texture quarto = LoadTexture("assets/img0012.png");
    Texture quarto1 = LoadTexture("assets/img00121.png");
    Texture quarto2 = LoadTexture("assets/img00122.png");
    Texture quarto3 = LoadTexture("assets/img00123.png");
    Texture quarto4 = LoadTexture("assets/img00124.png");
    Texture quarto5 = LoadTexture("assets/img00125.png");
    Texture quarto6 = LoadTexture("assets/img00126.png");
    Texture quarto7 = LoadTexture("assets/img00127.png");
    Texture salav1 = LoadTexture("assets/img00131.png");
    Texture estantef = LoadTexture("assets/img00132.png");
    Texture salaopened = LoadTexture("assets/img00134.png");
    Texture banheiro = LoadTexture("assets/img00151.png");
    Texture selva = LoadTexture("assets/img0016.png");
    Texture cacto = LoadTexture("assets/img00129.png");
    Texture cactoFlor = LoadTexture("assets/img001210.png");
    Texture gaveta = LoadTexture("assets/img00122.png");



    Texture senha1 = LoadTexture("assets/Menu/lonb01.png");
    Texture senha2 = LoadTexture("assets/Menu/lonb02.png");
    Texture senha3 = LoadTexture("assets/Menu/lonb03.png");
    Texture senha4 = LoadTexture("assets/Menu/lonb00.png");
    Texture senha5 = LoadTexture("assets/Menu/lonb04.png");

    Texture feixeHorizontal = LoadTexture("assets/img00126.png");
    Texture feixeVertical1 = LoadTexture("assets/img00125.png");
    Texture feixeVertical2 = LoadTexture("assets/img00127.png");

    Texture salalab1 = LoadTexture("assets/puzzle estante/qt001.png");
    Texture salalab2 = LoadTexture("assets/puzzle estante/qt002.png");
    Texture salalab3 = LoadTexture("assets/puzzle estante/qt003.png");
    Texture salalab4 = LoadTexture("assets/puzzle estante/qt004.png");
    Texture salalab5 = LoadTexture("assets/puzzle estante/qt005.png");
    Texture salalab6 = LoadTexture("assets/puzzle estante/qt006.png");
    Texture salalab7 = LoadTexture("assets/puzzle estante/qt007.png");
    Texture salalab8 = LoadTexture("assets/puzzle estante/qt008.png");
    Texture salalab9 = LoadTexture("assets/puzzle estante/qt009.png");

    Texture num1 = LoadTexture("assets/puzzle estante/num23.png");
    Texture num2 = LoadTexture("assets/puzzle estante/num11.png");
    Texture num3 = LoadTexture("assets/puzzle estante/num02.png");
    Texture num4 = LoadTexture("assets/puzzle estante/num31.png");
    Texture num5 = LoadTexture("assets/puzzle estante/num79.png");
    Texture num6 = LoadTexture("assets/puzzle estante/num09.png");
    Texture num7 = LoadTexture("assets/puzzle estante/num01.png");
    Texture num8 = LoadTexture("assets/puzzle estante/num03.png");
    Texture num9 = LoadTexture("assets/puzzle estante/num15.png");

    Texture final1 = LoadTexture("assets/final001.png");

    Texture texturaray[64]= {mn1, //0
                            mn2,  //1
                            mn3, //2
                            mn4,//3
                            mn5,//4
                            mn6,//5
                            fundo,//6
                            fundo1, //7
                            sala,//8
                            sala1, //9
                            fora, //10
                            fora1,//11
                            fora2,//12
                            fora3, //13
                            fora4,//14
                            casavizin,//15
                            casavizin1,//16
                            casavizin2, //17
                            salav,//18
                            cozinhav, //19
                            cozinhav1,//20
                            quarto,//21
                            quarto1, //22
                            quarto2, //23
                            quarto3, //24
                            quarto4, //25
                            quarto5,//26
                            quarto6,//27
                            quarto7, //28
                            salav1, //29
                            estantef, //30
                            salaopened,//31
                            banheiro, //32
                            selva,//33
                            cacto, //34
                            cactoFlor,//35
                            gaveta,//36
                            senha1,//37
                            senha2, //38
                            senha3,//39
                            senha4,//40
                            senha5, //41
                            feixeHorizontal,//42
                            feixeVertical1,//43
                            feixeVertical2,//44
                            salalab1, //45
                            salalab2,//46
                            salalab3, //47
                            salalab4, //48
                            salalab5, //49
                            salalab6, //50
                            salalab7, //51
                            salalab8, //52
                            salalab9, //53
                            num1, //54
                            num2, //55
                            num3, //56
                            num4, //57
                            num5, //58
                            num6, //59
                            num7,//60
                            num8,//61
                            num9, //62
                            final1//63
                          };


    Texture* texturas = (Texture*) malloc(NumTexture*sizeof(Texture));

    for(int i=0; i<NumTexture; i++){

        texturas[i]=texturaray[i];

    }

    return(texturas);

}

void freeTexturasD(Texture** TexturasD){

    for(int i=0; i<NumTexture; i++){

        UnloadTexture(TexturasD[0][i]);
        free(TexturasD[i]);

    }

}
void freeTexturas2D(Texture2D** Texturas2D){

    for(int i=0; i<NumTexture2D; i++){

        UnloadTexture(Texturas2D[0][i]);
        free(Texturas2D[i]);

    }

}
void freeTexturas2DI(Texture2D** Texturas2D){

    for(int i=0; i<NumTexture2DI; i++){

        UnloadTexture(Texturas2D[0][i]);
        free(Texturas2D[i]);

    }

}

