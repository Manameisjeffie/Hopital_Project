#include "mainDeclaration.h"
#include "queue.h"
#include <stdbool.h>

PatQueue AddPatient(Patient P, PatQueue *SQ, PatQueue *EQ) //SQ for standard queue and EQ for emergency queue
{ 
    if (P.emergencySituation == false)
    {
        Push(&SQ, P);
        return SQ;
    }
    else
    {
        Push(&EQ, P);
        return EQ;
    }
}