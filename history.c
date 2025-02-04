#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mainDeclaration.h"
#include "history.h"


History* InitHistory()
{
    History* hist;
    HistoryData data;
    hist = (History*) malloc(sizeof(History));
    hist->index = 0;
    hist->next = 0;
    hist->info = data;
    return hist;
}

//Adds at the end of list
void AddHistory(History* history, HistoryData info, int* lastElemIndex)
{
    History* newElem = 0;
    History* firstElem = 0;
    History* temp = 0;
    firstElem = history;
    temp = history;
    newElem = (History*) malloc(sizeof(History));
    newElem->info = info;
    while(temp->next != 0)
    {
        temp = temp->next;
    }
    newElem->index = temp->index + 1;
    *lastElemIndex = newElem->index;
    newElem->next = 0;
    temp->next = newElem;
    history = firstElem;
}

//This Function Might not be used
HistoryData get(History* history, int index)
{
    History* temp = history;
    while (temp->index < index)
    {
        temp = temp->next;
    }
    return temp->info;
}

void ShowHistory(History* history, int lastElemIndex)
{
    History* temp;
    temp = history;
    temp = temp->next;
    int i = 0;
    if (temp == 0)
    {
        printf("There is nothing to show here\n");
    }
    else
    {
        while (i < lastElemIndex)
        {
            printf("History Position: %u\n", temp->index);
            printf("Patient ID: %d\n", temp->info.p.id);
            printf("Full Name: %s %s\n", temp->info.p.IP.firstName, temp->info.p.IP.lastName);
            printf("Age: %d\n", temp->info.p.age);
            printf("Gender: %s\n", temp->info.p.IP.gender == 'M' || temp->info.p.IP.gender == 'm' ? "Male" : "Female");
            printf("Was %s The Waiting Queue, in the %s Queue\n", temp->info.state ? "Added To" : "Removed From", temp->info.p.emergencySituation ? "Emergency" : "Standard");
            printf("-------------------------------------------------\n");
            i++;
            temp = temp->next;
        }
    }
}

void ShowMoreInfo(History* history, int index)
{
    History* temp = 0;
    temp = history;
    while (temp->index < index)
    {
        temp = temp->next;
    }
    printf("-------------------------------------------------\n");
    printf("\nHistory Position: %u\n", temp->index);
    printf("Patient ID: %u\n", temp->info.p.id);
    printf("Full Name: %s %s\n", temp->info.p.IP.firstName, temp->info.p.IP.lastName);
    printf("Age: %d\n", temp->info.p.age);
    printf("Gender: %s\n", temp->info.p.IP.gender == 'M' || temp->info.p.IP.gender == 'm' ? "Male" : "Female");
    printf("Blood Type: %s\n", temp->info.p.bloodType);
    printf("The Injury/Illness: %s\n", temp->info.p.illnessOrInjury);
    printf("The Block he will pass in: %c\n", temp->info.p.block);
    printf("is it an Emergency ?: %s\n", temp->info.p.emergencySituation ? "Yes" : "No");
    printf("Was %s The Waiting Queue, in the %s Queue\n", temp->info.state ? "Added To" : "Removed From", temp->info.p.emergencySituation ? "Emergency" : "Standard");
    printf("\n-------------------------------------------------\n");
}