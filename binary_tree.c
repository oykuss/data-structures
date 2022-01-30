// ODEV 1 - BINARY AGAC VERI YAPISI :

#include <stdio.h>
#include <stdlib.h>

struct node { 
    int key; 
    struct node *left, *right; 
}; 
typedef struct node Node;

Node * queue[1000];
int front=0;
int rear=-1;

Node* newNode(int data){ 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->key = data;
    temp->left = temp->right = NULL; 
    return temp; 
}

Node *insertRight(Node *new, int data){
    if (new==NULL){
        new = newNode(data);
    }
    
    else{
        Node * temp = new;
        if (temp->right != NULL)
        {
            temp->right = insertRight(temp->right, data);
        }
        else{
            temp->right = newNode(data);
        }
    }
    return new;
}

Node *insertLeft(Node *new, int data){
    
    if (new==NULL){
        new = newNode(data);
    }
    
    else{
        Node * temp = (Node*)malloc(sizeof(Node));
        temp = new;
        if (temp->left != NULL){
            temp->left = insertLeft(temp->left, data);
        }
        else{
            temp->left = newNode(data);
        }
    }
    return new;
}

void printPreorder( Node* node){ 
    if (node == NULL) 
        return; 

    printf("%d ", node->key); 
  
    printPreorder(node->left); 
  
    printPreorder(node->right); 
} 

void printInorder(Node* node){ 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
  
    printf("%d ", node->key); 
    
    printInorder(node->right); 
} 

void printPostorder(Node* node) 
{ 
    if (node == NULL) 
        return; 

    printPostorder(node->left); 
  
    printPostorder(node->right); 
  
    printf("%d ", node->key); 
} 

void enqueue(Node *root){
    if(root != NULL){
        rear++;
        queue[rear] = root;
    }
}

void dequeue(){
    if(rear>=front){
        Node *root = queue[front];
        if(root != NULL) {
            printf("%d ", root->key);
        }
        front++;
        enqueue(root->left);
        enqueue(root->right);
    }
}

void printBFS(Node *node){
    if(node != NULL){
        enqueue(node);
        do{
            dequeue(node);
        }while(front <= rear);
    }
}


int main()
{
    Node* root = ( Node*)malloc(sizeof( Node));
    root = NULL;
    
    root = insertRight(root,1);
    insertRight(root,2);
    insertLeft(root,3);
    insertLeft(root,5);
    insertRight(root->left,7);
    insertRight(root,4);
    insertLeft(root->right,6);
    
    printf("Preorder: ");
    printPreorder(root);
    printf("\n");
    printf("Inorder : ");
    printInorder(root);
    printf("\n");
    printf("Postorder: ");
    printPostorder(root);
    printf("\n");
    printf("BFS : ");
    printBFS(root);

    return 0;
}


// ODEV 2 - INDEX TABLOSU :

#include <stdio.h>
#include <stdlib.h>

struct binarySearchTree { 
    int index;
    struct binarySearchTree *left, *right; 
};
typedef struct binarySearchTree bst;

int ogrenci[15] = {18060311,20060045,19061091,20060134,20060678,18061086,20060032,20060067,19060456,18060245,20060110,20060234,20060141,20060011,20060012};
int puan[15] = {40,50,75,90,40,75,50,60,60,75,40,90,60,50,60};


bst* kayitYarat(int index)
{
    bst *p;
    p = (bst*)malloc(sizeof(bst));
    p->index = index;
    p->left = NULL;
    p->right = NULL;

    return p;
}


bst* ekle(bst *root, int index)
{
    if(root==NULL)
        return kayitYarat(index);
    else if(puan[root->index] > puan[index])
        root->left = ekle(root->left, index);
    else if(puan[root->index] < puan[index])
        root->right = ekle(root->right, index);
    else
        if(ogrenci[root->index] < ogrenci[index])
            root->left = ekle(root->left, index);
        else
            root->right = ekle(root->right, index);
    return root;
}

void siraliYazdir(bst *root, int grade)
{
    if(root != NULL) {
        siraliYazdir(root->right, grade);
        if (grade != puan[root->index])
            
            printf("%d \t %d \t %d\n", root->index, ogrenci[root->index], puan[root->index]);
        siraliYazdir(root->left, grade);
    }
    
}

bst* min(bst *root){
    
    bst* current = root;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}


bst* sil(bst* node , int i){
    if(node == NULL) 
        return NULL;

    else if (puan[i] < puan[node->index])
        node->left = sil(node->left, i);

    else if (puan[i] > puan[node->index])
        node->right = sil(node->right, i);
    
    else {
        if (i == node->index) {

            if (node->left == NULL) {
                bst* temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL) {
                bst* temp = node->left;
                free(node);
                return temp;
            }
            bst* temp = min(node->right);

            node->index = temp->index;

            node->right = sil(node->right, temp->index);
        }
        else {
            if (ogrenci[i] <= ogrenci[node->index])
                node->right = sil(node->right, i);
            else
                node->left = sil(node->left, i);
        }
    }
    return node;
}


void degistir(bst* root, int i, int yeniPuan){
    sil(root,i);
    puan[i] = yeniPuan ;
    ekle(root,i);
    
}

void yazdir(bst* node , int grade){ 
    if (node == NULL) {
        return;
    }
    else if (grade < puan[node->index])
        yazdir(node->left, grade);
    
    else if (grade > puan[node->index])
        yazdir(node->right, grade);
    
    else
        siraliYazdir(node->right, grade);
} 


int main()
{
    bst* root;
    root = kayitYarat(0);
    for (int i = 1; i < 15; i++) {
        ekle(root, i);
    }
    
    //sil(root, 0);
    //printf("0 indeksi silindi\n");
    //ekle(root,0);
    //printf("0 indeksi eklendi\n");
    //degistir(root,2,100);
    //printf("2 indeksinin puanı 100 ile değişti\n");
    printf("Index \t Öğrenci No \t Puan\n");
    yazdir(root, 50);
    
    return 0;
}