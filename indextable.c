#include <stdio.h>
#include <stdlib.h>

struct Kayit_s {
  int index;
  int ogrenciNo;
  int puan;
};
struct Kayit_s kayitTablosu[15];

struct Kayit_s default_kayit[15] = {-1, -1, -1,-1, -1, -1,-1, -1, -1,-1, -1,-1, -1, -1}; 
int kayitSayisi = 0;

void ekle(int student[], int grade[]);
void sirala(int student[], int grade[]);
void sil( int ind, int student[], int grade[]);
void degistir(int i, int degisenPuan, int student[], int grade[]);
void yazdir(int hedefPuan);
void tabloyuYazdir(int hedef);

int main()
{
    int ogrenci[15] = {18060311,20060045,19061091,20060134,20060678,18061086,20060032,20060067,19060456,18060245,20060110,20060234,20060141,20060011,20060012};
    int puan[15] = {40,50,75,90,40,75,50,60,60,75,40,90,60,50,60};
    ekle(ogrenci, puan);
    //sil(3, ogrenci, puan);
    //degistir(18060311,70,ogrenci,puan);
    //yazdir(40);
    tabloyuYazdir(kayitSayisi);
    return 0;
}

void sirala(int student[], int grade[]){
    int i, element, element1, element2, j;
    //Puanlara göre karşılaştırma yaparak sıralar.
    for (i = 1; i < 15; i++) { 
        element = kayitTablosu[i].puan;
        element1 = kayitTablosu[i].ogrenciNo;
        element2 = kayitTablosu[i].index;
        j = i - 1; 
        while (j >= 0 && kayitTablosu[j].puan < element){ 
            kayitTablosu[j+1].puan = kayitTablosu[j].puan; 
            kayitTablosu[j+1].ogrenciNo = kayitTablosu[j].ogrenciNo;
            kayitTablosu[j+1].index = kayitTablosu[j].index;
            j = j - 1; 
            
            kayitTablosu[j+1].puan = element; 
            kayitTablosu[j+1].ogrenciNo = element1;
            kayitTablosu[j+1].index = element2;
        } 
    }
    
    for (i = 1; i < 15; i++) { 
        element = kayitTablosu[i].puan;
        element1 = kayitTablosu[i].ogrenciNo;
        element2 = kayitTablosu[i].index;
        j = i - 1; 
        //Puanlar eşitse öğrenci numaralarına göre karşılaştırarak sıralama yapar.
        while (j >= 0 && kayitTablosu[j].puan == element){ 
            if(element1 < kayitTablosu[j].ogrenciNo){
                kayitTablosu[j+1].ogrenciNo = kayitTablosu[j].ogrenciNo;
                kayitTablosu[j].ogrenciNo = element1;
                
                kayitTablosu[j+1].index = kayitTablosu[j].index;
                kayitTablosu[j].index = element2;
            }
            j = j - 1; 
        } 
    }
}

void ekle(int student[], int grade[]){
    // Verilen dizileri kayitTablosu'na indeksine göre ekler.
    for(int j= 0; j <15; j++){
        kayitTablosu[j].index = j ;
        kayitTablosu[j].ogrenciNo = student[j];
        kayitTablosu[j].puan = grade[j];
        kayitSayisi++;
    }
    
    //Ekleme işlemi bittikten sonra istenilene göre sıralama işlemini gerçekleştirir.
    sirala(student,grade);
}

void sil(int ind, int student[], int grade[]){
    for (int i = 0; i < kayitSayisi; i++) {
        if (kayitTablosu[i].index == ind) {
            kayitTablosu[i] = default_kayit[i];
            break;
        }
    }
    //Dizinin boyutunu küçültmek için kayitSayisi değerini azaltırız.
    kayitSayisi--;
    sirala(student,grade);
    
}

void degistir(int i , int degisenPuan, int student[], int grade[]){
    for(int j = 0 ; j<15 ; j++){
        if(kayitTablosu[j].ogrenciNo == i){
            kayitTablosu[j].puan = degisenPuan;
        }
    }
    // Puan değiştikten sonraki duruma göre sıralama yapar.
    sirala(student,grade);
}
void yazdir(int hedefPuan) {
    // Tablomuz puana gore sıralı olduğundan, verilen hedefPuan'dan küçük olan ilk puanı bulalım.
    int hedefIndex = -1;
    for (int i = 0; i < 15; i++) {
        if (kayitTablosu[i].puan <= hedefPuan) {
            hedefIndex = i;
            break;
        }
    }
    // Şimdi hedefIndex'e kadar (kendisi hariç) bütün kayıtları yazdıralım.
    tabloyuYazdir(hedefIndex);
}

void tabloyuYazdir(int hedef) {
    for (int i = 0; i < hedef; i++) {
        printf("%d | %d | %d\n", kayitTablosu[i].index, kayitTablosu[i].ogrenciNo, kayitTablosu[i].puan);
    }
}