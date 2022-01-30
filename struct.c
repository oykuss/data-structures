#include <stdio.h>
#include <stdlib.h>

struct kategori{
    char tur ;
    char urun_adi[20];
    float maliyet;
    char turu;
    char alinma[15];
    char paketlenme[15];
    char sonkullanma[15];
    int reyon_nu;
    char reyon_taraf;
    struct kategori *next;
};
typedef struct kategori Kategoriler;

Kategoriler* urun_kaydet(Kategoriler* root){

    printf("Ürün kategorisi seçiniz (E,T,S,K,G) -> ");
    char cevap ;
    scanf(" %c",&cevap);
    Kategoriler * temp ;
    if(root == NULL) 
	{
		root = (Kategoriler*)malloc(sizeof(Kategoriler));
		root -> next = NULL;
		temp = root ;
	}
	
	else{
	    Kategoriler * iter = root;
	    while(iter ->next != NULL){
		    iter = iter -> next; 
	    }
	    temp = (Kategoriler*)malloc(sizeof(Kategoriler)); 
	    iter -> next = temp;
	    temp -> next = NULL;
	}
	
	temp->tur = cevap;
    switch(cevap){
        case 'E':
            temp->tur = cevap;
            printf("Ürün adını giriniz->");
            scanf("%s", temp->urun_adi);
            printf("Ürünün TL cinsinden maliyetini giriniz ->");
            scanf("%f",&(temp->maliyet));   
            printf("Et türünü giriniz (R,B,P)->");
            while( getchar() != '\n'){
                continue;
            }
            temp->turu = getchar();
            printf("Paketlenme tarihini giriniz(#-#-#)->");
            scanf(" %s", temp->paketlenme);
            printf("Son kullanım tarihini giriniz(#-#-#)->");
            scanf(" %s", temp->sonkullanma);
            break; 
    
        case 'T':
            temp->tur = cevap;
            printf("Ürün adını giriniz->");
            scanf("%s",temp->urun_adi);
            printf("Ürünün TL cinsinden maliyetini giriniz ->");
            scanf("%f",&(temp->maliyet));   
            printf("Tarım türünü giriniz (M,S)->");
            while( getchar() != '\n'){
                continue;
            }
            temp->turu = getchar();
            printf("Alınma tarihini giriniz(#-#-#)->");
            scanf(" %s", temp->alinma);
            break;
        
        case 'S':
            temp->tur = cevap;
            printf("Ürün adını giriniz->");
            scanf("%s",temp->urun_adi);
            printf("Ürünün TL cinsinden maliyetini giriniz ->");
            scanf("%f",&(temp->maliyet));
            printf("Son kullanım tarihini giriniz(#-#-#)->");
            scanf("%s", temp->sonkullanma);
            break;
      
        case 'K' :
            temp->tur = cevap;
            printf("Ürün adını giriniz->");
            scanf("%s",temp->urun_adi);
            printf("Ürünün TL cinsinden maliyetini giriniz ->");
            scanf("%f",&(temp->maliyet));
            printf("Son kullanım tarihini giriniz(#-#)->");
            scanf(" %s", temp->sonkullanma);
            printf("Ürün reyon numarasını giriniz->");
            scanf("%d", &(temp->reyon_nu));
            printf("Ürünün reyon tarafını giriniz (A/B)->");
            while( getchar() != '\n'){
                continue;
            }
            temp->reyon_taraf = getchar();
            break;
            
        case 'G':
            temp->tur = cevap;
            printf("Ürün adını giriniz->");
            scanf(" %s",temp->urun_adi);
            printf("Ürünün TL cinsinden maliyetini giriniz ->");
            scanf("%f",&(temp->maliyet));     
            printf("Gıda dışı türünü giriniz (C,P,D)->");
            while( getchar() != '\n'){
                continue;
            }
            temp->turu = getchar();
            printf("Ürün reyon numarasını giriniz->");
            scanf("%d", &(temp->reyon_nu));
            printf("Ürünün reyon tarafını giriniz (A/B)->");
            while( getchar() != '\n'){
                continue;
            }
            temp->reyon_taraf = getchar();
            
            break;
    
    }
   

   return root;
}

void urun_goster(Kategoriler* root){
    printf("------------------------Kayitli Urunler-----------------------------\n");
    
    Kategoriler *temp = root ;
    while (temp != NULL){
        char harf = temp->tur ;
        switch(harf){
            case 'E':
                printf("%s %fTL %c %s %s \n",temp->urun_adi, temp->maliyet , temp->turu, temp->paketlenme ,temp->sonkullanma);
                break;
            case 'T':
                printf("%s %fTL %c %s \n",temp->urun_adi, temp->maliyet ,  temp->turu, temp->alinma);
                break;
            case 'S':
                printf("%s %fTL %s \n",temp->urun_adi, temp->maliyet,temp->sonkullanma);
                break;
            case 'K':
                printf("%s %fTL %s %d %c \n",temp->urun_adi, temp->maliyet,temp->sonkullanma ,temp->reyon_nu,temp->reyon_taraf);
                break;
            case 'G':
                printf("%s %fTL %c %d %c \n",temp->urun_adi, temp->maliyet,root->turu ,temp->reyon_nu,temp->reyon_taraf);
            
        }
        temp = temp->next;
    }
    printf("----------------------------------------\n");
}

int main()
{
    
    Kategoriler *UK = NULL;
    UK = urun_kaydet(UK);
    
    printf("----------- 2. Ürün Bilgileri -----------------\n");
    UK =urun_kaydet(UK);
    
    urun_goster(UK);
    return 0;
}

