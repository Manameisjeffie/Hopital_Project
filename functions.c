#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainDeclaration.h"
#include "queue.h"
#include "history.h"

// Function Made By Yasser Kadri
int max(int a, int b){
    if (a > b){
        return a;
    }
    else
    {
        return b;
    }
}

void HandlePatientId(Patient *P, PatQueue *SQ, PatQueue *EQ)
{
    if (IsEmpty(*SQ) && IsEmpty(*EQ))
    {
        P->id = 1;
    }
    else
    {
        P->id = max(TailQueue(*SQ).id, TailQueue(*EQ).id) + 1;
    }
}

void AddPatient(Patient P, PatQueue *SQ, PatQueue *EQ, History* history, int* lastElemIndex) //SQ for standard queue and EQ for emergency queue
{
    HistoryData data;
    HandlePatientId(&P, SQ, EQ);
    data.p = P;
    data.state = true;

    if (P.emergencySituation == false)
    {
        Push(SQ, P);
        AddHistory(history, data, lastElemIndex);
    }
    else
    {
        Push(EQ, P);
        AddHistory(history, data, lastElemIndex);
    }
}

// Function Made By Touri Houcine
bool SearchPAt(PatQueue sq, PatQueue eq, Patient *p){//sq for standard queue and eq for emergency queue
    Patient psq,peq;//rana n7awso 3la p w psq w peq w temp hada zyada ghir lel pop wel push
    PatQueue temp;
    bool b;

    temp.head = NULL;
    temp.tail = NULL;

    if (p->emergencySituation!=true){
        if (p->id<=0){
        
        while (sq.head != NULL){
            if (strcmp(p->IP.firstName, sq.head->info.IP.firstName)== 0 && strcmp(p->IP.lastName, sq.head->info.IP.lastName)== 0){//3jzt nachra7 mi 3labali ana chikor suuuuuu

                    if (p->IP.gender== sq.head->info.IP.gender// hadi drtha hna bl3ani pssq 9adr wa7d machi 3arbi ...
                    && p->age== sq.head->info.age
                    && strcmp(p->illnessOrInjury, sq.head->info.illnessOrInjury)== 0
                    && p->emergencySituation== sq.head->info.emergencySituation 
                    && strcmp(p->personalDoctor.IP.firstName, sq.head->info.personalDoctor.IP.firstName)== 0
                    && strcmp(p->personalDoctor.IP.lastName, sq.head->info.personalDoctor.IP.lastName)== 0){//zdt hadi ligne bach btkon wad7a ktr
                    
                        b = true;
                        Pop(&eq, p);//rani dayrha bach yt7at kolch fl p bla ma nach9a ....1
                        Push(&eq, *p);//w hna raja3t mi manach 7nperdiw wach kayn fel p 
                        break;
                    }
                }else{
                    Pop(&sq, &psq);
                    Push(&temp, psq);
                    b = false;
                }
            }
        }else{
            while (sq.head != NULL){
                if (p->id==sq.head->info.id){
                
                        b = true;
                        Pop(&eq, p);//rani dayrha bach yt7at kolch fl p bla ma nach9a ....2
                        Push(&eq, *p);//w hna raja3t mi manach 7nperdiw wach kayn fel p
                        break;
                }else{
                    Pop(&sq, &psq);
                    Push(&temp, psq);
                    b = false;
                }
            }
        }

        while (temp.head != NULL){
            Pop(&temp, &psq);
            Push(&sq, psq);
        }
        free(temp.head);
        free(temp.tail);
    }else{
        if (p->id<=0){
        
        while (eq.head != NULL){
            if (strcmp(p->IP.firstName, eq.head->info.IP.firstName)== 0 && strcmp(p->IP.lastName, eq.head->info.IP.lastName)== 0){//3jzt nachra7 mi 3labali ana chikor suuuuuu

                    if (p->IP.gender== eq.head->info.IP.gender// hadi drtha hna bl3ani pseq 9adr wa7d machi 3arbi ...
                    && p->age== eq.head->info.age
                    && strcmp(p->illnessOrInjury, eq.head->info.illnessOrInjury)== 0
                    && p->emergencySituation== eq.head->info.emergencySituation 
                    && strcmp(p->personalDoctor.IP.firstName, eq.head->info.personalDoctor.IP.firstName)== 0
                    && strcmp(p->personalDoctor.IP.lastName, eq.head->info.personalDoctor.IP.lastName)== 0){//zdt hadi ligne bach btkon wad7a ktr
                    
                        b = true;
                        Pop(&eq, p);//rani dayrha bach yt7at kolch fl p bla ma nach9a ....3
                        Push(&eq, *p);//w hna raja3t mi manach 7nperdiw wach kayn fel p
                        break;
                    }
                }else{
                    Pop(&eq, &peq);
                    Push(&temp, peq);
                    b = false;
                }
            }
        }else{
            while (eq.head != NULL){
                if (p->id==eq.head->info.id){
                
                        b = true;
                        Pop(&eq, p);//rani dayrha bach yt7at kolch fl p bla ma nach9a ....4
                        Push(&eq, *p);//w hna raja3t mi manach 7nperdiw wach kayn fel p
                        break;
                }else{
                    Pop(&eq, &peq);
                    Push(&temp, peq);
                    b = false;
                }
            }
        }

        while (temp.head != NULL){
            Pop(&temp, &peq);
            Push(&sq, peq);
        }
        free(temp.head);
        free(temp.tail);
    }

    return b;
}

// Function Made By Yasser Kadri
void DeletePatient(PatQueue *SQ, PatQueue *EQ, History* history, int* lastElemIndex){
    Patient P;
    if (!IsEmpty(*EQ)) {
        Pop(EQ, &P);
        HistoryData data = {P, false};
        AddHistory(history, data, lastElemIndex);
    }
    else if (!IsEmpty(*SQ)) {
        Pop(SQ, &P);
        HistoryData data = {P, false};
        AddHistory(history, data, lastElemIndex);
    }
    else {
        printf("both queues are empty\n"); //no patients
    }
}
