#include "raylib/src/raylib.h"
#include "itens.h"

void gerarItens(Texture2D **listaDeItens){

    Texture2D chave = LoadTexture("assets/itens/iten007.png");
    Texture2D maca = LoadTexture("assets/itens/iten005.png");
    Texture2D livro = LoadTexture("assets/itens/iten0010.png");
    Texture2D baldeVazio = LoadTexture("assets/itens/iten008.png");
    Texture2D baldeCheio = LoadTexture("assets/itens/iten009.png");

    (*listaDeItens)[0] = chave;
    (*listaDeItens)[1] = maca;
    (*listaDeItens)[2] = livro;
    (*listaDeItens)[3] = baldeVazio;
    (*listaDeItens)[4] = baldeCheio;
}
