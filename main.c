#include "raylib.h"
#include "colisoes.h"
#include "animacao.h"
#include "player.h"
#include "textures.h"
#include <stdio.h>
#include <stdlib.h>


#define NUM_FRAMES  5

int main(void)
{
 
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "O vizin");

    Vector2 position = { (float)screenWidth/2, (float)screenHeight/2 };
    
    Texture* TexturasD = InitTex();

    Texture2D* Texturas2D = InitiTex2D();

    Texture2D* Texturas2Ditens = InitiTex2DI();

    InitAudioDevice();                                      
    Music music = LoadMusicStream("assets/sons/MusicaTeste.mp3");  
           
    PlayMusicStream(music);                                 
    Sound sound = LoadSound("assets/sons/PokemonA.wav");


    Cenas* cenas = criarCenas(23); 
   

    ////Joao's code ///////////////////////////////////////////////////////////////////////////////////////////////////

    float FrameWidth = (float) (Texturas2D[6].width/6);
    float x = 10;
    float y = 10;                                                 //PLAYER;
    int frame = 1;
    float Mov = 2;
 
    Rectangle Fire;        
    Vector2 f = {942, 50};                         //FOGO;
 
    float FrameWidth2 = (float) (Texturas2D[8].width/3);
    float px = 1200;
    float py = 401;                                         //PATO; --- COMIDA++ QUANDO O PATO RECEBE COMIDA;
    int frame2 = 1; 
    float Mov2 = 2;
    int PatoFlag = 0;
    Rectangle patoHitbox = {px, py, FrameWidth2, Texturas2D[8].height/4};

    
    /////Quinha's code///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   
    Vector2 nextPosition = { (float)screenWidth/2 + 100, (float)screenHeight/2};
    Rectangle player = {position.x, position.y, 100, 80};
    

    //FINAL DO CÓDIGO DO QUNHAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    //Giovanna's code///////////////////////////////////////////////////////////////////////////////////////////////////////
        
    Vector2 PosMouse = { 0.0f, 0.0f };   

    //usado para animacao das nuvens
    float movnuvens = 0.0f;
    
    //Botao Jogar:
    
    float frameHeightstart = (float)Texturas2D[0].height/NUM_FRAMES;
    Rectangle sourceRecstart = {0, 0,(float)Texturas2D[0].width, frameHeightstart+110};
    Rectangle btnStartrec = { 200,500,(float)Texturas2D[0].width, frameHeightstart+110};
    int btnstart = 0;
    int btnActionstart = false;
    
 
    //Botao Sobre:
    
    float frameHeightsobre = (float)Texturas2D[0].height/NUM_FRAMES;
    Rectangle sourceRecsobre = {0, 0,(float)Texturas2D[1].width, frameHeightsobre+110};
    Rectangle btnSobrerec = { 200, 620,(float)Texturas2D[1].width, frameHeightsobre+110};
    int btnsobre = 0;
    int btnActionsobre = false;
    
    //Botao Instrucoes:
    
    float frameHeightinst = (float)Texturas2D[2].height/NUM_FRAMES;
    Rectangle sourceRecinst = {0, 0,(float)Texturas2D[2].width, frameHeightinst+110};
    Rectangle btnInstrec = { 200, 740,(float)Texturas2D[2].width, frameHeightinst+110};
    int btninst = 0;
    int btnActioninst = false;
    
    //Botao Fechar:
    
    float frameHeightfechar = (float)Texturas2D[3].height/NUM_FRAMES;
    Rectangle sourceRecfechar = {0, 0,(float)Texturas2D[3].width, frameHeightfechar+100};
    Rectangle btnFecharrec = { 1650, 80,(float)Texturas2D[3].width, frameHeightfechar+100};
    int btnfechar = 0;
    int btnActionfechar = false;

    //usado para animacao do texto
    
    int framesCounter1 = 0;
    int framesCounter2 = 0;
    int framesCounter3 = 0;
    int framesCounter4 = 0;
    int framesCounter5 = 0;
    int framesCounter6 = 0;
    int framesCounter7 = 0;
    //variavel para iniciar o jogo
    
    int iniciajogo = false;
    
    //mensagens:
    
    const char messagejogar1[128] = "Sabrina sempre desconfiou que seu vizinho, Isac, escondia algo.";
    const char messagejogar3[128] = "sempre foi muito curiosa, resolveu invadir a casa dele a fim de encontrar";
    const char messagejogar2[128] = "Certo dia, Sabrina percebeu que Isac havia saido e como desde pequena";
    const char messagejogar4[128] = "alguma coisa que confirmasse sua desconfiança."; 
    const char messagejogar5[128] = "Para isso, ela precisa desvendar uma serie de desafios antes que Isac a pegue no flagra!";
    const char messagejogar6[128] = "AJUDE SABRINA A MATAR SUA CURIOSIDADE!!";
    
    
    const char messagesobre1[128] = "Este jogo é um projeto para disciplina de Introdução a";
    const char messagesobre2[128] = "Programação, com o objetivo principal aplicar os conhecimentos";
    const char messagesobre3[128] = "da linguagem C e da biblioteca Raylib.";
   
    
    const char messageinst1[128] = "PARA QUE SABRINA ANDE PARA DIREITA APERTE : D";
    const char messageinst2[128] = "PARA QUE SABRINA ANDE PARA ESQUERDA APERTE : A";
    const char messageinst3[128] = "PARA QUE SABRINA ANDE PARA CIMA APERTE : W";
    const char messageinst4[128] = "PARA QUE SABRINA ANDE PARA BAIXO APERTE : S";
    const char messageinst5[128] = "PARA QUE SABRINA INTERAJA COM ALGO APERTE : E";
    const char messageinst6[128] = "PARA PAUSAR O JOGO APERTE : P";
                                 
    int currentScreen=1;


    //senha 1
    float frameHeights1 = (float)TexturasD[37].height/NUM_FRAMES;
    Rectangle sourceRecs1 = {0, 0,(float)TexturasD[37].width, frameHeights1+200};
    Rectangle btnS1rec = { 600, 400,(float)TexturasD[37].width, frameHeights1+200};
    int btns1 = 0;
    int btnActions1 = false;
   
    
    // senha 2
    float frameHeights2 = (float)TexturasD[38].height/NUM_FRAMES;
    Rectangle sourceRecs2 = {0, 0,(float)TexturasD[38].width, frameHeights2+200};
    Rectangle btnS2rec = { 200, 600,(float)TexturasD[38].width, frameHeights2+200};
    int btns2 = 0;
    int btnActions2 = false;
    
    //senha 3
    
    float frameHeights3 = (float)TexturasD[39].height/NUM_FRAMES;
    Rectangle sourceRecs3 = {0, 0,(float)TexturasD[39].width, frameHeights3+180};
    Rectangle btnS3rec = { 1000, 600,(float)TexturasD[39].width, frameHeights3+180};
    int btns3 = 0;
    int btnActions3 = false;
    
    //senha 4
   
    
    float frameHeights4 = (float)TexturasD[40].height/NUM_FRAMES;
    Rectangle sourceRecs4 = {0, 0,(float)TexturasD[40].width, frameHeights4+180};
    Rectangle btnS4rec = { 200, 800,(float)TexturasD[40].width, frameHeights4+180};
    int btns4 = 0;
    int btnActions4 = false;
    
    //senha 5
    
    float frameHeights5 = (float)TexturasD[41].height/NUM_FRAMES;
    Rectangle sourceRecs5 = {0, 0,(float)TexturasD[41].width, frameHeights5+180};
    Rectangle btnS5rec = { 1000, 800,(float)TexturasD[41].width, frameHeights5+180};
    int btns5 = 0;
    int btnActions5 = false;

    

    // FINAL DO CODE DA GIO //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Arthur's code   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Jogador jogador;
    for(int h = 0; h < 5; h++){
        jogador.key[h] = false;
        jogador.itens[h] = false;
    }
    int frameEsp1 = 3, frameEsp2 = 0;

    /////////////////////////////////

    int cena = 0;    /////troca aqui pra começar em outra cena  // controle de produção
    int cenapp = 1;
    float VelPadrao = 10;



    SetTargetFPS(60);           

    while (!WindowShouldClose())   
    {

        UpdateMusicStream(music);                          //TOCAR MUSICA;

        // Update
        //---------------------------------------0------------------------------------------
        // TODO: Update your variables here

        position.x = nextPosition.x;
        position.y = nextPosition.y;

        if (IsKeyDown(KEY_D)&& position.x<1890) nextPosition.x += VelPadrao;
        if (IsKeyDown(KEY_A)&& position.x>0) nextPosition.x -= VelPadrao;
        if (IsKeyDown(KEY_W)&& position.y>220) nextPosition.y -= VelPadrao;
        if (IsKeyDown(KEY_S)&& position.y<1040) nextPosition.y += VelPadrao;

        if (IsKeyDown(KEY_M)) {VelPadrao+=0.5;}
        if (IsKeyDown(KEY_N)){VelPadrao-=0.5;}
        if (IsKeyDown(KEY_P)){if(cena!=0){cenapp=cena;} cena=0;}
        //LUCAS//------------------------





        if(trocarCena(player, &(nextPosition.x), &(nextPosition.y), cenas[cena], &cena)==1){
            position.x = nextPosition.x;
            position.y = nextPosition.y;
        }

        player.x = nextPosition.x;
        player.y = nextPosition.y;

        if(colisaoMapa(player, cenas[cena])==1){ //Houve colisão com algum objeto
          player.x = position.x;
          player.y = position.y;
          nextPosition.x = position.x;
          nextPosition.y = position.y;
        }
        if((cena==9)&&(CheckCollisionRecs(patoHitbox, player)==1)){ //Houve colisão com algum objeto
          player.x = position.x;
          player.y = position.y;
          nextPosition.x = position.x;
          nextPosition.y = position.y;
        }
     
     
        //ARTHUR//-----------------------

        jogador.posX = position.x;
        jogador.posY = position.y;

        phaseOne(&jogador, &cena, &cenas[6], sound);
        if(jogador.key[0] == true) cenas[5].portas[2].check = 1;

        phaseTwo(&jogador, &cena, &cenas[8], sound, &PatoFlag);

        phaseThree(&jogador, &cena, &cenas[9], sound, &frameEsp1, &frameEsp2);
        if(jogador.key[2] ==  true) cenas[7].portas[4].check = 1;

        //---------------------------------


        //GIOVANNA//--------------------
        if(cena==0){

          switch(currentScreen)
          {
        
              case 1:
              {
                  //animacao das nuvens:
                  movnuvens -= 0.3f;
        
                  if (movnuvens <= -(TexturasD[4]).width*2) movnuvens = 0;
        
                  //checando colisao do mouse com os botoes:
                  
                  PosMouse = GetMousePosition();
                  //colisao com o botao jogar    
                  if (CheckCollisionPointRec(PosMouse, btnStartrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnstart = 2; currentScreen =2;}
                      else {btnstart = 1;}
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnActionstart = true;   
                  }
        
                  else btnstart = 0;
                  
                  sourceRecstart.y = btnstart*(frameHeightstart-30);
        
                  //colisao com o botao sobre
        
                  if (CheckCollisionPointRec(PosMouse, btnSobrerec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnsobre = 2;currentScreen = 3;}
                      else {btnsobre = 1;}
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionsobre = true;}   
                  }
        
                  else btnsobre = 0;
                  sourceRecsobre.y = btnsobre*(frameHeightsobre-30);
        
                  //colisao com o botao instrucoes
        
                  if (CheckCollisionPointRec(PosMouse, btnInstrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btninst = 2; currentScreen=4;}
                      else btninst = 1;
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActioninst = true;}   
                  }
        
                  else btninst = 0;
                  
                  sourceRecinst.y = btninst*(frameHeightinst-30);
          
              }break;
        
              case 2:
              {
                  //letrinha por letrinha

                  framesCounter1++;
                  
                  if(framesCounter1 > 245){framesCounter2++;}
                  if(framesCounter2 > 245){framesCounter3++;}
                  if(framesCounter3 > 245){framesCounter4++;}
                  if(framesCounter4 > 255){framesCounter5++;}
                  if(framesCounter5 > 293){framesCounter6++;}
                  
                  iniciajogo = true;
                  if(framesCounter6 > 150){cena=cenapp;currentScreen=1;}
              
                  
              }break;
        
              case 3:
              {

                  PosMouse = GetMousePosition();
                  
                  if (CheckCollisionPointRec(PosMouse, btnFecharrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnfechar = 2; currentScreen=1;}
                      else btnfechar = 1;
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionfechar = true;}   
                  }
        
                  else btnfechar = 0;
                  
                  sourceRecfechar.y = btnfechar*(frameHeightfechar-20);
                  
              }break;
        
              case 4:
              {
              PosMouse = GetMousePosition();
                  
                  if (CheckCollisionPointRec(PosMouse, btnFecharrec)){
    
                      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {btnfechar = 2; currentScreen=1;}
                      else btnfechar = 1;
              
                      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActionfechar = true;}   
                  }
        
                  else btnfechar = 0;
                  
                  sourceRecfechar.y = btnfechar*(frameHeightfechar-20);
              
              }break;
        
              default: break;
          }
       
        }
      
        else if(cena==21){

            PosMouse= GetMousePosition();
            
            if (CheckCollisionPointRec(PosMouse, btnS1rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns1 = 2;
                    else btns1 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActions1 = true;cena=12;}
                }
            else btnActions1 = 0;
                
            sourceRecs1.y = btns1*(frameHeights1-55);
            
            //checando colisao com o botao 2
            
            if (CheckCollisionPointRec(PosMouse, btnS2rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns2 = 2;
                    else btns2 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActions2 = true;cena=12;}
                }
            else btnActions2 = 0;
                
            sourceRecs2.y = btns2*(frameHeights2-55);
            
            //checando colisao com o botao 3
            if (CheckCollisionPointRec(PosMouse, btnS3rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns3 = 2;
                    else btns3 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){btnActions3= true;cena=12;}
                }
            else btnActions3 = 0;
                
            sourceRecs3.y = btns3*(frameHeights3-55);
            
            //checando colisao com o botao 4
            
            if (CheckCollisionPointRec(PosMouse, btnS4rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns4 = 2;
                    else btns4 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){ btnActions4 = true;cena=22;}
                }
            else btnActions4 = 0;
                
            sourceRecs4.y = btns4*(frameHeights4-55);
            
            //checando colisao com o botao 5
            
            if (CheckCollisionPointRec(PosMouse, btnS5rec))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btns5 = 2;
                    else btns5 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {btnActions5 = true;cena=12;}
                }
            else btnActions5 = 0;
            
            sourceRecs5.y = btns5*(frameHeights5-55);
            
            }

        //------------------------------


        printf("X=%.1f ",position.x);
        printf("Y=%.1f ",position.y);
        printf("Cena=%d\n",cena);
        

        //----------------------------------------------------------------------------------

        // Draw

        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLUE);
            
            if(cena==0 ){

              switch(currentScreen)
              {
                case 1:
                {
                    
                    DrawTextureEx(TexturasD[4], (Vector2) {movnuvens, -100}, 0.0f, 2.0f, WHITE);//textura das nuvens->telacarreg
                    DrawTexture(TexturasD[2], 0, 0, RAYWHITE); //textura da grama -> teladecarregamento 
                    DrawTextureEx(TexturasD[4], (Vector2){ TexturasD[4].width*2 + movnuvens, -100}, 0.0f, 2.0f, WHITE);
                    DrawTexture(TexturasD[3], 0, 0, RAYWHITE);//textura da casa
                    DrawTexture(Texturas2D[4], 0, 0, RAYWHITE);//textura da casa
                    DrawTextureRec(Texturas2D[0], sourceRecstart, (Vector2){ btnStartrec.x, btnStartrec.y}, WHITE);//texturabotao
                    DrawTextureRec(Texturas2D[1], sourceRecsobre, (Vector2){ btnSobrerec.x, btnSobrerec.y}, WHITE);//texturabotao
                    DrawTextureRec(Texturas2D[2], sourceRecinst, (Vector2){ btnInstrec.x, btnInstrec.y}, WHITE);//texturabotao
                  
                    //mudando cor do botao qnd passa o mouse por cima
                    if(btnstart){DrawTextureRec(Texturas2D[0], sourceRecstart, (Vector2){ btnStartrec.x, btnStartrec.y}, LIGHTGRAY);}
                   
                    if(btnsobre){DrawTextureRec(Texturas2D[1], sourceRecsobre, (Vector2){ btnSobrerec.x, btnSobrerec.y},LIGHTGRAY);}
                    
                    if(btninst) {DrawTextureRec(Texturas2D[2], sourceRecinst, (Vector2){ btnInstrec.x, btnInstrec.y},LIGHTGRAY);}
                    
                    
                }break;
                
                case 2:{
                
                //carregando texturas da tela que aparece antes do jogo comecar
                
               // DrawTexture(mn1, 0, 0, WHITE);
                DrawTexture(TexturasD[5], 0, 0, WHITE);
                DrawText(TextSubtext(messagejogar1, 0, framesCounter1/3), 130, 160, 40, BLACK);
                DrawText(TextSubtext(messagejogar2, 0, framesCounter2/3), 130, 220, 40, BLACK);
                DrawText(TextSubtext(messagejogar3, 0, framesCounter3/3), 130, 280, 40, BLACK);
                DrawText(TextSubtext(messagejogar4, 0, framesCounter4/3), 130, 340, 40, BLACK);
                DrawText(TextSubtext(messagejogar5, 0, framesCounter5/3), 133, 480, 31, DARKBROWN);
                DrawText(TextSubtext(messagejogar6, 0, framesCounter6/3), 200, 600, 65, RED);
                
                }break;    
                case 3:{
                    
                    //texturas da tela "sobre"
                    
                  //  DrawTexture(mn1, 0, 0, WHITE);
                    DrawTexture(TexturasD[5], 0, 0, WHITE);
                    DrawTexture(Texturas2D[5], 1070, 110, WHITE);
                    DrawText("SOBRE", 680, 100, 100, BLACK);
                    DrawText(messagesobre1, 200, 240, 40, DARKBROWN);
                    DrawText(messagesobre2, 200, 300, 40, DARKBROWN);
                    DrawText(messagesobre3, 200, 360, 40, DARKBROWN);
                    DrawTextureRec(Texturas2D[3], sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y}, WHITE);
                    
                    //mudando cor do botao "fechar"
                   if(btnfechar){DrawTextureRec(Texturas2D[3], sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y},RED);}
                   
                    
                }break;
                
                case 4:
                {
                    //carregando texturas da tela de instrucoes
                    
                    DrawTexture(TexturasD[0], 0, 0, DARKBROWN);
                    DrawTexture(TexturasD[5], 0, 0, WHITE);
                    DrawText("INSTRUçÕES", 320, 120, 100,BLACK);
                    DrawTexture(Texturas2D[5], 1000, 130, WHITE);
                    DrawText(messageinst1, 300, 320, 30, BLACK);
                    DrawText(messageinst2, 300, 380, 30, BLACK);
                    DrawText(messageinst3, 300, 440, 30, BLACK);
                    DrawText(messageinst4, 300, 500, 30, BLACK);
                    DrawText(messageinst5, 300, 560, 30, BLACK);
                    DrawText(messageinst6, 300, 620, 30, BLACK);
                    DrawTextureRec(Texturas2D[3], sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y}, WHITE);
                    
                    //mudando cor do botao "fechar"
                    if(btnfechar){DrawTextureRec(Texturas2D[3], sourceRecfechar, (Vector2){ btnFecharrec.x, btnFecharrec.y},RED);}
                    
                }break;
                
                  
          }  
  
        }
            
            else if(cena == 1){

                DrawTexture(TexturasD[6],0,0,WHITE);
                DrawTexture(TexturasD[7],0,0,WHITE);
             
                 
            }
        
            else  if(cena ==2){

                DrawTexture(TexturasD[8],0,0,WHITE);
                DrawTexture(TexturasD[9],0,0,WHITE);
             
            }

            else if(cena==3){

                DrawTexture(TexturasD[10],0,0,WHITE );
                DrawTexture(TexturasD[11],0,0,WHITE );
             

            }

            else if(cena==4){

                DrawTexture(TexturasD[12],0,0,WHITE );
              

            }

            else if(cena==5){

                DrawTexture(TexturasD[15],0,0,WHITE);
                DrawTexture(TexturasD[16],0,0,WHITE);
                if(cenas[5].portas[2].check == 0) DrawText("O vizinho geralmente deixa a chave embaixo do vaso", 0, 0, 45, WHITE);
            }
             
            else if(cena==6){

                DrawTexture(TexturasD[13],0,0,WHITE );
                DrawTexture(TexturasD[14],0,0,WHITE );

            }

            else if(cena==7){

                DrawTexture(TexturasD[18],0,0,WHITE);
                DrawTexture(TexturasD[29],0,0,WHITE);
                jogador.itens[0] = false;
                Fire = AnimFogo(Texturas2D[9]);
                DrawTextureRec(Texturas2D[9], Fire, f, RAYWHITE);

            }

            else if(cena==8){

                DrawTexture(TexturasD[19],0,0,WHITE );
                DrawTexture(TexturasD[20],0,0,WHITE );
             
            }

            else if(cena==9){

                DrawTexture(TexturasD[21],0,0,WHITE);
                DrawTexture(TexturasD[22],0,0,WHITE);
                DrawTexture(TexturasD[25],0,0,WHITE);
                DrawTexture(TexturasD[34], 0, 0,WHITE);
                AnimEspelho(Texturas2D[10], frameEsp1, 1000, 700);
                AnimEspelho(Texturas2D[10], frameEsp2, 130, 700);
                Vector2 vec2 = {px, py};
                AnimPato(Texturas2D[8], FrameWidth2, &frame2, &Mov2, &px, &py, &nextPosition.x, &nextPosition.y, &Mov, PatoFlag);
                Rectangle Duck = {FrameWidth2*frame2, Texturas2D[8].height/Mov2, FrameWidth2, (float) Texturas2D[8].height/4};      //PATO - APENAS NA FASE DO PATO;
                DrawTextureRec(Texturas2D[8], Duck, vec2, RAYWHITE);
                patoHitbox.x = px;
                patoHitbox.y = py;
                DrawTexture(TexturasD[43],0,0,WHITE);
                if(jogador.key[1]==false) DrawText("O pato parece estar com fome", 0, 0, 45, WHITE);
                if(frameEsp1==0) DrawTexture(TexturasD[42],0,80,WHITE);
                if(frameEsp1==0 && frameEsp2==2) {
                    DrawTexture(TexturasD[36],0,0,WHITE);
                    DrawTexture(TexturasD[44],0,20,WHITE);
                    DrawTexture(TexturasD[35], 0, 0,WHITE);
                }
            }

            else if(cena==10){

                DrawTexture(TexturasD[32],0,0,WHITE);
              

            }

            else if(cena==11){
        
                DrawTexture(TexturasD[33],0,0,WHITE);
                DrawTexture(Texturas2D[7], 660, 240, WHITE);

            }

            //labirinto----------------------------------------------

            else if(cena==12){

                DrawTexture(TexturasD[45],0,0,WHITE);
                DrawTexture(TexturasD[54],0,10,WHITE);
                jogador.itens[2] = false;

            }

            else if(cena==13){

                DrawTexture(TexturasD[46],0,0,WHITE);
                DrawTexture(TexturasD[55],0,10,WHITE);

            }

            else if(cena==14){

                DrawTexture(TexturasD[47],0,0,WHITE);
                DrawTexture(TexturasD[56],0,10,WHITE);

            }

            else if(cena==15){

                DrawTexture(TexturasD[48],0,0,WHITE);
                DrawTexture(TexturasD[57],0,10,WHITE);
            }

            else if(cena==16){

                DrawTexture(TexturasD[49],0,0,WHITE);
                DrawTexture(TexturasD[58],0,10,WHITE);
             
            }

            else if(cena==17){

                DrawTexture(TexturasD[50],0,0,WHITE);
                DrawTexture(TexturasD[59],0,10,WHITE);
               

            }

            else if(cena==18){

                DrawTexture(TexturasD[51],0,0,WHITE);
                DrawTexture(TexturasD[60],0,10,WHITE);
                

            }

            else if(cena==19){

                DrawTexture(TexturasD[52],0,0,WHITE);
                DrawTexture(TexturasD[61],0,10,WHITE);
               
            }

            else if(cena==20){

                DrawTexture(TexturasD[53],0,0,WHITE);
                DrawTexture(TexturasD[62],0,10,WHITE);
             

            }

            
            if(cena==21){

                ClearBackground(BLUE);
                DrawTexture(TexturasD[5], 0, 0, WHITE);
                DrawText("Qual a senha?",450,200,150,BLACK);
                DrawTextureRec(TexturasD[37], sourceRecs1, (Vector2){ btnS1rec.x, btnS1rec.y}, WHITE);
                DrawTextureRec(TexturasD[38], sourceRecs2, (Vector2){ btnS2rec.x, btnS2rec.y}, WHITE);
                DrawTextureRec(TexturasD[39], sourceRecs3, (Vector2){ btnS3rec.x, btnS3rec.y}, WHITE);
                DrawTextureRec(TexturasD[40], sourceRecs4, (Vector2){ btnS4rec.x, btnS4rec.y}, WHITE);
                DrawTextureRec(TexturasD[41], sourceRecs5, (Vector2){ btnS5rec.x, btnS5rec.y}, WHITE);

            }

            else if(cena==22){
                
                framesCounter7++;

                DrawTexture(TexturasD[63],0,0,RAYWHITE);

                if(framesCounter7<300)DrawText(TextSubtext("???????????????????????????????????", 0, framesCounter7/3), 200, 850, 60, BLACK);
                if(framesCounter7>300&&framesCounter7<600)DrawText("Sabrina: ?????????  Então era você o saci Perêrê", 200, 850, 60,WHITE);
                if(framesCounter7>600&&framesCounter7<1100)DrawText("Saci: Como você chegou aqui?", 200, 850, 60, RED);
                if(framesCounter7>600&&framesCounter7<1100)DrawText("Já vi que o labirinto não é de nada.", 200,920, 60, RED);
                if(framesCounter7>1100&&framesCounter7<1500)DrawText("Sabrina: Nada que uma garota ", 200, 850, 60, WHITE);
                if(framesCounter7>1100&&framesCounter7<1500)DrawText("de talentos não dê conta ;).", 200,920, 60, WHITE);
                if(framesCounter7>1500&&framesCounter7<1900)DrawText("Saci: Só não me prenda numa garrafa,", 200, 850, 60, RED);
                if(framesCounter7>1500&&framesCounter7<1900)DrawText("tenho más memórias", 200,920, 60, RED);
                if(framesCounter7>1900&&framesCounter7<2200)DrawText("Sabrina: Não é o tipo  de magia que eu faço.", 200, 850, 60, WHITE);
                if(framesCounter7>2200&&framesCounter7<2600)DrawText("Saci: Mas...... por favor não conte, ", 200, 850, 60, RED);
                if(framesCounter7>2200&&framesCounter7<2600)DrawText("meu segredo a ninguém!", 200,920, 60, RED);
                if(framesCounter7>2600&&framesCounter7<3000)DrawText("Saci: o preconceio é demais nessa ", 200, 850, 60, RED);
                if(framesCounter7>2600&&framesCounter7<3000)DrawText("sociedade opressora", 200,920, 60, RED);
                if(framesCounter7>3000&&framesCounter7<3300)DrawText("Sabrina: Qual motivo eu teria pra guardar segredo?", 200, 850, 60, WHITE);
                if(framesCounter7>3300&&framesCounter7<3700)DrawText("Saci: Você também tem seus segredos,", 200, 850, 60, RED);
                if(framesCounter7>3300&&framesCounter7<3700)DrawText(" gostaria de explanar?", 200,920, 60, RED);
                if(framesCounter7>3700&&framesCounter7<4000)DrawText("Sabrina: Bom ponto, não mexo em quem tá quieto", 200, 850, 60, WHITE);
                if(framesCounter7>4000&&framesCounter7<4300)DrawText("Sabrina: Gostei do senhor, seu segredo está guardado", 190, 850, 60, WHITE);
                if(framesCounter7>4300&&framesCounter7<4700)DrawText("Sabrina: Só me garanta que vai cuida da ", 200, 850, 60, WHITE);
                if(framesCounter7>4300&&framesCounter7<4700)DrawText("natureza, e lutar contra o desmatamento", 200,920, 60, WHITE);
                if(framesCounter7>4700&&framesCounter7<5100)DrawText("Sabrina e Saci observam juntos a paisagem.", 200,850, 60, BLACK);
                if(framesCounter7> 5100){cena=11; nextPosition.y=800;}




            }

            else if(cena>0){

                Vector2 vec = {nextPosition.x-200, nextPosition.y-250};
                AnimPlayer(Texturas2D[6], FrameWidth, &frame, &Mov, &x, &y);
                Rectangle Character = {FrameWidth*frame, Texturas2D[6].height/Mov, FrameWidth, (float) Texturas2D[6].height/4};     //PLAYER - INICIO DO LOOP;
                DrawTextureRec(Texturas2D[6], Character, vec, RAYWHITE);
            } 
            

            AnimItem(Texturas2Ditens, jogador.itens, 5, nextPosition.x - 200, nextPosition.y - 250);
            
            EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadSound(sound);
    UnloadMusicStream(music);
    CloseAudioDevice();

    //--------------------------------------------------------------------------------------

    freeCenas(cenas,23);
    freeTexturasD(TexturasD);
    freeTexturas2D(Texturas2D);
    freeTexturas2DI(Texturas2Ditens);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}