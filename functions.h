#pragma once

// Put Every Function Declaration You Add here in the same order they are in functions.c

void AddPatient(Patient P, PatQueue *SQ, PatQueue *EQ, History* history);
bool SearchPAt(PatQueue q, Patient p);