#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *isimler[] = {"Ahmet","Bilal","Cemal","Adem","Yasin","Esin","Emel","Mustafa","Ayten","Ceylan","Nesrin","Bekir","Emin","Hakan", "Hatice"};
int tutarlar[15] = {100,1000,600,650,350,270,410,750,600,1000,900,850,790,610,550};

typedef struct kayit {
    char* isim;
    int tutar;
    struct node * next;
} kayit_t;

// olusturulacak üc listenin ilk nodelari
kayit_t *liste1 ;
kayit_t *liste2 ;
kayit_t *liste3 ;


// verilen kaydı listeye sondan ekler
void ekle1(kayit_t *liste, char *isim, int tutar) {
    // verilen listenin sonuna git
    kayit_t* simdiki = liste;
    while (simdiki->next != NULL) {
        simdiki = simdiki->next;
    }

    // yeni kayit olustur
    kayit_t *yeni = (kayit_t*) malloc(sizeof(kayit_t));
    yeni->isim = isim;
    yeni->tutar = tutar;
    
    // yeni kaydi listenin sonuna ekle
    simdiki->next = yeni;
}

// verilen kaydi listeye sondan ekler
void ekle2(kayit_t **liste, char *name, int fatura) {
    
    // yeni kayit olustur
    kayit_t *yeni = (kayit_t*) malloc(sizeof(kayit_t));
    yeni->isim = name;
    yeni->tutar = fatura;

    // listenin boş olup olmadığını ve liste başına ekleme yapılıp yapılmayacağını kontrol ediyor.
    if (*liste == NULL || strcmp((*liste)->isim, yeni->isim) > 0){
        yeni->next = *liste; 
        *liste = yeni; 
    } else {
        kayit_t* simdiki = *liste;
        while (simdiki->next != NULL) {
            kayit_t *iter = simdiki->next;
            if (strcmp(iter->isim, yeni->isim) >= 0) {
                break;
            }
            simdiki = simdiki->next;
        }
        yeni->next = simdiki->next;
        simdiki->next = yeni;
    }
}

void ekle3(kayit_t **liste,char *name,int fatura){
    // yeni kayit olustur
    kayit_t *yeni = (kayit_t*) malloc(sizeof(kayit_t));
    yeni->isim = name;
    yeni->tutar = fatura;
    // listenin boş olup olmadığını ve liste başına ekleme yapılıp yapılmayacağını kontrol ediyor.
    if(*liste == NULL || (*liste)->tutar < yeni->tutar){ 
        yeni->next = *liste; 
        *liste= yeni;
    }else{
        kayit_t* simdiki = *liste;
        while (simdiki != NULL) {
            kayit_t* iter = simdiki->next;
            if (iter->tutar < yeni->tutar){
                break;
            }
            simdiki= simdiki->next;
        }
        yeni->next = simdiki->next;
        simdiki->next = yeni;
        
    }
}

// verilen harfe ile başlayan listedeki kişileri basar.
void YazdirAd( kayit_t *liste,char hedefHarf) {
    kayit_t *temp = (kayit_t*) malloc(sizeof(kayit_t));
    temp = liste;
    printf("Müşteri Adı\t Fatura Bedeli \n");
    while(temp != NULL ) {
        if((temp->isim[0]) == hedefHarf ){
            printf("%s\t\t %d \n", temp->isim, temp->tutar);
        }
        temp = temp->next;
    }
}

// verilen tutardan veya eşit olan fatura miktarına sahip listedeki kişileri basar.
void YazdirTutar( kayit_t *liste,int hedefTutar){
    kayit_t *temp = (kayit_t*) malloc(sizeof(kayit_t));
    temp = liste;
	printf("Müşteri Adı\t Fatura Bedeli \n");

    while(temp != NULL ){
        if(temp->tutar >= hedefTutar){
            printf("%s\t\t %d \n", temp->isim, temp->tutar);
        }
        temp = temp->next;
    }
}



int main()
{
    liste1 = (kayit_t*) malloc(sizeof(kayit_t));
    liste1 = NULL;
    for (int i = 0; i < 15; i++) {
        ekle1(&liste1, isimler[i], tutarlar[i]);
    }//verilen kayıtları  listeye olduğu gibi ekler
    
    liste2 = (kayit_t*) malloc(sizeof(kayit_t));
    liste2 = NULL;
    for (int i = 0; i < 15; i++) {
        ekle2(&liste2, isimler[i], tutarlar[i]);
    }//verilen kayıtları listeye olduğu isme göre ekleyerek sıralar
    
    liste3 = (kayit_t*) malloc(sizeof(kayit_t));
    liste3=NULL;
    for (int i = 0; i < 15; i++) {
        ekle3(&liste3, isimler[i], tutarlar[i]);
    }//verilen kayıtları listeye olduğu fatura miktarına göre ekleyerek sıralar
    
    YazdirAd(liste2,'A');
    printf(" \n");
    YazdirTutar(liste3,900);
    
    return 0;
    
}