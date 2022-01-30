#include<stdio.h>
#include <stdlib.h>
// stackteki bir elemani gosteren veri yapisi.
struct StackNode {
    int data;
    char* name;
    struct StackNode* next;
};

// stacke eklemek icin yeni dugum olusturur.
struct StackNode* newNode(int data, char* name)
{
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->name = name;
    stackNode->next = NULL;
    return stackNode;
}

// stackin bos olup olmadigini doner. 
int isEmpty(struct StackNode* root)
{
    return !root;
}

// stackin en ustteki elemanini stackten cikarmadan doner.
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return -1;
    return root->data;
}

// stacke yeni eleman ekler.
void push(struct StackNode** root, int data)
{
    // stacking en ustteki elemani ekleyecegimiz elemandan kucukse veya stack bossa ekleyemeyiz.
    int top = peek(*root);
    if (top != -1 && data > top)
        return;
        
    // stackin ismini alalim.
    char* name = (*root)->name;
    // yeni dugumu ayni stack ismiyle ve verilen data ile olsuturalim.
    struct StackNode* stackNode = newNode(data, name);
    // olusturdugumuz yeni dugumu rootun onune ekliyoruz.
    stackNode->next = *root;
    // rootu yeni dugumu gosterecek sekilde guncelliyoruz.
    *root = stackNode;
    
    printf("Disk %d  %s'e/ye eklendi\n", data, name);
}
 
// stackin en ustteki elemanini stackten cikarir.
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return -1;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    printf("Disk %d %s'den cikarildi\n", popped, (*root)->name);
    return popped;
}

void towerOfHanoi(int n, struct StackNode** fromStack, struct StackNode** toStack, struct StackNode** auxStack) 
{ 
    if (n == 1) 
    { 
        // en kucuk diski tasidigimizda recursive call'dan cikiyoruz.
        int disk = pop(fromStack);
        push(toStack, disk);
        return; 
    } 
    towerOfHanoi(n-1, fromStack, auxStack, toStack); 
    int disk = pop(fromStack);
    push(toStack, disk);
    towerOfHanoi(n-1, auxStack, toStack, fromStack); 
} 

int main()
{
    
    struct StackNode* cubuk1 = newNode(-1, "Çubuk 1");
    struct StackNode* cubuk2 = newNode(-1, "Çubuk 2");
    struct StackNode* cubuk3 = newNode(-1, "Çubuk 3");
 
    push(&cubuk1, 3);
    push(&cubuk1, 2);
    push(&cubuk1, 1);
    
    printf(" \n\n\n");
    
    // stackler asagidaki pozisyonda su anda
    //     |1|      |       |
    //    | 2 |     |       |
    //   |  3  |    |       |
    //  -------- ------- -------
 
    towerOfHanoi(3, &cubuk1, &cubuk3, &cubuk2);
    

    return 0;
}
