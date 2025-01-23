#include <stdbool.h>
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
        return b;
}

void HandlePatientId(Patient P, PatQueue *SQ, PatQueue *EQ)
{
    if (isEmpty(SQ) && isEmpty(EQ))
    {
        P.id = 1;
    }
    else
    {
        P.id = max(TailQueue(SQ).id, TailQueue(EQ).id) + 1;
    }
}

void AddPatient(Patient P, PatQueue *SQ, PatQueue *EQ, History* history) //SQ for standard queue and EQ for emergency queue
{
    HistoryData data = {P, false, true};

    if (P.emergencySituation == false)
    {
        HandlePatientId(P, SQ, EQ);
        Push(&SQ, P);
        AddHistory(history, data);
    }
    else
    {
        HandlePatientId(P, SQ, EQ);
        Push(&EQ, P);
        AddHistory(history, data);
    }
}

// Function Made By Touri Houcine
bool SearchPAt(PatQueue q, Patient p){
    Patient pq;//rana n7awso 3la p w pq w temp hada zyada ghir lel pop wel push
    PatQueue temp;
    int x;
    bool b;

    temp.head = NULL;
    temp.tail = NULL;

    if (p.IP.firstName == "?" || p.IP.lastName == "?"){
        
        p.emergencySituation=(x!=0);// 0 m3ntha false w ay ra9m akher true

        while (q.head != NULL){
            if (p.personalDoctor.block== q.head->info.block){//3jzt nachra7 mi 3labali ana chikor suuuuuu

                if (p.IP.gender== q.head->info.IP.gender
                && p.age== q.head->info.age
                && strcmp(p.illnessOrInjury, q.head->info.illnessOrInjury)== 0
                && p.emergencySituation== q.head->info.emergencySituation 
                && strcmp(p.personalDoctor.IP.firstName, q.head->info.personalDoctor.IP.firstName)== 0
                && strcmp(p.personalDoctor.IP.lastName, q.head->info.personalDoctor.IP.lastName)== 0){//zdt hadi ligne bach btkon wad7a ktr
                    
                    b = true;
                    break;
                }
            }else{
                Pop(&q,&pq);
                Push(&temp,pq);
                b = false;
            }
        }
    }else{
        while (q.head != NULL){
            if (strcmp(p.IP.firstName, q.head->info.IP.firstName)== 0, strcmp(p.IP.lastName, q.head->info.IP.lastName)== 0){
                
                    b = true;
                    break;
            }else{
                Pop(&q, &pq);
                Push(&temp, pq);
                b = false;
            }
        }
    }
    while (temp.head != NULL){
        Pop(&temp, &pq);
        Push(&q, pq);
    }
    free(temp.head);
    free(temp.tail);
    return b;
}

// Function Made By Yasser Kadri
void DeletePatient(Patient P , PatQueue *SQ , PatQueue *EQ){
    if(P.emergencySituation == true){
        Pop(&EQ,&P);
    }
    else{
        if(IsEmpty(EQ)){
            Pop(&SQ,&P);
        }
        else{
            printf("clear all emergencies before");
        }
    }
}
