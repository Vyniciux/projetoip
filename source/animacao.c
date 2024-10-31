#include "raylib/src/raylib.h"
#include <stdio.h>

void AnimPlayer(Texture2D Player, float FrameWidth, int *frame, float *Mov, float *x, float *y){
    int maxFrames = (int) (Player.width/(int)FrameWidth);
    static float timer = 0.0f;
    timer += GetFrameTime();
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)){
        if(timer >= 0.2f){
            timer = 0.0f;
            *frame += 1;
        }
    }
    *frame = *frame % maxFrames;
    if(IsKeyDown(KEY_W)){
        *Mov = 4;
        *y -= 5;
    }
    if(IsKeyDown(KEY_A)){
        *Mov = 1.30;
        *x -=5;
    }
    if(IsKeyDown(KEY_S)){
        *Mov = 1;
        *y += 5;
    }
    if(IsKeyDown(KEY_D)){
        *Mov = 2;
        *x += 5;
    }
}

void AnimPato(Texture2D Pato, float FrameWidth2, int *frame2, float *mov2, float *px, float *py, float *x, float *y, float *Mov, int comida){
    int maxFrames = (int) (Pato.width/(int)FrameWidth2);
    static float timer = 0.0f;
    static int cnt = 0, pnt = 0;
    timer += GetFrameTime();
    *frame2 = *frame2 % maxFrames;
    if(comida>0){
        if(*y < 600 && *y > 150 && *x < 1300 && *x > 1200){
            if(cnt == 0){
                if(IsKeyDown(KEY_W)){
                    *y += 5;
                }
                *Mov = 1;
                *y += 5;
            }
        }
        if(*y >= 600){
            *Mov = 4;
            cnt = 1;
        }
        if(*y>=500){
            pnt++;
        }
        if(pnt>0){
            if(*px < 1700 || *py > 200){
                if(timer >= 0.2f){
                timer = 0.0f;
                *frame2 += 1;
                }
            }
            if(*px < 1700){
                *px += 5;
            }
            if(*py > 200){
                *py -= 3;
            }
            if(*px == 1700 && *py == 200){
                *mov2 = 1;
            }
        }
    }
} 

void AnimEspelho(Texture2D Espelho, int frame3, float x, float y){       
    float FrameWidth3 = (float) (Espelho.width/4);
    Vector2 e = {x, y};
    Rectangle Mirror = {FrameWidth3*frame3, Espelho.height, FrameWidth3, (float) Espelho.height};    
    DrawTextureRec(Espelho, Mirror, e, RAYWHITE);
}

Rectangle AnimFogo(Texture2D Fire){
    float FrameWidth = (float) (Fire.width/8);
    int maxFrames = (int) (Fire.width/(int)FrameWidth);
    static float timer = 0.0f;
    static int frame = 1;
    timer += GetFrameTime();
    if(timer >= 0.2f){
        timer = 0.0f;
        frame += 1;
    }
    frame = frame % maxFrames;
    Rectangle Fogo = {FrameWidth*frame, Fire.height, FrameWidth, (float) Fire.height};
    
    return Fogo;
}

void AnimItem(Texture2D *item, bool *itens, int qtdItens, float x, float y){
    for(int i=0; i<qtdItens; i++){
        if(itens[i]){
            DrawTexture(item[i], x+300, y-10, RAYWHITE);
        }
    }
}







