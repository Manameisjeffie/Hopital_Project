#pragma once

typedef struct HistoryData
{
    Patient p;
    bool state; //if Patient was added/removed to/from the queue, state = true means added to the queue, state = false means removed from the queue
}HistoryData;

// i might remove Pervious Pointer at a later point if it will not be used
typedef struct History
{
    HistoryData info;
    struct History* next;
    unsigned int index;
}History;

History* InitHistory();
void AddHistory(History* history, HistoryData info, int* lastElemIndex);
HistoryData get(History* history, int index);
void ShowHistory(History* history);
void ShowMoreInfo(History* history, int index);