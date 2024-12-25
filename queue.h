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
    /**temp-> patient. IP. firstName = x. IP. firstName;
    *temp-> patient . IP.  lastName = x. IP. lastName;
    temp-> patient. age = x. age;
    temp-> patient. bloodType = x. bloodType;
    temp-> patient. emergencySituation = x. emergencySituation;
    temp-> patient. illnessOrInjury = x. illnessOrInjury;
    temp-> patient. block = x. block;
    temp-> patient. priority = x. priority;
    temp-> patient. personalDoctor = x. personalDoctor;*/

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
    /*x. IP. firstName = **f-> head. patient. IP. firstName;
    *x. IP. lasttName = **f-> head. patient. IP.lasttName;
    x. age = *f-> head. patient. age;
    x. block = *f-> head. patient. block;
    x. bloodType = *f-> head. patient. bloodType;
    x. emergencySituation = *f->head. patient. emergencySituation;
    x. illnessOrInjury = *f->head. patient. illnessOrInjury;
    x. priority = *f-> head. patient. priority;
    x. personalDoctor = *f->head. patient. personalDoctor*/

    temp = f->head;

    if (f->head == f->tail){
        f->head = NULL;
        f->tail = NULL;
    }else{
        f->head = f->head->next;
    }
    free(temp);
}

int main(){
  Patient p1;
  printf("3mr");

  

  scanf("%s %s %d", p1.IP.firstName, p1.IP.lastName, p1.age);

  scanf("%s %s %c", p1.bloodType, p1.illnessOrInjury, p1.block);

  scanf("%d %s %s", p1.priority, p1.personalDoctor.IP.firstName, p1.personalDoctor.IP.lastName);

  scanf("%s %c", p1.personalDoctor.specialization, p1.personalDoctor.block);


  printf("1 %s %s %d",p1.IP.firstName, p1.IP.lastName, p1.age);

  printf("2 %s %s %c",p1.bloodType, p1.illnessOrInjury, p1.block);

  printf("3 %d %s %s",p1.priority, p1.personalDoctor.IP.firstName, p1.personalDoctor.IP.lastName);

  printf("4 %s %c",p1.personalDoctor.specialization, p1.personalDoctor.block);
}