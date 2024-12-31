#pragma once

// Put Every Function Declaration You Add here in the same order they are in functions.c

PatQueue AddPatient(Patient P, PatQueue *SQ, PatQueue *EQ);
bool SearchPAt(PatQueue q, Patient p);