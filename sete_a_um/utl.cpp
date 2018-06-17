#include "utl.h"

//---------------------------------------------------------------------
//			PACOTE FIGURAS
//---------------------------------------------------------------------
void AbrePacoteFigura(TPacote *pct)
{	
    memset(pct, 0, TOTAL_FIGURAS_PACOTE);    
    int i = 0;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
            pct->figura[i] = (rand() % TOTAL_FIGURAS_ALBUM);  
    }
}

//---------------------------------------------------------------------
void ImprimePacote(TPacote *pct)
{
    int i = 0;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
        printf(" %i ", pct->figura[i]);	
    }	
}

//---------------------------------------------------------------------
//			ALBUM
//---------------------------------------------------------------------
void InicializarAlbum(TAlbum *album){
    //Iniciar seed rand (numero aleatorio)
    srand(time(NULL));  
    memset(album, 0, sizeof(TAlbum));
}

//---------------------------------------------------------------------
int TamanhoAlbum(TAlbum *album){
    return album->totalFiguras;
}

//---------------------------------------------------------------------
bool ColarFigura(TAlbum *album, int pos){  
    album->totalFiguras = album->totalFiguras + 1;
    album->figura[pos].qtde++;    
    return true;
}

//---------------------------------------------------------------------
void ColarPacote(TAlbum *album, TPacote *pct){
    int i;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
        ColarFigura(album, pct->figura[i]);
    }
}

//---------------------------------------------------------------------
void ImprimirAlbum(TAlbum *album){
    //http://patorjk.com/software/taag/
    printf("\n");    
    printf("  /$$$$$$  /$$       /$$$$$$$  /$$   /$$ /$$      /$$        /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$\n");
    printf(" /$$__  $$| $$      | $$__  $$| $$  | $$| $$$    /$$$       /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$\n");
    printf("| $$  \\ $$| $$      | $$  \\ $$| $$  | $$| $$$$  /$$$$      | $$  \\__/| $$  \\ $$| $$  \\ $$| $$  \\ $$\n");
    printf("| $$$$$$$$| $$      | $$$$$$$ | $$  | $$| $$ $$/$$ $$      | $$      | $$  | $$| $$$$$$$/| $$$$$$$$\n");
    printf("| $$__  $$| $$      | $$__  $$| $$  | $$| $$  $$$| $$      | $$      | $$  | $$| $$____/ | $$__  $$\n");
    printf("| $$  | $$| $$      | $$  \\ $$| $$  | $$| $$\\  $ | $$      | $$    $$| $$  | $$| $$      | $$  | $$\n");
    printf("| $$  | $$| $$$$$$$$| $$$$$$$/|  $$$$$$/| $$ \\/  | $$      |  $$$$$$/|  $$$$$$/| $$      | $$  | $$\n");
    printf("|__/  |__/|________/|_______/  \\______/ |__/     |__/       \\______/  \\______/ |__/      |__/  |__/\n");                                                                                          
                                                                                                   
    int i;
    int count = 0;
    for(i = 0 ; i <= TOTAL_FIGURAS_ALBUM; i++) { 
        if(album->figura[i].qtde > 0){
            printf("\n\t\t--------------------------------------------------------\n");
            printf("\t\t|\tIDX\t|\tFIGURA\t|\tREPETIDAS\t|\n");
            printf("\t\t|\t%i\t|\t%i\t|\t%i\t\t|", count++, i, (album->figura[i].qtde - 1));
        }        
    }
    printf("\n\t\t--------------------------------------------------------\n");
}

//---------------------------------------------------------------------
void ImprimirFigura(TAlbum *album, int pos){
    printf(" figura %i qtde: %i\n", pos, album->figura[pos].qtde);
}

//---------------------------------------------------------------------
bool SalvarAlbum(TAlbum *album){
    bool rslt = false;
    FILE * file = fopen("album.alb", "wb");
    if(file != NULL) {
        int r = fwrite(album, sizeof(TAlbum), 1, file);
        if(r != 0){
            printf("Album salvo com sucesso!\n");
            rslt = true;
        }
        else{
            printf("Erro ao salvar album!\n");  
        }        
        fclose(file);
    }  
    return rslt;
}

//---------------------------------------------------------------------
bool AbrirAlbum(TAlbum *album){
    bool rslt = false;
    FILE * file= fopen("album.alb", "rb");
    if (file != NULL) {
        fread(album, sizeof(TAlbum), 1, file);
        int totalFiguras = 0;
        for(int i = 0; i <= TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i].qtde > 0){
                totalFiguras++;
            }
        }
        if(totalFiguras == album->totalFiguras){
            rslt = true;
        }
        fclose(file);
    }
    return rslt;
}

//---------------------------------------------------------------------
bool BuscaFigura(TAlbum* album, int figura){
    for(int i = 0; i <= TOTAL_FIGURAS_ALBUM; i++){
        if(album->figura[i].qtde > 0){
            return true;
        }
    }    
    return false;
}


//---------------------------------------------------------------------
void IrABanca(TAlbum *album, TPacote *pct, int times){
    for(int i = 0; i < times; i++){
        AbrePacoteFigura(pct);
	printf("Figuras pacote: \n"); 
	ImprimePacote(pct);	
	ColarPacote(album, pct);
	printf("\nTamanho album: %i\n", TamanhoAlbum(album));
    }
}

//---------------------------------------------------------------------
//  RELATORIO
//---------------------------------------------------------------------
void RelatorioAlbum(TAlbum *album, int tipo){
    // tipo 1: FIGURAS_COLADAS  Relatorio Figuras Coladas
    // tipo 2: FIGURAS_FALTANDO Relatorio Figuras Faltando
    printf("\nRelatorio Album\n");
    printf("Completo: %i / 681", album->totalFiguras);
    if(tipo == FIGURAS_COLADAS){
        printf("\nFiguras Coladas: ");
        for(int i = 1; i <= TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i].qtde > 0){                
                printf("%i ", i);
            }
        }
    }
    else{
        printf("\nFiguras Faltando: ");
        for(int i = 1; i <= TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i].qtde == 0){                
                printf("%i ", i);
            }
        }
    }
}
