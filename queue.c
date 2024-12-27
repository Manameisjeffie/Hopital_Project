#include <stdlib.h>
#include <stdbool.h>
#include "mainDeclaration.h"
#include "queue.h"

bool IsEmpty(PatQueue Q)
{
    return(Q.head==NULL);
}

PatQueue InitQueue() {
    PatQueue f;
    f.head = NULL;
    f.tail = NULL;
    return f;
}

Patient HeadQueue(PatQueue f) {
    Patient X;
    if(f.head !=NULL){
         X = f.head->info;
    }
    return X;
}

void Push(PatQueue *f, Patient X) {
    SinglePat *temp = (SinglePat*) malloc(sizeof(SinglePat));
    temp->info = X;
    temp->next = NULL;
    if (f->head == NULL) {
        f->head = temp;
        f->tail = temp;
    } else {
        f->tail->next = temp;
        f->tail = temp;
    }
}

void Pop(PatQueue *f, Patient *X) {
    SinglePat *temp = f->head;
    *X = temp->info;
    if (f->head == f->tail) {
        f->head = NULL;
        f->tail = NULL;
    } else {
        f->head = f->head->next;
    }
    free(temp);
}
