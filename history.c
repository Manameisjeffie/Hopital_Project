#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mainDeclaration.h"
#include "history.h"


History* InitHistory(HistoryData data)
{
    History* hist;
    hist = (History*) malloc(sizeof(History));
    hist->index = 0;
    hist->next = 0;
    hist->previous = 0;
    hist->info = data;
    return hist;
}

//Adds at the end of list
void AddHistory(History* history, HistoryData info)
{
    History* newElem;
    History* temp = history;
    newElem = (History*) malloc(sizeof(History));
    newElem->info = info;
    if (temp == 0)
    {
        history = InitHistory(info);
        free(newElem);
    }
    else
    {
        while(temp->next != 0)
        {
            temp = temp->next;
        }
        newElem->index = temp->index + 1;
        temp->next = newElem;
        newElem->previous = temp;
    }
    temp = 0;
    free(temp);
}

HistoryData get(History* history, int index)
{
    History* temp = history;
    while (temp->index < index)
    {
        temp = temp->next;
    }
    return temp->info;
}

void ShowHistory(History* history)
{
    History* temp = history;
    while (temp != 0)
    {
        printf("History Position: %u\n", temp->index);
        printf("Patient ID: %u\n", temp->info.p.id);
        printf("Full Name: %s %s\n", temp->info.p.IP.firstName, temp->info.p.IP.lastName);
        printf("Age: %d\n", temp->info.p.age);
        printf("Gender: %c\n", temp->info.p.IP.gender);
        printf("Was %s The Waiting Queue", temp->info.state ? "Added To" : "Removed From");
    }
    temp = 0;
    free(temp);
}

void ShowMoreInfo(History* history, int index)
{
    History* temp = history;
    while (temp->index < index)
    {
        temp = temp->next;
    }
    printf("History Position: %u\n", temp->index);
    printf("Patient ID: %u\n", temp->info.p.id);
    printf("Full Name: %s %s\n", temp->info.p.IP.firstName, temp->info.p.IP.lastName);
    printf("Age: %d\n", temp->info.p.age);
    printf("Gender: %c\n", temp->info.p.IP.gender);
    printf("Blood Type: %s\n", temp->info.p.bloodType);
    printf("The Injury/Illness: %s\n", temp->info.p.illnessOrInjury);
    printf("The Block he will pass in: %c\n", temp->info.p.block);
    printf("is it an emergency ?: %s\n", temp->info.p.emergencySituation ? "Yes" : "No");
    printf("Was %s The Waiting Queue\n", temp->info.state ? "Added To" : "Removed From");
    temp = 0;
    free(temp);
}