 #pragma once

typedef struct SinglePat {
    Patient info;
    struct SinglePat *next;
} SinglePat;

typedef struct {
    SinglePat *head;
    SinglePat *tail;
} PatQueue;

bool IsEmpty(PatQueue Q);
PatQueue InitQueue();
Patient HeadQueue(PatQueue f);
Patient TailQueue(PatQueue f);
void Push(PatQueue *f, Patient X);
void Pop(PatQueue *f, Patient *X);
