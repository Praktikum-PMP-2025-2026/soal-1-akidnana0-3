#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ID[10];
    int WaktuTunggu;
    struct Node* next; 
} Node;

Node *Head = NULL;

void PushBack(int WaktuTunggu, char *ID) {
    Node *NodeBaru = (Node*)malloc(sizeof(Node));

    if (!NodeBaru) {
        return;
    }

    strcpy(NodeBaru->ID, ID);
    NodeBaru->WaktuTunggu = WaktuTunggu;
    NodeBaru->next = NULL;

    if (Head == NULL) {
        Head = NodeBaru;
        return;
    }

    Node *Current = Head;
    while(Current->next != NULL) {
        Current = Current->next;
    }
    Current->next = NodeBaru;
}

void Display(){
    Node* Current = Head;
    while(Current != NULL){
        printf(" %s", Current->ID);
        Current = Current->next;
    }
}

int HitungWaktuTotal(){
    Node* Current = Head;
    int WaktuTungguTotal = 0;
    while(Current->next != NULL){
        WaktuTungguTotal = WaktuTungguTotal + Current->WaktuTunggu;
    }
    return WaktuTungguTotal;
}

int main() {
    int N, TempWaktuTunggu;
    char TempID[10];
    int WaktuTungguTotal;
    
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s%d", TempID, &TempWaktuTunggu);
        PushBack(TempWaktuTunggu, TempID);
    }
    
    printf("ORDER");
    Display();

    WaktuTungguTotal = HitungWaktuTotal();
    printf("\n");
    printf("WAIT ");
    printf("%d", WaktuTungguTotal);


    return 0;
}
