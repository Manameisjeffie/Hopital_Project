#pragma once

typedef struct HistoryData
{
    Patient p;
    bool hasBeenConsulted; //if Patient was checked by doc
    bool state; //if Patient was added/removed to/from the queue, state = true means added to the queue, state = false means removed from the queue
}HistoryData;

// i might remove Pervious Pointer at a later point if it will not be used
typedef struct History
{
    HistoryData info;
    History* next;
    History* previous;
    unsigned int index;
}History;

History* InitHistory(HistoryData data);
void AddHistory(History* history, HistoryData info);
HistoryData get(History* history, int index);
void ShowHistory(History* history);
void ShowMoreInfo(History* history, int index);