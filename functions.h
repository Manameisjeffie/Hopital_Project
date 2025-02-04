#pragma once

// Put Every Function Declaration You Add here in the same order they are in functions.c
int max(int a, int b);
void HandlePatientId(Patient P, PatQueue *SQ, PatQueue *EQ);
void AddPatient(Patient P, PatQueue *SQ, PatQueue *EQ, History* history, int* lastElemIndex);
bool SearchPAt(PatQueue sq, PatQueue eq, Patient *p);
void DeletePatient(PatQueue *SQ, PatQueue *EQ, History* history, int* lastElemIndex);