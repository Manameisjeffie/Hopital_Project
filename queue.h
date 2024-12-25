#pragma once

#include "mainDecelaration.h"

typedef struct SinglePat{
    Patient patient;//drtha haka khir mn info
    struct SinglePat *next;//hna stikitha jon kan ghalt w makach katb struct
}SinglePat;
//Pat is short for patient

typedef struct PatQueue{
    SinglePat *head;
    SinglePat *tail;
}PatQueue;

bool IsEmpty(PatQueue Q){
    return Q.head == NULL;
}

PatQueue InitQueue(){
    PatQueue f;
    f.head = NULL;
    f.tail = NULL;
    return f;
}

Patient HeadQueue(PatQueue *f){//hna bdeltha ga3 jon kan mroblha hakda khir
    if (f->head == NULL) {
        printf("no patient fonded\n");
        exit(EXIT_FAILURE);
    }
    return f->head->patient;
}

void Push(PatQueue *f,Patient x){
    SinglePat *temp;
    
    temp = (SinglePat *)malloc(sizeof(SinglePat));//hna kifkif bdlt 3fays
    
    if (temp==NULL){
        printf("error in allocation in push fonction\n");
        exit(EXIT_FAILURE);
    }
    temp->patient = x;
    

    temp->next = NULL;

    if (f->head == NULL){
        f->head = temp;
        f->tail = temp;
    }else{
        f->tail->next = temp;
        f->tail = temp;//kont nasi ";" rak nawi n9tlk
    }
}

void Pop(PatQueue *f,Patient *x){// the same I will kill you if you do this again
    SinglePat *temp;
    if (f->head == NULL) {
        printf("no patient fonded\n");
        exit(EXIT_FAILURE);
    }
    *x = f-> head->patient;
    

    temp = f->head;

    if (f->head == f->tail){
        f->head = NULL;
        f->tail = NULL;
    }else{
        f->head = f->head->next;
    }
    free(temp);
}