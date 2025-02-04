#include <stdlib.h>
#include <stdbool.h>
#include "mainDeclaration.h"
#include "queue.h"

bool IsEmpty(PatQueue Q){
    return Q.head == 0;
}

PatQueue InitQueue() {
    PatQueue f;
    f.head = 0;
    f.tail = 0;
    return f;
}

Patient HeadQueue(PatQueue f) {
    Patient X;
    if (IsEmpty(f))
    {
        X.id = 0;
        //return X;
    }

    if (f.head != 0){
         X = f.head->info;
    }
    return X;
}

Patient TailQueue(PatQueue f){
    Patient X;
    if (IsEmpty(f))
    {
        X.id = 0;
        //return X;
    }

    if(f.tail != 0){
        X = f.tail->info;
    }
    return X;
}

void Push(PatQueue *f, Patient X) {
    SinglePat *temp = (SinglePat*) malloc(sizeof(SinglePat));
    temp->info = X;
    temp->next = 0;
    if (f->head == 0) {
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
        f->head = 0;
        f->tail = 0;
    } else {
        f->head = f->head->next;
    }
    free(temp);
}