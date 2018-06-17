#ifndef UTL_H
#define UTL_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <cstring>
#include <iostream>



// ------------------------------------------ 
// DEFINES
// ------------------------------------------

#define TOTAL_FIGURAS_PACOTE 5
#define TOTAL_FIGURAS_ALBUM 681
#define NAO_ACHOU_FIGURA -1
#define FIGURAS_COLADAS 1
#define FIGURAS_FALTANDO 2

// ------------------------------------------ 
// ESTRUTURAS
// ------------------------------------------

// PACOTE FIGURAS
typedef struct{
    int figura[TOTAL_FIGURAS_PACOTE];
}TPacote;

// ALBUM FIGURAS
typedef struct{
    int qtde;
}TFigura;

typedef struct{
    TFigura figura[TOTAL_FIGURAS_ALBUM];  
    int totalFiguras; 
}TAlbum;

// ------------------------------------------ 
// FUNCOES PACOTE
// ------------------------------------------

void AbrePacoteFigura(TPacote *pct);
void ImprimePacote(TPacote *pct);

// ------------------------------------------ 
// FUNCOES ALBUM
// ------------------------------------------

void InicializarAlbum(TAlbum *album);
int TamanhoAlbum(TAlbum *album);
bool ColarFigura(TAlbum *album, int figura);
void ColarPacote(TAlbum *album, TPacote *pct);
void ImprimirAlbum(TAlbum *album);
void ImprimirFigura(TAlbum *album, int pos);
bool BuscaFigura(TAlbum* album, int figura);
void IrABanca(TAlbum *album, TPacote *pct,int times);

// ------------------------------------------ 
// RELATORIO
// ------------------------------------------

void RelatorioAlbum(TAlbum *album, int tipo);

// ------------------------------------------ 
// ACESSO ARQUIVO
// ------------------------------------------

bool SalvarAlbum(TAlbum *album);
bool AbrirAlbum(TAlbum *album);
#endif
