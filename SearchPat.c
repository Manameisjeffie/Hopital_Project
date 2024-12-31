#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"mainDecelaration.h"
#include"queue.h"

bool SearchPAt(PatQueue q){
    Patient p,pq;//rana n7awso 3la p w pq w temp hada zyada ghir lel pop wel push
    PatQueue temp;
    int x;
    bool b;

    temp.head=NULL;
    temp.tail=NULL;

    printf("Please fill the full name of the patient you search for\nif you don't know type \"?\" ");
    scanf("%s %s", p.IP.firstName, p.IP.lastName);

    if (p.IP.firstName== "?" || p.IP.lastName== "?"){

        printf("you should give her emergency Situation And the gender and the age of the patient\nand if he is illness or injury and if you can the his doctor");
        scanf("%c %d %d %s %s %s",p.IP.gender, p.age, x, p.illnessOrInjury, p.personalDoctor.IP.firstName, p.personalDoctor.IP.lastName);

        p.emergencySituation=(x!=0);// 0 m3ntha false w ay ra9m akher true

        while (q.head!= NULL){
            if (p.personalDoctor.block== q.head->info.block){//3jzt nachra7 mi 3labali ana chikor suuuuuu

                if (p.IP.gender== q.head->info.IP.gender
                && p.age== q.head->info.age
                && strcmp(p.illnessOrInjury, q.head->info.illnessOrInjury)== 0
                && p.emergencySituation== q.head->info.emergencySituation 
                && strcmp(p.personalDoctor.IP.firstName, q.head->info.personalDoctor.IP.firstName)== 0
                && strcmp(p.personalDoctor.IP.lastName, q.head->info.personalDoctor.IP.lastName)== 0){//zdt hadi ligne bach btkon wad7a ktr
                    
                    b=true;
                    break;
                }
            }else{
                Pop(&q,&pq);
                Push(&temp,pq);
                b=false;
            }
        }
    }else{
        while (q.head!= NULL){
            if (strcmp(p.IP.firstName, q.head->info.IP.firstName)== 0, strcmp(p.IP.lastName, q.head->info.IP.lastName)== 0){
                
                    b=true;
                    break;
            }else{
                Pop(&q,&pq);
                Push(&temp,pq);
                b=false;
            }
        }
    }
    while (temp.head!=NULL){
        Pop(&temp,&pq);
        Push(&q,pq);
    }
    free(temp.head);
    free(temp.tail);
    return b;
}