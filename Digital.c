#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Digital{
    struct Digital *letra[27];
}digital;

digital *criando_arvore();
digital *inserindo(digital *raiz,char nome[],int n);
void procura_palavra(digital *raiz,char nome[],int n);

int main(){
    digital *mae;
    mae=criando_arvore();
    int menu=0;
    char nome[20];
    do{
        printf("MENU:\n1)Inserir\n2)Procurar");
        scanf("%d",&menu);
        switch (menu){
            case 1:
                printf("\nQual palavra a ser inserida?\n");
                setbuf(stdin,NULL);
                gets(nome);
                mae=inserindo(mae,nome,0);
                break;
            case 2:
                printf("\nQual palavra procuramos??\n");
                setbuf(stdin,NULL);
                gets(nome);
                procura_palavra(mae,nome,0);
                break;
        }
        system("pause");
        system("cls");
    }while(menu!=0);

    return 0;
}
void procura_palavra(digital *raiz,char nome[],int n){
    printf("%c\n",nome[n]);
    for(int i=0;i<=27;i++){
        if(nome[n]==i+97){
            if(raiz->letra[i]!=NULL){
                procura_palavra(raiz->letra[i],nome,n+1);
            }
        }else if(nome[n]=='\0'&&raiz->letra[27]!=NULL){
            printf("PALAVRA ENCONTRADA\n");
            break;
        }
    }
}

digital *inserindo(digital *raiz,char nome[],int n){/////
    digital *aux;
    aux=criando_arvore();
    if(nome[n]!='\0'||nome[n]=='\0'){
        for(int j=0;j<=27;j++){
            if(raiz->letra[j]!=NULL){
                raiz->letra[j]=inserindo(raiz->letra[j],nome,n+1);
            }else if(nome[n]==j+97){
                raiz->letra[j]=aux;
                aux=inserindo(aux,nome,n+1);
                return raiz;
            }else if(nome[n]=='\0'){
                raiz->letra[27]=aux;
                return raiz;
            }
        }
    }
    return raiz;
}

digital *criando_arvore(){
    digital *aux;
    aux=(digital *)malloc(sizeof(digital));
    int i=0;
    for(i=0;i<=27;i++){
        aux->letra[i]=NULL;
    }
    return aux;
}